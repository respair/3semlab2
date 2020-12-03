#pragma once
#include "Sequence.hpp"
#include "string"
#include "IDictionary.hpp"
using namespace std;

class Split_into_pages {
private:
	IDictionary<string, int>* map;
	int count_ = 0; //кол-во слов на странице
	int size_ = 0; //кол-во стр
public:
	Split_into_pages(Sequence<string>* seq, int words, int (*cmp)(pair_<string, int>, pair_<string, int>)) {
		this->map = new IDictionary<string, int>(cmp);
		this->count_ = words;
		//int size = seq->GetSize();
		int count = 1;
		int word = words;
		for (int i = 0; i < seq->GetSize(); i = i + word) {
			for (int j = i; j < i + word && j < seq->GetSize(); j++) {
				if (count == 1) { 
					if (j < words / 2) {
						if (!this->map->ContainsKey(seq->Get(j))) map->Add(seq->Get(j), count);
					}
					else {
						word = words / 2;
						break;
					}
				}
				else if (count % 10 == 0) {
					if (j < (i + 3*words / 4)) {
						if (!this->map->ContainsKey(seq->Get(j))) map->Add(seq->Get(j), count);
					}
					else {
						word = 3*words / 4;
						break;
					}
				}

				else if (!this->map->ContainsKey(seq->Get(j))) {
					map->Add(seq->Get(j), count);
					word = words;
				}
			}
			count++;
		}	    
		count--;
		this->size_ = count;
	}
	int GetNumberPages() {
		return this->size_;
	}

	Sequence<string>* GetPage(int number, Sequence<string>* seq) {
		string* arr = new string[this->count_];
		string str;
		int j = 0, i = 0;
		int c = 0;
		if (number == 1) {
			for (i; i < this->count_/2; i++) {
				for (j = c; j < seq->GetSize(); j++) {
					c++;
					if (this->map->Get(seq->Get(j)) == number) {
						str = seq->Get(j);
						break;
					}
					
				}
				arr[i] = str;
			}
		}
		else if (number % 10 == 0) {
			for (i; i < 3 * this->count_ / 4; i++) {
				for (j = c; j < seq->GetSize(); j++) {
					c++;
					if (this->map->Get(seq->Get(j)) == number) {
						str = seq->Get(j);
						break;
					}
			     	
			    }
				arr[i] = str;
			}
		}
		else
		for (i; i < this->count_; i++) {
			for (j = c; j < seq->GetSize(); j++) {
				c++;
				if (this->map->Get(seq->Get(j)) == number) {
					str = seq->Get(j);
					break;
				}
				
			}
			arr[i] = str;
		}
		Sequence<string>* seq_ = new ArraySequence<string>(arr, i);
		delete[] arr;
		return seq_;
	}
	void PrintPage(int number, Sequence<string>* seq) {
		string str;
		int j = 0;
		if (number == 1)
			for (int i = 0; i < this->count_ / 2; i++) {
				for (j; j < seq->GetSize(); j++)
					if (this->map->Get(seq->Get(j)) == number) {
						cout << seq->Get(j) << " ";
						j++;
						break;
					}
				if (i % 25 == 0 && i > 0) cout << endl;
			}
		else if (number % 10 == 0)
			for (int i = 0; i < 3*this->count_ / 4; i++) {
			for (j; j < seq->GetSize(); j++)
				if (this->map->Get(seq->Get(j)) == number) {
					cout << seq->Get(j) << " ";
					j++;
					break;
				}
			if (i % 25 == 0 && i > 0) cout << endl;
		}
		else
		for (int i = 0; i < this->count_; i++) {
			for (j; j < seq->GetSize(); j++)
				if (this->map->Get(seq->Get(j)) == number) {
					cout<<seq->Get(j)<<" ";
					j++;
					break;
				}
			if (i % 25 == 0 && i > 0) cout << endl;
		}
	}
	void PrintAllPages(Sequence<string>* seq) {
		int i = 1;
		for (i; i <= this->size_; i++) {
			PrintPage(i, seq);
			cout << endl;
		}
		/*if (seq->GetSize() % this->count_ != 0) {
			PrintPage(i, seq);
			cout << endl;
		}*/
	}
	~Split_into_pages() {
		delete map;
		this->count_ = 0;
		this->size_ = 0;
	}
};
