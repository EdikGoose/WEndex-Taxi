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
    friend class Admin;
protected:
    string name;
    double rating = 0;
    string phoneNumber;
    string password;
    list<Order*> orderHistory;
    list<int> orderHistoryID;

    bool isBlocked = false;

public:
    User(string name, string phoneNumber, string password) : name(move(name)),phoneNumber(move(phoneNumber)),
                                                                                                 password(move(password)) {};


    [[nodiscard]] const string &getName() const;

    [[nodiscard]] double getRating() const;

    [[nodiscard]] const string &getPhoneNumber() const;

    void addOrder(Order* order);

    [[nodiscard]] const list<Order *> &getOrderHistory() const;

    void addIdOfOrder(int id);

    [[nodiscard]] const list<int> &getOrderHistoryId() const;

    [[nodiscard]] const string &getPassword() const;

    [[nodiscard]] bool isBlockedByAdmin() const;


};


#endif //WENDEX_TAXI_USER_H
