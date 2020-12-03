#pragma once
#include "pair.hpp"
#include "ArraySequence.hpp"
#include "Sequence.hpp"
#include "Alphabet.hpp"
#include <cassert>
#include <iostream>

void GenerateRandomText(int size, string* arr_) {
	const char* ar[] = { "a", "b", "c", "d", "e", "f", "g", "h", "j", "k", "l", "m", "n", "o", "p", "i", "u", "r", "s",
		"t", "q", "v", "f", "w", "x", "y", "z" };
	string  s = "";
	string* ss = new string[size];
	for (int j = 0; j < size; j++) {
		for (int i = 0; i < 5; i++)
			s += ar[rand() % (sizeof ar / sizeof(char*))];
		ss[j] = s;
		s = "";
	}
	cout << "The resulting text: " << endl;
	for (int i = 0; i < size; i++) {
		cout << ss[i] << " ";
		if (i % 25 == 0 && i != 0) cout << endl;
	}
	cout << endl;
	for (int i = 0; i < size; i++) arr_[i] = ss[i];
}

void testAlph() {
	std::cout << "TEST: ALPHABET:" << std::endl;
	{
		//12 p
		string arr_[43] = { "abab", "tryu", "nfj","nafln","naevnv","93238", "nedw","lkencf",";ekrfn","ew;navf","er;kn","ek;fn","spk","wefn","nf", "1", "2","3","4","5", "6","7",";8","9","10","e1k;fn","sp2k","we3fn","n4f" , "tr5yu", "n6fj","naf7ln","nae8vnv","993238", "n10edw","lken11cf",";ekr12fn","ew;13navf","e`4r;kn","ek;15fn","sp16k","w17efn","18nf" };
		ArraySequence<string> test_(arr_, 43);
		Sequence<string>* seq_ = &test_;
		Split_into_pages b(seq_, 4, cmp);
		assert(b.GetNumberPages() == 12);
		std::cout << "GET NUMBER PAGES: 1 TEST: DONE!" << std::endl;

	}
	{
		string arr_[43] = { "abab", "tryu", "nfj","nafln","naevnv","93238", "nedw","lkencf",";ekrfn","ew;navf","er;kn","ek;fn","spk","wefn","nf", "1", "2","3","4","5", "6","7",";8","9","10","e1k;fn","sp2k","we3fn","n4f" , "tr5yu", "n6fj","naf7ln","nae8vnv","993238", "n10edw","lken11cf",";ekr12fn","ew;13navf","e`4r;kn","ek;15fn","sp16k","w17efn","18nf" };
		ArraySequence<string> test_(arr_, 43);
		Sequence<string>* seq_ = &test_;
		Split_into_pages b(seq_, 6, cmp);
		assert(b.GetNumberPages() == 8);
		std::cout << "GET NUMBER PAGES: 2 TEST: DONE!" << std::endl;

	}
	{
		string arr_[43] = { "abab", "tryu", "nfj","nafln","naevnv","93238", "nedw","lkencf",";ekrfn","ew;navf","er;kn","ek;fn","spk","wefn","nf", "1", "2","3","4","5", "6","7",";8","9","10","e1k;fn","sp2k","we3fn","n4f" , "tr5yu", "n6fj","naf7ln","nae8vnv","993238", "n10edw","lken11cf",";ekr12fn","ew;13navf","e`4r;kn","ek;15fn","sp16k","w17efn","18nf" };
		ArraySequence<string> test_(arr_, 43);
		Sequence<string>* seq_ = &test_;
		Split_into_pages b(seq_, 3, cmp);
		assert(b.GetNumberPages() == 16);
		std::cout << "GET NUMBER PAGES: 3 TEST: DONE!" << std::endl;

	}
	{
		string arr_[1] = { "abab" };
		ArraySequence<string> test_(arr_, 1);
		Sequence<string>* seq_ = &test_;
		Split_into_pages b(seq_, 3, cmp);
		assert(b.GetNumberPages() == 1);
		std::cout << "GET NUMBER PAGES: 4 TEST: DONE!" << std::endl;

	}
	{
		string arr_[43] = { "abab", "tryu", "nfj","nafln","naevnv","93238", "nedw","lkencf",";ekrfn","ew;navf","er;kn","ek;fn","spk","wefn","nf", "1", "2","3","4","5", "6","7",";8","9","10","e1k;fn","sp2k","we3fn","n4f" , "tr5yu", "n6fj","naf7ln","nae8vnv","993238", "n10edw","lken11cf",";ekr12fn","ew;13navf","e`4r;kn","ek;15fn","sp16k","w17efn","18nf" };
		ArraySequence<string> test_(arr_, 43);
		Sequence<string>* seq_ = &test_;
		Split_into_pages b(seq_, 2, cmp);
		assert(b.GetNumberPages() == 23);
		std::cout << "GET NUMBER PAGES: 5 TEST: DONE!" << std::endl;

	}
	cout << std::endl;
	{
		string arr_[43] = { "abab", "tryu", "nfj","nafln","naevnv","93238", "nedw","lkencf",";ekrfn","ew;navf","er;kn","ek;fn","spk","wefn","nf", "1", "2","3","4","5", "6","7",";8","9","10","e1k;fn","sp2k","we3fn","n4f" , "tr5yu", "n6fj","naf7ln","nae8vnv","993238", "n10edw","lken11cf",";ekr12fn","ew;13navf","e`4r;kn","ek;15fn","sp16k","w17efn","18nf" };
		ArraySequence<string> test_(arr_, 43);
		Sequence<string>* seq_ = &test_;
		Split_into_pages b(seq_, 4, cmp);
		Sequence<string>* seq_1 = b.GetPage(2, seq_);
		string arr[4] = { "nfj", "nafln", "naevnv", "93238" };
		ArraySequence<string> test_1(arr, 4);
		Sequence<string>* seq_2= &test_1;
		//std::cout << seq_1->Get(3) << " " << seq_2->Get(1);
		assert(seq_1->Get(0) == seq_2->Get(0));
		assert(seq_1->Get(1) == seq_2->Get(1));
		assert(seq_1->Get(2) == seq_2->Get(2));
		assert(seq_1->Get(3) == seq_2->Get(3));
		std::cout << "GET PAGE: 1 TEST: DONE!" << std::endl;

	}
	{
		string arr_[43] = { "abab", "tryu", "nfj","nafln","naevnv","93238", "nedw","lkencf",";ekrfn","ew;navf","er;kn","ek;fn","spk","wefn","nf", "1", "2","3","4","5", "6","7",";8","9","10","e1k;fn","sp2k","we3fn","n4f" , "tr5yu", "n6fj","naf7ln","nae8vnv","993238", "n10edw","lken11cf",";ekr12fn","ew;13navf","e`4r;kn","ek;15fn","sp16k","w17efn","18nf" };
		ArraySequence<string> test_(arr_, 43);
		Sequence<string>* seq_ = &test_;
		Split_into_pages b(seq_, 4, cmp);
		Sequence<string>* seq_1 = b.GetPage(10, seq_);
		string arr[3] = { "n10edw", "lken11cf", ";ekr12fn" };
		ArraySequence<string> test_1(arr, 3);
		Sequence<string>* seq_2 = &test_1;
		//std::cout << seq_1->Get(1) << " " << seq_1->Get(2)<<" ";
		assert(seq_1->Get(0) == seq_2->Get(0));
		assert(seq_1->Get(1) == seq_2->Get(1));
		assert(seq_1->Get(2) == seq_2->Get(2));
		std::cout << "GET PAGE: 2 TEST: DONE!" << std::endl;

	}
	{
		string arr_[43] = { "abab", "tryu", "nfj","nafln","naevnv","93238", "nedw","lkencf",";ekrfn","ew;navf","er;kn","ek;fn","spk","wefn","nf", "1", "2","3","4","5", "6","7",";8","9","10","e1k;fn","sp2k","we3fn","n4f" , "tr5yu", "n6fj","naf7ln","nae8vnv","993238", "n10edw","lken11cf",";ekr12fn","ew;13navf","e`4r;kn","ek;15fn","sp16k","w17efn","18nf" };
		ArraySequence<string> test_(arr_, 43);
		Sequence<string>* seq_ = &test_;
		Split_into_pages b(seq_, 4, cmp);
		Sequence<string>* seq_1 = b.GetPage(1, seq_);
		string arr[2] = { "abab", "tryu" };
		ArraySequence<string> test_1(arr, 2);
		Sequence<string>* seq_2 = &test_1;
		assert(seq_1->Get(0) == seq_2->Get(0));
		assert(seq_1->Get(1) == seq_2->Get(1));
		std::cout << "GET PAGE: 3 TEST: DONE!" << std::endl;

	}
	{
		string arr_[1] = { "abab" };
		ArraySequence<string> test_(arr_, 1);
		Sequence<string>* seq_ = &test_;
		Split_into_pages b(seq_, 3, cmp);
		Sequence<string>* seq_1 = b.GetPage(1, seq_);
		string arr[1] = { "abab" };
		ArraySequence<string> test_1(arr, 1);
		Sequence<string>* seq_2 = &test_1;
		assert(seq_1->Get(0) == seq_2->Get(0));
		std::cout << "GET PAGE: 4 TEST: DONE!" << std::endl;

	}
	{
		string arr_[43] = { "abab", "tryu", "nfj","nafln","naevnv","93238", "nedw","lkencf",";ekrfn","ew;navf","er;kn","ek;fn","spk","wefn","nf", "1", "2","3","4","5", "6","7",";8","9","10","e1k;fn","sp2k","we3fn","n4f" , "tr5yu", "n6fj","naf7ln","nae8vnv","993238", "n10edw","lken11cf",";ekr12fn","ew;13navf","e`4r;kn","ek;15fn","sp16k","w17efn","18nf" };
		ArraySequence<string> test_(arr_, 43);
		Sequence<string>* seq_ = &test_;
		Split_into_pages b(seq_, 4, cmp);
		Sequence<string>* seq_1 = b.GetPage(7, seq_);
		string arr[4] = { ";8", "9", "10", "e1k;fn" };
		ArraySequence<string> test_1(arr, 4);
		Sequence<string>* seq_2 = &test_1;
		assert(seq_1->Get(0) == seq_2->Get(0));
		assert(seq_1->Get(1) == seq_2->Get(1));
		assert(seq_1->Get(2) == seq_2->Get(2));
		assert(seq_1->Get(3) == seq_2->Get(3));
		std::cout << "GET PAGE: 5 TEST: DONE!" << std::endl;

	}
}