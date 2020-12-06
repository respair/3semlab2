#pragma once
#include "ArraySequence.hpp"
#include "iostream"
using namespace std;

template <class T>
int cmp(T a, T b) {
    if (a > b) return 1;
    else return 0;
}

template <class T>
Sequence<T>* Bubble(Sequence <T>* seq, int (*cmp)(T, T)) {
    int count = seq->GetSize();
    for (int i = 0; i < (count - 1); i++) {
        for (int j = 0; j < (count - 1 - i); j++)
            if (cmp(seq->Get(j), seq->Get(j + 1)) && j + 1 < count) {
                T temp = seq->Get(j);
                seq->Set(j, seq->Get(j + 1));
                seq->Set(j + 1, temp);
            }
    }
    return seq;
}

template <class T>
void quickSort_support(Sequence<T>* numbers, int (*cmp)(T, T), int left, int right) {
    T pivot; // ðàçðåøàþùèé ýëåìåíò
    int l_hold = left; //ëåâàÿ ãðàíèöà
    int r_hold = right; // ïðàâàÿ ãðàíèöà
    pivot = numbers->Get(left);
    while (left < right) {
        while ((numbers->Get(right) >= pivot) && cmp(right, left))
            right--;
        while ((numbers->Get(left) <= pivot) && cmp(right, left))
            left++;
        T tmp = numbers->Get(right);
        numbers->Set(right, numbers->Get(left));
        numbers->Set(left, tmp);
    }
    T tmpp = numbers->Get(left);
    numbers->Set(left, pivot);
    numbers->Set(l_hold, tmpp);
    int pivot_ = left;
    left = l_hold;
    right = r_hold;
    if (left < pivot_)
        quickSort_support(numbers, cmp, left, pivot_ - 1);
    if (right > pivot_)
        quickSort_support(numbers, cmp, pivot_ + 1, right);
}

template <class T>
Sequence <T>* quickSort(Sequence <T>* numbers, int (*cmp)(T, T)) {
    quickSort_support(numbers, cmp, 0, numbers->GetSize() - 1);
    return numbers;
}

template <class T>
Sequence <T>* Sort(Sequence <T>* arr, int (*cmp)(T, T)) {
    int count = arr->GetSize();
    for (int i = 1; i < count; i++) {
        for (int j = i; j > 0 && cmp(arr->Get(j - 1), arr->Get(j)); j--) {
            T tmp = arr->Get(j - 1);
            arr->Set(j - 1, arr->Get(j));
            arr->Set(j, tmp);
        }
    }
    return arr;
}
