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
    const std::vector<std::vector<int>> testSet = Test::getTestSet();
    for (int i = 0; i < testSet.size(); ++i) {
        std::vector<int> expected = testSet[i];
        std::sort(expected.begin(), expected.end());
        std::vector<int> result = testSet[i];
        mergeSort(result, 0, (int)result.size()-1);
        if (!Test::isSorted(result)) {
            std::cout << "Merge Sort failed:\n";
            std::cout << "Original: ";
            Test::printVector(testSet[i]);
            std::cout << "Expected: ";
            Test::printVector(expected);
            std::cout << "Result: ";
            Test::printVector(result);
            std::cout << std::endl;
            exit(1);
        }
    }
    std::cout << "Merge Sort successful\n";
    
    return 0;
}
