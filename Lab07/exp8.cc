#include <cstdlib>			// for free()

int main() {
    double *p = new double[1000];
    //free(p);
	delete[] p;
    return 0;
}
