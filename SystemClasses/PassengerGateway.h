//
// Created by super on 11.04.2021.
//

#ifndef WENDEX_TAXI_PASSENGERGATEWAY_H
#define WENDEX_TAXI_PASSENGERGATEWAY_H


#include "../Users/Passenger.h"

class PassengerGateway {
    friend class System;

private:
    static inline list<Passenger> listOfPassengers = {};
    static Passenger* addPassenger(const string &name, const string &phoneNumber, const string &password);

public:
    static const list<Passenger> &getListOfAllPassengers();

    static void addOrder(Passenger* passenger, Order* order);

};



#endif //WENDEX_TAXI_PASSENGERGATEWAY_H
