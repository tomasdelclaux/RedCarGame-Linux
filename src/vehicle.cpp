#include "vehicle.h"

Vehicle::Vehicle(Type type, int laneDir) : type(type) {
    switch(type)
    {
        case red :
            w = 90;
            h = 90;
            v = 0.0001;
            x = 640 - w;
            y = 700-h;
            break;
        case blue :
            w = 90;
            h = 90;
            v = 5;
            y = 0;
            break;
        case truck :
            w = 105;
            h = 180;
            v = 5;
            y = 0;
            break;
        case white :
            w = 90;
            h = 90;
            v = 5;
            y = 0;
            break;
    }
}

Vehicle::Vehicle(const Vehicle &v2){
    type = v2.type;
    w = v2.w;
    h = v2.h;
    v = v2.v;
    x = v2.x;
    y = v2.y;
}

Vehicle::Vehicle(Vehicle &&otherV){
    type = std::move(otherV.type);
    w = std::move(otherV.w);
    h = std::move(otherV.h);
    v = std::move(otherV.v);
    x = std::move(otherV.x);
    y = std::move(otherV.y);
}

Vehicle::~Vehicle(){
    std::cout << "Vehicle is destructed\n";
}


RedCar::RedCar() : Vehicle(red, 0){};

RedCar::~RedCar(){
    std::cout << "RedCar is destructed\n";  
}

void RedCar::Update(){
    switch(direction)
    {
        case kLeft :
        if (x <= 0){
            break;
        };
            x-=5;
            break;
        case kRight :
        if (x+w >= 640){
            break;
        }
            x += 5;
            break;
        case noPress :
            break;
    }
}