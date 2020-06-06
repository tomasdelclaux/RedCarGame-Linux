#include "controller.h"
#include <iostream>
#include "SDL.h"

void Controller::ChangeDirection(RedCar &redCar, Direction input) const{
  redCar.direction = input;
  return;
}

void Controller::HandleInput(bool &running, RedCar &redCar) const {
  SDL_Event e;
  while (SDL_PollEvent(&e)) {
    if (e.type == SDL_QUIT) {
      running = false;
    } else if (e.type == SDL_KEYDOWN) {
      switch (e.key.keysym.sym) {
        case SDLK_UP:
          std::cout << "MOVING UP\n";
          ChangeDirection(redCar, kUp);
          break;

        case SDLK_LEFT:
          std::cout << "MOVING LEFT\n";
          ChangeDirection(redCar, kLeft);
          break;

        case SDLK_RIGHT:
          std::cout << "MOVING RIGHT\n";
          ChangeDirection(redCar, kRight);
          break;
        
        default:
          std::cout << "Cruise mode\n";
          ChangeDirection(redCar, noPress);
      }
    }
  }
}