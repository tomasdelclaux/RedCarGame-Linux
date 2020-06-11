#include "lane.h"

int Lane::getDirection(){
    return direction;
}

int Lane::getLaneRefx(){
    return laneRefx;
}

std::list<Vehicle> &Lane::getVehicles(){
    return vehicles;
}

void Lane::updatePositions(){
    for (auto &vehicle : vehicles){
        if (this->getDirection() < 0){
            vehicle.y += 2;
        }
        else {
            vehicle.y += 1;
        }
    }
}

void Lane::addVehicle(){
    if (vehicles.size() > 0 && vehicles.back().y <= 180){
        return;
    }
    std::random_device dev;
    std::mt19937 engine(dev());
    std::uniform_int_distribution<std::mt19937::result_type> probability(1,100);
    if (probability(engine) <= PNewVehicle){
        if (probability(engine) < PWhatVehicle['T']){
            std::cout << "new Truck created";
            vehicles.emplace_back(Vehicle(truck, direction));
        }
        else if (probability(engine) < PWhatVehicle['G']){
            std::cout << "new garbage truck created";
            vehicles.emplace_back(Vehicle(gTruck, direction));
        }
        else if (probability(engine) < PWhatVehicle['B']){
            std::cout << "new Blue created";
            vehicles.emplace_back(Vehicle(blue, direction));
        }
    }
};

void Lane::removeVehicles(){
    auto end = this->laneHeight;
    vehicles.remove_if([end] (auto &i) { return i.y > end;});
}

