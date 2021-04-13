//
// Created by super on 11.04.2021.
//

#ifndef WENDEX_TAXI_CARGATEWAY_H
#define WENDEX_TAXI_CARGATEWAY_H

#include <iostream>
#include <list>
#include "../Cars/EconomyCar.h"
#include "../Cars/ComfortCar.h"
#include "../Cars/ComfortPlusCar.h"
#include "../Cars/BusinessCar.h"


using namespace std;


class CarGateway {
    friend class System;
    friend class DB_Helper;
private:
    static inline list<EconomyCar> listOfEconomy = {};
    static inline list<ComfortCar> listOfComfort = {};
    static inline list<ComfortPlusCar> listOfComfortPlus = {};
    static inline list<BusinessCar> listOfBusiness = {};

    static Car* addCar(const string& model, const string& color, const string& number, CarType carType);

public:
    static list<EconomyCar> &getListOfEconomy();

    static list<ComfortCar> &getListOfComfort();

    static list<ComfortPlusCar> &getListOfComfortPlus();

    static list<BusinessCar> &getListOfBusiness();

    static Car* findCarByNumber(const string& numberOfCar);
};


#endif //WENDEX_TAXI_CARGATEWAY_H
