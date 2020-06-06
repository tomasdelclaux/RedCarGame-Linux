#include "vehicle.h"

Vehicle::Vehicle(Type type){
    switch(type)
    {
        case red :
            w = 90;
            h = 90;
            v = 0.0001;
            x = 300;
            y = 700;
            direction = kRight;
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
            std::cout << "Moving left\n";
            x-=5;
            break;
        case kRight :
            std::cout << "Moving right\n";
            x += 5;
            break;
        case kUp :
            std::cout << "Moving up\n";
            y -= 5;
            break;
        case noPress :
            y += 5;
            break;
    }
}