//
// Created by super on 26.04.2021.
//

#include "Console.h"

void Console::printMainMenu() {
    cout << "----Main menu----\n";
    cout << " 1.Login as passenger\n";
    cout << " 2.Login as driver\n";
    cout << " 3.Register as passenger\n";
    cout << " 4.Register as driver\n";
    cout << " 5.Login as admin\n";

    int answer = writeAnswer();

    switch (answer) {
        case 1:
            printLoginForPassenger();
            break;
        case 2:
            printLoginForDriver();
            break;
        case 3:
            printRegistrationForPassenger();
            break;
        case 4:
            printRegistrationForDriver();
            break;
        case 5:
            printLoginForAdmin();
            break;
        default: {
            cout << "Illegal symbol\n";
            printMainMenu();
        }
    }
}

vector<string> Console::printLoginMessage() {
    cout << "--------------\n";
    vector<string> info = {};

    cout << "Please, write your phone number: ";
    string phoneNumber; cin >> phoneNumber;
    info.push_back(phoneNumber);

    cout << "Please, write your password: ";
    string password; cin >> password;
    info.push_back(password);

    return info;
}

void Console::printLoginForPassenger() {
    vector<string> info = printLoginMessage();
    try {
        Passenger *passenger = System::loginAsPassenger(info[0], info[1]);
        printOptionsForPassenger(passenger);
    }
    catch (IncorrectLoginException& e) {
        cout << e.what();
        printMainMenu();
    }
}

void Console::printLoginForAdmin() {
    vector<string> info = printLoginMessage();
    try {
        Admin *admin = System::loginAsAdmin(info[0], info[1]);
        printOptionsForAdmin(admin);
    }
    catch (IncorrectLoginException& e) {
        cout << e.what();
        printMainMenu();
    }
}


void Console::printLoginForDriver() {
    vector<string> info = printLoginMessage();
    try {
        Driver *driver = System::loginAsDriver(info[0], info[1]);
        printOptionsForDriver(driver);
    }
    catch (IncorrectLoginException& e) {
        cout << e.what();
        printMainMenu();
    }


}


vector<string> Console::printRegistrationMessage() {
    cout << "--------------\n";
    vector<string> info = {};

    cout << "Please, write your name: ";
    string name; cin >> name;
    info.push_back(name);

    cout << "Please, write your phone number: ";
    string phoneNumber; cin >> phoneNumber;
    info.push_back(phoneNumber);

    cout << "Please, write your password: ";
    string password; cin >> password;
    info.push_back(password);

    return info;

}


void Console::printRegistrationForPassenger() {
    vector<string> info = printRegistrationMessage();

    System::registerPassenger(info[0],info[1],info[2]);

    printMainMenu();

}

void Console::printRegistrationForDriver() {
    vector<string> info = printRegistrationMessage();

    System::registerDriver(info[0],info[1],info[2]);

    printMainMenu();

}

void Console::printRegistrationForCar(Driver *driver) {
    cout << "--------------\n";
    vector<string> info = {};

    cout << "Please, write model(one word): ";
    string model; cin >> model;

    cout << "Please, write color: ";
    string color; cin >> color;

    cout << "Please, write number: ";
    string number; cin >> number;

    cout << "Please, write car type(Economy, Comfort, Comfort plus, Business): ";
    string stringCarType; cin >> stringCarType;
    CarType carType = stringToCarType(stringCarType);

    Car* car = System::registerCar(model,color,number,carType);

    driver->pinCar(car);
    cout << "Car: " << car->getNumber() << " is pinned to " << driver->getName() << endl;

}



void Console::printOptionsForPassenger(Passenger* passenger) {
    cout << "--------------\n";
    cout << "Hello " << passenger->getName() << "!\n";
    cout << "What do you want to do?\n";

    cout << " 1.Make order\n";
    cout << " 2.Add pin address\n";
    cout << " 3.Log out\n";


    int answer = writeAnswer();
    switch (answer) {
        case 1:
            order(passenger);
            printOptionsForPassenger(passenger);
            break;
        case 2:
            addNewPinnedLocation(passenger);
            printOptionsForPassenger(passenger);
            break;
        case 3:
            printMainMenu();
            break;
        default:
            cout << "Illegal symbol\n";
            printOptionsForPassenger(passenger);
    }

}
void Console::order(Passenger *passenger) {
    Location startLocation;
    Location endLocation;

    CarType carType;

    cout << "----Preorder----\n";
    cout << "Choose start location:\n";
    int index = 1;
    vector<Location> arrayOfPinnedAddresses; // it is needed because std::list does not has random access iterator
    for(auto& pinnedLocation: passenger->getPinnedAddresses()){
        cout << " " << index << ".X: " << pinnedLocation.getCoordinateX() << " Y: " << pinnedLocation.getCoordinateY() << endl;
        arrayOfPinnedAddresses.push_back(pinnedLocation);
        index++;
    }
    cout << " " << index << "." << "Or choose in map\n";

    int answer = writeAnswer();

    if(answer > index || answer < 1){
        cout << "Illegal symbol\n";
        order(passenger);
    }
    else if(answer == index){
        startLocation = writeLocation();
    }
    else{
        startLocation = arrayOfPinnedAddresses[answer-1]; // indexes from zero, answers from one
    }


    cout << "Choose end location:\n";
    arrayOfPinnedAddresses.clear(); // it is needed because std::list does not has random access iterator
    index = 1;
    for(auto& pinnedLocation: passenger->getPinnedAddresses()){
        cout << " " << index << ".X: " << pinnedLocation.getCoordinateX() << " Y: " << pinnedLocation.getCoordinateY() << endl;
        arrayOfPinnedAddresses.push_back(pinnedLocation);
        index++;
    }
    cout << " " << index << "." << "Or choose in map\n";

    answer = writeAnswer();

    if(answer > index || answer < 1){
        cout << "Illegal symbol\n";
        order(passenger);
    }
    else if(answer == index){
        endLocation = writeLocation();
    }
    else{
        endLocation = arrayOfPinnedAddresses[answer-1]; // indexes from zero, answers from one
    }

    cout << "Choose needed car type(Economy, Comfort, Comfort plus, Business)\n";

    string stringCarType;
    cin >> stringCarType;
    carType = stringToCarType(stringCarType);

    System::preOrder(startLocation,endLocation,passenger,carType);

}



void Console::printOptionsForDriver(Driver* driver) {
    cout << "--------------\n";
    cout << "Hello " << driver->getName() << "!\n";
    cout << "What do you want to do?\n";

    cout << " 1.Add car\n";
    cout << " 2.Log out\n";

    int answer = writeAnswer();
    switch (answer) {
        case 1:
            printRegistrationForCar(driver);
            printOptionsForDriver(driver);
            break;
        case 2:
            printMainMenu();
            break;
        default:
            cout << "Illegal symbol\n";
            printOptionsForDriver(driver);
    }


}


void Console::printOptionsForAdmin(Admin *admin) {
    cout << "--------------\n";
    cout << "ADMIN. " << admin->getName() << "!\n";
    cout << "What do you want to do?\n";

    cout << " 1.Block/Unblock passenger\n";
    cout << " 2.Block/Unblock driver\n";
    cout << " 3.Get info of passenger\n";
    cout << " 4.Get info of driver\n";
    cout << " 5.Log out\n";

    int answer = writeAnswer();

    switch (answer) {
        case 1:
            try {
                admin->blockPassenger(admin->findPassenger(writePhoneNumber()));
            }
            catch (NoSuchUserException &e) {
                cout << e.what();
            }
            printOptionsForAdmin(admin);
            break;
        case 2:
            try {
                admin->blockDriver(admin->findDriver(writePhoneNumber()));
            }
            catch (NoSuchUserException &e) {
                cout << e.what();
            }
            printOptionsForAdmin(admin);
            break;
        case 3:
            try {
                Output::printInfoAboutPassenger(admin->findPassenger(writePhoneNumber()));
            }
            catch (NoSuchUserException &e) {
                cout << e.what();
            }
            printOptionsForAdmin(admin);
            break;
        case 4:
            try {
                Output::printInfoAboutDriver(admin->findDriver(writePhoneNumber()));
            }
            catch (NoSuchUserException &e) {
                cout << e.what();
            }
            printOptionsForAdmin(admin);
            break;
        case 5:
            printMainMenu();
            break;
        default:
            cout << "Illegal symbol\n";
            printOptionsForAdmin(admin);
    }


}



int Console::writeAnswer() {
    cout << "Choose your variant(write only number)\n";

    int answer;
    cin >> answer;
    return answer;
}

void Console::addNewPinnedLocation(Passenger* passenger) {
    int x,y;
    cout << "Print coordinate X: ";
    cin >> x;
    cout << "Print coordinate Y: ";
    cin >> y;
    passenger->addPinnedAddress(Location(x,y));
}

Location Console::writeLocation() {
    int x,y;
    cout << "Print coordinate X: ";
    cin >> x;
    cout << "Print coordinate Y: ";
    cin >> y;
    return Location(x,y);
}

CarType Console::stringToCarType(const string& stringCarType) {
    CarType carType = CarType::ECONOMY;
    if(stringCarType == "Economy"){
        carType = CarType::ECONOMY;
    }
    else if(stringCarType == "Comfort"){
        carType = CarType::COMFORT;
    }
    else if(stringCarType == "Comfort plus"){
        carType = CarType::COMFORTPLUS;
    }
    else if(stringCarType == "Business"){
        carType = CarType::BUSINESS;
    }
    else{
        cout << "Incorrect type. Type of car will be economy\n";
    }
    return carType;
}

string Console::writePhoneNumber() {
    cout << "Write phone number of user: ";
    string phoneNumber;
    cin >> phoneNumber;

    return phoneNumber;
}











