#include "controller.h"
#include <iostream>
#include "SDL.h"

void Controller::HandleInput(bool &running) const {
  SDL_Event e;
  while (SDL_PollEvent(&e)) {
    if (e.type == SDL_QUIT) {
      running = false;
    } else if (e.type == SDL_KEYDOWN) {
      switch (e.key.keysym.sym) {
        case SDLK_UP:
          std::cout << "MOVING UP\n";
          break;

        case SDLK_DOWN:
          std::cout << "MOVING DOWN\n";
          break;

        case SDLK_LEFT:
          std::cout << "MOVING LEFT\n";
          break;

        case SDLK_RIGHT:
          std::cout << "MOVING RIGHT\n";
          break;
      }
    }
  }
}