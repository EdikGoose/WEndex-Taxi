//
// Created by super on 11.04.2021.
//

#include "ComfortPlusCar.h"


CarType ComfortPlusCar::getType() {
    return CarType::COMFORTPLUS;
}

ComfortPlusCar::ComfortPlusCar(const string &model, const string &color, const string &number) : ComfortCar(model,
                                                                                                            color,
                                                                                                            number) {}

int ComfortPlusCar::getRate() {
    return 35;
}
