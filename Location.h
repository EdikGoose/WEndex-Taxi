//
// Created by super on 10.04.2021.
//

#ifndef WENDEX_TAXI_LOCATION_H
#define WENDEX_TAXI_LOCATION_H

#include <iostream>
#include <cmath>

using namespace std;

/**
 * Class for saving coordinates and address
 */
class Location {
    int coordinateX = 0;
    int coordinateY = 0;
    string address;
public:
    Location() = default;

    Location(int coordinateX, int coordinateY);

    /**
     * Change coordinate and address according to new coordinate
     * @param newCoordinateX
     * @param newCoordinateY
     */
    void changeLocation(int newCoordinateX, int newCoordinateY);

    [[nodiscard]] int getCoordinateX() const;

    [[nodiscard]] int getCoordinateY() const;

    [[nodiscard]] const string &getAddress() const;

    static int getDistance(const Location& from, const Location& to);

    static Location deserialize(string location);

    static string serialize(const Location& location);

private:
    /**
     * Define new address according to new coordinate;
     * @param coordinateX
     * @param coordinateY
     */
    void defineAddress(int coordinateX, int coordinateY);
};


#endif //WENDEX_TAXI_LOCATION_H
