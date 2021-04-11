//
// Created by super on 11.04.2021.
//

#include "Car.h"

#include <utility>

Car::Car(string model, string color, string number) : model(move(model)), color(move(color)), number(move(number)) {}

const string &Car::getModel() const {
    return model;
}

const Location &Car::getLocation() const {
    return location;
}

const string &Car::getColor() const {
    return color;
}

const string &Car::getNumber() const {
    return number;
}

void Car::setLocation(const Location &location) {
    Car::location = location;
}
