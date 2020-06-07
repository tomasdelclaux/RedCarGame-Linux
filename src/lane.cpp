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
    for (auto &vehicle : vehicles){
        vehicle.y += 1;
    }
}

void Lane::addVehicle(){
    if (vehicles.size() > 0 && vehicles.back().y <= 180){
        return;
    }
    std::random_device dev;
    std::mt19937 engine(dev());
    std::uniform_int_distribution<std::mt19937::result_type> probability(1,100);
    std::cout << probability(engine) << std::endl;
    if (probability(engine) <= PNewVehicle){
        if (probability(engine) < PWhatVehicle['T']){
            Vehicle newVehicle(truck, direction);
            std::cout << "new Truck created";
            vehicles.emplace_back(std::move(newVehicle));
        }
        else if (probability(engine) < PWhatVehicle['W']){
            Vehicle newVehicle(white, direction);
            std::cout << "new White created";
            vehicles.emplace_back(std::move(newVehicle));
        }
        else if (probability(engine) < PWhatVehicle['B']){
            Vehicle newVehicle(blue, direction);
            std::cout << "new Blue created";
            vehicles.emplace_back(std::move(newVehicle));
        }
    }
};

void Lane::removeVehicles(){
    for (auto &vehicle : vehicles){
        if (vehicle.y > laneHeight){
            vehicles.remove(vehicle);
        }
    }
}

