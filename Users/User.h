//
// Created by super on 10.04.2021.
//

#ifndef WENDEX_TAXI_USER_H
#define WENDEX_TAXI_USER_H

#include <iostream>
#include <list>
#include <utility>
#include "../OrderClasses/Order.h"

using namespace std;

class User {
protected:
    string name;
    double rating = 0;
    string phoneNumber;
    string password;
    list<Order*> orderHistory;
public:
    User(string name, string phoneNumber, string password) : name(move(name)),phoneNumber(move(phoneNumber)),
                                                                                                 password(move(password)) {}
    [[nodiscard]] const string &getName() const;

    [[nodiscard]] double getRating() const;

    [[nodiscard]] const string &getPhoneNumber() const;

    void addOrder(Order* order);

    const list<Order *> &getOrderHistory() const;

};


#endif //WENDEX_TAXI_USER_H
