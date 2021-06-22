//
// Created by super on 10.04.2021.
//

#include "Location.h"

Location::Location(int coordinateX, int coordinateY) : coordinateX(coordinateX), coordinateY(coordinateY) {
    defineAddress(coordinateX,coordinateY);
}

void Location::defineAddress(int coordinateX, int coordinateY) {
    // Using google maps we define address:
    address = "Pushkin street";
}

void Location::changeLocation(int newCoordinateX, int newCoordinateY) {
    coordinateX = newCoordinateX;
    coordinateY = newCoordinateY;
    defineAddress(coordinateX, coordinateY);

}

int Location::getCoordinateX() const {
    return coordinateX;
}

int Location::getCoordinateY() const {
    return coordinateY;
}

const string &Location::getAddress() const {
    return address;
}

int Location::getDistance(const Location &from, const Location &to) {
    return sqrt((from.getCoordinateX() - to.getCoordinateX()) * (from.getCoordinateX() - to.getCoordinateX())
                + (from.getCoordinateY() - to.getCoordinateY()) * (from.getCoordinateY() - to.getCoordinateY()));

}

Location Location::deserialize(string location) {
    int x,y;
    char symbol = ':';
    int indexOfDivider = 0;
    string beforeDivider;
    string afterDivider;
    while(location[indexOfDivider] != symbol){
        beforeDivider+=location[indexOfDivider];
        indexOfDivider++;
    }
    indexOfDivider++;
    while(indexOfDivider != location.size()){
        afterDivider+=location[indexOfDivider];
        indexOfDivider++;
    }
    x = stoi(beforeDivider);
    y = stoi(afterDivider);
    return Location(x,y);
}

string Location::serialize(const Location& location) {
    return to_string(location.getCoordinateX()) + ":" + to_string(location.getCoordinateY());
}



