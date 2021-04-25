//
// Created by super on 10.04.2021.
//

#ifndef WENDEX_TAXI_DRIVER_H
#define WENDEX_TAXI_DRIVER_H


#include <vector>
#include "User.h"
#include "../Cars/Car.h"
#include "../SystemClasses/DriverGateway.h"

class Driver: public User {
    friend class DriverGateway;
private:
    vector<Car*> cars = {};
    Driver(const string &name, const string &phoneNumber, const string &password);
public:


    bool isReady(Date startDate) const;

    void pinCar(Car* car);


    const vector<Car *> &getCars() const;

    Date getEndDate();

    static string serialize(const Driver& driver);

};


#endif //WENDEX_TAXI_DRIVER_H
