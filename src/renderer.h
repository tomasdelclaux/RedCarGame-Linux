#ifndef RENDERER_H
#define RENDERER_H

#include <vector>
#include "SDL.h"
#include "vehicle.h"
#include "lane.h"
#include <map>
#include "SDL_image.h"

class Renderer {
    public:
    Renderer(const std::size_t screen_width, const std::size_t screen_height);
    ~Renderer();

    void Render(RedCar &redCar, std::vector<Lane> &lanes);

    void UpdateWindowTitle(int distance, int fps);

    void VerticalDottedLine(int start_x);

    std::map<Type, SDL_Texture *> textures;

    private:
    SDL_Window *sdl_window;
    SDL_Renderer *sdl_renderer;

    const std::size_t screen_width;
    const std::size_t screen_height;
};

#endif
