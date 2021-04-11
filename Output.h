//
// Created by super on 11.04.2021.
//

#ifndef WENDEX_TAXI_OUTPUT_H
#define WENDEX_TAXI_OUTPUT_H


#include "Date.h"
#include "OrderClasses/Order.h"
#include "Users/User.h"


/**
 * Class for output info about instances through the console
 */
class Output {
public:
    static void printInfoAboutDate(const Date& date);

    static void printInfoAboutOrder(const Order& order);

    static void printInfoAboutUser(User* user);

    static void printInfoAboutLocation(const Location& location);
};


#endif //WENDEX_TAXI_OUTPUT_H
