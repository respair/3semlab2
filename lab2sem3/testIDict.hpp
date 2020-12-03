#pragma once
#include "LinkedListSequence.hpp"
#include "ArraySequence.hpp"
#include "Sequence.hpp"
#include "IDictionary.hpp"
#include <cassert>
#include <iostream>

void testIDICTAdd(){	
	std::cout << "IDICTIONARY: SORT SEQUENCE:" << std::endl;
	{
		IDictionary<string, int>* map = new IDictionary<string, int>(cmp);
		string x[20] = { "1","2","3","4","5","6","7","8","9","10","11","12","13","14","15","16","17","18","19","20" };
		for (int i = 0; i < 20; i++)	
			map->Add(x[i], i);
		for (int i = 0; i < 20; i++)
			assert(map->Get(x[i]) == i);
		std::cout << "ADD: 1 TEST: DONE!" << std::endl;
	}
	{
		IDictionary<string, int>* map = new IDictionary<string, int>(cmp);
		string x[20] = { "1","2","3","4","5","6","7","8","9","10","11","12","13","14","15","16","17","18","19","20" };
		for (int i = 0; i < 20; i++)
			map->Add(x[i], -i);
		for (int i = 0; i < 20; i++)
			assert(map->Get(x[i]) == -i);
		std::cout << "ADD: 2 TEST: DONE!" << std::endl;
	}
	{
		IDictionary<string, int>* map = new IDictionary<string, int>(cmp);
		string x[1] = {"1"};
		for (int i = 0; i < 1; i++)
			map->Add(x[i], i);
		for (int i = 0; i < 1; i++)
			assert(map->Get(x[i]) == i);
		std::cout << "ADD: 3 TEST: DONE!" << std::endl;
	}
	{
		IDictionary<string, int>* map = new IDictionary<string, int>(cmp);
		string x[20] = { "1","2","3","4","5","6","7","8","9","10","11","12","13","14","15","16","17","18","19","20" };
		for (int i = 0; i < 20; i++) {
			map->Add(x[i], i + 1);
			map->Add(x[i], i);
		}
		for (int i = 0; i < 20; i++)
			assert(map->Get(x[i]) == i);
		std::cout << "ADD: 4 TEST: DONE!" << std::endl;
	}
	std::cout << std::endl;
}
void testIDICTContain() {
	{
		IDictionary<string, int>* map = new IDictionary<string, int>(cmp);
		string x[20] = { "1","2","3","4","5","6","7","8","9","10","11","12","13","14","15","16","17","18","19","20" };
		for (int i = 0; i < 20; i++)
			map->Add(x[i], i);
		for (int i = 0; i < 20; i++)
			assert(map->ContainsKey(x[i]) == true);
		std::cout << "CONTAIN: 1 TEST: DONE!" << std::endl;
	}
	{
		IDictionary<string, int>* map = new IDictionary<string, int>(cmp);
		string x[20] = { "1","2","3","4","5","6","7","8","9","10","11","12","13","14","15","16","17","18","19","20" };
		for (int i = 0; i < 20; i++)
			if(i%2==0) map->Add(x[i], i);
		for (int i = 0; i < 20; i++)
			if (i % 2 == 0) assert(map->ContainsKey(x[i]) == true);
			else assert(map->ContainsKey(x[i]) == false);
		std::cout << "CONTAIN: 2 TEST: DONE!" << std::endl;
	}
	{
		IDictionary<string, int>* map = new IDictionary<string, int>(cmp);
		assert(map->ContainsKey("1") == false);
		std::cout << "CONTAIN: 3 TEST: DONE!" << std::endl;
	}
	std::cout << std::endl;
}
void testIDICTGet() {
	{
		IDictionary<string, int>* map = new IDictionary<string, int>(cmp);
		string x[20] = { "1","2","3","4","5","6","7","8","9","10","11","12","13","14","15","16","17","18","19","20" };
		for (int i = 0; i < 20; i++)
			map->Add(x[i], i);
		for (int i = 0; i < 20; i++)
			assert(map->Get(x[i]) == i);
		std::cout << "GET: 1 TEST: DONE!" << std::endl;
	}
	{
		IDictionary<string, int>* map = new IDictionary<string, int>(cmp);
		string x[20] = { "1","2","3","4","5","6","7","8","9","10","11","12","13","14","15","16","17","18","19","20" };
		for (int i = 0; i < 20; i++)
			map->Add(x[i], -i);
		for (int i = 0; i < 20; i++)
			assert(map->Get(x[i]) == -i);
		std::cout << "GET: 2 TEST: DONE!" << std::endl;
	}
	{
		IDictionary<string, int>* map = new IDictionary<string, int>(cmp);
		string x[1] = { "1" };
		for (int i = 0; i < 1; i++)
			map->Add(x[i], i);
		for (int i = 0; i < 1; i++)
			assert(map->Get(x[i]) == i);
		std::cout << "GET: 3 TEST: DONE!" << std::endl;
	}
	{
		IDictionary<string, int>* map = new IDictionary<string, int>(cmp);
		string x[20] = { "1","2","3","4","5","6","7","8","9","10","11","12","13","14","15","16","17","18","19","20" };
		for (int i = 0; i < 20; i++) {
			map->Add(x[i], i + 1);
			map->Add(x[i], i);
		}
		for (int i = 0; i < 20; i++)
			assert(map->Get(x[i]) == i);
		std::cout << "GET: 4 TEST: DONE!" << std::endl;
	}
	std::cout << std::endl;
}
void testIDICTRemove() {
	{
		IDictionary<string, int>* map = new IDictionary<string, int>(cmp);
		string x[20] = { "1","2","3","4","5","6","7","8","9","10","11","12","13","14","15","16","17","18","19","20" };
		for (int i = 0; i < 20; i++)
			map->Add(x[i], i);
		map->Remove(x[19]);
		for (int i = 0; i < 19; i++)
			assert(map->Get(x[i]) == i);
		assert(map->ContainsKey(x[19]) == false);
		std::cout << "REMOVE: 1 TEST: DONE!" << std::endl;
	}
	{
		IDictionary<string, int>* map = new IDictionary<string, int>(cmp);
		string x[20] = { "1","2","3","4","5","6","7","8","9","10","11","12","13","14","15","16","17","18","19","20" };
		for (int i = 0; i < 20; i++)
			map->Add(x[i], -i);
		for (int i = 0; i < 20; i++) {
			if (i % 2 == 0) {
				map->Remove(x[i]);
				assert(map->ContainsKey(x[i]) == false);
			}
		}
		/*for (int i = 0; i < 20; i++)
			assert(map->ContainsKey(x[i]) == false);*/
		std::cout << "REMOVE: 2 TEST: DONE!" << std::endl;
	}
	{
		IDictionary<string, int>* map = new IDictionary<string, int>(cmp);
		string x[1] = { "1" };
		for (int i = 0; i < 1; i++)
			map->Add(x[i], i);
		map->Remove(x[0]);
		for (int i = 0; i < 1; i++)
			assert(map->ContainsKey(x[i]) == false);
		std::cout << "REMOVE: 3 TEST: DONE!" << std::endl;
	}
	{
		IDictionary<string, int>* map = new IDictionary<string, int>(cmp);
		string x[20] = { "1","2","3","4","5","6","7","8","9","10","11","12","13","14","15","16","17","18","19","20" };
		for (int i = 0; i < 20; i++)
			map->Add(x[i], -i);
		for (int i = 1; i < 9; i = i + 2) {
			map->Remove(x[i]);
			assert(map->ContainsKey(x[i]) == false);
		}
		std::cout << "REMOVE: 4 TEST: DONE!" << std::endl;
	}
	{
		IDictionary<string, int>* map = new IDictionary<string, int>(cmp);
		string x[20] = { "1","2","3","4","5","6","7","8","9","10","11","12","13","14","15","16","17","18","19","20" };
		for (int i = 0; i < 20; i++)
			map->Add(x[i], i);
		map->Remove(x[0]);
		for (int i = 1; i < 20; i++)
			assert(map->Get(x[i]) == i);
		assert(map->ContainsKey(x[0]) == false);
		std::cout << "REMOVE: 5 TEST: DONE!" << std::endl;
	}
	{
		IDictionary<string, int>* map = new IDictionary<string, int>(cmp);
		string x[20] = { "1","2","3","4","5","6","7","8","9","10","11","12","13","14","15","16","17","18","19","20" };
		for (int i = 0; i < 20; i++)
			map->Add(x[i], i);
		map->Remove(x[10]);
		for (int i = 0; i < 10; i++)
			assert(map->Get(x[i]) == i);
		for (int i = 11; i < 20; i++)
			assert(map->Get(x[i]) == i);
		assert(map->ContainsKey(x[10]) == false);
		std::cout << "REMOVE: 6 TEST: DONE!" << std::endl;
	}
	std::cout << std::endl;
}