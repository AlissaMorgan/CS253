// This is test code for CheapVector.

#include "cv4.h"		// Change to cv1.h … cv4.h, as needed.
#include <iostream>
#include <string>

using namespace std;

int main() {
    cv v={1, 2, 3, 4};

    for (auto val : v)
	cout << val << ' ';
    cout << '\n';

    cout << "Out-of-bounds subscripting:\n";
    try {
	for (size_t i=0; i<=v.size(); ++i)	// incorrect ≤, should be <
	    cout << v[i] << ' ';
	cout << '\n';
    }
    catch (const exception &e) {
	cerr << e.what() << '\n';
    }

    cout << "Out-of-bounds iterator:\n";
    try {
	for (auto it=v.begin(); ; ++it)		// incorrectly goes forever
	    cout << *it << ' ';
	cout << '\n';
    }
    catch (const exception &e) {
	cerr << e.what() << '\n';
    }
}
