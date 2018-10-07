// CPP11.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <cstring>
#include <stdexcept>
#include <iostream>
#include "catch.h"

namespace CPP98
{
	class Widget
	{
		int bufferSize = 1000;
		int* _buffer;
		int _id = 0;
	public:
		Widget()
			: _buffer(new int[bufferSize])
		{
			_id = counter++;
			std::cout << "Ctor begins with id=" << _id << std::endl;
		}

		Widget(const Widget& widget)
			: _buffer(new int[bufferSize])
		{
			std::cout << "Copy ctor begins with copy object with id=" << widget._id << std::endl;
			memcpy(_buffer, widget._buffer, sizeof(int)*bufferSize);
		}

		Widget& operator=(const Widget& widget)
		{
			if (this == &widget)
				return *this;
			memcpy(_buffer, widget._buffer, sizeof(int)*bufferSize);

			return *this;
		}

		bool operator<(const Widget& other)
		{
			return _id < other._id;
		}

		~Widget()
		{
			delete[] _buffer;
		}
		static int counter;
	};
	int Widget::counter = 0;
}


TEST_CASE("Wihout move semantics")
{
	std::vector<CPP98::Widget> widgets(3);
	std::sort(std::begin(widgets), std::end(widgets));
}

