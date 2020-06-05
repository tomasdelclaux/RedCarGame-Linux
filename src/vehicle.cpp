#include "vehicle.h"

Vehicle::Vehicle(Type type){
    switch(type)
    {
        case red :
            w = 90;
            h = 90;
            v = 5;
            image = "assets/redCar.png";
        case blue :
            w = 90;
            h = 90;
            v = 5;
            image = "assets/blueCar.png";
        case truck :
            w = 105;
            h = 180;
            v = 5;
            image = "assets/truck.png";
        case white :
            w = 90;
            h = 90;
            v = 5;
            image = "assets/white.png";
    }
}

Vehicle::~Vehicle(){
    std::cout << "Vehicle is destructed\n";
}

RedCar::RedCar() : Vehicle(red){};

RedCar::~RedCar(){
    std::cout << "RedCar is destructed\n";
}

void RedCar::Update(){
    switch(direction)
    {
        case kLeft :
            y += 1.0/sqrt(2) * v;
            x -= 1.0/sqrt(2) * v;
        case kRight :
            y += 1.0/sqrt(2) * v;
            x += 1.0/sqrt(2) * v;
        case kUp :
            y += 2*v;
        default:
            y += v;
    }
}