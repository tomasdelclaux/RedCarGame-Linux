#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "vehicle.h"

class Controller {
    public:
    void HandleInput(bool &running, RedCar &redCar) const;

    void ChangeDirection(RedCar &redCar, Direction input) const;

    void ChangeAcceleration(RedCar &redCar, int input) const;

    int frameCount{0};
};

#endif