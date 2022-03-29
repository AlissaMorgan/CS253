#ifndef DIRECTORY_H_INCLUDED
#define DIRECTORY_H_INCLUDED

#include <dirent.h>
#include <string>

// Normally, I’d have DirectoryIterator be a nested class, Directory::iterator,
// to avoid namespace pollution.  However, this is easier to read.

class DirectoryIterator {
  public:
	DirectoryIterator() = default;
	DirectoryIterator(DIR *);
	DirectoryIterator(DIR *, std::string word); // Fix 3
	DirectoryIterator &operator++();
	std::string operator*() const;
	bool operator!=(const DirectoryIterator &) const;
	std::string word = "";
  private:
	std::string wanted(std::string filename); // Fix #2
	DIR *dp = nullptr;
	std::string name;
	
};

class Directory {
  public:
    typedef DirectoryIterator iterator;
    Directory() = delete;		// not really necessary
    Directory(const char dirname[], std::string optional = ""); // Fix 3
    ~Directory();
    iterator begin() const;
    iterator end() const;
	std::string phrase = "";
  private:
    	DIR *dp;			// null if open failed
};

#endif /* DIRECTORY_H_INCLUDED */
