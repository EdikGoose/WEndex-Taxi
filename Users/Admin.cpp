//
// Created by super on 25.04.2021.
//

#include "Admin.h"
#include "../SystemClasses/PassengerGateway.h"
#include "../SystemClasses/DriverGateway.h"
#include "../SystemClasses/CarGateway.h"




Admin::Admin(const string &name, const string &phoneNumber, const string &password) {
    this->name = name;
    this->phoneNumber = phoneNumber;
    this->password = password;
}


string Admin::serialize(const Admin &admin) {
    string adminStr = "/Name " + admin.getName() + "/Phone " + admin.getPhoneNumber() + "/Password " + admin.getPassword() + "/";
    return adminStr;
}

const string &Admin::getName() const {
    return name;
}

const string &Admin::getPhoneNumber() const {
    return phoneNumber;
}

const string &Admin::getPassword() const {
    return password;
}

void Admin::blockPassenger(Passenger *passenger) {
    passenger->isBlocked = true;
}

void Admin::blockDriver(Driver *driver) {
    driver->isBlocked = true;
}

const Passenger *Admin::findPassenger(const string& phoneNumber) {
    return PassengerGateway::findByPhoneNumber(phoneNumber);
}

const Driver *Admin::findDriver(const string& phoneNumber) {
    return DriverGateway::findByPhoneNumber(phoneNumber);
}

const Car *Admin::findCar(const string& numberOfCar) {
    return CarGateway::findCarByNumber(numberOfCar);
}

void Admin::unblockPassenger(Passenger *passenger) {
    passenger->isBlocked = false;
}

void Admin::unblockDriver(Driver *driver) {
    driver->isBlocked = false;
}






