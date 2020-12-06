#pragma once
#include "Sort.hpp"
#include <iostream>
#include "Sequence.hpp"
using namespace std;

template<class T>
class SortSequence {
private:
    Sequence<T>* seq;
    int (*cmp)(T, T);

private:
    SortSequence(Sequence<T>* seq, int (*cmp)(T, T)) {
        this->seq = seq;
        this->cmp = cmp;
    }
public:
    SortSequence(Sequence<T>* (*sort)(Sequence<T>*, int (*cmp)(T, T)), Sequence<T>* not_sorted, int (*cmp)(T, T)) {
        seq = sort(not_sorted, cmp);
        this->cmp = cmp;
    }

    int GetSize() {
        return this->seq->GetSize();
    }

    bool GetEmpty() {
        if (!this->seq->GetSize())
            return 1;
        return 0;
    }

    T Get(int index) {
        return this->seq->Get(index);
    }

    T GetLast() {
        return this->seq->GetLast();
    }

    T GetFirst() {
        return this->seq->GetFirst();
    }

    bool beornot(T item) {
        for (int i = 0; i < this->seq->GetSize(); i++) {
            if (this->seq->Get(i) == item)
                return 1;
        }
        return 0;
    }

    int GetIndex(T item) {
        for (int i = 0; i < this->seq->GetSize(); i++) {
            if (this->seq->Get(i) == item)
                return i;
        }
        return -1;
    }
    ~SortSequence() {
        this->seq = nullptr;
    }                              // ñèêâåíñ è ëèøíèé ðàç íå ñîðòèðîâàòü åãî

    SortSequence<T>* GetSubList(int start, int end) {
        Sequence<T>* SubSeq = this->seq->GetSubList(start, end);
        SortSequence<T>* SortedSubSeq_ptr = new SortSequence<T>(SubSeq, cmp);
        return SortedSubSeq_ptr;
    }

    void Add(T item) {
        int i = 0;
        while (i < this->seq->GetSize() && item > this->seq->Get(i))
            i++;
        /*std::cout << i;
        if (i == this->seq->GetSize()) i++;
        std::cout << i;
        if (i == 0) i++;*/
        this->seq->InsertAt(item, i);                              
    }
    

    /*void print() {
        seq->print();
    }*/

};
