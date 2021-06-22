//
// Created by super on 11.04.2021.
//

#include "Car.h"

#include <utility>

Car::Car(string model, string color, string number) : model(move(model)), color(move(color)), number(move(number)){}

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

CarType Car::stringToCarType(const string& type) {
    if(type == "ECONOMY")
        return CarType::ECONOMY;
    if(type == "COMFORT")
        return CarType::COMFORT;
    if(type == "COMFORTPLUS")
        return CarType::COMFORTPLUS;
    if(type == "BUSINESS")
        return CarType::BUSINESS;
    return CarType::ECONOMY;
}

string Car::carTypeToString(CarType carType) {
    switch (carType) {
        case CarType::ECONOMY:
            return "ECONOMY";
        case CarType::COMFORT:
            return "COMFORT";
        case CarType::COMFORTPLUS:
            return "COMFORTPLUS";
        case CarType::BUSINESS:
            return "BUSINESS";
    }
}

