#include "Snake.hpp"

snake::snake(){
     direction_vector = {config::grid_size, 0};
     int middle_row = config::total_row / 2;
     body.push_back({5 * config::grid_size, middle_row});
     body.push_back({6 * config::grid_size, middle_row});
     body.push_back({7 * config::grid_size, middle_row});
}

void snake::move(){
     pos new_head = {
                    (body.front().x + direction_vector.x + config::screen_width) % config::screen_width,
                    (body.front().y + direction_vector.y + config::screen_height) % config::screen_height,

     };
     body.push_front(new_head);
     if(grow_pending > 0){
          grow_pending--;
     }else{
          body.pop_back();
     }
}

void snake::set_direction(pos new_dir){
     direction_vector = new_dir;
}

void snake::grow(){
     grow_pending++;
}