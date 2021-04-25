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
#include <bits/stdc++.h>


void System::registerPassenger(const string &name, const string &phoneNumber, const string &password) {
    Passenger* refToNewPassenger = PassengerGateway::addPassenger(name, phoneNumber, password);
    DB_Helper::writeListOfPassenger(); // update BD
}

void System::registerDriver(const string &name, const string &phoneNumber, const string &password) {
    Driver* refToNewDriver = DriverGateway::addDriver(name,phoneNumber,password);
    DB_Helper::writeListOfDrivers();
}

void System::registerAdmin(const string &name, const string &phoneNumber, const string &password) {
    AdminGateway::addAdmin(name,phoneNumber,password);
    DB_Helper::writeListOfAdmins();
}

Car* System::registerCar(const string& model, const string& color, const string& number, CarType carType) {
    Car* refToNewCar = CarGateway::addCar(model,color,number,carType);
    DB_Helper::writeListOfCars();
    return refToNewCar;
}

const list<Order> &System::getListOfAllOrders() {
    return listOfAllOrders;
}


Order* System::preOrder(const Location &startLocation, const Location &endLocation, Passenger *passenger, CarType carType) {
    Date startDate = Date::getCurrentDate();
    for(Driver& driver: DriverGateway::getMutableListOfAllDrivers()) {
        for(Car* car: driver.getCars()) {
            if (car->getType() == carType && driver.isReady(startDate)) {
                int distance = Location::getDistance(startLocation, endLocation) * 100; // in km (scale of map is 1:100)
                // int duration = distance / 70 ; // average speed of cars is 70 km/h
                int duration = 1; // we use constant 1 minute for easily testing. For real program I'll use the previous line
                Date endDate = startDate + duration;
                int cost = (distance * car->getRate()) / 1000;
                Output::printCondition(cost, duration);
                string answer;
                cin >> answer;

                if (answer == "Yes") {
                    return makeOrder(startDate, endDate, startLocation, endLocation, passenger, &driver, car, cost,
                                     distance);
                } else {
                    return nullptr;
                }
            }
        }
    }
    Output::printMessageAboutAbsence();
    return nullptr;

}

Order* System::makeOrder(const Date &startDate, const Date &endDate, const Location &startLocation,
                         const Location &endLocation, Passenger *passenger, Driver *driver, Car* car, int cost,
                         int distance) {
    Order order(startDate,endDate,startLocation,endLocation,passenger,driver,car,cost,distance);
    listOfAllOrders.push_back(order);

    PassengerGateway::addOrder(passenger,&listOfAllOrders.back());
    DriverGateway::addOrder(driver,&listOfAllOrders.back());

/*
    // Random decreasing number of bottles
    if(driver->getCar()->getType() > CarType::ECONOMY){
        dynamic_cast<ComfortCar*>(driver->getCar())->decreaseBottles(); // safe cast
    }
*/

    DB_Helper::writeListOfOrders();

    return &listOfAllOrders.back();
}

const Order *System::findOrderById(int id) {
    for(const Order& order: listOfAllOrders){
        if(order.getId() == id){
            return &order;
        }
    }
    return nullptr;
}

Driver *System::loginAsDriver(const string &phoneNumber, const string &password) {
    for(auto& driver: DriverGateway::getMutableListOfAllDrivers()){
        if(driver.getPhoneNumber() == phoneNumber && driver.getPassword() == password){
            return &driver;
        }
    }
    return nullptr;
}

Passenger *System::loginAsPassenger(const string &phoneNumber, const string &password) {
    for(auto& passenger: PassengerGateway::getMutableListOfAllPassengers()){
        if(passenger.getPhoneNumber() == phoneNumber && passenger.getPassword() == password){
            return &passenger;
        }
    }
    return nullptr;
}

Admin *System::loginAsAdmin(const string &phoneNumber, const string &password) {
    for(auto& admin: AdminGateway::getMutableListOfAllAdmins()){
        if(admin.getPhoneNumber() == phoneNumber && admin.getPassword() == password){
            return &admin;
        }
    }
    return nullptr;
}






