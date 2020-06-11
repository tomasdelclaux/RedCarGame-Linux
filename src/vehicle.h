#ifndef VEHICLE_H
#define VEHICLE_H
#include <iostream>
#include <math.h>

enum Type { red, blue, gTruck, truck};
enum Direction {kLeft, kRight, kUp, kRelease};

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

        void accelerate(int a);

        //method to update position
        void Update();

        //Dimensions
        int w;
        int h;

        //Coordinates
        int x;
        int y;

    protected:
        //Red, blue, truck, gTruck
        Type type;

        //velocity
        float v;

        static int acceleration; 
};

class RedCar : public Vehicle {
    public:
        RedCar(int xLimit);
        RedCar();
        ~RedCar();
        void Update();
        Direction direction{kRelease};
        bool alive{true};
    
    private:
        int xLimit;
};

#endif