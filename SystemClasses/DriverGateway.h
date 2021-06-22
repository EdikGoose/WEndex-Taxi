//
// Created by super on 11.04.2021.
//

#ifndef WENDEX_TAXI_DRIVERGATEWAY_H
#define WENDEX_TAXI_DRIVERGATEWAY_H


#include "../Users/Driver.h"

class DriverGateway {
    friend class System;
    friend class DB_Helper;
    friend class Admin;

private:
    static inline list<Driver> listOfDrivers = {};
    static Driver* addDriver(const string &name, const string &phoneNumber, const string &password);

    static list<Driver> &getMutableListOfAllDrivers();

public:

    static const list<Driver> &getListOfDrivers();

    static void addOrder(Driver* driver, Order* order);



    static Driver* findByPhoneNumber(const string& PhoneNumber);

    /**
     * Specific method for DB work
     * @param driver
     * @param order
     */
    static void addOrderToDriverById(Driver* driver, Order* order);

};


#endif //WENDEX_TAXI_DRIVERGATEWAY_H
