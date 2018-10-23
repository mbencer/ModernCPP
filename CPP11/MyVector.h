#pragma once
#include "stdafx.h"
#include <vector>
#include "catch.h"
#include <iostream>

namespace OldCpp
{
	class MyString : std::string
	{
	public:
		MyString(const MyString& other)
			: std::string(other)
		{
			std::cout << "MyString copy ctor begins" << std::endl;
		}

		explicit MyString(const basic_string& _Right)
			: basic_string<char>(_Right)
		{
			std::cout << "Ctor begins" << std::endl;
		}
	};

	class MyVector
	{
	private:
		std::vector<MyString> _myVector;
	public:
		void push_back(const MyString& item)
		{
			_myVector.push_back(item);
		}
	};
}

namespace ModernCpp
{
	class MyString : std::string
	{
	public:
		MyString(MyString&& other) noexcept
			: std::string(std::move(other))
		{
			std::cout << "Move constructor begins" << std::endl;
		}

		MyString(const MyString& other)
			: std::string(other)
		{
			std::cout << "MyString copy ctor begins" << std::endl;
		}

		explicit MyString(const basic_string& _Right)
			: basic_string<char>(_Right)
		{
			std::cout << "Ctor begins" << std::endl;
		}
	};

	class MyVector
	{
	private:
		std::vector<MyString> _myVector;
	public:
		void push_back(const MyString& item)
		{
			_myVector.push_back(item);
		}
		
		void push_back(MyString&& item)
		{
		_myVector.push_back(std::move(item));
		}
	};
}