#include "Phobic.h"
#include <cctype>


using namespace std;

Phobic::Phobic() : currValue(0) {
}
Phobic::Phobic(const int value) : currValue(value) {
}
Phobic::Phobic(const Phobic &phob) = default; //Copy Ctor

Phobic::~Phobic() =  default;	// Destructor

Phobic Phobic::add(const Phobic phob) const{
	int a = phob.get() + get();
	Phobic ret;
	ret.currValue = a;
	for (auto val : scary){
		ret.scary.insert(val);
	}
	for (auto pval : phob.scary){
		ret.scary.insert(pval);
	}
	return ret;
}
Phobic Phobic::sub(const Phobic phob) const{
	int a = get() - phob.get();
	Phobic ret;
	ret.currValue = a;
	for (auto val : scary){
		ret.scary.insert(val);
	}
	for (auto pval : phob.scary){
		ret.scary.insert(pval);
	}
	return ret;
}
Phobic Phobic::mul(const Phobic phob) const{
	int a = phob.get() * get();
	Phobic ret;
	ret.currValue = a;
	for (auto val : scary){
		ret.scary.insert(val);
	}
	for (auto pval : phob.scary){
		ret.scary.insert(pval);
	}
	return ret;
}
Phobic Phobic::div(const Phobic phob) const{
	int a = get() / phob.get();
	Phobic ret;
	ret.currValue = a;
	for (auto val : scary){
		ret.scary.insert(val);
	}
	for (auto pval : phob.scary){
		ret.scary.insert(pval);
	}
	return ret;
}
void Phobic::add_to(const Phobic phob){
	int a = phob.get();
	currValue = get() + a;
	for (auto val : phob.scary){
		make_scary(val);
	}
}
void Phobic::sub_from(const Phobic phob){
	int a = phob.get();
	currValue = get() - a;
	for (auto val : phob.scary){
		make_scary(val);
	}
}
void Phobic::mul_by(const Phobic phob){
	int a = phob.get();
	currValue = get() * a;
	for (auto val : phob.scary){
		make_scary(val);
	}
}
void Phobic::div_by(const Phobic phob){
	int a = phob.get();
	currValue = get() / a;
	for (auto val : phob.scary){
		make_scary(val);
	}
}
bool Phobic::eq(const Phobic phob) const{
	bool ret = phob.get() == get();
	return ret;
}
bool Phobic::eq(const Phobic phob){
	bool ret = phob.get() == get();
	return ret;
}
bool Phobic::lt(const Phobic phob) const{
	bool ret = get() < phob.get();
	return ret;
}
bool Phobic::lt(const Phobic phob){
	bool ret = get() < phob.get();
	return ret;
}
int Phobic::get() {
	while(is_scary(currValue)){currValue++;}
	return currValue;
}
int Phobic::get() const{
	return currValue;
}

void Phobic::print_scary() {
	for(auto val: scary){
		cout << val << " is scary\n";
	}
}

bool Phobic::is_scary(int i){
	for (auto val : scary){
		if(val == i){
			return true;
		}
	}
	return false;
}

void Phobic::make_scary(int a){
	scary.insert(a);
}
void Phobic::make_scary(int a, int b){
	scary.insert(a);
	scary.insert(b);
}
void Phobic::make_scary(int a, int b, int c){
	scary.insert(a);
	scary.insert(b);
	scary.insert(c);
}
void Phobic::make_scary(int a, int b, int c, int d){
	scary.insert(a);
	scary.insert(b);
	scary.insert(c);
	scary.insert(d);
}
void Phobic::make_scary(int a, int b, int c, int d, int e){
	scary.insert(a);
	scary.insert(b);
	scary.insert(c);
	scary.insert(d);
	scary.insert(e);
}
void Phobic::make_scary(int a, int b, int c, int d, int e, int f){
	scary.insert(a);
	scary.insert(b);
	scary.insert(c);
	scary.insert(d);
	scary.insert(e);
	scary.insert(f);
}
void Phobic::make_scary(int a, int b, int c, int d, int e, int f, int g){
	scary.insert(a);
	scary.insert(b);
	scary.insert(c);
	scary.insert(d);
	scary.insert(e);
	scary.insert(f);
	scary.insert(g);
}
void Phobic::make_scary(int a, int b, int c, int d, int e, int f, int g, int h){
	scary.insert(a);
	scary.insert(b);
	scary.insert(c);
	scary.insert(d);
	scary.insert(e);
	scary.insert(f);
	scary.insert(g);
	scary.insert(h);
}
void Phobic::make_scary(int a, int b, int c, int d, int e, int f, int g, int h, int i){
	scary.insert(a);
	scary.insert(b);
	scary.insert(c);
	scary.insert(d);
	scary.insert(e);
	scary.insert(f);
	scary.insert(g);
	scary.insert(h);
	scary.insert(i);
}
void Phobic::make_scary(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j){
	scary.insert(a);
	scary.insert(b);
	scary.insert(c);
	scary.insert(d);
	scary.insert(e);
	scary.insert(f);
	scary.insert(g);
	scary.insert(h);
	scary.insert(i);
	scary.insert(j);
}
