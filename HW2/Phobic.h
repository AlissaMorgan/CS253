#include <iostream>
#include <set>

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
	Phobic add(const Phobic phob) const;
	Phobic sub(const Phobic phob) const;
	Phobic mul(const Phobic phob) const;
	Phobic div(const Phobic phob) const;
	void add_to(const Phobic phob);
	void sub_from(const Phobic phob);
	void mul_by(const Phobic phob);
	void div_by(const Phobic phob);
	bool eq(const Phobic phob) const;
	bool eq(const Phobic phob);
	bool lt(const Phobic phob) const;
	bool lt(const Phobic phob);
	void make_scary(int a);
	void make_scary(int a, int b);
	void make_scary(int a, int b, int c);
	void make_scary(int a, int b, int c, int d);
	void make_scary(int a, int b, int c, int d, int e);
	void make_scary(int a, int b, int c, int d, int e, int f);
	void make_scary(int a, int b, int c, int d, int e, int f, int g);
	void make_scary(int a, int b, int c, int d, int e, int f, int g, int h);
	void make_scary(int a, int b, int c, int d, int e, int f, int g, int h, int i);
	void make_scary(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j);
	Phobic &operator=(const Phobic &phob){
		currValue = phob.currValue;
		for (auto val : phob.scary){
			scary.insert(val);
		}
		return *this;
	}
private:
	int currValue;
	std::set<int> scary = {13};
};
