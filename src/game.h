#ifndef GAME_H
#define GAME_H

#include "SDL.h"
#include "controller.h"
#include "renderer.h"

class Game {
    public:
     void Run(Controller const &controller, Renderer &renderer,
              std::size_t target_frame_duration);
     int GetScore() const;
     int GetSize() const;
    
    private:
     int distance{0};
};

#endif