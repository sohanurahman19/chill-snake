#pragma once
#include "Location.hpp"

class food{
private:
     pos current_pos;
     int randomIntegerRange = 10000000;
     pos get_random_pos();
public:
     food(snake &python);
     void re_spawn(const snake &current_snake);
     pos get_current_pos(){
          return current_pos;
     }
};