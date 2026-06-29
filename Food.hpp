#pragma once
#include "Location.hpp"

class food{
private:
     pos current_pos;
     int randomIntegerRange = 10000000;
     int get_random();
public:
     food();
     void re_spawn();
     pos get_current_pos(){
          return current_pos;
     }
};