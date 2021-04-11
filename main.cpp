#include <iostream>
#include "Users/Passenger.h"
#include "Users/Driver.h"
#include "Date.h"
#include "Output.h"
#include "Cars/Car.h"
#include "Cars/ComfortCar.h"
#include <ctime>

using namespace std;

int main() {
    srand((unsigned) time(0)); // for unique random

    Location location1(5,6);
    Location location2(7,8);

    Date date1(23,40,1,12,2020);


    Passenger passenger("Eduard","9738","123");
    Driver driver("Mike","135653","245");


    Order order1(Date::getCurrentDate(), Date::getCurrentDate()+15, location1, location2,&passenger,&driver,250, 15);



    Output::printInfoAboutOrder(order1);

    ComfortCar comfortCar("LADA", "RED", "a355c");

    Car* p = &comfortCar;

    list<int> a;
    a.p




    return 0;
}
