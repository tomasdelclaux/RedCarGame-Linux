#ifndef VEHICLE_H
#define VEHICLE_H
#include <iostream>
#include <math.h>

enum Type { red, blue, white, truck};
enum Direction {kUp, kLeft, kRight};

class Vehicle{
    public:
    //Constructor
    Vehicle(Type type);

    //Destructor
    ~Vehicle();

    //Direction
    Direction direction;

    protected:
    //Red, blue, truck, white
    Type _type;

    //asset to load for this vehicle
    std::string image;
    
    //Dimensions
    int w;
    int h;

    //Coordinates
    int x;
    int y;

    //velocity
    int v;
};

class RedCar : public Vehicle {
    public:
    RedCar();
    ~RedCar();
    void Update();
};

#endif