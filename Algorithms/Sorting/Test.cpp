#include "Test.hpp"
#include <random>
#include <iostream>

bool Test::isSorted(const std::vector<int> &v) {
    for (int i = 1; i < v.size(); i++)
        if (v[i] < v[i-1])
            return false;
    return true;
}

std::vector<int> Test::generateRandomVector() {
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<> dis(1, 13);
    
    std::vector<int> v{};
    for (int i = 0; i < 16; ++i)
        v.push_back(dis(mt));
    
    return v;
}

void Test::printVector(const std::vector<int> &v) {
	for (int i = 0; i < v.size(); i++)
		std::cout << v[i] << " ";
	std::cout << std::endl;
}