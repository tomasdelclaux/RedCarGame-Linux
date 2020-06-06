#include "game.h"
#include <iostream>
#include "SDL.h"

Game::Game() {
  Lane Lane1(-1);
  Lane Lane2(-1);
  Lane Lane3(0);
  Lane Lane4(0);
  Lane Lane5(5);
  lanes.emplace_back(std::move(Lane1));
  lanes.emplace_back(std::move(Lane2));
  lanes.emplace_back(std::move(Lane3));
  lanes.emplace_back(std::move(Lane4));
  lanes.emplace_back(std::move(Lane5));
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
    renderer.Render(redCar, lanes);

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