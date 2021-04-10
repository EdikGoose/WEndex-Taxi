#include <iostream>
#include "Users/Passenger.h"
#include "Users/Driver.h"

using namespace std;

int main() {
    Passenger passenger("Eduard","89279388380","2314");
    Driver driver("Iskander","89270377123","4513");

    cout << passenger.getName() << " " << passenger.getPhoneNumber() << " " << passenger.getRating() << endl;
    cout << driver.getName() << " " << driver.getPhoneNumber() << " " << driver.getRating() << endl;

    return 0;
}
