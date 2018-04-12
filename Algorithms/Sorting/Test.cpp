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

std::vector<std::vector<int>> Test::getTestSet() {
    // Initialize with special cases
    std::vector<std::vector<int>> testSet{{}, {0}, {0, 0, 0, 0, 0, 0, 0}, {0, 1, 2, 3, 4, 5, 6}, {6, 5, 4, 3, 2, 1, 0}};
    
    for (int i = 0; i < 50; ++i) {
        testSet.push_back(generateRandomVector());
    }
    
    return testSet;
}
