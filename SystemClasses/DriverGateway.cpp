//
// Created by super on 11.04.2021.
//

#include "DriverGateway.h"
#include "../DB_Helper.h"

Driver* DriverGateway::addDriver(const string &name, const string &phoneNumber, const string &password) {
    Driver driver(name, phoneNumber, password);
    DriverGateway::listOfDrivers.push_back(driver);
    return &listOfDrivers.back();
}

list<Driver> &DriverGateway::getListOfAllDrivers() {
    return listOfDrivers;
}

void DriverGateway::addOrder(Driver *driver, Order *order) {
    driver->addOrder(order);
    driver->addIdOfOrder(order->getId());
    DB_Helper::writeListOfDrivers();
}

Driver *DriverGateway::findByPhoneNumber(const string& phoneNumber) {
    for(Driver& driver: getListOfAllDrivers()){
        if(driver.getPhoneNumber() == phoneNumber)
            return &driver;
    }
    return nullptr;
}

void DriverGateway::addOrderToDriverById(Driver *driver, Order *order) {
    for(int idOfOrder: driver->getOrderHistoryId()){
        if(idOfOrder == order->getId()){
            driver->addOrder(order);
        }
    }
}