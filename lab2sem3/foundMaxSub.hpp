#pragma once
#include "Sequence.hpp"
#include "IDictionary.hpp"
#include "string"
#include "iostream"
#include "pair.hpp"
#include "ArraySequence.hpp"
using namespace std;

class SearchMaxSub {
private:
    IDictionary<string, int>* map;
    int min, max;
    int max_count;
    string max_string;
public:
    SearchMaxSub(Sequence<char>* seq, int min, int max, int (*cmp)(pair_<string, int>, pair_<string, int>)) {
        this->map = new IDictionary<string, int>(cmp);
        if (min > max) {
            int t = min;
            min = max;
            max = t;
        }
        this->min = min;
        this->max = max;
        this->max_count = 0;
        this->max_string = "EMPTY! Size of sub list is 0.";
        int j;
        if (min == 0) min++;
        for (int i = 0; i < seq->GetSize(); i++) {
            for (j = min - 1; i + j < seq->GetSize() && j < max; j++) {
                Sequence<char>* sub = seq->GetSubList(i, i + j);
                 /*for (int l = 0; l < sub->GetSize(); l++) {
                    cout<< sub->Get(l)<< " ";
                }*/
                // cout << endl;
                //string sub_string = "fill";
                //sub_string.clear();
                string sub_string;

                for (int i = 0; i < sub->GetSize(); i++) {
                   sub_string.append(1, sub->Get(i));
                }
               // sub_string = sub->GetSubList(0, sub->GetSize());
                if (!this->map->ContainsKey(sub_string)) {
                    int count = 1;
                    this->map->Add(sub_string, count);
                    if (this->max_count < count) {
                        this->max_count = 1;
                        this->max_string = sub_string;
                    }
                }
                else {
                    int count = map->Get(sub_string);
                    count++;
                    this->map->Remove(sub_string);
                    this->map->Add(sub_string, count);
                    if (this->max_count < count) {
                        this->max_count = count;
                        this->max_string = sub_string;
                    }
                }
            }
        }
    }

   /* Sequence<pair<string, int>>* output_seq() {
        vector<Tpair_for_dict<string, int>>* vect = dict->LKP();
        ArraySequence<Tpair_for_dict<string, int>>* arr = new
            ArraySequence<Tpair_for_dict<string, int>>(dict->Count());
        Sequence<Tpair_for_dict<string, int>>* seq = arr;
        for (size_t i = 0; i < vect->size(); i++) {
            seq->Set(i, vect->at(i));
        }
        vect->clear();
        return seq;
    }*/

    ~SearchMaxSub() {
        delete this->map;
    }

    int Get(string sub) {
        return this->map->Get(sub);
    }

    pair_<string, int> GetMax() {
        return pair_<string, int>(this->max_string,this->max_count);
    }

    int GetMaxCount() {
        return this->max_count;
    }
    string GetMaxString() {
        return this->max_string;
    }
    /*void print() {
        this->dict->Print();
    }*/
};