//
// Created by super on 10.04.2021.
//

#include "Driver.h"
#include "../DB_Helper.h"

Driver::Driver(const string &name, const string &phoneNumber, const string &password) : User(name, phoneNumber,
                                                                                             password){};

void Driver::pinCar(Car *car) {
    this->cars.push_back(car);
    DB_Helper::writeListOfDrivers();
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

const vector<Car*> &Driver::getCars() const {
    return cars;
}



string Driver::serialize(const Driver& driver) {
    string passengerStr = "/Name " + driver.getName() + "/Phone " + driver.getPhoneNumber() + "/Password " + driver.getPassword() +
                          "/Orders {";
    for(auto order: driver.getOrderHistoryId()){
        passengerStr += to_string(order);
        passengerStr += " ";
    }
    passengerStr += "}";

    passengerStr += "/";

    passengerStr += "Cars {";
    for(const auto& car: driver.getCars()){
        passengerStr += car->getNumber();
        passengerStr += " ";
    }
    passengerStr += "}";

    passengerStr += "/";

    return passengerStr;
}
