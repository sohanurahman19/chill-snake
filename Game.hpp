#pragma once
#include <SDL3/SDL.h>
#include <Config.hpp>
#include <Snake.hpp>
#include <Food.hpp>

class game{
private:
     SDL_Window* window;
     SDL_Renderer* painter;
     snake python;
     food fish;
     int delay = 100; 
     void handle_input(SDL_Event &event);
     void update();
     void paint();
public:
     game();
     ~game();
     bool init();
     void run();
};