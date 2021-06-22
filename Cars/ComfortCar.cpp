//
// Created by super on 11.04.2021.
//

#include "ComfortCar.h"

CarType ComfortCar::getType() const {
    return CarType::COMFORT;
}

ComfortCar::ComfortCar(const string &model, const string &color, const string &number) : Car(model, color, number) {
    this->freeBottleOfWater = 15;
}

void ComfortCar::decreaseBottles() {
    freeBottleOfWater -= (rand() % freeBottleOfWater) + 1;
}

int ComfortCar::getFreeBottleOfWater() const {
    return freeBottleOfWater;
}

ComfortCar::ComfortCar() {}

int ComfortCar::getRate() const {
    return 30;
}
