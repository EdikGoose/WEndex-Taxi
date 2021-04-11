//
// Created by super on 11.04.2021.
//

#ifndef WENDEX_TAXI_BUSINESSCAR_H
#define WENDEX_TAXI_BUSINESSCAR_H


#include "Car.h"

class BusinessCar: public  Car {
    CarType getType() override;

};


#endif //WENDEX_TAXI_BUSINESSCAR_H
