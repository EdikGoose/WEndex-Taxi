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
#include "../DB_Helper.h"

using namespace std;

class System {
private:
    static inline list<Order> listOfAllOrders = DB_Helper::readListOfOrders(); // read date from DB

public:
    static Passenger* registerPassenger(const string& name, const string& phoneNumber, const string& password);

    static Driver* registerDriver(const string &name, const string &phoneNumber, const string &password);

    static Car* registerCar(const string& model, const string& color, const string& number, CarType carType);

    static Order* preOrder(const Location &startLocation, const Location &endLocation, Passenger *passenger, CarType carType);

    static const list<Order> &getListOfAllOrders();

    static const Order* findOrderById(int id);

private:
    static Order* makeOrder(const Date &startDate, const Date &endTime, const Location &startLocation, const Location &endLocation,
                             Passenger *passenger,  Driver *driver, Car* car, int cost, int distance);

};




#endif //WENDEX_TAXI_SYSTEM_H
