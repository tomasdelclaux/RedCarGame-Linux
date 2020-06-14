#include "game.h"
#include <iostream>
#include "SDL.h"

Game::Game(int kScreenHeight, int kScreenWidth) : rollLanes(1,5), rollVehicles(1, 1000), rollTypes(1,10){
  lanes.emplace_back(Lane(false,kScreenHeight, kScreenWidth/5 *0));
  lanes.emplace_back(Lane(false,kScreenHeight,  kScreenWidth/5 *1));
  lanes.emplace_back(Lane(true,kScreenHeight,  kScreenWidth/5 *2));
  lanes.emplace_back(Lane(true,kScreenHeight,  kScreenWidth/5 *3));
  lanes.emplace_back(Lane(true,kScreenHeight,  kScreenWidth/5 *4));

  redCar = RedCar(kScreenWidth);
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

    // Diffficulty increase
    if (redCar.alive){
      upLevel();
    }

    //Render
    renderer.Render(redCar, lanes);

    //Update vehicle in lanes and remove those that exit
    if (redCar.alive){
      for (auto &lane : lanes){
        lane.updatePositions();
        lane.removeVehicles();
      }
    }

    frame_end = SDL_GetTicks();

    // Keep track of how long each loop through the input/update/render cycle
    // takes.
    frame_count++;
    frame_duration = frame_end - frame_start;

    // After every second, update the window title.
    if (frame_end - title_timestamp >= 1000) {
      renderer.UpdateWindowTitle(redCar.distance, frame_count);
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

void Game::upLevel(){
  int i = 0;
  if (redCar.distance %5 != 4){
    return;
  }
  while(i < addedLanes){
    if (rollVehicles(engine) < PaddVehicle){
      auto laneIndex = rollLanes(engine)-1;
      if (laneIndex == lastAdded){
        laneIndex = (lastAdded +1)%5;
      }
      lanes[laneIndex].addVehicle(getType());
      lastAdded = laneIndex;
    }
    i++;
  }
  if (redCar.distance % 300 == 299){
    if (PaddVehicle < 300){
      std::cout << "increasing probability of adding a new car\n";
      PaddVehicle++;
    }
  }
  if (redCar.distance > 1000){
    if (addedLanes == 2){
      std::cout << "increasing lanes\n";
      addedLanes++;
    }
  }
  if (redCar.distance % 500 == 499){
    if (Ptypes['T'] < 3){
      std::cout << "increasing p of truck\n";
      Ptypes['T']++;
    }
    if (Ptypes['G'] < 5){
      std::cout << "increasing p of garbage\n";
      Ptypes['G']++;
    }
  }
}

Type Game::getType(){
  auto p = rollTypes(engine);
  if(p < Ptypes['T']){
    return truck;
  }
  else if(p < Ptypes['G']){
    return gTruck;
  }
  else{
    return blue;
  }
}
