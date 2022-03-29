#ifndef HSET_H_INCLUDED
#define HSET_H_INCLUDED

#include <list>
#include <vector>
#include <algorithm>
#include <iostream>
#include "hasher.h"
#include "hset_iter.h"

template <typename T, int N = 5, typename H = Hasher> // Exercise 1
class hset {
  private:
    static constexpr unsigned table_size=N;// Exercise 1
    std::vector<std::list<T>> table = {};
	bool isEmpty = true;	// Exercise 2

  public:
    using iterator = hset_iter<T>;
    using value_type = T;
    using size_type = size_t;

    hset() : table(table_size) { }
    hset(const hset &) = default;
    hset &operator=(const hset &) = default;
    ~hset() = default;

    void insert(const T &datum) {
	isEmpty = false;	// Exercise 2
	unsigned hashval = H()(datum) % table.size();
	auto &lr = table[hashval];
	if (find(lr.begin(), lr.end(), datum) == lr.end())
	    lr.push_back(datum);
    }

    // Walk down the hash table, adding up all the sizes.
    size_type size() const {
	size_type total = 0;
	for (const auto &row : table)
	    total += row.size();
	return total;
    }

	bool empty() const{ // Exercise 2
		return isEmpty;
	}

    iterator begin() {
	//return iterator(table, 0);
	return iterator(table, 0, 0); // Exercise 4
    }

    iterator end() {
	//return iterator(table, size());
	return iterator(table, table.size() - 1, table[table.size()-1].size()); // Exercise 4
    }

    void dump() const {
	for (unsigned i=0; i<table.size(); i++) {
	    std::cout << "table[" << i << "]";
	    for (auto v : table[i]) 
		    std::cout << ' ' << v;
	    std::cout << '\n';
	}
    }
};

#endif /* HSET_H_INCLUDED */
