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

void game::run(){
     bool is_running = true;
     SDL_Event event;
     while(is_running){
          while(SDL_PollEvent(&event)){
               handle_input(event);
          }
          update();
          paint();
          SDL_Delay(delay);
     }
}

void game::handle_input(SDL_Event &event){
     if(event.type == SDL_EVENT_KEY_DOWN){
          switch(event.key.key){
               case SDLK_UP : python.set_direction({0, -config::grid_size}); break;
               case SDLK_DOWN : python.set_direction({0, config::grid_size}); break;
               case SDLK_RIGHT : python.set_direction({config::grid_size, 0}); break;
               case SDLK_LEFT : python.set_direction({-config::grid_size, 0}); break;
          }
     }
}