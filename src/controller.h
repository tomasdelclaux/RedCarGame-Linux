#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "vehicle.h"

class Controller {
    public:
    void HandleInput(bool &running) const;

    void ChangeDirection(Vehicle &redCar, Direction direction);
};

#endif