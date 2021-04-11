//
// Created by super on 11.04.2021.
//

#include "Output.h"

void Output::printInfoAboutDate(const Date& date) {
    cout << "Time: " << date.getHours() << ":" << date.getMinutes() << ". Date: " << date.getDay() << "." << date.getMonth() << "." << date.getYear() << endl;

}

void Output::printInfoAboutOrder(const Order& order) {
    cout << "Order number: " << order.getId() << endl;

    cout << "   Start location:\n    ";
    printInfoAboutLocation(order.getStartLocation());

    cout << "   End location:\n    ";
    printInfoAboutLocation(order.getEndLocation());

    cout << "   Distance:\n    ";
    cout << order.getDistance() << endl;

    cout << "   Passenger:\n    ";
    printInfoAboutUser(reinterpret_cast<User *>(order.getPassenger()));

    cout << "   Driver:\n    " ;
    printInfoAboutUser(reinterpret_cast<User *>(order.getDriver()));

    cout << "   Start time:\n    ";
    printInfoAboutDate(order.getStartDate());

    cout << "   End time:\n    ";
    printInfoAboutDate(order.getEndTime());

    cout << "   Cost:\n    ";
    cout << order.getCost() << endl;


}

void Output::printInfoAboutUser(User* user) {
    cout << "Name: " << user->getName() << ". Rating:" << user->getRating() << ". Phone number: " << user->getPhoneNumber() << endl;
}

void Output::printInfoAboutLocation(const Location &location) {
    cout << "Address: " << location.getAddress() << ". X: " << location.getCoordinateX() << ". Y: " << location.getCoordinateY() << "." << endl;
}

