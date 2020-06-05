#ifndef LANE_H
#define LANE_H

#include "vehicle.h"
#include <vector>

class Lane{
    public:
    Lane(int direction) : direction(direction){};

    //Add vehicle to lane
    void addVehicle(Type type);

    //Remove vehicle from lane
    void removeVehicle(Vehicle*);

    private:
    //can be reverse or normal
    int direction;
    
    //vector of vehicles in the lane
    std::vector<Vehicle*> _vehicles;
};

#endif