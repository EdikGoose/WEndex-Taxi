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

const list<EconomyCar> &CarGateway::getListOfEconomy() {
    return listOfEconomy;
}

const list<ComfortCar> &CarGateway::getListOfComfort() {
    return listOfComfort;
}

const list<ComfortPlusCar> &CarGateway::getListOfComfortPlus() {
    return listOfComfortPlus;
}

const list<BusinessCar> &CarGateway::getListOfBusiness() {
    return listOfBusiness;
}
