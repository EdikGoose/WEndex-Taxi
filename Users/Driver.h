//
// Created by super on 10.04.2021.
//

#ifndef WENDEX_TAXI_DRIVER_H
#define WENDEX_TAXI_DRIVER_H


#include "User.h"
#include "../Cars/Car.h"
#include "../SystemClasses/DriverGateway.h"

class Driver: public User {
    friend class DriverGateway;
private:
    Car* car;
    Driver(const string &name, const string &phoneNumber, const string &password);
public:

    bool isReady(Date startDate);

    void pinCar(Car* car);


    Car *getCar() const;

};


#endif //WENDEX_TAXI_DRIVER_H
