#include "renderer.h"
#include <iostream>
#include <string>

//Constructor
Renderer::Renderer(const std::size_t screen_width,
                   const std::size_t screen_height,
                   const std::size_t grid_width, const std::size_t grid_height)
    : screen_width(screen_width),
        screen_height(screen_height),
        grid_width(grid_width),
        grid_height(grid_height) {
    
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
    redCar = IMG_LoadTexture(sdl_renderer, "../assets/redCar.png");

    // SDL_Surface *sdl_surface = SDL_GetWindowSurface(sdl_window);

    // if(!sdl_surface)
    // {
    //     std::cout<<"Failed to get the surface from the window\n";
    //     std::cerr<<"SDL2 Error: " << SDL_GetError() << "\n";
    // }

    // SDL_UpdateWindowSurface(sdl_window);
    SDL_Delay(1000);
}

//Destructor
Renderer::~Renderer() {
  SDL_DestroyWindow(sdl_window);
  SDL_Quit();
}

void Renderer::Render(RedCar &redCar, std::vector<Lane> &lanes){
    SDL_Rect block;
    block.w = screen_width / grid_width;
    block.h = screen_height / grid_height;

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


    //Vehicle Animation
    SDL_Rect animation;
    animation.x = 150;
    animation.y = 150;
    animation.w = 90;
    animation.h = 90;
    SDL_RenderCopy(sdl_renderer, redCar, NULL, &animation);
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