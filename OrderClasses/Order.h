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
class Car;

class Order {
private:
    Date startDate;
    Date endDate;

    Location startLocation;
    Location endLocation;


    const Passenger* passenger;
    const Driver* driver;
    const Car* car;


    int cost;
    int distance; // km
    static inline int commonId = 0; // to track number of order
    int id = -1;
public:
    Order(const Date &startDate, const Date &endDate, const Location &startLocation, const Location &endLocation,
          Passenger *passenger, const Driver *driver, const Car* car, int cost, int distance);


    const Date &getStartDate() const;

    const Date &getEndDate() const;

    const Location &getStartLocation() const;

    const Location &getEndLocation() const;

    const Passenger *getPassenger() const;

    const Driver *getDriver() const;

    int getCost() const;

    int getDistance() const;

    int getId() const;

    const Car *getCar() const;

    void setId(int id);

    static void setCommonId(int commonId);
};


#endif //WENDEX_TAXI_ORDER_H
