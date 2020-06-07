#include "lane.h"

int Lane::getDirection(){
    return direction;
}

int Lane::getLaneRefx(){
    return laneRefx;
}

std::list<Vehicle> Lane::getVehicles(){
    return vehicles;
}

void Lane::updatePositions(){
    //TODO
}

void Lane::addVehicle(Type type){
    if (newVehicle(engine) <= PNewVehicle){
        auto prob = typeVehicle(engine);
        if (prob < PWhatVehicle['T']){
            Vehicle newVehicle(truck, direction);
            vehicles.emplace_back(std::move(newVehicle));
        }
        else if (prob < PWhatVehicle['W']){
            Vehicle newVehicle(truck, direction);
            vehicles.emplace_back(std::move(newVehicle));
        }
        else if (prob < PWhatVehicle['B']){
            Vehicle newVehicle(truck, direction);
            vehicles.emplace_back(std::move(newVehicle));
        }
    }
};

void Lane::removeVehicles(){
    for (auto &vehicle : vehicles){
        if (vehicle.getY() > laneHeight){
            vehicles.remove(vehicle);
        }
    }
}

