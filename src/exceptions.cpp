#include "exceptions.hpp"

#include <iostream>

using namespace umbrella;

Exception::Exception(int err) : errCode(err) { }

void Exception::print() const {
    printf("[%02x] ERR\n", errCode);
}
