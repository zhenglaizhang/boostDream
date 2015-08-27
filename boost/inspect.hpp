#pragma once
#include <iostream>

template <typename Container>
void print(const Container& c)
{
	std::cout << "( ";
	for (auto& e : c)
	{
		std::cout << e << ", ";
	}
	std::cout << ")";
}