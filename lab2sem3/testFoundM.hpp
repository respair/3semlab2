#pragma once
#include "pair.hpp"
#include "ArraySequence.hpp"
#include "Sequence.hpp"
#include "foundMaxSub.hpp"
#include <cassert>
#include <iostream>

void GenerateRandomString(int size, char* arr_) {
	const char* ar[] = { "a", "b", "c", "d", "e", "f", "g", "h", "j", "k", "l", "m", "n", "o", "p", "i", "u", "r", "s",
		"t", "q", "v", "f", "w", "x", "y", "z" };
		string  s = "";
		for (int i = 0; i < size; i++) s += ar[rand() % (sizeof ar / sizeof(char*))];
		cout << "The resulting string: " << s << endl;
		for (int i = 0; i < size; i++) arr_[i] = s[i];
}

void TestFound() {
	std::cout << "TEST: FOUND MAX SUB:" << std::endl;
	{
		char arr[15] = "ababrtyuabrthj";
		ArraySequence<char> test(arr, 15);
		Sequence<char>* seq = &test;
		int min = 2;
		int max = 7;
		SearchMaxSub a(seq, min, max, cmp);
		assert(a.GetMaxString() == "ab");
		std::cout << "GET MAX SUB STRING: 1 TEST: DONE!" << std::endl;
	}
	{
		char arr[15] = "ababrtyuabrthj";
		ArraySequence<char> test(arr, 15);
		Sequence<char>* seq = &test;
		int min = 0;
		int max = 0;
		SearchMaxSub a(seq, min, max, cmp);
		assert(a.GetMaxString() == "EMPTY! Size of sub list is 0.");
		std::cout << "GET MAX SUB STRING: 2 TEST: DONE!" << std::endl;
	}
	{
		char arr[15] = "ababrtyuabrthj";
		ArraySequence<char> test(arr, 15);
		Sequence<char>* seq = &test;
		int min = 7;
		int max = 2;
		SearchMaxSub a(seq, min, max, cmp);
		assert(a.GetMaxString() == "ab");
		std::cout << "GET MAX SUB STRING: 3 TEST: DONE!" << std::endl;
	}
	{
		char arr[1] = { 'a' };
		ArraySequence<char> test(arr, 1);
		Sequence<char>* seq = &test;
		int min = 0;
		int max = 1;
		SearchMaxSub a(seq, min, max, cmp);
		assert(a.GetMaxString() == "a");
		std::cout << "GET MAX SUB STRING: 4 TEST: DONE!" << std::endl;
	}
	cout << std::endl;
	{
		char arr[15] = "ababrtyuabrthj";
		ArraySequence<char> test(arr, 15);
		Sequence<char>* seq = &test;
		int min = 2;
		int max = 7;
		SearchMaxSub a(seq, min, max, cmp);
	//	std::cout << a.GetMaxCount() << " ";
		assert(a.GetMaxCount() == 3);
		std::cout << "GET MAX SUB SIZE: 1 TEST: DONE!" << std::endl;
	}
	{
		char arr[15] = "ababrtyuabrthj";
		ArraySequence<char> test(arr, 15);
		Sequence<char>* seq = &test;
		int min = 0;
		int max = 0;
		SearchMaxSub a(seq, min, max, cmp);
		assert(a.GetMaxCount() == 0);
		std::cout << "GET MAX SUB SIZE: 2 TEST: DONE!" << std::endl;
	}
	{
		char arr[15] = "ababrtyuabrthj";
		ArraySequence<char> test(arr, 15);
		Sequence<char>* seq = &test;
		int min = 7;
		int max = 2;
		SearchMaxSub a(seq, min, max, cmp);
		assert(a.GetMaxCount() == 3);
		std::cout << "GET MAX SUB SIZE: 3 TEST: DONE!" << std::endl;
	}
	{
		char arr[1] = { 'a' };
		ArraySequence<char> test(arr, 1);
		Sequence<char>* seq = &test;
		int min = 0;
		int max = 1;
		SearchMaxSub a(seq, min, max, cmp);
		assert(a.GetMaxCount() == 1);
		std::cout << "GET MAX SUB SIZE: 4 TEST: DONE!" << std::endl;
	}
	cout << std::endl;
	{
		char arr[15] = "ababrtyuabrthj";
		ArraySequence<char> test(arr, 15);
		Sequence<char>* seq = &test;
		int min = 2;
		int max = 7;
		SearchMaxSub a(seq, min, max, cmp);
		auto t = pair_<string, int>("ab", 2);
		assert(a.GetMax() == t);
		std::cout << "GET MAX: 1 TEST: DONE!" << std::endl;
	}
	{
		char arr[15] = "ababrtyuabrthj";
		ArraySequence<char> test(arr, 15);
		Sequence<char>* seq = &test;
		int min = 0;
		int max = 0;
		SearchMaxSub a(seq, min, max, cmp);
		auto t = pair_<string, int>("EMPTY! Size of sub list is 0.", 0);
		assert(a.GetMax() == t);
		std::cout << "GET MAX: 2 TEST: DONE!" << std::endl;
	}
	{
		char arr[15] = "ababrtyuabrthj";
		ArraySequence<char> test(arr, 15);
		Sequence<char>* seq = &test;
		int min = 7;
		int max = 2;
		SearchMaxSub a(seq, min, max, cmp);
		auto t = pair_<string, int>("ab", 2);
		assert(a.GetMax() == t);
		std::cout << "GET MAX: 3 TEST: DONE!" << std::endl;
	}
	{
		char arr[1] = { 'a' };
		ArraySequence<char> test(arr, 1);
		Sequence<char>* seq = &test;
		int min = 0;
		int max = 1;
		SearchMaxSub a(seq, min, max, cmp);
		auto t = pair_<string, int>("a", 1);
		assert(a.GetMax() == t);
		std::cout << "GET MAX: 4 TEST: DONE!" << std::endl;
	}
	cout << std::endl;
}