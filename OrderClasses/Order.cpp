//
// Created by super on 10.04.2021.
//

#include "Order.h"

Order::Order(const Date &startDate, const Date &endDate, const Location &startLocation, const Location &endLocation,
             Passenger *passenger, const Driver *driver, int cost, int distance) : startDate(startDate), endDate(endDate),
                                                                             startLocation(startLocation),
                                                                             endLocation(endLocation),
                                                                             passenger(passenger), driver(driver),
                                                                             cost(cost), distance(distance) {
    this->id = ++commonId;
}

const Date &Order::getStartDate() const {
    return startDate;
}

const Date &Order::getEndDate() const {
    return endDate;
}

const Location &Order::getStartLocation() const {
    return startLocation;
}

const Location &Order::getEndLocation() const {
    return endLocation;
}

const Passenger *Order::getPassenger() const {
    return passenger;
}

const Driver *Order::getDriver() const {
    return driver;
}

int Order::getCost() const {
    return cost;
}

int Order::getDistance() const {
    return distance;
}

int Order::getId() const {
    return id;
};
