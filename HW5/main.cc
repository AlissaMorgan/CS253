#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <fstream>
#include <sstream>

using namespace std;

int main(int argc, char *argv[])
{
	int opt;
	string argStr = ",";
	string strBounds;
	
	bool argR = false;
	bool argF = false;
	bool argS = false;
	bool argC = false;
	bool argV = false;
	bool fileFirst = false;

	if(argv[1]){
		string isArg = argv[1];
		if(!(isArg.at(0) == '-')){
			fileFirst = true;
		}
	}
	
	while ((opt = getopt(argc, argv, "fr:sc:v")) != -1) { //optstring = legitmate option characters
		switch (opt) {
		case 'r':
			if(argR){
				cerr << argv[0] << ": Error -- 'r' given more than once.\n";
				return 1;
			}
			strBounds = optarg;
			argR = true;
		    	break;
		case 'f':
			argF = true;
			break;
		case 's':
			argS = true;
			break;
		case 'c':
			if(argC){
				cerr << argv[0] << ": Error -- 'c' given more than once.\n";
				return 1;
			}
			argStr = optarg;
			argC = true;
			break;
		case 'v':
			argV = true;
			break;
		default: /* '?' */
			//cerr << argv[0] << ": Error -- argument invalid (default)\n";
			return 1;
		}
	}
	if(fileFirst && (argR || argF || argS || argC || argV)){
		cerr << argv[0] << ": Error -- Options must precede filenames.\n";
		return 1;
	}
	
	if(argC && argF && (!argS)){
		cerr << argv[0] << ": Error -- 'c' given without an explicit or implicit '-s'.\n";
				return 1;
	}

	

	int upperBound = 99;
	int lowerBound = 0;
	int loB, upB;
	char delimeter;
	if(argR){
		istringstream iss(strBounds);  // Initialize with the string
		if (iss >> loB >> delimeter >> upB && iss.eof()){        // Extract from the stream
			if(!(delimeter == '-')){
				cerr << argv[0] << ":Error-- option 'r' must provide delimeter '-' to seperate int values instead of " << strBounds << "\n";
				return 1;
			}
			upperBound = upB;
			lowerBound = loB;
		}else{
			cerr << argv[0] << ":Error-- option 'r' must provide range of int bounds\n";
			return 1;
		}
		if(lowerBound > upperBound){
			cerr << argv[0] << ":Error-- the second number (upperbound) given to option 'r' " << upperBound << " is less than the first number(lowerbound) " << lowerBound << "\n";
			return 1;
		}
	}
	auto arrLen = upperBound - lowerBound + 1;
	int *array = new int[arrLen]{0};
	int input = 0;
	if (optind >= argc) { // optind index of next element to be processed in argv // if file not given reading from terminal
		if(argV){cout << argv[0] << ": reading from standard input.\n";}
		while (cin >> input){ 		//inputs data from terminal into array
			if(input >= lowerBound && input <= upperBound){ 			//checks if out of bounds
				array[input - lowerBound] += 1;
			}else{
				cerr << argv[0] << ": input " << input << " not in range [" << lowerBound << "," << upperBound << "]\n";
				delete [] array;
				return 1;
			}
		}
		if(!cin.eof()){ 		//if istream stopped due to not reaching end of inputs
			cerr << argv[0] << ": standard input must only give data of ints\n";
			return 1;
		}
	}else{
		for(int fileOpening = optind; fileOpening < argc; fileOpening++){ //for however many files given
			if(argV){cout << "Reading from " << argv[fileOpening] << "\n";}
			ifstream in(argv[fileOpening]);
			if(!in){		//if can't open file
				cerr << argv[0] << ": can't open " << argv[fileOpening] << "\n";
				delete [] array;
				return 1;
			}
			string s;
			while (in >> s){	//while there's stuff in the file
				int ret;
				istringstream issi(s);  // Initialize with the string
				if (issi >> ret && issi.eof()){        // Extract an int from the stream
					input = ret;
				}else{
					cerr << argv[0] << ": inputs must be ints\n";
					delete [] array;
					return 1;
				}
				if(input >= lowerBound && input <= upperBound){ 		//checks if out of bounds
					array[input - lowerBound] += 1;
				}else{
					cerr << argv[0] << ": input " << input << " not in range [" << lowerBound << "," << upperBound << "]\n";
					delete [] array;
					return 1;
				}
			}
		}
	}
	bool isFirst = true;
	if(argF || (!argF && !argS)){
		for(int i = 0; i <= arrLen - 1; i++){ 	//outputs how many of number there is (ex 10x3)
			if(array[i] != 0){
				if(isFirst){
					cout << i + lowerBound << "x" << array[i];
					isFirst = false;
				}else{
				cout << " " << i + lowerBound << "x" << array[i];
				}
			}
		}
	cout << "\n";
	}
	isFirst = true;
	if(argS || (!argF && !argS)){
		for(int i = 0; i <= arrLen - 1; i++){
			if(array[i] != 0){
				for(int n = array[i]; n > 0; n--){
					if(isFirst){
						cout << i + lowerBound;
						isFirst = false;
					}else{
					cout << argStr << i + lowerBound;
					}
				}
			}
		}
		cout << "\n";
	}
	
	delete [] array;
	return 0;
}
