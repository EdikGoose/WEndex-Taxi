//
// Created by super on 25.04.2021.
//

#ifndef WENDEX_TAXI_PASSENGERBLOCKEDEXCEPTION_H
#define WENDEX_TAXI_PASSENGERBLOCKEDEXCEPTION_H

#include <iostream>
#include "../Users/Passenger.h"

using namespace std;

class PassengerBlockedException: public exception{
    string error = "Passenger is blocked. (";
public:
    explicit PassengerBlockedException(Passenger* passenger) {
        error+=(passenger->getName()+" "+passenger->getPhoneNumber()+=")");
    }

    [[nodiscard]] const char *what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW override {
        return error.c_str();
    }
};


#endif //WENDEX_TAXI_PASSENGERBLOCKEDEXCEPTION_H
