//
// Created by super on 11.04.2021.
//

#include "BusinessCar.h"


CarType BusinessCar::getType() const  {
    return CarType::BUSINESS;
}

void BusinessCar::parkRightInFrontOfTheEntrance() {
    cout << "Car parked right in front of the entrance";
}



BusinessCar::BusinessCar(const string &model, const string &color, const string &number) : ComfortPlusCar(model, color,
                                                                                                          number) {}

int BusinessCar::getRate() const {
    return 50;
}
