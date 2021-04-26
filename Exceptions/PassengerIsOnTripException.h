//
// Created by super on 26.04.2021.
//

#ifndef WENDEX_TAXI_PASSENGERISONTRIPEXCEPTION_H
#define WENDEX_TAXI_PASSENGERISONTRIPEXCEPTION_H

#include <iostream>
#include "../Users/Passenger.h"

using namespace std;


class PassengerIsOnTripException: public exception{
    string exceptionMessage;
    Passenger* passenger;
public:
    PassengerIsOnTripException(Passenger* passenger) {
        this->passenger = passenger;
        exceptionMessage = "Wait until another order is completed before placing another order.(until: "+passenger->getOrderHistory().back()->getEndDate().to_stringTime()+")\n";
    }

    const char *what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW override {
        return exceptionMessage.c_str();
    }

};


#endif //WENDEX_TAXI_PASSENGERISONTRIPEXCEPTION_H
