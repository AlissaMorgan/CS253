#include <iostream>

// Note that there is NO public: section in Foo.

class Foo {
  public:
    void *operator new(std::size_t);
    static void operator delete(void *, std::size_t);
	char zot[4000];
};

using namespace std;

int main() {
    Foo bar;
    //Foo *p;
    Foo *p = new 1;
    cout << "done\n";
    return 0;
}
