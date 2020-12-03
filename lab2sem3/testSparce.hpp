#pragma once
#include "Sparce.hpp"
#include <cassert>
#include <iostream>



void testSparce() {
	std::cout << "TEST: SPARCE VECTOR:" << std::endl;
	{
		int* arr = new int[10000];
		int* arr_ = new int[20];
		int j = 0;
		for (int i = 0; i < 10000; i++)
			if (i % 500 == 0) {
				arr[i] = rand() % 1000;
				arr_[j] = arr[i];
				j++;
			}
			else arr[i] = 0;
		Sparce<int> test(arr, 10000, cmp);
		int* arr1 = test.GetSparceVector();
		for (int i = 0; i < 20; i++) {
			assert(arr_[i] == arr1[i]);
		}
		std::cout << "GET SPARCE VECTOR: 1 TEST: DONE!" << std::endl;
	}
	{
		int* arr = new int[20000];
		int* arr_ = new int[40];
		int j = 0;
		for (int i = 0; i < 20000; i++)
			if (i % 500 == 0) {
				arr[i] = rand() % 1000;
				arr_[j] = arr[i];
				j++;
			}
			else arr[i] = 0;
		Sparce<int> test(arr, 20000, cmp);
		int* arr1 = test.GetSparceVector();
		for (int i = 0; i < 40; i++) {
			assert(arr_[i] == arr1[i]);
		}
		std::cout << "GET SPARCE VECTOR: 2 TEST: DONE!" << std::endl;
	}
	{
		int* arr = new int[20000];
		for (int i = 0; i < 20000; i++)
			if (i % 500 == 0) {
				arr[i] = rand() % 1000;
			}
			else arr[i] = 0;
		Sparce<int> test(arr, 20000, cmp);
		int* arr1 = test.GetVector();
		for (int i = 0; i < 20000; i++) {
			assert(arr[i] == arr1[i]);
		}
		std::cout << "GET VECTOR: 1 TEST: DONE!" << std::endl;
	}
	{
		int* arr = new int[10000];
		for (int i = 0; i < 10000; i++)
			if (i % 500 == 0) {
				arr[i] = rand() % 1000;
			}
			else arr[i] = 0;
		Sparce<int> test(arr, 10000, cmp);
		int* arr1 = test.GetVector();
		for (int i = 0; i < 10000; i++) {
			assert(arr[i] == arr1[i]);
		}
		std::cout << "GET VECTOR: 2 TEST: DONE!" << std::endl;
	}
	{
		int* arr = new int[10000];
		for (int i = 0; i < 10000; i++)
			if (i % 500 == 0) {
				arr[i] = rand() % 1000;
			}
			else arr[i] = 0;
		Sparce<int> test(arr, 10000, cmp);
		assert(20 == test.GetSparceSize());
		std::cout << "GET SPARCE SIZE: 1 TEST: DONE!" << std::endl;
	}
	{
		int* arr = new int[20000];
		for (int i = 0; i < 20000; i++)
			if (i % 500 == 0) {
				arr[i] = rand() % 1000;
			}
			else arr[i] = 0;
		Sparce<int> test(arr, 20000, cmp);
		assert(40 == test.GetSparceSize());
		std::cout << "GET SPARCE SIZE: 2 TEST: DONE!" << std::endl;
	}
	{
		int* arr = new int[20000];
		for (int i = 0; i < 20000; i++)
			if (i % 1000 == 0) {
				arr[i] = rand() % 1000;
			}
			else arr[i] = 0;
		Sparce<int> test(arr, 20000, cmp);
		assert(20 == test.GetSparceSize());
		std::cout << "GET SPARCE SIZE: 3 TEST: DONE!" << std::endl;
	}
	{
		int* arr = new int[20000];
		for (int i = 0; i < 20000; i++)
			if (i % 2000 == 0) {
				arr[i] = rand() % 1000;
			}
			else arr[i] = 0;
		Sparce<int> test(arr, 20000, cmp);
		assert(10 == test.GetSparceSize());
		std::cout << "GET SPARCE SIZE: 4 TEST: DONE!" << std::endl;
	}
	std::cout << std::endl;
}