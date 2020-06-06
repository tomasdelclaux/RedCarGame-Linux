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

        //Copy Constructor
        Vehicle(const Vehicle &v2);

        //Move Constructor
        Vehicle(Vehicle &&otherV);

        //overload assignment operator
        Vehicle &operator=(const Vehicle &rv){
            return *this;
        };

        //Destructor
        ~Vehicle();

        //Getters
        int getX();
        int getY();
        int getH();
        int getW();

        std::string getImage();

        //method to update position
        void Update();

        //Direction
        Direction direction;

    protected:
        //Red, blue, truck, white
        Type type;

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