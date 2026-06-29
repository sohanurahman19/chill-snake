#include "Game.hpp"
#include <SDL3/SDL_main.h>



int main(int argc, char *argv[]){
     game chill_snake;
     if(chill_snake.init()){
          chill_snake.run();
     }else{
          SDL_Log("init failed! %s", SDL_GetError());
          return 1;
     }
     return 0;
}