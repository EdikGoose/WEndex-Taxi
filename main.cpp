#include <iostream>
#include "Users/Passenger.h"
#include "Users/Driver.h"
#include "Date.h"
#include "Output.h"
#include "Cars/Car.h"
#include "Cars/ComfortCar.h"
#include "SystemClasses/System.h"
#include "Cars/EconomyCar.h"
#include <ctime>

using namespace std;

int main() {
    srand((unsigned) time(nullptr)); // for unique random

    Location location1(5,6);
    Location location2(7,8);

    Car* comfortCar = System::registerCar("LADA", "RED", "a355c", CarType::COMFORT);

    Driver* driver = System::registerDriver("Mike","891385","135df");
    Passenger* passenger = System::registerPassenger("Eduard","13524","135f");

    driver->pinCar(comfortCar);

    Order* order = System::preOrder(location1,location2,passenger,CarType::COMFORT);

    Output::printInfoAboutOrder(order);








    return 0;
}
