#include "Directory.h"
#include <iostream>

using namespace std;

// The directory iterator pre-fetches the name.  That is, readdir()
// is called when you first create the iterator, and upon ++.
//
// An end() iterator is designated by a null pointer for its DIR *.
// When readdir() fails, we set our pointer to null.

DirectoryIterator::DirectoryIterator(DIR *dp_arg) : dp(dp_arg) {
    ++*this;				// get that first entry
}
DirectoryIterator::DirectoryIterator(DIR *dp_arg, string phrase) : dp(dp_arg){ // Fix 3
	word = phrase;
    ++*this;				// get that first entry
}

// Get the next entry in the directory (that we like) and
// put it in the member variable name.

DirectoryIterator &DirectoryIterator::operator++() {	// pre-increment
    while (auto p = readdir(dp)) {	// Read a directory entry.
	name = p->d_name;		// C-string ⇒ C++ string
	if((wanted(name) == "want")){
		return *this;
	}
    }
    dp = nullptr;			// readdir failed; don’t try again.
    return *this;
}

string DirectoryIterator::operator*() const {
    return name;			// Fetched in a previous ++.
}

bool DirectoryIterator::operator!=(const DirectoryIterator &rhs) const {
    return dp != rhs.dp;
}

string DirectoryIterator::wanted(string name){ //Fix #2
	if (name == ".")		// Stupid entry for current directory?
	    return "";			// Nobody wants that.
	if (name == "..")		// Stupid entry for parent directory?
	    return "";			// Nobody wants that.
	if(!(name.find(word) != string::npos)){
		return "";
	}
	return "want";			// Everything else, I like!
}


//////////////// Directory methods

Directory::Directory(const char dirname[], string optional){
	try{
		if(opendir(dirname)){// Fix #1
			dp = opendir(dirname);
			phrase = optional; // Fix 3
		}else{
			throw runtime_error("no directory found"); // Fix #1
		}
	}catch(const runtime_error &e){ // Fix #1
		cerr << "runtime_error: directory " << dirname << " not found.\n";
		abort();
	}
}

Directory::~Directory() {
    if (dp)				// Only if opendir() succeeded:
	closedir(dp);			//   should we close it.
}

Directory::iterator Directory::begin() const {
	if(phrase != ""){return iterator(dp, phrase);} // Fix 3
    return iterator(dp);
}

Directory::iterator Directory::end() const {
    return iterator();
}
