#pragma once
#include "Location.hpp"

class food{
private:
     pos current_pos;
public:
     food();
     void re_spawn();
     pos get_current_pos(){
          return current_pos;
     }
};