#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char *argv[]) {
	fstream fs;
	fs.open(argv[1]);
	if (!fs) {
		cerr << argv[0] << ": can't open " << argv[1] << '\n';
		return 1;
	}
	for (string line; getline(fs, line); ) {
		for (size_t pos = 0; (pos=line.find("Trump", pos)) != line.npos; ){
			int fsPos = fs.tellg();
			int stringPos = pos;
			line.replace(pos, 5, "Biden");
			int newPos = (fsPos - line.length()) + (stringPos - 1);
			fs.seekp(newPos);
			fs << "Biden";
			fs.seekp(fsPos);
			
		}
	}
	return 0;
}

// Note that line.npos ≡ string::npos.
// It’s a static constant, part of the string class.
// It’s a number that means “Sorry, I couldn’t find that.”
