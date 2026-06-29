#pragma once
#include <SDL3/SDL.h>
#include <Snake.hpp>
#include <Food.hpp>

class game{
private:
     SDL_Window* window;
     SDL_Renderer* painter;
     snake python;
     food fish;

     void handle_input();
     void update();
     void paint();
public:
     game();
     ~game();
     bool init();
     void run();
};