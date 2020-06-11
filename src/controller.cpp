#include "controller.h"
#include <iostream>
#include "SDL.h"

void Controller::ChangeDirection(RedCar &redCar, Direction input) const{
  redCar.direction = input;
  return;
}

void Controller::ChangeAcceleration(RedCar &redCar, int input) const {
  redCar.accelerate(input);
  return;
}

void Controller::HandleInput(bool &running, RedCar &redCar) const {
  SDL_Event e;
  while (SDL_PollEvent(&e)) {
    if (e.type == SDL_QUIT) {
      running = false;
    } else if (e.type == SDL_KEYDOWN) {
      switch (e.key.keysym.sym) {
        case SDLK_LEFT:
          ChangeDirection(redCar, kLeft);
          return;

        case SDLK_RIGHT:
          ChangeDirection(redCar, kRight);
          return;

        case SDLK_UP:
          ChangeAcceleration(redCar, 2);
          return;
      }
    }
    else if(e.type == SDL_KEYUP){
      switch(e.key.keysym.sym){
        case SDLK_LEFT:
          ChangeDirection(redCar, kRelease);
        case SDLK_RIGHT:
          ChangeDirection(redCar, kRelease);
        case SDLK_UP:
          ChangeAcceleration(redCar, 1);
      }
    }  
  }
}