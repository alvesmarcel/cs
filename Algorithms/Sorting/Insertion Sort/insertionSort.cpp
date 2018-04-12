#include <iostream>
#include <vector>
#include "../Test.hpp"

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
    const std::vector<std::vector<int>> testSet = Test::getTestSet();
    for (int i = 0; i < testSet.size(); ++i) {
        std::vector<int> expected = testSet[i];
        std::sort(expected.begin(), expected.end());
        std::vector<int> result = testSet[i];
        insertionSort(result);
        if (!Test::isSorted(result)) {
            std::cout << "Insertion Sort failed:\n";
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
    std::cout << "Insertion Sort successful\n";
    
    return 0;
}
