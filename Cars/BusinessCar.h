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
    friend class CarGateway;
protected:
    BusinessCar();

public:
    BusinessCar(const string &model, const string &color, const string &number);

private:
    int getRate() override;
};


#endif //WENDEX_TAXI_BUSINESSCAR_H
