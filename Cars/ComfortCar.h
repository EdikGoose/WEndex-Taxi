//
// Created by super on 11.04.2021.
//

#ifndef WENDEX_TAXI_COMFORTCAR_H
#define WENDEX_TAXI_COMFORTCAR_H


#include "Car.h"

class ComfortCar: public Car {
private:
    int freeBottleOfWater;

public:
    ComfortCar(const string &model, const string &color, const string &number);

    void decreaseBottles();

    [[nodiscard]] int getFreeBottleOfWater() const;

    CarType getType() override;
};


#endif //WENDEX_TAXI_COMFORTCAR_H
