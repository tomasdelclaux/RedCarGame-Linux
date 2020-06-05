#ifndef VEHICLE_H
#define VEHICLE_H

enum Type { red, blue, white, truck};

class Vehicle{
    public:
    //Constructor
    Vehicle(Type type);

    //Destructor
    ~Vehicle();

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

#endif