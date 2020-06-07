#include "vehicle.h"

Vehicle::Vehicle(Type type) : type(type) {
    switch(type)
    {
        case red :
            w = 90;
            h = 90;
            v = 0.0001;
            x = 300;
            y = 700;
            image = "../assets/redCar.png";
            break;
        case blue :
            w = 90;
            h = 90;
            v = 5;
            image = "../assets/blueCar.png";
            break;
        case truck :
            w = 105;
            h = 180;
            v = 5;
            image = "../assets/truck.png";
            break;
        case white :
            w = 90;
            h = 90;
            v = 5;
            image = "../assets/white.png";
            break;
    }
}

Vehicle::Vehicle(const Vehicle &v2){
    image = v2.image;
    type = v2.type;
    w = v2.w;
    h = v2.h;
    v = v2.v;
    direction = v2.direction;
    x = v2.x;
    y = v2.y;
}

Vehicle::Vehicle(Vehicle &&otherV){
    image = std::move(otherV.image);
    type = std::move(otherV.type);
    w = std::move(otherV.w);
    h = std::move(otherV.h);
    v = std::move(otherV.v);
    direction = std::move(otherV.direction);
    x = std::move(otherV.x);
    y = std::move(otherV.y);
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