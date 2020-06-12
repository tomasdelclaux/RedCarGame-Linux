#ifndef VEHICLE_H
#define VEHICLE_H
#include <iostream>
#include <math.h>

enum Type { red, blue, gTruck, truck};
enum Direction {kLeft, kRight, kUp, kRelease};

class Vehicle{
    public:
        //Constructors Destructors
        Vehicle(Type type);

        Vehicle(const Vehicle &v2);

        Vehicle(Vehicle &&otherV);

        ~Vehicle();

        //Overloads

        Vehicle &operator=(const Vehicle &rv){
            return *this;
        };

        bool operator==(const Vehicle &v2) const{
            if (x == v2.x && y == v2.y && type == v2.getType()){
                return true;
            }
            else {
                return false;
            }
        };

        //Getters
        Type getType() const{
            return type;
        };

        int width() const {
            return w;
        };

        int height() const {
            return h;
        };
        
        int velocity() const {
            return v;
        };

        static int getAcceleration ();

        //method to update position
        void Update();

        //method to accelerate
        void accelerate(int a);

        //Coordinates
        int x;
        int y;

    protected:
        //Red, blue, truck, gTruck
        Type type;

        //velocity acceleration
        float v;
        static int acceleration;

        //Dimensions
        int w;
        int h;
};

class RedCar : public Vehicle {
    public:
        RedCar(int xLimit);
        RedCar();
        ~RedCar();
        void Update();
        Direction direction{kRelease};
        bool alive{true};
        int distance{0};
    
    private:
        int xLimit;
};

#endif