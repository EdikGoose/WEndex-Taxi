//
// Created by super on 11.04.2021.
//

#ifndef WENDEX_TAXI_COMFORTCAR_H
#define WENDEX_TAXI_COMFORTCAR_H


#include "Car.h"

class ComfortCar: public Car {
    friend class CarGateway;
private:
    int freeBottleOfWater;

protected:
    ComfortCar(const string &model, const string &color, const string &number);

    ComfortCar();

public:
    void decreaseBottles();

    [[nodiscard]] int getFreeBottleOfWater() const;

    CarType getType() override;

    int getRate() override;
};


#endif //WENDEX_TAXI_COMFORTCAR_H
