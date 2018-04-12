#include <iostream>
#include <vector>
#include "Test.hpp"

void insertionSort(std::vector<int> &v) {
    for (int i = 1; i < v.size(); i++) {
        int value = v[i];
        int j = i - 1;
        while (j >= 0 && v[j] > value) {
            v[j+1] = v[j];
            j--;
        }
        v[j+1] = value;
    }
}

int main(int argc, const char * argv[]) {
    
    for (int i = 0; i < 10; i++) {
        std::vector<int> v = Test::generateRandomVector();
        std::vector<int> original = v;
        std::vector<int> expected = v;
        std::sort(expected.begin(), expected.end());
        insertionSort(v);
        if (!Test::isSorted(v)) {
            std::cout << "Insertion Sort failed:\n";
            std::cout << "Original: ";
            Test::printVector(original);
            std::cout << "Expected: ";
            Test::printVector(expected);
            std::cout << "Result: ";
            Test::printVector(v);
            std::cout << std::endl;
        }
    }
    
    std::vector<std::vector<int>> specialCases = {{}, {0}, {0, 0, 0, 0, 0, 0, 0}, {0, 1, 2, 3, 4, 5, 6}, {6, 5, 4, 3, 2, 1, 0}};
    for (int i = 0; i < specialCases.size(); i++) {
        insertionSort(specialCases[i]);
        std::vector<int> original = specialCases[i];
        std::vector<int> expected = specialCases[i];
        std::sort(expected.begin(), expected.end());
        if (!Test::isSorted(specialCases[i])) {
            std::cout << "Insertion Sort failed:\n";
            std::cout << "Original: ";
            Test::printVector(original);
            std::cout << "Expected: ";
            Test::printVector(expected);
            std::cout << "Result: ";
            Test::printVector(specialCases[i]);
            std::cout << std::endl;
        }
    }
    
    std::cout << "Insertion Sort successful\n";
    
    return 0;
}