#include "CountSort.h"
#include <iostream> 
#include <stdexcept>	// out_of_range
#include <string>	// to_string()
#include <array>
#include <initializer_list>


CountSort::CountSort() = default;

CountSort::CountSort(int closed, int inclusive) : leftRange(closed), rightRange(inclusive) {
	//std::cout << leftRange << " " << rightRange;
	if(closed > inclusive){
		throw std::invalid_argument("Given range " + std::to_string(closed) + "-" + std::to_string(inclusive) + " is out of order");
	}else{
		auto arrLen = inclusive - closed + 1;
		array = new int[arrLen];//{0};
			for(int i = 0; i < arrLen; i++){
				array[i] = 0;
			}
		//std::cout << arrLen;
		totalRange = arrLen;
	}
}

CountSort::~CountSort() { delete[] array; }

int CountSort::size() const{ return count; }

//int CountSort::size(){ return count; }

CountSort::iterator CountSort::begin() { return iterator(this, 0); }

CountSort::iterator CountSort::end() { return iterator(this, size()); }

CountSort::iterator CountSort::begin() const{ return iterator(this, 0); }

CountSort::iterator CountSort::end() const{ return iterator(this, size()); }

int CountSort::min(){return leftRange;}
	
int CountSort::max(){return rightRange;}

int CountSort::width(){return totalRange;}
	
bool CountSort::empty(){ return count == 0;}

void CountSort::clear(){
	for(int i = 0; i < totalRange; i++){
		array[i] = 0;
	}
	count = 0;
}

void CountSort::insert(const int &input) {
	if(input >= leftRange && input <= rightRange){ //checks if out of bounds
		//std::cout << input - leftRange - 1 << " ";
		array[input - leftRange] += 1;
		count++;
	}else{
		throw std::out_of_range("Value " + std::to_string(input) + " is out of range [" + std::to_string(leftRange) + "-" + std::to_string(rightRange) + "]");
	}
}
