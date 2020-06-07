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

        //Overloading == operator to use list remove
        bool operator==(const Vehicle &v2) const{
            if (x == v2.getX() && y == v2.getY() && type == v2.getType()){
                return true;
            }
            else {
                return false;
            }
        };
        //Destructor
        ~Vehicle();

        //Getters
        int getX() const{
            return x;
        };
        int getY() const{
            return y;
        };
        int getH() const{
            return h;
        };
        int getW() const{
            return w;
        };
        int getType() const{
            return type;
        };
        const char* getImage() {
            return image;
        };

        //method to update position
        void Update();

        //Direction
        Direction direction;

    protected:
        //Red, blue, truck, white
        Type type;

        //asset to load for this vehicle
        const char *image;
        
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