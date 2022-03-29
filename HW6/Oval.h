#ifndef OVAL_H_INCLUDED
#define OVAL_H_INCLUDED

#include <functional>
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

template <typename T, int N = 1, typename U = std::equal_to<T>>
class Oval{
	T type;
	U compare;
	int promote = N;
	std::vector<T> data = {};
    public:
	Oval(){
	}
	Oval(const Oval &rhs){
		data = rhs.data;
	}
	template <typename C>
	Oval(C incluStart, C end){
		for (auto it = incluStart; it != end; ++it){
			data.push_back(*it);
		}
	}
	~Oval(){clear();}
	size_t size() const {return data.size();}
	int find(const T& t){
		int i = 0;
		for(auto it = data.begin(); it != data.end(); ++it){
			if(compare(data.at(i), t)){
				if(i == 0){
					return 0;
				}
				for(int p = i; p > i - promote; p--){
					if(p == 0){return i - promote;}
					std::swap(data.at(p - 1), data.at(p));
				}
				return i - promote;
			}
			i++;
		}
		return -1;
	}
	size_t count(const T& t) const {
		size_t ret = 0;
		for(auto element: data){
			if(compare(element, t)){ret++;}
		}
		return ret;}
	void push_back(const T& value){data.push_back(value);}
	size_t erase(const T& t){
		auto counter = 0;
		for(auto it = data.begin(); it != data.end(); ++it){
			if(compare(*it, t)){
				if(it == (--data.end())){
					data.pop_back();
					counter++;
					return counter;
				}else{
					data.erase(it);
				}
				counter++;
			}
		}
		return counter;
	}
	void clear(){data = {};}
	T& operator[](size_t t){return data.at(t);}
	const T& operator[](size_t t) const{return data.at(t);}
    private:
    	


};

#endif /* OVAL_H_INCLUDED */
