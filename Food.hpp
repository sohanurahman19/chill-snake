#pragma once
#include "Location.hpp"

class Food{
private:
     pos current_pos;
public:
     Food();
     void re_spawn();
     pos get_current_pos(){
          return current_pos;
     }
};