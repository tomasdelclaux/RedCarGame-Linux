#ifndef VEHICLE_H
#define VEHICLE_H
#include <iostream>
#include <math.h>

enum Type { red, blue, white, truck};
enum Direction {kUp, kLeft, kRight, noPress};

class Vehicle{
    public:
        //Constructor
        Vehicle(Type type, int laneDir);

        //Copy Constructor
        Vehicle(const Vehicle &v2);

        //Move Constructor
        Vehicle(Vehicle &&otherV);

        //overload assignment operator
        Vehicle &operator=(const Vehicle &rv){
            return *this;
        };

        //Overloading == operator to use list remove
        bool operator==(const Vehicle &v2) const{
            if (x == v2.x && y == v2.y && type == v2.getType()){
                return true;
            }
            else {
                return false;
            }
        };
        //Destructor
        ~Vehicle();

        //Getters
        Type getType() const{
            return type;
        };

        //method to update position
        void Update();

        //Direction
        Direction direction;

        //Dimensions
        int w;
        int h;

        //Coordinates
        int x;
        int y;

    protected:
        //Red, blue, truck, white
        Type type;

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