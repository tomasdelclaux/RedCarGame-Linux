#ifndef LANE_H
#define LANE_H

#include "vehicle.h"
#include <random>
#include <vector>

class Lane{
    public:
    //Constructors
    Lane(int dir, int kScreenHeight) : direction(dir), laneHeight(kScreenHeight){};

    //Copy
    Lane(const Lane &lane2){
        std::cout << "copy constructor called\n";
        direction = lane2.direction;
        vehicles = lane2.vehicles;
        probability = lane2.probability;
    };

    //Move
    Lane(Lane &&otherLane){
        std::cout << "Move constructor called\n";
        direction = otherLane.direction;
        // vehicles = std::move(otherLane.vehicles);
        probability = otherLane.probability;
    };

    //overload assignment operator
    Lane &operator=(const Lane &rv){
        return *this;
    };

    //Add vehicle to lane
    void addVehicle(Type type);

    //Remove vehicle from lane
    void removeVehicle(Vehicle);

    //Getters
    std::vector<Vehicle> getVehicles();

    int getDirection();

    private:
    //can be reverse(-1) or normal(0)
    int direction;

    int laneHeight;
    
    //vector of vehicles in the lane
    std::vector<Vehicle> vehicles;

    std::random_device rd;
    std::uniform_int_distribution<int> distribution{(1,100)};
    std::mt19937 engine;
    int probability;
};

#endif