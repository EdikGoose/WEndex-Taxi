//
// Created by super on 13.04.2021.
//

#ifndef WENDEX_TAXI_DB_HELPER_H
#define WENDEX_TAXI_DB_HELPER_H

#include <iostream>
#include "Users/User.h"
#include "Users/Passenger.h"
#include "SystemClasses/PassengerGateway.h"
#include "SystemClasses/DriverGateway.h"
#include "Cars/EconomyCar.h"
#include "SystemClasses/CarGateway.h"
#include <fstream>
#include <vector>
#include <bits/stdc++.h>

class DB_Helper {
public:
    // min1 hour1 day1 month1 year1  min2 hour2 day2 month2 year2  coordX coordY coordX coordY phonePassenger phoneDriver
    static list<Order> readListOfOrders();
    static void writeListOfOrders();


    // name phone password numberOfCar
    // IDorder1 IDorder2 IDorder3 ...
    static void readListOfDrivers();
    static void writeListOfDrivers();


    // name phone password
    // IDorder1 IDorder2 IDorder3 ...
    static void readListOfPassenger();
    static void writeListOfPassenger();

    static void readListOfAdmins();
    static void writeListOfAdmins();


    //  number model color type
    static void readListOfCars();
    static void writeListOfCars();




    static vector<string> divideIntoWords(const string& line);

    static vector<int> divideIntoNumbers(const string &line);
};


#endif //WENDEX_TAXI_DB_HELPER_H
