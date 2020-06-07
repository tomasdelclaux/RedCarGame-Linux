#include "vehicle.h"

Vehicle::Vehicle(Type type, int laneDir) : type(type) {
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
            y = 0;
            if (laneDir >= 0){
                image = "../assets/blueCar.png";
            }
            else {
                image = "../assets/blueCarReverse.png";
            }
            break;
        case truck :
            w = 105;
            h = 180;
            v = 5;
            y = 0;
            if (laneDir >= 0){
                image = "../assets/truck.png";
            }
            else {
                image = "../assets/truckReverse.png";
            }
            break;
        case white :
            w = 90;
            h = 90;
            v = 5;
            y = 0;
            if (laneDir >= 0){
                image = "../assets/whiteCar.png";
            }
            else {
                image = "../assets/whiteCarReverse.png";
            }
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


RedCar::RedCar() : Vehicle(red, 0){};

RedCar::~RedCar(){
    std::cout << "RedCar is destructed\n";
}

void RedCar::Update(){
    switch(direction)
    {
        case kLeft :
            x-=5;
            break;
        case kRight :
            x += 5;
            break;
        case kUp :
            y -= 5;
            break;
        case noPress :
            y += 5;
            break;
    }
}