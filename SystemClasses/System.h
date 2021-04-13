//
// Created by super on 11.04.2021.
//

#ifndef WENDEX_TAXI_SYSTEM_H
#define WENDEX_TAXI_SYSTEM_H

#include <iostream>
#include "../Users/Passenger.h"
#include "PassengerGateway.h"
#include "DriverGateway.h"
#include "../Cars/EconomyCar.h"
#include "CarGateway.h"


using namespace std;

class System {
private:
    static inline list<Order> listOfAllOrders = {};

public:
    static Passenger* registerPassenger(const string& name, const string& phoneNumber, const string& password);

    static Driver* registerDriver(const string &name, const string &phoneNumber, const string &password);

    static Car* registerCar(const string& model, const string& color, const string& number, CarType carType);

    static Order* preOrder(const Location &startLocation, const Location &endLocation, Passenger *passenger, CarType carType);

    static const list<Order> &getListOfAllOrders();

private:
    static Order* makeOrder(const Date &startDate, const Date &endTime, const Location &startLocation, const Location &endLocation,
                             Passenger *passenger,  Driver *driver, int cost, int distance);

};




#endif //WENDEX_TAXI_SYSTEM_H
