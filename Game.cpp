#pragma once
#include <game.hpp>

bool game::init(){
     if(SDL_Init(SDL_INIT_VIDEO) != 0) return false;
     window = SDL_CreateWindow("Chill Game", config::screen_width, config::screen_height, 0);
     if(window == nullptr) return false;
     painter = SDL_CreateRenderer(window, nullptr);
     if(painter == nullptr) return false;
     return true;
}