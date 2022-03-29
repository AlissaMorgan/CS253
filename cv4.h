// This file is one of a series that illustrates CheapVector (cv),
// It’s an example of an STL-like container, including
// an iterator.  It’s not efficient, but that’s not the point.
//
// Instead of a pointer to the data, the iterator now contains
// a pointer the the parent container and an int offset.

#ifndef CV_H_INCLUDED
#define CV_H_INCLUDED

#include <algorithm>	// copy()
#include <stdexcept>	// out_of_range
#include <string>	// to_string()

// The Cheap Vector
// It’s missing many things:
//  copy ctor
//  assignment
//  assignment from initializer_list
//  cbegin()/cend()/rbegin()/rend()/…
//  empty()
//  clear()
//  value_type

class cv;		    // forward declaration

template <typename T>
class cv_iter {
  public:
    cv_iter(cv<T> *pop=nullptr, size_t i=0)
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
    int &operator*() const {
	if (!parent)
	    throw std::out_of_range("Attempt to indirect uninitialized iterator");
	//if (index==parent->size())
	    //throw std::out_of_range("Attempt to indirect end() iterator");
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
    const cv *parent;	// parent vector
    size_t index;	// our subscript into the vector
};

template <typename T>
class cv {
  public:
    typedef size_t size_type;
    typedef cv_iter iterator;

    cv() = default;
    template <typename U>
    cv(const std::initializer_list<U> &il)
	: count(il.size()), data(new T[count]) {
	std::copy_n(il.begin(), count, data);
    }
    ~cv() { delete[] data; }
    size_type size() const { return count; }
    iterator begin() { return iterator(this, 0); }
    iterator end() { return iterator(this, count); }
    int &operator[](size_type n) {
	if (n >= count)
	    throw std::out_of_range("Bad subscript " + std::to_string(n)
				    + ", size is " + std::to_string(count));
	return data[n];
    }
    void push_back(const T &datum) {
	T *new_data = new T[count+1];
	std::copy(data, data+count, new_data);
	delete[] data;
	data = new_data;
	data[count++] = datum;
    }
  private:
    size_type count = 0;
    T *data = nullptr;
};

#endif /* CV_H_INCLUDED */
