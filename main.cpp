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

    //cout << order->getDriver()->getName() << " " << order->getDriver()->getCar()->getModel();


    int a = 5;


    cout << "   Start location:\n    " << endl;



    cout << "Order number: " << order->getId() << endl;

    cout << "   Start location:\n    ";
    Output::printInfoAboutLocation(order->getStartLocation());

    cout << "   End location:\n    ";
    Output::printInfoAboutLocation(order->getEndLocation());

    cout << "   Distance:\n    ";
    cout << order->getDistance() << endl;

    cout << "   Passenger:\n    ";
    Output::printInfoAboutPassenger(order->getPassenger());

    cout << "   Driver:\n    " ;
    Output::printInfoAboutDriver(order->getDriver());

    cout << "   Start time:\n    ";
    Output::printInfoAboutDate(order->getStartDate());

    cout << "   End time:\n    ";
    Output::printInfoAboutDate(order->getEndTime());

    cout << "   Cost:\n    ";
    cout << order->getCost() << endl;

    //Output::printInfoAboutOrder(order);

    /*
    list<Order> orders = System::getListOfAllOrders();
    for(Order order: orders){
        Output::printInfoAboutOrder(order);
    }


    list<Order*> ordersOfUser = passenger->getOrderHistory();
    for(Order* order: ordersOfUser){
        cout << order->getDriver()->getName();
    }
    // что-то не так с водителем....

     */








    return 0;
}
