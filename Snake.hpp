#pragma once
#include <deque>
#include "Location.hpp"
#include "Config.hpp"

class snake{
private:
     std::deque<pos> body;
     pos direction_vector;
     int grow_pending = 0;
public:
     snake();
     void move();
     void grow();
     void set_direction(pos new_pos);
     const std::deque<pos> get_body() const{
          return body;
     }
     const pos get_head() const {
          return body.front();
     }
};