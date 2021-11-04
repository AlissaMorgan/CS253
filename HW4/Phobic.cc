#include "Phobic.h"
#include <cctype>
#include <string>


using namespace std;

Phobic::Phobic() : currValue(0) {
}
Phobic::Phobic(const int value) : currValue(value) {
}
Phobic::Phobic(const Phobic &phob) = default; //Copy Ctor

Phobic::~Phobic() =  default;	// Destructor



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

Phobic operator+(const Phobic &lhs, const Phobic &rhs){
	int a = lhs.get() + rhs.get();
	Phobic ret(a);
	for (auto val : lhs.scary){
		ret.scary.insert(val);
	}
	for (auto pval : rhs.scary){
		ret.scary.insert(pval);
	}
	return ret;
}
Phobic operator-(const Phobic &lhs, const Phobic &rhs){
	Phobic ret;
	ret.currValue = lhs.get() - rhs.get();
	for (auto val : lhs.scary){
		ret.scary.insert(val);
	}
	for (auto pval : rhs.scary){
		ret.scary.insert(pval);
	}
	return ret;
}
Phobic operator*(const Phobic &lhs, const Phobic &rhs){
	int a = lhs.get() * rhs.get();
	Phobic ret(a);
	for (auto val : lhs.scary){
		ret.scary.insert(val);
	}
	for (auto pval : rhs.scary){
		ret.scary.insert(pval);
	}
	return ret;
}
Phobic operator/(const Phobic &lhs, const Phobic &rhs){
	if(rhs.get() == 0){
		int left = lhs.get();
		int right = rhs.get();
		string errorMSG = left + "/" + right + " can not divide by zero"s;
		throw runtime_error(errorMSG);
	}
	int a = lhs.get() / rhs.get();
	Phobic ret(a);
	for (auto val : lhs.scary){
		ret.scary.insert(val);
	}
	for (auto pval : rhs.scary){
		ret.scary.insert(pval);
	}
	return ret;
}
Phobic& operator<<(Phobic &lhs, int rhs){
	lhs.scary.insert(rhs);
	return lhs;
}
bool operator==(const Phobic &lhs, const Phobic &rhs){
	if( lhs.get() == rhs.get()){
		return true;
	}
	return false;
}
bool operator<(const Phobic &lhs, const Phobic &rhs){
	bool ret = lhs.get() < rhs.get();
	return ret;
}
bool operator<=(const Phobic &lhs, const Phobic &rhs){
	bool ret = lhs.get() <= rhs.get();
	return ret;
}
bool operator>=(const Phobic &lhs, const Phobic &rhs){
	bool ret = lhs.get() >= rhs.get();
	return ret;
}
bool operator>(const Phobic &lhs, const Phobic &rhs){
	bool ret = lhs.get() > rhs.get();
	return ret;
}
bool operator!=(const Phobic &lhs, const Phobic &rhs){
	bool ret = lhs.get() != rhs.get();
	return ret;
}

