//
// Created by super on 10.04.2021.
//

#ifndef WENDEX_TAXI_ORDER_H
#define WENDEX_TAXI_ORDER_H


#include "../Date.h"
#include "../Location.h"
//#include "../Users/Passenger.h" // infinite recursion. HELP!(

class Passenger;
class Driver;

class Order {
private:
    Date startDate;
    Date endDate;

    Location startLocation;
    Location endLocation;


    Passenger* passenger;
    Driver* driver;


    int cost;
    int distance; // km
    static inline int commonId = 0; // to track number of order
    int id;
public:
    Order(const Date &startDate, const Date &endDate, const Location &startLocation, const Location &endLocation,
          Passenger *passenger, Driver *driver, int cost, int distance);


    [[nodiscard]] const Date &getStartDate() const {
        return startDate;
    }

    [[nodiscard]] const Date &getEndTime() const {
        return endDate;
    }

    [[nodiscard]] const Location &getStartLocation() const {
        return startLocation;
    }

    [[nodiscard]] const Location &getEndLocation() const {
        return endLocation;
    }

    [[nodiscard]] Passenger *getPassenger() const {
        return passenger;
    }

    [[nodiscard]] Driver *getDriver() const {
        return driver;
    }

    [[nodiscard]] int getCost() const {
        return cost;
    }

    [[nodiscard]] int getDistance() const {
        return distance;
    }

    [[nodiscard]] int getId() const {
        return id;
    }





};


#endif //WENDEX_TAXI_ORDER_H
