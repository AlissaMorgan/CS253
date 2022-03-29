#ifndef HSET_ITER_H_INCLUDED
#define HSET_ITER_H_INCLUDED

#include <list>
#include <vector>
#include <iterator>	// for advance()

// Each hset_iter contains a reference to its associated hash,
// and an int indicating progress within the hash.

template <typename T>
class hset_iter {
  private:
    using table_t = typename std::vector<std::list<T>>;
    const table_t &parent;  // reference to the hash table we’re iterating over
    //int num;		    // how far along we are.  0=first item
	//const std::vector<std::list<T>> & vIter;
	//const std::list<T> & lIter;
	unsigned int vector_index;
	unsigned int list_index;

  public:
    //hset_iter(table_t &table, int n) : parent(table), num(n) { }
    //hset_iter(std::vector<std::list<T>> & vector_index, std::list<T> & list_index) : vIter(vector_index), lIter(list_index){}
    hset_iter(table_t &table, int vIndex, int lIndex) : parent(table), vector_index(vIndex), list_index(lIndex){}

    bool operator==(const hset_iter &rhs) const {
	if((vector_index == rhs.vector_index) && (list_index == rhs.list_index)){
	return true;
	}
	return false;
    }

    bool operator!=(const hset_iter &rhs) const {
	return !(*this == rhs);
    }

    // Return a pointer to the num'th element,
    // where num==0 is the first element.

    T operator*() const {
	/*unsigned int remaining = num;
	int i;
	// First, find the right list:
	for (i=0; parent[i].size() <= remaining; i++)
	    remaining -= parent[i].size();

	// Second, find the right slot within that list:*/
	auto it = parent[vector_index].begin();
	advance(it, list_index);  // go forward that many steps
	return *it;

    }

    // Pre-increment
    void operator++() {
	if(parent[vector_index].size() - 1 == list_index){
		if(parent.size() - 1 != vector_index){
		++vector_index;
		list_index = 0;
		}else{++list_index;}
	}else if(parent[vector_index].size() == 0){
		++vector_index;
	}else{
		++list_index;
	}
	
    }
};

#endif /* HSET_ITER_H_INCLUDED */
