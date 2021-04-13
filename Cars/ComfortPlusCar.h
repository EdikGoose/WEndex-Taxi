//
// Created by super on 11.04.2021.
//

#ifndef WENDEX_TAXI_COMFORTPLUSCAR_H
#define WENDEX_TAXI_COMFORTPLUSCAR_H


#include "Car.h"
#include "ComfortCar.h"

class ComfortPlusCar: ComfortCar {
    CarType getType() override;

    int getRate() override;

    friend class CarGateway;
protected:
    ComfortPlusCar(const string &model, const string &color, const string &number);
};


#endif //WENDEX_TAXI_COMFORTPLUSCAR_H
