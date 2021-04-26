//
// Created by super on 25.04.2021.
//

#ifndef WENDEX_TAXI_PASSENGERBLOCKEDEXCEPTION_H
#define WENDEX_TAXI_PASSENGERBLOCKEDEXCEPTION_H

#include <iostream>
#include "../Users/Passenger.h"

using namespace std;

class PassengerBlockedException: public exception{
    string exceptionMessage = "Sorry, but you are blocked by admin. (";
public:
    explicit PassengerBlockedException(Passenger* passenger) {
        exceptionMessage+=(passenger->getName() + " " + passenger->getPhoneNumber()+=")")+"\n";
    }

    [[nodiscard]] const char *what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW override {
        return exceptionMessage.c_str();
    }
};


#endif //WENDEX_TAXI_PASSENGERBLOCKEDEXCEPTION_H
