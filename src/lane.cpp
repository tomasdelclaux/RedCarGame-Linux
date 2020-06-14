#include "lane.h"

bool Lane::getDirection(){
    return direction;
}

int Lane::getLaneRefx(){
    return laneRefx;
}

std::list<Vehicle> &Lane::getVehicles(){
    return vehicles;
}

void Lane::updatePositions(){
    for (auto v = vehicles.begin(); v != vehicles.end(); v++){
        if (!this->getDirection()){
            //avoid overlap of cars in lane
            if (v != vehicles.begin() && std::prev(v)->y <= v->y + v->velocity() * v->getAcceleration() *2 + v->height()){
                return;
            }
            v->y += v->velocity()*v->getAcceleration()*2;
        }
        else {
            if (v != vehicles.begin() && std::prev(v)->y <= v->y + v->velocity() * v->getAcceleration() + v->height()){
                return;
            }
            v->y += v->velocity()*v->getAcceleration();
        }
    }
}

void Lane::addVehicle(Type type){
    if (vehicles.size() > 0 && vehicles.back().y <= 180){
        return;
    }
    vehicles.emplace_back(Vehicle(type));
};

void Lane::removeVehicles(){
    auto end = this->laneHeight;
    vehicles.remove_if([end] (auto &i) { return i.y > end;});
}

