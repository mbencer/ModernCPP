// CPP11.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "catch.h"
#include "Widget.h"


TEST_CASE("Wihout move semantics")
{
	std::cout << "Wihout move semantics";
	std::vector<OldCpp::Widget> widgets(3);
	std::sort(std::begin(widgets), std::end(widgets));
}

TEST_CASE("With using move semantics")
{
	std::cout << "With using move semantics";
	std::vector<ModernCpp::Widget> widgets(3);
	std::sort(std::begin(widgets), std::end(widgets));
}

