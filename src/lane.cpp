#include "lane.h"

int Lane::getDirection(){
    return direction;
}

std::vector<Vehicle> Lane::getVehicles(){
    return vehicles;
}

void Lane::addVehicle(Type type){
    Vehicle newVehicle(type);
    vehicles.emplace_back(std::move(newVehicle));
};

void Lane::removeVehicle(Vehicle){
    vehicles.erase(vehicles.end());
};

