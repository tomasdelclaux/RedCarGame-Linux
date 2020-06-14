#include "renderer.h"
#include <iostream>
#include <string>

//Constructor
Renderer::Renderer(const std::size_t screen_width,
                   const std::size_t screen_height)
    : screen_width(screen_width),
        screen_height(screen_height){
    
    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "SDL could not initialize.\n";
        std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
    }

    // Create Window
    sdl_window = SDL_CreateWindow("Red Car Game", SDL_WINDOWPOS_CENTERED,
                                SDL_WINDOWPOS_CENTERED, screen_width,
                                screen_height, SDL_WINDOW_SHOWN);

    if (nullptr == sdl_window) {
        std::cerr << "Window could not be created.\n";
        std::cerr << " SDL_Error: " << SDL_GetError() << "\n";
    }

    // Create renderer
    sdl_renderer = SDL_CreateRenderer(sdl_window, -1, SDL_RENDERER_ACCELERATED);
    if (nullptr == sdl_renderer) {
        std::cerr << "Renderer could not be created.\n";
        std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
    }

    //Initialize PNG loading
    if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG)){
        std::cout << "SDL_image could not initialize.\n";
        std::cerr << IMG_GetError() << "\n";
    }

    textures[red]=IMG_LoadTexture(sdl_renderer, "../assets/redCar.png");
    textures[blue]=IMG_LoadTexture(sdl_renderer,"../assets/blueCar.png");
    textures[truck]=IMG_LoadTexture(sdl_renderer,"../assets/bigTruck.png");
    textures[gTruck]=IMG_LoadTexture(sdl_renderer,"../assets/garbageTruck.png");

}

//Destructor
Renderer::~Renderer() {
  SDL_DestroyTexture(textures[red]);
  SDL_DestroyTexture(textures[blue]);
  SDL_DestroyTexture(textures[truck]);
  SDL_DestroyTexture(textures[gTruck]);
  SDL_DestroyWindow(sdl_window);
  SDL_Quit();
}

void Renderer::Render(RedCar &redCar, std::vector<Lane> &lanes){

    //Clear Screen
    SDL_SetRenderDrawColor(sdl_renderer, 0, 12, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(sdl_renderer);

    //Draw the Roads
    SDL_SetRenderDrawColor(sdl_renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
    SDL_Rect r1;
    r1.x = 256;
    r1.y = 0;
    r1.w = 5;
    r1.h = 800;
    
    SDL_RenderFillRect(sdl_renderer, &r1);
    VerticalDottedLine(128);
    VerticalDottedLine(384);
    VerticalDottedLine(512);


    //RedCar
    SDL_Rect animation;
    redCar.Update();
    animation.x = redCar.x;
    animation.y = redCar.y;
    animation.w = redCar.width();
    animation.h = redCar.height();
    SDL_RenderCopy(sdl_renderer, textures[red], NULL, &animation);


    // Draw vehicles in lanes and check collision
    for (auto &lane : lanes){
        for (auto &vehicle : lane.getVehicles()){
            SDL_Rect obstacle;
            obstacle.x = lane.getLaneRefx() + ((screen_width/5 - vehicle.width())/2);
            obstacle.y = vehicle.y;
            obstacle.w = vehicle.width();
            obstacle.h = vehicle.height();
            SDL_bool collision = SDL_HasIntersection(&obstacle, &animation);
            if (collision == SDL_TRUE){
                redCar.alive = false;
            }
            SDL_RendererFlip flip;
            if (!lane.getDirection()){
                flip = SDL_FLIP_VERTICAL;
            }
            else {
                flip = SDL_FLIP_HORIZONTAL;
            }
            SDL_RenderCopyEx(sdl_renderer, textures[vehicle.getType()], NULL, &obstacle, NULL, NULL, flip);
        }
    }

    SDL_RenderPresent(sdl_renderer);
 }


void Renderer::UpdateWindowTitle(int distance, int fps){
    std::string title{"Distance: " + std::to_string(distance) + "FPS: " + std::to_string(fps)};
    SDL_SetWindowTitle(sdl_window, title.c_str());
}

void Renderer::VerticalDottedLine(int start_x){
    int position_y = 0;
    int dottedWidth = 10;
    int spaceWidth = 5;
    while(position_y < screen_height){
        SDL_RenderDrawLine(sdl_renderer, start_x, position_y, start_x, position_y + dottedWidth);
        position_y += dottedWidth + spaceWidth;
    }
}