//
// Created by super on 26.04.2021.
//

#ifndef WENDEX_TAXI_INCORRECTLOGINEXCEPTION_H
#define WENDEX_TAXI_INCORRECTLOGINEXCEPTION_H

#include <iostream>
#include <exception>

using namespace std;

class IncorrectLoginException: public exception{
    string exceptionMessage = "The phone number or password is incorrect\n";
public:
    IncorrectLoginException() = default;

    const char *what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW override {
        return exceptionMessage.c_str();
    }
};


#endif //WENDEX_TAXI_INCORRECTLOGINEXCEPTION_H
