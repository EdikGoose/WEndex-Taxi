//
// Created by super on 11.04.2021.
//

#ifndef WENDEX_TAXI_BUSINESSCAR_H
#define WENDEX_TAXI_BUSINESSCAR_H


#include "Car.h"
#include "ComfortPlusCar.h"

class BusinessCar: public ComfortPlusCar {
    CarType getType() override;
    void parkRightInFrontOfTheEntrance();
};


#endif //WENDEX_TAXI_BUSINESSCAR_H
