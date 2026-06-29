#include <SDL3/SDL.h>
#include "Food.hpp"
#include "Config.hpp"

food::food(){
     re_spawn();
}

void food::re_spawn(){
     int unit_x = config::screen_width / config::grid_size;
     int unit_y = config::screen_height / config::grid_size;
     current_pos.x = (get_random() % unit_x) * config::grid_size;
     current_pos.y = (get_random() % unit_y) * config::grid_size;
}


int food::get_random(){
     return SDL_rand(randomIntegerRange);
}