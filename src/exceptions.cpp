#include "exceptions.hpp"

#include <iostream>

using namespace umbrella;

Exception::Exception(int err) : errCode(err) { }

void Exception::print() const {
    printf("[0x%02X] ERR\n", errCode);
}

SocketException::SocketException(int err) : Exception(SOCKET_EXCEPTION | err) { }

void SocketException::print() const {
    printf("[0x%02X] SOCKET ERR\n", errCode);
}
