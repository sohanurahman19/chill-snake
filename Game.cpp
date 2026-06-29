#include "Game.hpp"

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
     if(SDL_Init(SDL_INIT_VIDEO) == false) return false;
     window = SDL_CreateWindow("Chill Game", config::screen_width, config::screen_height, 0);
     if(window == nullptr) return false;
     painter = SDL_CreateRenderer(window, nullptr);
     if(painter == nullptr) return false;
     is_running = true;
     return true;
}

void game::run(){
     SDL_Event event;
     while(is_running){
          while(SDL_PollEvent(&event)){
               handle_input(event);
               if(event.type == SDL_EVENT_QUIT){
                    is_running = false;
               }
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

void game::update(){
     python.move();

     pos head = python.get_head();
     auto body = python.get_body();
     for(int i = 1; i < body.size(); i++){
          if(head == body[i]){
               SDL_Log("Game Over!");
               is_running = false;
               break;
          }
     }

     if(fish.get_current_pos() == python.get_head()){
          python.grow();
          fish.re_spawn(python);
     }
}

void game::paint(){
     float grid_si = (float)config::grid_size;
     SDL_SetRenderDrawColor(painter, 0, 0, 0, 255);
     SDL_RenderClear(painter);

     // drawing the fish (food)
     SDL_SetRenderDrawColor(painter, 255, 0, 0, 255);
     pos fish_pos = fish.get_current_pos();
     SDL_FRect fish_rect = {(float)fish_pos.x, (float)fish_pos.y, grid_si, grid_si};
     SDL_RenderFillRect(painter, &fish_rect);

     // drawing python (the snake)
     SDL_SetRenderDrawColor(painter, 0, 255, 0, 255);
     auto body = python.get_body();
     for(const auto &part : body){
          SDL_FRect part_rect = {(float)part.x, (float)part.y, grid_si, grid_si};
          SDL_RenderFillRect(painter, &part_rect);
     }

     // swapping the front and the back buffer
     SDL_RenderPresent(painter);
}