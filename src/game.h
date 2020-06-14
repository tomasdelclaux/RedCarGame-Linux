#ifndef GAME_H
#define GAME_H

#include <vector>
#include "SDL.h"
#include "lane.h"
#include "controller.h"
#include "renderer.h"
#include "vehicle.h"

class Game {
    public:
    Game(int kScreenHeight, int kScreenWidth);
     void Run(Controller const &controller, Renderer &renderer,
              std::size_t target_frame_duration);

     void upLevel();

     Type getType();
    
    private:
     RedCar redCar;
     std::vector<Lane> lanes;

     //Difficulty flags
     int PaddVehicle{30};
     std::map<char, int> Ptypes {{{ 'T', 1}, {'G', 2}}};
     int addedLanes{2};
     int lastAdded{0};

     //Probability generator
    std::random_device dev;
    std::mt19937 engine{(dev())};
    std::uniform_int_distribution<std::mt19937::result_type> rollVehicles;
    std::uniform_int_distribution<std::mt19937::result_type> rollLanes;
    std::uniform_int_distribution<std::mt19937::result_type> rollTypes;
};

#endif