//
// Created by super on 11.04.2021.
//

#include "CarGateway.h"

Car* CarGateway::addCar(const string& model, const string& color, const string& number, CarType carType) {
    switch (carType) {
        case CarType::ECONOMY:
            listOfEconomy.push_back(EconomyCar(model,color,number));
            return &listOfEconomy.back();
        case CarType::COMFORT:
            listOfComfort.push_back(ComfortCar(model,color,number));
            return &listOfComfort.back();
        case CarType::COMFORTPLUS:
            listOfComfortPlus.push_back(ComfortPlusCar(model,color,number));
            return &listOfComfortPlus.back();
        case CarType::BUSINESS:
            listOfBusiness.push_back(BusinessCar(model,color,number));
            return &listOfBusiness.back();
    }
}

list<EconomyCar> &CarGateway::getListOfEconomy() {
    return listOfEconomy;
}

list<ComfortCar> &CarGateway::getListOfComfort() {
    return listOfComfort;
}

list<ComfortPlusCar> &CarGateway::getListOfComfortPlus() {
    return listOfComfortPlus;
}

list<BusinessCar> &CarGateway::getListOfBusiness() {
    return listOfBusiness;
}

Car *CarGateway::findCarByNumber(const string& numberOfCar) {
    Car* refToCar = nullptr;
    for(BusinessCar& car: CarGateway::getListOfBusiness()){
        if(car.getNumber() == numberOfCar){
            refToCar = &car;
            break;
        }
    }
    for(EconomyCar& car: CarGateway::getListOfEconomy()){
        if(car.getNumber() == numberOfCar){
            refToCar = &car;
            break;
        }
    }
    for(ComfortCar& car: CarGateway::getListOfComfort()){
        if(car.getNumber() == numberOfCar){
            refToCar = &car;
            break;
        }
    }
    for(ComfortPlusCar& car: CarGateway::getListOfComfortPlus()){
        if(car.getNumber() == numberOfCar){
            refToCar = &car;
            break;
        }
    }
    return refToCar;
}
