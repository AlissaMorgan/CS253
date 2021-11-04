//@Alissa Morgan

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

int main(int argc, char *argv[]) {
	int input = 0;
	if(!(argv[1] && argv[2])){ 		// checks if there are at least two args
		cerr << argv[0] << ": needs at least two int arguments\n";
		return 1;
	}
	int upperBound = 0;
	int upB;
	istringstream iss(argv[2]);  // Initialize with the string
	if (iss >> upB && iss.eof()){        // Extract an int from the stream
		upperBound = upB;
	}else{
		cerr << argv[0] << ": must provide two int bounds\n";
		return 1;
	}
	int lowerBound = 0;
	int loB;
	istringstream issl(argv[1]);  // Initialize with the string
	if (issl >> loB && issl.eof()){        // Extract an int from the stream
		lowerBound = loB;
	}else{
		cerr << argv[0] << ": must provide two int bounds\n";
		return 1;
	}
	if(lowerBound > upperBound){
		cerr << argv[0] << ": first argument is greater than the second\n";
		return 1;
	}
	auto arrLen = upperBound - lowerBound + 1;
	int *array = new int[arrLen]{0};
	if(argc >= 4){ 				//if file is given
		for(int fileOpening = 3; fileOpening < argc; fileOpening++){ 			//for however many files given
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
	}else{
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
			cerr << argv[0] << ": inputs must be ints\n";
			return 1;
		}
	}
	bool isFirst = true;
	for(int i = 0; i <= arrLen; i++){ 	//outputs how many of number there is (ex 10x3)
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
	isFirst = true;
	for(int i = 0; i <= arrLen; i++){ 	//outputs list of inputted numbers
		if(array[i] != 0){
			for(int n = array[i]; n > 0; n--){
				if(isFirst){
					cout << i + lowerBound;
					isFirst = false;
				}else{
				cout << "," << i + lowerBound;
				}
			}
		}
	}
	cout << "\n";
	delete [] array;
	return 0;

}
