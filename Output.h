//
// Created by super on 11.04.2021.
//

#ifndef WENDEX_TAXI_OUTPUT_H
#define WENDEX_TAXI_OUTPUT_H


#include "Date.h"
#include "OrderClasses/Order.h"
#include "Users/User.h"
#include "Users/Driver.h"
#include "Cars/Car.h"


/**
 * Class for output info about instances through the console
 */
class Output {
public:
    static void printInfoAboutDate(const Date& date);

    static void printInfoAboutOrder(Order* order);


    static void printInfoAboutDriver(const Driver* driver);
    static void printInfoAboutPassenger(const Passenger *passenger);

    static void printInfoAboutCar(const Car* car);

    static void printInfoAboutLocation(const Location& location);

    static void printCondition(int price, int duration);

    static void printMessageAboutAbsence();

};


#endif //WENDEX_TAXI_OUTPUT_H
