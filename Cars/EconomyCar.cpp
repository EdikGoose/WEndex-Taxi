//
// Created by super on 11.04.2021.
//

#include "EconomyCar.h"

CarType EconomyCar::getType() const {
    return CarType::ECONOMY;
}

EconomyCar::EconomyCar(const string &model, const string &color, const string &number) : Car(model, color, number) {}

int EconomyCar::getRate() const {
    return 20;
}
