//
// Created by super on 11.04.2021.
//

#ifndef WENDEX_TAXI_PASSENGERGATEWAY_H
#define WENDEX_TAXI_PASSENGERGATEWAY_H


#include "../Users/Passenger.h"

class PassengerGateway {
    friend class System;
    friend class DB_Helper;

private:
    static inline list<Passenger> listOfPassengers = {};
    static Passenger* addPassenger(const string &name, const string &phoneNumber, const string &password);
    static Passenger* findByPhoneNumber(const string& phoneNumber);
    static list<Passenger> &getMutableListOfAllPassengers();
public:
    static const list<Passenger> &getListOfPassengers();

    static void addOrder(Passenger* passenger, Order* order);



    /**
     * Specific method for DB work
     * @param passenger
     * @param order
     */
    static void addOrderToPassengerById(Passenger* passenger, Order* order);
};




#endif //WENDEX_TAXI_PASSENGERGATEWAY_H
