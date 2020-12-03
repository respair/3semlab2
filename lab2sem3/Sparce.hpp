#pragma once
#include "IDictionary.hpp"

template <class A, class T>
struct pair_2 {
    A priority = 0;
    T item = 0;
};

template <class T>
class Sparce {
private:
    IDictionary<int, T>* vec;
    int size = 0;
    int size_sparce = 0;
public:
    Sparce(T* vector, int size, int (*cmp)(pair_<int, T>, pair_<int, T>)) {
        int j = 0;
        vec = new IDictionary<int, T>(cmp);
        for (int i = 0; i < size; i++)
            if (vector[i] != 0) {
                vec->Add(i, vector[i]);
                j++;
            }
        this->size = size;
        this->size_sparce = j;
    }

    T* GetVector() {
        T* vector_ = new T[this->size];
        for (int i = 0; i < this->size; i++) {
            if (vec->ContainsKey(i))
                vector_[i] = vec->Get(i);
            else
                vector_[i] = 0;
        }
        return vector_;
    }
    T* GetSparceVector() {
        int j = 0;
        T* vector_ = new T[this->size_sparce];
        for (int i = 0; i < this->size; i++) {
            if (vec->ContainsKey(i)) {
                vector_[j] = vec->Get(i);
                j++;
            }
        }
        return vector_;
    }

    int GetSparceSize() {
        return this->size_sparce;
    }

    /*IDictionary<int, T>* GetIDictionary() {
        return this->dict;
    }*/

    /*void Print() {
        vec->Print();
    }*/
    ~Sparce() {
        this->size = 0;
        this->size_sparce = 0;
    }

};