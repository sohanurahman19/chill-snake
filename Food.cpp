#include <SDL3/SDL.h>
#include "Snake.hpp"
#include "Game.hpp"
#include "Food.hpp"
#include "Config.hpp"

food::food(snake &python){
     re_spawn(python);
}

void food::re_spawn(const snake &current_snake){
     auto body = current_snake.get_body();
     bool invalid = true;
     while(invalid){
          pos new_pos = get_random_pos();
          bool collision = false;
          for(const auto &part : body){
               if(part == new_pos){
                    collision = true;
                    break;
               }
          }
          if(!collision){
               current_pos = new_pos;
               invalid = false;
          }
     }
}


pos food::get_random_pos(){
     int unit_x = config::screen_width / config::grid_size;
     int unit_y = config::screen_height / config::grid_size;
     current_pos.x = (SDL_rand(randomIntegerRange) % unit_x) * config::grid_size;
     current_pos.y = (SDL_rand(randomIntegerRange) % unit_y) * config::grid_size;
     return {current_pos.x, current_pos.y};
}