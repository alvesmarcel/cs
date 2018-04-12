#include <iostream>
#include <vector>
#include "../Test.hpp"

int partition(std::vector<int> &v, int left, int right) {
    int pivotValue = v[right];
    int j = left - 1;
    for (int i = left; i < right; ++i) {
        if (v[i] <= pivotValue) {
            ++j;
            std::swap(v[i], v[j]);
        }
    }
    std::swap(v[j+1], v[right]);
    return j+1;
}

void quicksort(std::vector<int> &v, int left, int right) {
    if (left < right) {
        int pivotPos = partition(v, left, right);
        quicksort(v, left, pivotPos-1);
        quicksort(v, pivotPos+1, right);
    }
}

int main(int argc, const char * argv[]) {
    
    for (int i = 0; i < 10; i++) {
        std::vector<int> v = Test::generateRandomVector();
        std::vector<int> original = v;
        std::vector<int> expected = v;
        std::sort(expected.begin(), expected.end());
        quicksort(v, 0, (int)v.size()-1);
        if (!Test::isSorted(v)) {
            std::cout << "Quicksort failed:\n";
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
        quicksort(specialCases[i], 0, (int)specialCases[i].size()-1);
        std::vector<int> original = specialCases[i];
        std::vector<int> expected = specialCases[i];
        std::sort(expected.begin(), expected.end());
        if (!Test::isSorted(specialCases[i])) {
            std::cout << "Quicksort failed:\n";
            std::cout << "Original: ";
            Test::printVector(original);
            std::cout << "Expected: ";
            Test::printVector(expected);
            std::cout << "Result: ";
            Test::printVector(specialCases[i]);
            std::cout << std::endl;
        }
    }
    
    std::cout << "Quicksort successful\n";
    
    return 0;
}
