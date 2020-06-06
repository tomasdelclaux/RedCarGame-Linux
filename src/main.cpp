#include <iostream>
#include "controller.h"
#include "game.h"
#include "renderer.h"

int main(){
    constexpr std::size_t kFramesPerSecond{60};
    constexpr std::size_t kMsperFrame{1000 / kFramesPerSecond};
    constexpr std::size_t kScreenWidth{640};
    constexpr std::size_t kScreenHeight{800};

    Controller controller;
    Game game(kScreenHeight);
    Renderer renderer(kScreenWidth, kScreenHeight);
    game.Run(controller, renderer, kMsperFrame);
    std::cout << "RED CAR GAME !!!!!\n";
}