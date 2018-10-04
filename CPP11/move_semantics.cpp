// CPP11.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <cstring>
#include <stdexcept>
#include <iostream>
#include "catch.h"

namespace CPP98
{
	class MyString
	{
	public:
		explicit MyString(const char* initText)
		{
			std::cout << "MyString constructor begins with: " << initText << "\n";
			_data = new char[_capacity];
			const auto initSize = strlen(initText);
			Init(initText, 0, initSize);
		}

		int Size() const
		{
			return _lastElem;
		}
		char* Data() const
		{
			return _data;
		}

		~MyString()
		{
			std::cout << "MyString destructor begins with: " << _data << "\n";
			delete[] _data;
		}
		
		MyString(const MyString& myString)
		{
			std::cout << "MyString copy constructor begins with: " << myString.Data() << "\n";
			_data = new char[_capacity];
			Init(myString.Data(), 0, myString.Size());
		}

		/*
		MyString(MyString&& myString)
		: _data(myString.Data()), _lastElem(myString.Size())
		{
			std::cout << "Move constructor begins with: " << _data << "\n";
			myString._data = nullptr;
			myString._lastElem = 0;
		}*/

		void push_back(const MyString& newString)
		{
			auto newSize = Size() + newString.Size();
			Init(newString.Data(), _lastElem, newSize);
		}

	private:
		void Init(const char* text, int firstIndex, int lastIndex)
		{
			if (lastIndex >= _capacity)
				throw std::runtime_error("out of range");

			for (auto i = 0; i < lastIndex - firstIndex; ++i)
				_data[firstIndex+i] = text[i];

			_data[lastIndex] = '\0';
			_lastElem = lastIndex;
		}

		unsigned _lastElem;
		unsigned _capacity = 1000;
		char* _data;
	};
}


TEST_CASE("Wihout move semantics")
{
	using namespace CPP98;
	MyString ala("Ala");
	ala.push_back(MyString(" ma"));
	//MyString ma(" ma");
	//MyString kota(" kota");
	//ala.push_back(ma);
	//ala.push_back(kota);
	std::cout << "Output: " << ala.Data() << "\n";
	std::string x;
}

