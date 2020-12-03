#pragma once
#include "ArraySequence.hpp"
#include "LinkedListSequence.hpp"
#include "ArraySequence.hpp"
#include "SortSequence.hpp"
#include <cassert>
#include <iostream>

void SSTestGetSize() {
    std::cout << "TEST: SORT SEQUENCE:" << std::endl;

    {
        int arr[5] = { 1,0,2,3,-1 };
        ArraySequence<int> test(arr, 5);
        Sequence<int>* seq1 = &test;
        SortSequence<int>* seq = new SortSequence<int>(Bubble, seq1, cmp);
        assert(5 == seq->GetSize());
        std::cout << "GET SIZE: 1 TEST: DONE!" << std::endl;
    }
    {
        int arr[10] = { 1,0,2,3,-1,1,44,6,32,1 };
        ArraySequence<int> test(arr, 10);
        Sequence<int>* seq1 = &test;
        SortSequence<int>* seq = new SortSequence<int>(Bubble, seq1, cmp);
        assert(10 == seq->GetSize());
        std::cout << "GET SIZE: 2 TEST: DONE!" << std::endl;
    }
    {
        int arr[5] = { 1,0,2,3,-1 };
        ListSequence<int> test(arr, 5);
        Sequence<int>* seq1 = &test;
        SortSequence<int>* seq = new SortSequence<int>(Bubble, seq1, cmp);
        //Sequence<int>* seq1 = new ListSequence<int>(arr, 5);
        assert(5 == seq->GetSize());
        std::cout << "GET SIZE: 3 TEST: DONE!" << std::endl;
    }
    {
        int arr[10] = { 1,0,2,3,-1,1,44,6,32,1 };
        ListSequence<int> test(arr, 10);
        Sequence<int>* seq1 = &test;
        SortSequence<int>* seq = new SortSequence<int>(Bubble, seq1, cmp);
        //Sequence<int>* seq1 = new ListSequence<int>(arr, 5);
        assert(10 == seq->GetSize());
        std::cout << "GET SIZE: 4 TEST: DONE!" << std::endl;
    }
    {
        ArraySequence<int> test(50);
        Sequence<int>* seq1 = &test;
        SortSequence<int>* seq = new SortSequence<int>(Bubble, seq1, cmp);
        //Sequence<int>* seq1 = new ListSequence<int>(arr, 5);
        assert(50 == seq->GetSize());
        std::cout << "GET SIZE: 5 TEST: DONE!" << std::endl;
    }
    std::cout << std::endl;
}

void SSTestGet() {
    {
        int arr[5] = { 1,0,2,3,-1 };
        ArraySequence<int> testing(arr, 5);
        Sequence<int>* seq1 = &testing;
        SortSequence<int>* seq = new SortSequence<int>(Bubble, seq1, cmp);
        //Sequence<int>* seq1 = new ListSequence<int>(arr, 5);
        assert(0 == seq->Get(1));
        assert(-1 == seq->Get(0));
        assert(1 == seq->Get(2));
        std::cout << "GET: 1 TEST: DONE!" << std::endl;
    }
    {
        int arr[5] = { 8899,-97665,0,998,-345 };
        ArraySequence<int> testing(arr, 5);
        Sequence<int>* seq1 = &testing;
        SortSequence<int>* seq2 = new SortSequence<int>(Bubble, seq1, cmp);
        //Sequence<int>* seq3 = new ListSequence<int>(arr, 5);
        assert(998 == seq2->Get(3));
        assert(8899 == seq2->Get(4));
        assert(-345 == seq2->Get(1));
        std::cout << "GET: 2 TEST: DONE!" << std::endl;
    }
    {
        int arr[5] = { 1,0,2,3,-1 };
        ListSequence<int> testing(arr, 5);
        Sequence<int>* seq1 = &testing;
        SortSequence<int>* seq4 = new SortSequence<int>(Bubble, seq1, cmp);
        //Sequence<int>* seq5 = new ListSequence<int>(arr, 5);
        assert(3 == seq4->Get(4));
        assert(2 == seq4->Get(3));
        assert(1 == seq4->Get(2));
        std::cout << "GET: 3 TEST: DONE!" << std::endl;
    }
    {
        int arr[5] = { 8899,-97665,0,998,-345 };
        ListSequence<int> testing(arr, 5);
        Sequence<int>* seq1 = &testing;
        SortSequence<int>* seq6 = new SortSequence<int>(Bubble, seq1, cmp);
        //Sequence<int>* seq3 = new ListSequence<int>(arr, 5);
        assert(0 == seq6->Get(2));
        assert(-97665 == seq6->Get(0));
        assert(-345 == seq6->Get(1));
        std::cout << "GET: 4 TEST: DONE!" << std::endl;
    }
    std::cout << std::endl;
}

void SSTestAdd() {
    {
        int arr[5] = { 1,0,2,3,-1 };
        ArraySequence<int> testing(arr, 5);
        Sequence<int>* seq1 = &testing;
        SortSequence<int>* seq = new SortSequence<int>(Bubble, seq1, cmp);
        seq->Add(18);
        seq->Add(12);
       // cout <<" "<< seq->Get(0) << " " << seq->Get(1) << " " << seq->Get(2) << " " << seq->Get(3) << " " << seq->Get(4) << " " << seq->Get(5) << " " << seq->Get(6) << " ";
        assert(12 == seq->Get(5));
        assert(18 == seq->Get(6));
        std::cout << "SET: 1 TEST: DONE!" << std::endl;
        std::cout << "SET: 2 TEST: DONE!" << std::endl;
    }
    {
        int arr[5] = { 8899,-97665,0,998,-345 };
        ArraySequence<int> testing(arr, 5);
        Sequence<int>* seq1 = &testing;
        SortSequence<int>* seq2 = new SortSequence<int>(Bubble, seq1, cmp);
        seq2->Add(-100000);
        assert(-100000 == seq2->Get(0));
        std::cout << "SET: 3 TEST: DONE!" << std::endl;
    }
    {
        int arr[5] = { 1,0,4,5,-1 };
        ListSequence<int> testing(arr, 5);
        Sequence<int>* seq1 = &testing;
        SortSequence<int>* seq4 = new SortSequence<int>(Bubble, seq1, cmp);
        seq4->Add(2);
        assert(2 == seq4->Get(3));
        seq4->Add(3);
        assert(3 == seq4->Get(4));
        std::cout << "SET: 4 TEST: DONE!" << std::endl;
        std::cout << "SET: 5 TEST: DONE!" << std::endl;
    }
    {
        int arr[5] = { 8899,-97665,0,998,-345 };
        ListSequence<int> testing(arr, 5);
        Sequence<int>* seq1 = &testing;
        SortSequence<int>* seq6 = new SortSequence<int>(Bubble, seq1, cmp);
        seq6->Add(1);
        assert(1 == seq6->Get(3));
        std::cout << "SET: 6 TEST: DONE!" << std::endl;
    }
    cout << std::endl;
}

