#include <iostream>
#include "controller.h"
#include "game.h"
#include "renderer.h"

int main(){
    constexpr std::size_t kFramesPerSecond{60};
    constexpr std::size_t kMsperFrame{1000 / kFramesPerSecond};
    constexpr std::size_t kScreenWidth{640};
    constexpr std::size_t kScreenHeight{640};
    constexpr std::size_t kGridWidth{32};
    constexpr std::size_t kGridHeight{32};

    Controller controller;
    Game game;
    Renderer renderer(kScreenWidth, kScreenHeight, kGridWidth, kGridHeight);
    game.Run(controller, renderer, kMsperFrame);
    std::cout << "RED CAR GAME !!!!!\n";
}