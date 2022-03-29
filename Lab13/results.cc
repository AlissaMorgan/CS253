#include <algorithm>
#include <iostream>
#include <list>
#include <string>
#include <vector>

using namespace std;

int main() {
    vector<short> pi = {3,1,4,1,5,9,2,6,5,3,5,8,9,7,9,3,2,3,8,4,6,2,6,4};
    string alpha="abcdefghijklmnopqrstuvwxyz", digits="0123456789";
    char cbuf[100] = { };	// contains 100 '\0' chars
    list<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
    short powers[] = {1,2,4,8,16,32,64};
    int ibuf[100];		// contains unknown values

    cout << "Exercise 0\n";
	copy(alpha.begin(), alpha.end(), cbuf);
    	cout << cbuf << '\n';
    cout << "Exercise 1\n";
	reverse(alpha.begin(), alpha.end());
	for(char e: alpha){
		cout << e;
	}
	cout << '\n';
    cout << "Exercise 2\n";
	transform(primes.begin(), primes.end(), begin(ibuf), [](int a) -> int { return a + 1; });
	for(int i = 0; i <= 8; i++){cout << ibuf[i] << " ";}
	cout << ibuf[9] << '\n';
    cout << "Exercise 3\n";
	if (any_of(primes.begin(), primes.end(), [](int i){return i % 2 == 0;})) {
        	cout << "div 2\n";
    	}if (any_of(primes.begin(), primes.end(), [](int i){return i % 42 == 0;})) {
        	cout << "div 42\n";
    	}
    cout << "Exercise 4\n";
	auto finder = find(begin(primes), end(primes), 13);
	auto result = next(finder, 1);
	cout << *result << '\n';
    cout << "Exercise 5\n";
	int counter = count(pi.begin(), pi.end(), 3);
	cout << counter << "\n";
    cout << "Exercise 6\n";
	int count = count_if(pi.begin(), pi.end(), [](int i){return i < 5;});
	cout << count << "\n";
    cout << "Exercise 7\n";
	auto max = max_element(pi.begin(), pi.end());
	cout << *max << "\n";
    cout << "Exercise 8\n";
	sort(pi.begin(), pi.end());
	long unsigned int len = 1;
	for(auto it = pi.begin(); it != pi.end(); ++it){
		if(len != pi.size()){
			cout << *it << " ";
		}else{cout << *it << "\n";}
		len++;
	}
    cout << "Exercise 9\n";
	auto lower = lower_bound(pi.begin(), pi.end(), 7);
	cout << (lower - pi.begin()) << '\n';
    cout << "Exercise 10\n";
	auto ibufIt = set_intersection(pi.begin(), pi.end(), begin(powers), end(powers), begin(ibuf));
	int dist = distance(&ibuf[0], ibufIt);
	for(int i = 0; i < dist - 1; i++){
		cout << ibuf[i] << " ";
	}
	cout << ibuf[dist] << "\n";
}
