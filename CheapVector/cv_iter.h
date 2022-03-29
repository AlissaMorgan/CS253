#include "cv4.h"

#include <algorithm>	// copy()
#include <stdexcept>	// out_of_range
#include <string>	// to_string()

class cv_iter {
  public:
    cv_iter(cv *pop, size_t i=0)
	: parent(pop), index(i) { }
    cv_iter(const cv_iter &rhs) = default;
    cv_iter &operator=(const cv_iter &rhs) = default;
    cv_iter &operator++() {
	if (!parent)
	    throw std::out_of_range("Attempt to increment iterator without parent");
	if (index==parent->size())
	    throw std::out_of_range("Attempt to increment end() iterator");
    	++index;
	return *this;
    }
    cv_iter operator++(int) {
    	const auto save = *this;
	++*this;
	return save;
    }
   int&operator*() const {
	if (!parent)
	    throw std::out_of_range("Attempt to indirect uninitialized iterator");
	if (index==parent->size())
	    throw std::out_of_range("Attempt to indirect end() iterator");
    	return (*parent)[index];
    }
    bool operator==(const cv_iter &rhs) const {
	if (!parent || !rhs.parent)
	    throw std::out_of_range("Attempt to compare uninitialized iterator");
	if (parent!=rhs.parent)
	    throw std::out_of_range("Attempt to compare iterators from different containers");
    	return index==rhs.index;
    }
    bool operator!=(const cv_iter &rhs) const { return !(*this==rhs); }
  private:
    cv *parent;	// parent vector
    size_t index;	// our subscript into the vector
};

