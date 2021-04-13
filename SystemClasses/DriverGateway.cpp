//
// Created by super on 11.04.2021.
//

#include "DriverGateway.h"

Driver* DriverGateway::addDriver(const string &name, const string &phoneNumber, const string &password) {
    Driver driver(name, phoneNumber, password);
    DriverGateway::listOfDrivers.push_back(driver);
    return &listOfDrivers.back();
}

const list<Driver> &DriverGateway::getListOfAllDrivers() {
    return listOfDrivers;
}

void DriverGateway::addOrder(Driver *driver, Order *order) {
    driver->addOrder(order);
}
