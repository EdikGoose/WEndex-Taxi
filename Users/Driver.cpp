//
// Created by super on 10.04.2021.
//

#include "Driver.h"

Driver::Driver(const string &name, const string &phoneNumber, const string &password) : User(name, phoneNumber,
                                                                                             password) {}

void Driver::pinCar(Car *car) {
    this->car = car;
}

Car *Driver::getCar() const {
    return car;
}

bool Driver::isReady(Date startDate) const {
    if(orderHistory.empty()){
        return true;
    }
    Order lastOrder = *orderHistory.back();

    if(startDate > lastOrder.getStartDate()){
        return true;
    }

    return false;
}
