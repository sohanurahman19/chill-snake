#include "Food.hpp"
#include "Config.hpp"
#include <cstdlib>

Food::Food(){
     re_spawn();
}

void Food::re_spawn(){
     int unit_x = config::screen_width / config::grid_size;
     int unit_y = config::screen_height / config::grid_size;
     current_pos.x = (rand() % unit_x) * config::grid_size;
     current_pos.y = (rand() & unit_y) * config::grid_size;
}
