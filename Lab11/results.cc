#include <iomanip>	// for right, setw
#include <iostream>
#include <map>
#include <string>

using namespace std;

template <typename T>
class BarGraph {
  public:
	void operator+=(const T &datum) {
		data[datum]++;
	}
	friend ostream &operator<< (ostream &out, const BarGraph<T> &b) {
		for (const auto &val : b.data){
			out << right << setw(10) << val.first << ' '
			 	<< string(val.second, '*') << '\n';
		}
		out << '\n';
		return out;
	}
  private:
    	map<T, unsigned> data;
};

template <>
class BarGraph<bool> {
    	unsigned false_count = 0, true_count = 0;
  public:
	void operator+=(bool datum) {
	datum ? true_count++ : false_count++;
	}
	friend ostream &operator<< (ostream &out, const BarGraph<bool> &b) {
        	return out << "     false " << string(b.false_count, '*') << "\n"
                	"      true " << string(b.true_count,  '*') << "\n\n";
	}
};

template <>
class BarGraph<char> {
    	int data[128] = {0};
  public:
	void operator+=(char datum) {
		int location = datum;
		data[location]++;
	}
	void operator+=(string datum) {
		for(char c : datum){
			int location = c;
			data[location]++;
		}
	}
	friend ostream &operator<< (ostream &out, const BarGraph<char> &b) {
        	for (int i = 0; i < 128; i++){
			if(b.data[i] != 0){
				char letter = i;
				out << right << setw(10) << letter << ' '
				 	<< string(b.data[i], '*') << '\n';
			}
		}
		out << '\n';
		return out;
	}
};

int main() {
	BarGraph<int> alpha;
	alpha += 12;
	alpha += 6;
	alpha += 4;
	alpha += 6;
	cout << alpha;

	BarGraph<double> beta;
	beta += 3.14;
	beta += 2.71828;
	beta += 6.023e23;
	beta += 2.71828;
	cout << beta;

	BarGraph<bool> gamma;
	gamma += false;
	gamma += true;
	gamma += false;
	gamma += true;
	gamma += true;
	cout << gamma;

	BarGraph<char> delta;
	delta += 'G';
	delta += 'e';
	delta += 'o';
	delta += "f";
	delta += 'f';
	delta += "Colorado";
	cout << delta;

	
	return 0;
}
