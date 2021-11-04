#include "Phobic.h"
#include <iostream>
#include <cassert>
 
using namespace std;
 
int main() {
	Phobic a(13);               // a is 13 bumped to 14
	assert(a.get() == 14);      // since 13 is always scarry
	a.make_scary(14);           // bumps a to 15
	assert(a.get() == 15);

	Phobic b = a.add(4);        // b is 15+4 = 19
	assert(a.get() == 15);
	assert(b.get() == 19);
	
	Phobic z = a.sub(4);
	assert(a.get() == 15);
	assert(z.get() == 11);

	Phobic w = a.mul(4);
	assert(a.get() == 15);
	assert(w.get() == 60);

	Phobic x = a.div(4);
	assert(a.get() == 15);
	assert(x.get() == 3);

	b.make_scary(35,12,34);     // b now fears 12,13,34,35
	assert(b.is_scary(12));
	assert(b.is_scary(13));
	assert(b.is_scary(35));
	assert(b.is_scary(34));
	assert(!b.is_scary(42));

	a.add_to(b);                // a is 15+19 = 34, bumped to 36
	assert(a.get() == 36);
	assert(b.add(0).get() == 19);

	assert(a.is_scary(12));     // b’s fears should get merged into a.
	assert(a.is_scary(13));     // a now fears 12,13,14,34,35
	assert(a.is_scary(14));
	assert(a.is_scary(34));
	assert(a.is_scary(35));

	a.mul_by(2);                // a is 36*2 = 72
	const Phobic c(72);
	assert(a.eq(c));            // 72 == 72
	assert(b.lt(c));            // 19 < 72
	assert(c.get() == 72);
	assert(c.eq(72));           // 72 == 72
	assert(c.eq(c));            // 72 == 72
	assert(!c.eq(99));          // !(72 == 99)
	assert(c.lt(99));           // 72 < 72
	assert(!c.lt(-12));         // !(72 < -12)
	assert(!c.lt(c));           // !(72 < 72)
	assert(c.add(1).eq(73));
	
	Phobic m(4); 
	Phobic n(42); 
	m.make_scary(4);
	n.make_scary(42);
	m = n; 
	assert(m.is_scary(42));
	assert(!n.is_scary(4));

	cout << "Success!\n";
	return 0;
}
