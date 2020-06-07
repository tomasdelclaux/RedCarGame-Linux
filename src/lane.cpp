#include "lane.h"

int Lane::getDirection(){
    return direction;
}

std::list<Vehicle> Lane::getVehicles(){
    return vehicles;
}

void Lane::addVehicle(Type type){
    Vehicle newVehicle(type);
    vehicles.emplace_back(std::move(newVehicle));
};

void Lane::removeVehicles(){
    for (auto &vehicle : vehicles){
        if (vehicle.getY() > laneHeight){
            vehicles.remove(vehicle);
        }
    }
}

