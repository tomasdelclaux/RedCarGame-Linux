#ifndef VEHICLE_H
#define VEHICLE_H

enum Type { red, blue, white, truck};
enum Direction {kUp, kLeft, Kright};

class Vehicle{
    public:
    //Constructor
    Vehicle(Type type);

    //Destructor
    ~Vehicle();

    //Direction
    Direction direction;

    private:
    //Red, blue, truck, white
    Type _type;

    //Pointer to animation class for this object
    int animation;
    
    //Dimensions
    int w;
    int h;

    //Coordinates
    int x;
    int y;

    //velocity
    int v;
};

class redCar : Vehicle {
    public:
    void Update();
};

#endif