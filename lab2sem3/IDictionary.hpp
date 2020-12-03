#pragma once
#include "BinTree.hpp"
#include "pair.hpp"
#include <stdexcept>
using namespace std;

const auto out_of_range_ = "not_found";

template<class TKey, class TElement>
class IDictionary {
private:
	BinaryTree<pair_<TKey, TElement>>* tree = nullptr;
	int (*cmp)(pair_<TKey, TElement>, pair_<TKey, TElement>);
public:
	IDictionary(TKey key, TElement element,
		int (*cmp)(pair_<TKey, TElement>, pair_<TKey, TElement>)) {
		this->tree = new BinaryTree<pair_<TKey, TElement>>(cmp);
		pair_<TKey, TElement> tmp{ key, element };
		this->tree->insert(tmp);
		this->cmp = cmp;
	}

	IDictionary(int (*cmp)(pair_<TKey, TElement>, pair_<TKey, TElement>)) {
		this->tree = new BinaryTree< pair_<TKey, TElement>>(cmp);
		this->cmp = cmp;
	}
	int GetCount() {
		return tree->GetSize();
	}
	TElement Get(TKey key){
		pair_<TKey, TElement> key_;
		key_.priority = key;
		//auto node = this->tree->search(key_);
		if (tree->search(key_)) return this->tree->what_in_node(this->tree->search(key_)).item;
		//else return nullptr;
		else throw std::out_of_range(out_of_range_);
	}

	bool ContainsKey(TKey key){
		pair_<TKey, TElement> key_;
		key_.priority = key;
		if (this->tree == nullptr) return false;
		else {
			auto node = this->tree->search(key_);
			if (node != nullptr) return true;
			else return false;
		}
		/*auto node = tree->(key_);
		if (node != nullptr) return 1;
		else return 0;*/
	}
	void Add(TKey key, TElement element){
		pair_<TKey, TElement> key_;
		key_.priority = key;
		//auto node = this->tree->search(key_);
		if (ContainsKey(key)) this->tree->delete_(key_);
		key_.item = element;
		//if (this->tree != nullptr) 
		this->tree->insert(key_);
		//else this->tree = new BinaryTree<pair_<TKey, TElement>>(key_);
	}
	void Remove(TKey key) {
		pair_<TKey, TElement> key_;
		key_.priority = key;
		if (ContainsKey(key)) this->tree->delete_(key_);
		else throw out_of_range(out_of_range_);
	}
	/*void Print() {
		ArraySequence<pair_<TKey, TElement>>* arr = tree->LKP();
		for (int i = 0; i < arr->GetSize(); i++)
			cout << (*arr)[i] << endl;
		delete arr;
	}*/
	~IDictionary() {
		delete this->tree;
	}
};
