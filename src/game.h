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
     int GetSize() const;
    
    private:
     RedCar redCar;
     std::vector<Lane> lanes;
};

#endif