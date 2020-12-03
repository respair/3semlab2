#include "foundMaxSub.hpp"
#include "Alphabet.hpp"
#include "LinkedListSequence.hpp"
#include "Sort.hpp"
#include "testSort.hpp"
#include "testSeq.hpp"
#include "testAlph.hpp"
#include "testIDict.hpp"
#include "testFoundM.hpp"
#include <iostream>
#include "testSortSeq.hpp"
#include "testSparce.hpp"
#include <chrono>
using namespace std;

string answ = "yes";


int main() {
	while (answ == "yes") {
		int answ_;
		cout << "Hello! What would you like to do? Choose a suitable number:" << endl;
		cout << "1) see all tests;" << endl;
		cout << "2) find the maximum substring in the string;" << endl;
		cout << "3) break the text into pages;" << endl;
		cout << "4) create a sparce vector." << endl;
		cout << "_______________________________________________" << endl;
		cin >> answ_;
		if (answ_ == 1) {
			TestGetSize();
			TestGet();
			TestSet();
			test<int>(Bubble);
			test<int>(quickSort);
			test<int>(Sort);
			SSTestGetSize();
			SSTestGet();
			SSTestAdd();
			testIDICTAdd();
			testIDICTContain();
			testIDICTGet();
			testIDICTRemove();
			TestFound();
			testAlph();
			testSparce();
		}
		else if (answ_ == 2) {
			int size;
			string answer;
			cout << "Enter the size of the sequence:" << endl;
			cin >> size;
			if (size <= 0) {
				cout << "Error!" << endl;
				exit(1);
			}
			char* arr = new char[size];
			cout << "Generate string automatically?" << endl;
			cin >> answer;
			if (answer == "yes") {
				GenerateRandomString(size,arr);
				cout << "_______________________________________________" << endl;
			}
			else {
				cout << "Enter numbers:" << endl;
				for (int i = 0; i < size; i++) {
					char el;
					cin >> el;
					arr[i] = el;
				}
			}
			Sequence<char>* seq = new ArraySequence<char>(arr, size);
			cout << "Enter the minimum and maximum lengths of the subsequences:" << endl;
			int min, max;
			cin >> min >> max;
			auto begin = std::chrono::steady_clock::now();
			SearchMaxSub testt(seq, min, max, cmp);
			auto end = std::chrono::steady_clock::now();
			auto elapsed_ms_ = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
			cout << "_______________________________________________" << endl;
			cout << "maximum length: " << testt.GetMaxCount() << endl;
			cout << "maximum subsequences: " << testt.GetMaxString() << endl;
			cout << "_______________________________________________" << endl;
			cout << "Want to know how long it took to search?" << endl;
			cin >> answ;
			if (answ == "yes") {
				cout << elapsed_ms_.count() << "ms." << endl;
				cout << "_______________________________________________" << endl;
			}
		}
		else if (answ_ == 3) {
			int size;
			string answer;
			cout << "Enter the size of the sequence:" << endl;
			cin >> size;
			if (size <= 0) {
				cout << "Error!" << endl;
				exit(1);
			}
			string* arr = new string[size];
			cout << "Generate text automatically?" << endl;
			cin >> answer;
			if (answer == "yes") {
				GenerateRandomText(size, arr);
				cout << "_______________________________________________" << endl;
			}
			else {
				cout << "Enter numbers:" << endl;
				for (int i = 0; i < size; i++) {
					string el;
					cin >> el;
					arr[i] = el;
				}
			}
			Sequence<string>* seq = new ArraySequence<string>(arr, size);
			int amount;
			cout << "How many words should there be on one completely filled page?" << endl;
			cin >> amount;
			auto begin2 = std::chrono::steady_clock::now();
			Split_into_pages ttest(seq, amount, cmp);
			auto end2 = std::chrono::steady_clock::now();
			auto elapsed_ms_2 = std::chrono::duration_cast<std::chrono::milliseconds>(end2 - begin2);
			cout << "Enter the number of the page you want to see, if you want to see all the page enter -1 :" << endl;
			cin >> amount;
			cout << "_______________________________________________" << endl;
			if (amount == -1) ttest.PrintAllPages(seq);
			else ttest.PrintPage(amount, seq);
			cout << "_______________________________________________" << endl;
			cout << "Want to know how long it took to split?" << endl;
			cin >> answ;
			if (answ == "yes") {
				cout << elapsed_ms_2.count() << "ms." << endl;
				cout << "_______________________________________________" << endl;
			}
		}
		else if (answ_ == 4) {
			string a;
			int size;
			cout << "enter the size of the sparse vector:" << endl;
			cin >> size;
			int* arr = new int[size];
			for (int i = 0; i < size; i++)
				if (i % 100 == 0) {
					arr[i] = rand() % 1000;
				}
				else arr[i] = 0;
			Sparce<int> vec(arr, size, cmp);
			cout << "Want to see a sparse vector?" << endl;
			cin >> a;
			if (a == "yes") {
				int* arr1 = vec.GetVector();
				for (int i = 0; i < size; i++) {
					cout << arr1[i] << " ";
					if (i % 25 == 0 && i != 0) cout << endl;
				}
				cout << endl;
				cout << "_______________________________________________" << endl;
			}
			cout << "Want to see the final vector?" << endl;
			cin >> a;
			if (a == "yes") {
				int* arr1 = vec.GetSparceVector();
				if (size % 100 != 0)size = size + 100;
				for (int i = 0; i < size/100; i++) {
					cout << arr1[i] << " ";
					if (i % 25 == 0 && i != 0) cout << endl;
				}
				cout << endl;
				cout << "Vector size: " << vec.GetSparceSize() << endl;
				cout << "_______________________________________________" << endl;
			}
		}
		cout << endl;
		cout << "Do you want to continue?" << endl;
		cin >> answ;
		if (answ == "yes") cout << "_______________________________________________" << endl;
	}
}