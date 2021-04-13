//
// Created by super on 10.04.2021.
//

#include "Driver.h"

Driver::Driver(const string &name, const string &phoneNumber, const string &password, Car* car) : User(name, phoneNumber,
                                                                                             password), car(car) {}

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

    if(startDate >= lastOrder.getEndDate()){
        return true;
    }

    return false;
}

Date Driver::getEndDate() {
    if(orderHistory.empty()){
        return Date::getCurrentDate();
    }
    return orderHistory.back()->getEndDate();

}
