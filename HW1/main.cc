//@Alissa Morgan

#include <iostream>
using namespace std;

int main(int, char *argv[]) {
	int input;
	int array[100] = {};
	bool isFirst = true;
    	while (cin >> input){
		if(input >= 0 && input <= 99){
			array[input] += 1;
		}else{
			cerr << argv[0] << ": input " << input << " not in range [0,99]\n";
			return 1;
		}
	}
	for(int i = 0; i <= 99; i++){
		if(array[i] != 0){
			if(isFirst){
				cout << i << "x" << array[i];
				isFirst = false;
			}else{
			cout << " " << i << "x" << array[i];
			}
		}
	}
	cout << "\n";
	isFirst = true;
	for(int i = 0; i <= 99; i++){
		if(array[i] != 0){
			for(int n = array[i]; n > 0; n--){
				if(isFirst){
					cout << i;
					isFirst = false;
				}else{
				cout << "," << i;
				}
			}
		}
	}
	cout << "\n";
	return 0;

}
