#ifndef LANE_H
#define LANE_H

#include "vehicle.h"
#include <random>
#include <list>
#include <map>

class Lane{
    public:
    //Constructors
    Lane(int dir, int kScreenHeight, int laneRefx) : direction(dir), laneHeight(kScreenHeight), laneRefx(laneRefx){};

    //Copy
    Lane(const Lane &lane2){
        direction = lane2.direction;
        vehicles = lane2.vehicles;
        PNewVehicle = lane2.PNewVehicle;
        PWhatVehicle = lane2.PWhatVehicle;
        laneHeight = lane2.laneHeight;
        laneRefx = lane2.laneRefx;
    };

    //Move
    Lane(Lane &&otherLane){
        direction = std::move(otherLane.direction);
        vehicles = std::move(otherLane.vehicles);
        PNewVehicle = std::move(otherLane.PNewVehicle);
        PWhatVehicle = std::move(otherLane.PWhatVehicle);
        laneHeight = std::move(otherLane.laneHeight);
        laneRefx = std::move(otherLane.laneRefx);
    };

    //overload assignment operator
    Lane &operator=(const Lane &rv){
        return *this;
    };

    //Add vehicle to lane
    void addVehicle();

    //Remove vehicle from lane
    void removeVehicles();

    //update positions of vehicles in the lane
    void updatePositions();

    //Getters
    std::list<Vehicle>& getVehicles();

    int getDirection();
    int getLaneRefx();

    private:
    //can be reverse(-1) or normal(0)
    int direction;

    //Screen distance of lane
    int laneHeight;

    //Starting x coordinate of lane
    int laneRefx;
    
    //vector of vehicles in the lane
    std::list<Vehicle> vehicles;

    int PNewVehicle{1};
    std::map<char, int> PWhatVehicle{{ 'T', 1}, {'W', 2}, {'B', 3}};
};

#endif