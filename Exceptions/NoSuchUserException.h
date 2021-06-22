//
// Created by super on 26.04.2021.
//

#ifndef WENDEX_TAXI_NOSUCHUSEREXCEPTION_H
#define WENDEX_TAXI_NOSUCHUSEREXCEPTION_H

#include <iostream>

using namespace std;

class NoSuchUserException: public exception{
public:
    NoSuchUserException() {}

    const char *what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW override {
        return "There is no such user";
    }

};


#endif //WENDEX_TAXI_NOSUCHUSEREXCEPTION_H
