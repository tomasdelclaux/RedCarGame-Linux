#ifndef VEHICLE_H
#define VEHICLE_H
#include <iostream>
#include <math.h>

enum Type { red, blue, white, truck};
enum Direction {kUp, kLeft, kRight, noPress};

class Vehicle{
    public:
    //Constructor
    Vehicle(Type type);

    //Destructor
    ~Vehicle();

    //Getters
    int getX(){
        return x;
    };

    int getY(){
        return y;
    }

    int getH(){
        return h;
    }

    int getW(){
        return w;
    }

    std::string getImage(){
        return image;
    }

    //method to update position
    void Update();

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
    float v;
};

class RedCar : public Vehicle {
    public:
    RedCar();
    ~RedCar();
    void Update();
};

#endif