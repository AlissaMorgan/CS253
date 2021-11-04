#ifndef PHOBIC_H_INCLUDED	
#define PHOBIC_H_INCLUDED	// redefinition if this header file is included twice.
#include <iostream>
#include <set>
#include <string>

class Phobic {
public:
	Phobic();
	Phobic(const int value);
	Phobic(const Phobic &phob); 	//Copy Constructor
	~Phobic();	// Destructor
	int get();
	int get() const;
	void print_scary();
	bool is_scary(int i);
	Phobic &operator=(const Phobic &phob){
		currValue = phob.currValue;
		for (auto val : phob.scary){
			scary.insert(val);
		}
		return *this;
	}
	Phobic &operator+=(const Phobic &phob){
		currValue += phob.currValue;
		for (auto val : phob.scary){
			scary.insert(val);
		}
		return *this;
	}
	Phobic &operator-=(const Phobic &phob){
		currValue -= phob.currValue;
		for (auto val : phob.scary){
			scary.insert(val);
		}
		return *this;
	}
	Phobic &operator*=(const Phobic &phob){
		currValue *= phob.currValue;
		for (auto val : phob.scary){
			scary.insert(val);
		}
		return *this;
	}
	Phobic &operator/=(const Phobic &phob){
		if(phob.get() == 0){
			int left = currValue;
			int right = phob.currValue;
			std::cerr<< left << "/" << right << " caused divide by zero error.";
			throw std::runtime_error(" Can not divide by zero");
		}
		currValue /= phob.currValue;
		for (auto val : phob.scary){
			scary.insert(val);
		}
		return *this;
	}
	int currValue = 0;
	std::set<int> scary = {13};
};

[[nodiscard]]Phobic operator+(const Phobic &, const Phobic &);
[[nodiscard]]Phobic operator-(const Phobic &, const Phobic &);
[[nodiscard]]Phobic operator*(const Phobic &, const Phobic &);
[[nodiscard]]Phobic operator/(const Phobic &, const Phobic &);
Phobic & operator<<(Phobic &, int rhs);
[[nodiscard]]bool operator==(const Phobic &, const Phobic &);
[[nodiscard]]bool operator<(const Phobic &, const Phobic &);
[[nodiscard]]bool operator<=(const Phobic &, const Phobic &);
[[nodiscard]]bool operator>=(const Phobic &, const Phobic &);
[[nodiscard]]bool operator>(const Phobic &, const Phobic &);
[[nodiscard]]bool operator!=(const Phobic &, const Phobic &);
#endif /* PHOBIC_H_INCLUDED */
