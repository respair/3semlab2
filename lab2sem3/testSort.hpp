#pragma once
#include "LinkedListSequence.hpp"
#include "ArraySequence.hpp"
#include "Sequence.hpp"
#include "Sort.hpp"
#include <cassert>
#include <iostream>

template <class T>
void test(Sequence<int>* (*s)(Sequence<T>* seqq, int (*cmp)(T a, T b))) {
    std::cout << "TEST: SORT:" << std::endl;
    {
        int arr[5] = { 1,0,2,3,-1 };
        int arr1[5] = { -1,0,1,2,3 };
        ListSequence<int> test(arr, 5);
        Sequence<int>* seq = &test;
        Sequence<int>* seq2 = s(seq, cmp);
        int arr2[5] = { seq2->Get(0) ,seq2->Get(1) ,seq2->Get(2),
        seq2->Get(3), seq2->Get(4) };
        assert(arr1[0] == arr2[0]);
        assert(arr1[1] == arr2[1]);
        assert(arr1[2] == arr2[2]);
        assert(arr1[3] == arr2[3]);
        assert(arr1[4] == arr2[4]);
        std::cout << "1 TEST: DONE!" << std::endl;
    }
    {
        int arr[1] = { 1 };
        int arr1[1] = { 1 };
        ListSequence<int> test(arr, 1);
        Sequence<int>* seq = &test;
        Sequence<int>* seq2 = s(seq, cmp);
        int arr2[1] = { seq2->Get(0) };
        assert(arr1[0] == arr2[0]);
        std::cout << "2 TEST: DONE!" << std::endl;
    }
    {
        int arr[7] = { -1,-3,-6,-2,-4,-1,-9 };
        int arr1[7] = { -9,-6,-4,-3,-2,-1,-1 };
        ListSequence<int> test(arr, 7);
        Sequence<int>* seq = &test;
        Sequence<int>* seq2 = s(seq, cmp);
        int arr2[7] = { seq2->Get(0) ,seq2->Get(1) ,seq2->Get(2),
        seq2->Get(3), seq2->Get(4),seq2->Get(5),seq2->Get(6) };
        assert(arr1[0] == arr2[0]);
        assert(arr1[1] == arr2[1]);
        assert(arr1[2] == arr2[2]);
        assert(arr1[3] == arr2[3]);
        assert(arr1[4] == arr2[4]);
        assert(arr1[5] == arr2[5]);
        assert(arr1[6] == arr2[6]);
        std::cout << "3 TEST: DONE!" << std::endl;
    }
    {
        int arr[7] = { 1,3,6,2,4,1,9 };
        int arr1[7] = { 1,1,2,3,4,6,9 };
        ListSequence<int> test(arr, 7);
        Sequence<int>* seq = &test;
        Sequence<int>* seq2 = s(seq, cmp);
        int arr2[7] = { seq2->Get(0) ,seq2->Get(1) ,seq2->Get(2),
        seq2->Get(3), seq2->Get(4), seq2->Get(5),seq2->Get(6) };
        assert(arr1[0] == arr2[0]);
        assert(arr1[1] == arr2[1]);
        assert(arr1[2] == arr2[2]);
        assert(arr1[3] == arr2[3]);
        assert(arr1[4] == arr2[4]);
        assert(arr1[5] == arr2[5]);
        assert(arr1[6] == arr2[6]);
        std::cout << "4 TEST: DONE!" << std::endl;
    }
    {
        int arr[4] = { 0,0,0,0 };
        int arr1[4] = { 0,0,0,0 };
        ListSequence<int> test(arr, 4);
        Sequence<int>* seq = &test;
        Sequence<int>* seq2 = s(seq, cmp);
        int arr2[4] = { seq2->Get(0) ,seq2->Get(1) ,seq2->Get(2), seq2->Get(3) };
        assert(arr1[0] == arr2[0]);
        assert(arr1[1] == arr2[1]);
        assert(arr1[2] == arr2[2]);
        assert(arr1[3] == arr2[3]);
        std::cout << "5 TEST: DONE!" << std::endl;
    }
    {
        int arr[10] = { 0,1,2,3,4,5,6,7,8,9 };
        int arr1[10] = { 0,1,2,3,4,5,6,7,8,9 };
        ListSequence<int> test(arr, 10);
        Sequence<int>* seq = &test;
        Sequence<int>* seq2 = s(seq, cmp);
        int arr2[10] = { seq2->Get(0) ,seq2->Get(1) ,seq2->Get(2),
        seq2->Get(3), seq2->Get(4), seq2->Get(5),seq2->Get(6),
        seq2->Get(7),seq2->Get(8),seq2->Get(9) };
        assert(arr1[0] == arr2[0]);
        assert(arr1[1] == arr2[1]);
        assert(arr1[2] == arr2[2]);
        assert(arr1[3] == arr2[3]);
        assert(arr1[4] == arr2[4]);
        assert(arr1[5] == arr2[5]);
        assert(arr1[6] == arr2[6]);
        assert(arr1[7] == arr2[7]);
        assert(arr1[8] == arr2[8]);
        assert(arr1[9] == arr2[9]);
        std::cout << "6 TEST: DONE!" << std::endl;
    }
    {
        int arr[5] = { 1,0,2,3,-1 };
        int arr1[5] = { -1,0,1,2,3 };
        ArraySequence<int> test(arr, 5);
        Sequence<int>* seq = &test;
        Sequence<int>* seq2 = s(seq, cmp);
        int arr2[5] = { seq2->Get(0) ,seq2->Get(1) ,seq2->Get(2),
        seq2->Get(3), seq2->Get(4) };
        assert(arr1[0] == arr2[0]);
        assert(arr1[1] == arr2[1]);
        assert(arr1[2] == arr2[2]);
        assert(arr1[3] == arr2[3]);
        assert(arr1[4] == arr2[4]);
        std::cout << "7 TEST: DONE!" << std::endl;
    }
    {
        int arr[1] = { 1 };
        int arr1[1] = { 1 };
        ArraySequence<int> test(arr, 1);
        Sequence<int>* seq = &test;
        Sequence<int>* seq2 = s(seq, cmp);
        int arr2[1] = { seq2->Get(0) };
        assert(arr1[0] == arr2[0]);
        std::cout << "8 TEST: DONE!" << std::endl;
    }
    {
        int arr[5] = { -1,0,-2,-3,-1 };
        int arr1[5] = { -3,-2,-1,-1,0 };
        ArraySequence<int> test(arr, 5);
        Sequence<int>* seq = &test;
        Sequence<int>* seq2 = s(seq, cmp);
        int arr2[5] = { seq2->Get(0) ,seq2->Get(1) ,seq2->Get(2),
        seq2->Get(3), seq2->Get(4) };
        assert(arr1[0] == arr2[0]);
        assert(arr1[1] == arr2[1]);
        assert(arr1[2] == arr2[2]);
        assert(arr1[3] == arr2[3]);
        assert(arr1[4] == arr2[4]);
        std::cout << "9 TEST: DONE!" << std::endl;
    }
    {
        int arr[5] = { 0,0,0,0,0 };
        int arr1[5] = { 0,0,0,0,0 };
        ArraySequence<int> test(arr, 5);
        Sequence<int>* seq = &test;
        Sequence<int>* seq2 = s(seq, cmp);
        int arr2[5] = { seq2->Get(0) ,seq2->Get(1) ,seq2->Get(2),
        seq2->Get(3), seq2->Get(4) };
        assert(arr1[0] == arr2[0]);
        assert(arr1[1] == arr2[1]);
        assert(arr1[2] == arr2[2]);
        assert(arr1[3] == arr2[3]);
        assert(arr1[4] == arr2[4]);
        std::cout << "10 TEST: DONE!" << std::endl;
    }
    cout << std::endl;
}

template <class T>
void testUser(Sequence<int>* (*s)(Sequence<T>* seqq, int (*cmp)(T a, T b)), Sequence <T>* seq) {
    Sequence<int>* seq2 = s(seq, cmp);
    for (int i = 0; i < seq2->GetSize(); i++)
    {
        if (i % 25 == 0) cout << endl;
        cout << seq2->Get(i) << " ";
    }
}


