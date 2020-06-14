#ifndef DIFFICULTY_H
#define DIFFICULTY_H

#include <random>
#include <map>

class Difficulty {
    public:
        int distance;
        int lanes [1,2,3,4,5];
        //modulo for round robin
        int last_added;
        int leftFree;

    private:
        int Ptruck;
        int Pgtruck;
        int Pblue;
        int PnewVehicle;
}

#endif