#include "hset.h"
#include <iostream>
#include <iomanip>			// for setw()
#include <time.h>			// for time() (duh)

using namespace std;

int main() {
    cout << setprecision(4);		// Display four significant digits

    hset<int> h;
	cout << h.empty() << '\n';
    for (int j=0; j<20; j++)		// Put some numbers into the set
	h.insert(j*17 % 100);		// Each number is [0,100).
    cout << h.empty() << '\n';
    h.dump();				// Let’s see what’s in there

    cout << "size=" << h.size() << ':';
     for (auto v : h)
	cout << ' ' << v;
    cout << '\n';

    hset<string> hs;
    for (auto s : {"alpha", "beta", "gamma", "delta", "epsilon", "zeta", "eta"})
	hs.insert(s);
   hs.dump();

    cout << "size=" << hs.size();
    for (auto v : hs)
	cout << ' ' << v;
    cout << '\n';
	
	hset<double> hsd;
	for (auto s : {1.1, 1.2, 1.3, 1.4, 1.5, 1.6, 1.7, 1.8, 1.9})
		hsd.insert(s);
    	hsd.dump();
	
	hset<int> hsi;
	hsi.insert(1);
	hsd.dump();
	for (auto v : hsi)
	cout << ' ' << v;
    cout << '\n';
	
}
