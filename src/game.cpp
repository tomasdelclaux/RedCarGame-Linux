#include "game.h"
#include <iostream>
#include "SDL.h"

Game::Game(int kScreenHeight){
  lanes.emplace_back(Lane(-1,kScreenHeight, 0));
  lanes.emplace_back(Lane(-1,kScreenHeight, 128));
  lanes.emplace_back(Lane(1,kScreenHeight, 256));
  lanes.emplace_back(Lane(1,kScreenHeight, 384));
  lanes.emplace_back(Lane(1,kScreenHeight, 512));
}

void Game::Run(Controller const &controller, Renderer &renderer,
               std::size_t target_frame_duration) {
  Uint32 title_timestamp = SDL_GetTicks();
  Uint32 frame_start;
  Uint32 frame_end;
  Uint32 frame_duration;
  int frame_count = 0;
  bool running = true;

  while (running) {
    frame_start = SDL_GetTicks();

    // Input, Update, Render - the main game loop.
    controller.HandleInput(running, redCar);

    //TODO Add vehicles to lanes
    
    renderer.Render(redCar, lanes);

    //TODO Remove vehicles from lanes
    frame_end = SDL_GetTicks();

    // Keep track of how long each loop through the input/update/render cycle
    // takes.
    frame_count++;
    frame_duration = frame_end - frame_start;

    // After every second, update the window title.
    if (frame_end - title_timestamp >= 1000) {
      renderer.UpdateWindowTitle(distance, frame_count);
      frame_count = 0;
      title_timestamp = frame_end;
    }

    // If the time for this frame is too small (i.e. frame_duration is
    // smaller than the target ms_per_frame), delay the loop to
    // achieve the correct frame rate.
    if (frame_duration < target_frame_duration) {
      SDL_Delay(target_frame_duration - frame_duration);
    }
  }
}