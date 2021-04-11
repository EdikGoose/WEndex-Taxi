//
// Created by super on 10.04.2021.
//

#include "Driver.h"

Driver::Driver(const string &name, const string &phoneNumber, const string &password) : User(name, phoneNumber,
                                                                                             password) {}

void Driver::pinCar(Car *car) {
    this->car = car;
}
