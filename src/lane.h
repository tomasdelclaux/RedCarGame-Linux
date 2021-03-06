#ifndef LANE_H
#define LANE_H

#include "vehicle.h"
#include <random>
#include <list>
#include <map>

class Lane{
    public:
        //Constructors
        Lane(bool dir, int kScreenHeight, int laneRefx) : direction(dir), laneHeight(kScreenHeight), laneRefx(laneRefx){};

        //Copy
        Lane(const Lane &lane2){
            direction = lane2.direction;
            vehicles = lane2.vehicles;
            laneHeight = lane2.laneHeight;
            laneRefx = lane2.laneRefx;
        };

        //Move
        Lane(Lane &&otherLane){
            direction = std::move(otherLane.direction);
            vehicles = std::move(otherLane.vehicles);
            laneHeight = std::move(otherLane.laneHeight);
            laneRefx = std::move(otherLane.laneRefx);
        };

        //overload assignment operator
        Lane &operator=(const Lane &rv){
            return *this;
        };

        //Add vehicle to lane
        void addVehicle(Type type);

        //Remove vehicle from lane
        void removeVehicles();

        //update positions of vehicles in the lane
        void updatePositions();

        //Getters
        std::list<Vehicle>& getVehicles();
        bool getDirection();
        int getLaneRefx();

    private:
        //can be reverse(false) or normal(true)
        bool direction{true};

        //Screen distance of lane
        int laneHeight;

        //Starting x coordinate of lane
        int laneRefx;
        
        //vector of vehicles in the lane
        std::list<Vehicle> vehicles;
};

#endif