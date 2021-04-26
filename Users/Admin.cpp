//
// Created by super on 25.04.2021.
//

#include "Admin.h"
#include "../SystemClasses/PassengerGateway.h"
#include "../SystemClasses/DriverGateway.h"
#include "../SystemClasses/CarGateway.h"
#include "../DB_Helper.h"



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
    if(passenger->isBlocked){
        passenger->isBlocked = false;
    }
    else {
        passenger->isBlocked = true;
    }
    DB_Helper::writeListOfPassenger();
}

void Admin::blockDriver(Driver *driver) {
    if(driver->isBlocked) {
        driver->isBlocked = false;
    }
    else{
        driver->isBlocked = true;
    }
    DB_Helper::writeListOfDrivers();
}

Passenger *Admin::findPassenger(const string& phoneNumber) {
    Passenger* passenger = PassengerGateway::findByPhoneNumber(phoneNumber);
    if(passenger == nullptr)
        throw NoSuchUserException();
    return passenger;
}

Driver *Admin::findDriver(const string& phoneNumber) {
    Driver* driver = DriverGateway::findByPhoneNumber(phoneNumber);
    if(driver == nullptr)
        throw NoSuchUserException();
    return driver;
}

const Car *Admin::findCar(const string& numberOfCar) {
    return CarGateway::findCarByNumber(numberOfCar);
}







