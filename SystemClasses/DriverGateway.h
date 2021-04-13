//
// Created by super on 11.04.2021.
//

#ifndef WENDEX_TAXI_DRIVERGATEWAY_H
#define WENDEX_TAXI_DRIVERGATEWAY_H


#include "../Users/Driver.h"

class DriverGateway {
    friend class System;
private:
    static inline list<Driver> listOfDrivers = {};
    static Driver* addDriver(const string &name, const string &phoneNumber, const string &password);

public:
    static const list<Driver> &getListOfAllDrivers();
    static void addOrder(Driver* driver, Order* order);
};


#endif //WENDEX_TAXI_DRIVERGATEWAY_H
