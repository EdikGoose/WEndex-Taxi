//
// Created by super on 11.04.2021.
//

#ifndef WENDEX_TAXI_CAR_H
#define WENDEX_TAXI_CAR_H

#include <iostream>
#include "../Location.h"
#include "CarType.h"
#include <cstdlib>
#include <ctime>

using namespace std;

/**
 * Abstract class with pure virtual method getType()
 */
class Car {
protected:
    string model;
    Location location;
    string color;
    string number; // number looks like : a065ac

public:
    virtual CarType getType() = 0;

    Car(string model, string color, string number);

    void setLocation(const Location &location);

    [[nodiscard]] const string &getModel() const;

    [[nodiscard]] const Location &getLocation() const;

    [[nodiscard]] const string &getColor() const;

    [[nodiscard]] const string &getNumber() const;


};


#endif //WENDEX_TAXI_CAR_H
