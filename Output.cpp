//
// Created by super on 11.04.2021.
//
#include <iostream>
#include "Output.h"
#include "Users/Passenger.h"


void Output::printInfoAboutDate(const Date& date) {
    cout << "Time: " << date.getHours() << ":" << date.getMinutes() << ". Date: " << date.getDay() << "." << date.getMonth() << "." << date.getYear() << endl;

}

void Output::printInfoAboutOrder(Order* const order) {
    cout << "Order number: " << order->getId() << endl;

    cout << "   Start location:\n    ";
    printInfoAboutLocation(order->getStartLocation());

    cout << "   End location:\n    ";
    printInfoAboutLocation(order->getEndLocation());

    cout << "   Distance:\n    ";
    cout << order->getDistance() << endl;

    cout << "   Passenger:\n    ";
    printInfoAboutPassenger(order->getPassenger());

    cout << "   Driver:\n    " ;
    printInfoAboutDriver(order->getDriver());

    cout << "   Start time:\n    ";
    printInfoAboutDate(order->getStartDate());

    cout << "   End time:\n    ";
    printInfoAboutDate(order->getEndDate());

    cout << "   Cost:\n    ";
    cout << order->getCost() << endl;
}

void Output::printInfoAboutPassenger(const Passenger* passenger) {
    cout << "Name: " << passenger->getName() << ". Rating:" << passenger->getRating() << ". Phone number: " << passenger->getPhoneNumber() << endl;
}

void Output::printInfoAboutLocation(const Location &location) {
    cout << "Address: " << location.getAddress() << ". X: " << location.getCoordinateX() << ". Y: " << location.getCoordinateY() << "." << endl;
}

void Output::printInfoAboutCar(const Car *car) {
    switch (car->getType()) {
        case CarType::ECONOMY:
            cout << "Type: economy. ";
            break;
        case CarType::COMFORT:
            cout << "Type: comfort. ";
            break;
        case CarType::COMFORTPLUS:
            cout << "Type: comfort plus. ";
            break;
        case CarType::BUSINESS:
            cout << "Type: business. ";

    }
    cout << "Model: " << car->getModel() << ". Number: " << car->getNumber() << ". Color:" << car->getColor() << endl;

}

void Output::printInfoAboutDriver(const Driver *driver) {
    cout << "Name: " << driver->getName() << ". Rating:" << driver->getRating() << ". Phone number: " << driver->getPhoneNumber() << endl;
    cout << "       " << "Car of this driver: ";
    printInfoAboutCar(driver->getCar());

}

void Output::printCondition(int price, int duration) {
    cout << "Do you agree with this condition:\n  Cost: " << price << " rubles . Duration: " << duration << " minutes" << endl;
    cout << "Answer yes, if you agree" << endl;
}

void Output::printMessageAboutAbsence() {
    cout << "Unfortunately, there are no free drivers yet. Wait some seconds" << endl;

}

