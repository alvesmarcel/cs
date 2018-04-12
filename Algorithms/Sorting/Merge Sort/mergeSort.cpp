#include <iostream>
#include <vector>
#include "../Test.hpp"

void merge(std::vector<int> &v, int left, int mid, int right) {
    //int mid = (left + right) / 2;
    int i = left;
    int j = mid + 1;
    
    std::vector<int> aux{};
    
    // Performs the usual merge
    while (i <= mid && j <= right) {
        if (v[i] < v[j]) {
            aux.push_back(v[i]);
            ++i;
        } else {
            aux.push_back(v[j]);
            ++j;
        }
    }
    
    // Insert the remaining elements in the range [left, mid] in aux vector
    while (i <= mid) {
        aux.push_back(v[i]);
        ++i;
    }
    
    // Insert the remaining elements in the range [mid+1, right] in aux vector
    while (j <= right) {
        aux.push_back(v[j]);
        ++j;
    }
    
    // Copy the elements from aux to v
    for (int i = left; i <= right; ++i) {
        v[i] = aux[i-left];
    }
}

void mergeSort(std::vector<int> &v, int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        mergeSort(v, left, mid);
        mergeSort(v, mid+1, right);
        merge(v, left, mid, right);
    }
}

int main(int argc, const char * argv[]) {
    
    for (int i = 0; i < 10; i++) {
        std::vector<int> v = Test::generateRandomVector();
        std::vector<int> original = v;
        std::vector<int> expected = v;
        std::sort(expected.begin(), expected.end());
        mergeSort(v, 0, (int)v.size()-1);
        if (!Test::isSorted(v)) {
            std::cout << "Merge Sort failed:\n";
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
        mergeSort(specialCases[i], 0, (int)specialCases[i].size()-1);
        std::vector<int> original = specialCases[i];
        std::vector<int> expected = specialCases[i];
        std::sort(expected.begin(), expected.end());
        if (!Test::isSorted(specialCases[i])) {
            std::cout << "Merge Sort failed:\n";
            std::cout << "Original: ";
            Test::printVector(original);
            std::cout << "Expected: ";
            Test::printVector(expected);
            std::cout << "Result: ";
            Test::printVector(specialCases[i]);
            std::cout << std::endl;
        }
    }
    
    std::cout << "Merge Sort successful\n";
    
    return 0;
}
