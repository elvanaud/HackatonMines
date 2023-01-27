#include "stdlib.h"

#include "internals.h"


#include "Game.hpp"


int main(){
    std::string filename = "../levels/level0.txt";
    
    Game game(filename);
    game.startGame();
   return 0;
}

