//@Alissa Morgan

#include <vector>
#include <string>
#include <set>
#include <iostream>
#include <fstream>

using namespace std;

int main() {
//read ints until given 0
    	vector<int> vec;
	int input;
	while(cin >> input){ 
		if(input == 0){ 
			break;
		}
		vec.push_back(input);
	}
//display content of vector w/ new line
	for (auto i : vec){ 
    		cout << i << "\n";
	}
//read in file, convert every byte to string
	string file;
	ifstream in("/etc/resolv.conf"); 
	for(string line; getline(in, line);){ //for each new line add to string file
		file += line + "\n";
		//if(!in.eof()){ file += "\n";}
	}
//copy contents of string file to multiset
	multiset<char> multis;
	for(auto c : file){ 
		multis.insert(c);	
	}
//copy contents of multiset to set
	set<char> s;
	for(auto c : multis){ 
		s.insert(c);
	}
//display 
	cout << "string: size=" << file.size() << " " << file << "\n"; 
	cout << "set: size=" << s.size() << " "; 
	for( auto val : s){
		cout << val;	
	}
	cout << "\n";
	cout << "multiset: size=" << multis.size() << " ";
	for( auto val : multis){
		cout << val;	
	}
	cout << "\n";
}

// QUESTION 7 /* The size of the set is the smallest because the set doesn't allow repeated values. The size of the string and the multiset are the same due to all values being added to the data structure, yet the multiset displays differently because it is in natural order while the string is in the order the characters were given (same size different ordering of characters). */
