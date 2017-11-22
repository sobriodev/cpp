#ifndef EXERCISE6_UTILS_H
#define EXERCISE6_UTILS_H

#include <cstdlib>

class Utils {

public:
    static char *allocateMemory(unsigned length);
    static void freeMemory(const char *ptr);
    static unsigned realPtrLength(const char *ptr);

};


#endif
