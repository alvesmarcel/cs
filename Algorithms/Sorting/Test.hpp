#ifndef Test_hpp
#define Test_hpp

#include <vector>

class Test {
    
public:
    static std::vector<int> generateRandomVector();
    static bool isSorted(const std::vector<int> &v);
    static void printVector(const std::vector<int> &v);
};

#endif