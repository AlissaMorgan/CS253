#ifndef COUNTSORT_H_INCLUDED
#define COUNTSORT_H_INCLUDED

#include <iostream> 
#include <stdexcept>	// out_of_range
#include <string>	// to_string()
#include <initializer_list>

class CountSort {
    public:
	class CountSort_iter {
  	    public:
	    	CountSort_iter(const CountSort* pop, size_t i=0)
		: parent(pop), index(i) { }
		CountSort_iter(const CountSort_iter &rhs) = default;
		CountSort_iter &operator=(const CountSort_iter &rhs) = default;
		CountSort_iter &operator++(){
			if (!parent){
			    throw std::out_of_range("Increment w/out reference to parent");
			}if (index >= (*parent).size()){ //parent->size()
			    throw std::out_of_range("can't increment iterator past end() iterator");
			}
			
			++index;
			return *this;
			}
		CountSort_iter operator++(int) {
			const auto save = *this;
			++*this;
			return save;
		}
		int operator*() const{
			if (!parent){
			    throw std::out_of_range("uninitialized iterator");
			}
			if (index>=(*parent).size()) //parent->size()
			    throw std::out_of_range("index > end() iterator");
			return (*parent)[index];
		}
		bool operator==(const CountSort_iter &rhs) const {
			if (!parent || !rhs.parent)
			    throw std::out_of_range("can't compare uninitialized iterator");
			if (parent!=rhs.parent)
			    throw std::out_of_range("can't compare iterators from different containers");
			return index==rhs.index;
		}
		bool operator!=(const CountSort_iter &rhs) const { return !(*this==rhs); }
	     private:
		const CountSort* parent;	// parent obj
		int index;	// our subscript into the vector
	};

	typedef CountSort_iter iterator;

	CountSort();
	void operator= (const std::initializer_list<int> &il){
		clear();
		for(int i: il){
			insert(i);
		}
		
	}
	CountSort(int closed, int inclusive);
	~CountSort();
	int size() const;
	//int size();
	iterator begin();
	iterator end();
	iterator begin() const;
	iterator end() const;
	int operator[](int n) const{
		//std::cout << " n(" << n << ") ";
		if (n >= count){
		    throw std::out_of_range("Given index " + std::to_string(n)
					    + " is out of range, size is " + std::to_string(count));
		}
		if (n < 0){
		    throw std::out_of_range("Given index " + std::to_string(n)
					    + " is out of range (because it is negative), size is " + std::to_string(count));
		}
		int match = 0;
		for(int i = 0; i < totalRange; i++){
			if(array[i] != 0){
				match += array[i];
				//std::cout << "match @" << i << ": " << match << "\n";
				if(n <= match - 1){
					return i + leftRange;
				}
			}
		}
		return n;
		
	}
	int operator()(int n) const{
		if(n < 0 || n >= totalRange){
			throw std::out_of_range("Value " + std::to_string(n) + " is out of range [0-" + std::to_string(totalRange - 1) + "]");
		}

		
		return array[n];
		
	}
	int min();
	int max();
	int width();
	bool empty();
	void clear();
	void insert(const int &input);
	int *array = nullptr;
	int count = 0;
	int leftRange, rightRange;
	int totalRange = 0;
};

#endif /* COUNTSORT_H_INCLUDED */
