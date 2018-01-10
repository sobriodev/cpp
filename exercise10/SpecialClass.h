#ifndef EXERCISE10_SPECIALCLASS_H
#define EXERCISE10_SPECIALCLASS_H

#include <iostream>
#include <utility>

class SpecialClass {
private:
    std::string string;
public:
    const std::string &getString() const;

public:
    explicit SpecialClass(std::string string) : string(std::move(string)) {}
    SpecialClass();
    friend std::ostream &operator<<(std::ostream &os, const SpecialClass &aClass);
};


#endif
