//
// Created by super on 25.04.2021.
//

#include "Admin.h"

Admin::Admin(const string &name, const string &phoneNumber, const string &password) : User(name, phoneNumber,
                                                                                           password) {}

string Admin::serialize(const Admin &admin) {
    string adminStr = "/Name " + admin.getName() + "/Phone " + admin.getPhoneNumber() + "/Password " + admin.getPassword() + "/";
    return adminStr;
}
