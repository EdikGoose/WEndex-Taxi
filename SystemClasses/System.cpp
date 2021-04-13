//
// Created by super on 11.04.2021.
//

#include "System.h"
#include "DriverGateway.h"
#include "CarGateway.h"
#include "../Output.h"
#include "../Cars/EconomyCar.h"
#include "../Cars/ComfortCar.h"
#include "../Cars/ComfortPlusCar.h"
#include "../Cars/BusinessCar.h"


Passenger* System::registerPassenger(const string &name, const string &phoneNumber, const string &password) {
    return PassengerGateway::addPassenger(name,phoneNumber,password);
}

Driver* System::registerDriver(const string &name, const string &phoneNumber, const string &password) {
    return DriverGateway::addDriver(name,phoneNumber,password);
}

Car* System::registerCar(const string& model, const string& color, const string& number, CarType carType) {
    return CarGateway::addCar(model,color,number,carType);
}

const list<Order> &System::getListOfAllOrders() {
    return listOfAllOrders;
}


Order* System::preOrder(const Location &startLocation, const Location &endLocation, Passenger *passenger, CarType carType) {
    for(Driver driver: DriverGateway::getListOfAllDrivers()){
        if(driver.getCar()->getType() == carType && driver.isReady(Date::getCurrentDate())){
            int distance = Location::getDistance(startLocation, endLocation)*100; // in km (scale of map is 1:100)
            int duration = distance / 70; // average speed of car is 70 km/h
            Date startDate = Date::getCurrentDate();
            Date endDate = startDate+duration;

            int cost = distance*driver.getCar()->getRate();

            Output::printCondition(cost,duration);
            string answer = "yes";
            //cin >> answer;
            if(answer == "yes"){
                return makeOrder(startDate,endDate,startLocation,endLocation,passenger,&driver,cost,distance);
            }

        }
    }

}

Order* System::makeOrder(const Date &startDate, const Date &endDate, const Location &startLocation,
                         const Location &endLocation, Passenger *passenger, Driver *driver, int cost,
                         int distance) {
    Order order(startDate,endDate,startLocation,endLocation,passenger,driver,cost,distance);
    listOfAllOrders.push_back(order);

    PassengerGateway::addOrder(passenger,&listOfAllOrders.back());
    DriverGateway::addOrder(driver,&listOfAllOrders.back());


    if(driver->getCar()->getType() > CarType::ECONOMY){
        //dynamic_cast<ComfortCar*>(driver->getCar())->decreaseBottles();
    }

    return &listOfAllOrders.back();
}


