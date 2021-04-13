//
// Created by super on 11.04.2021.
//

#ifndef WENDEX_TAXI_ECONOMYCAR_H
#define WENDEX_TAXI_ECONOMYCAR_H


#include "Car.h"

class EconomyCar: public Car{
    CarType getType() override;

public:
    int getRate() override;

private:
    friend class CarGateway;

protected:
    EconomyCar(const string &model, const string &color, const string &number);
};


#endif //WENDEX_TAXI_ECONOMYCAR_H
