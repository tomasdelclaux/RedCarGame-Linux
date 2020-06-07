#ifndef LANE_H
#define LANE_H

#include "vehicle.h"
#include <random>
#include <list>
#include <map>

class Lane{
    public:
    //Constructors
    Lane(int dir, int kScreenHeight) : direction(dir), laneHeight(kScreenHeight){};

    //Copy
    Lane(const Lane &lane2){
        direction = lane2.direction;
        vehicles = lane2.vehicles;
        PNewVehicle = lane2.PNewVehicle;
        PWhatVehicle = lane2.PWhatVehicle;
    };

    //Move
    Lane(Lane &&otherLane){
        direction = otherLane.direction;
        vehicles = std::move(otherLane.vehicles);
        PNewVehicle = otherLane.PNewVehicle;
        PWhatVehicle = std::move(otherLane.PWhatVehicle);
    };

    //overload assignment operator
    Lane &operator=(const Lane &rv){
        return *this;
    };

    //Add vehicle to lane
    void addVehicle(Type type);

    //Remove vehicle from lane
    void removeVehicles();

    //Getters
    std::list<Vehicle> getVehicles();

    int getDirection();

    private:
    //can be reverse(-1) or normal(0)
    int direction;

    int laneHeight;
    
    //vector of vehicles in the lane
    std::list<Vehicle> vehicles;

    std::random_device rd;
    std::uniform_int_distribution<int> distribution{(1,100)};
    std::mt19937 engine;
    int PNewVehicle{10};
    std::map<char, int> PWhatVehicle;
};

#endif