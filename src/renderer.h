#ifndef RENDERER_H
#define RENDERER_H

#include <vector>
#include "SDL.h"
#ifndef __INTELLISENSE__
#include "SDL2_image/SDL_image.h"
#endif

class Renderer {
    public:
    Renderer(const std::size_t screen_width, const std::size_t screen_height,
             const std::size_t grid_width, const std::size_t grid_height);
    ~Renderer();

    void Render();

    void UpdateWindowTitle(int distance, int fps);

    void VerticalDottedLine(int start_x);

    private:
    SDL_Window *sdl_window;
    SDL_Renderer *sdl_renderer;
    SDL_Texture *redCar;

    const std::size_t screen_width;
    const std::size_t screen_height;
    const std::size_t grid_width;
    const std::size_t grid_height;
};

#endif