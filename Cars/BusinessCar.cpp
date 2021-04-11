//
// Created by super on 11.04.2021.
//

#include "BusinessCar.h"


CarType BusinessCar::getType() {
    return CarType::BUSINESS;
}

void BusinessCar::parkRightInFrontOfTheEntrance() {
    cout << "Car parked right in front of the entrance";
}
