#pragma once
#include <game.hpp>

game::game() : painter(nullptr), window(nullptr) { };
game::~game(){
     if(window != nullptr){
          SDL_DestroyWindow(window);
     }
     if(painter != nullptr){
          SDL_DestroyRenderer(painter);
     }
     SDL_Quit();
}

bool game::init(){
     if(SDL_Init(SDL_INIT_VIDEO) != 0) return false;
     window = SDL_CreateWindow("Chill Game", config::screen_width, config::screen_height, 0);
     if(window == nullptr) return false;
     painter = SDL_CreateRenderer(window, nullptr);
     if(painter == nullptr) return false;
     return true;
}