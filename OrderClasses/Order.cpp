//
// Created by super on 10.04.2021.
//

#include "Order.h"

Order::Order(const Date &startDate, const Date &endDate, const Location &startLocation, const Location &endLocation,
             Passenger *passenger, Driver *driver, int cost, int distance) : startDate(startDate), endDate(endDate),
                                                                             startLocation(startLocation),
                                                                             endLocation(endLocation),
                                                                             passenger(passenger), driver(driver),
                                                                             cost(cost), distance(distance) {
    this->id = ++commonId;
};
