#ifndef Test_hpp
#define Test_hpp

#include <vector>

class Test {
    static std::vector<int> generateRandomVector();
    
public:
    static std::vector<std::vector<int>> getTestSet();
    static bool isSorted(const std::vector<int> &v);
    static void printVector(const std::vector<int> &v);
};

#endif
