#ifndef EXERCISE10_TESTCLASS_H
#define EXERCISE10_TESTCLASS_H

#include <ostream>

class TestClass {
private:
    int value;
public:
    explicit TestClass(int value) : value(value) {};
    TestClass();
    friend std::ostream &operator<<(std::ostream &os, const TestClass &object);
    bool operator<(const TestClass &rhs) const;
    bool operator>(const TestClass &rhs) const;
};


#endif
