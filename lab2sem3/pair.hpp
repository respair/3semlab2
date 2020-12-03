#pragma once
#include <ostream>

template <class A, class T>
class pair_
{
public:
	T item;  //значение
	A priority;  //ключ
	pair_() {
	//	this->priority = "0";
		this->item = 0;
	}
	pair_(A priority, T value) {
		this->priority = priority;
		this->item = value;
	}
	pair_& operator = (const pair_& pair) {
		this->item = pair.item;
		this->priority = pair.priority;
		return *this;
	}
	bool operator == (pair_& pair) {
		//if (this->priority == pair.priority && this->item == pair.item) {
		if (this->priority == pair.priority)
			return true;
		else 
			return false;
	}
	bool operator > (pair_& pair) {
		if (this->priority > pair.priority) 
			return true;
		else 
			return false;
	}
	bool operator < (const pair_& pair) {
		if (this->priority < pair.priority) 
			return true;
		else 
			return false;
	}
	/*std::ostream& operator << (std::ostream& out) {
		out << "(" << this->priority << " - ";
		out << this->item << ")";
		return out;
	};*/
	~pair_() = default;
};

template <class A,class T>
std::ostream& operator << (std::ostream& out, pair_<A, T>& p) {
	out << "(" << p.priority << " - ";
	out << p.item << ")";
	return out;
};
