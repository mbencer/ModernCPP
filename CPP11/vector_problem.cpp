#include "stdafx.h"
#include "catch.h"
#include "MyVector.h"
#include <driverspecs.h>

TEST_CASE("Vector without move semantics")
{
	using namespace OldCpp;
	std::cout << "Vector without move semantics" << std::endl;
	MyVector vec;
	vec.push_back(MyString("tekst"));
}

TEST_CASE("Vector with move semantics")
{
	using namespace ModernCpp;
	std::cout << "Vector with move semantics" << std::endl;
	MyVector vec;
	vec.push_back(MyString("tekst"));
}