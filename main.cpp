#include "stdlib.h"

#include "internals.h"


#include "Game.hpp"


int main(){
    /*std::string prefix ="../levels/level";
    std::string sufix = ".txt";*/
    
    std::string filename ="../levels/level0.txt";
    Game game0=Game(filename);
    game0.startGame();

    /*filename="../levels/level1.txt";
    Game game1 = Game(filename);
    game1.startGame();

    filename="../levels/level2.txt";
    Game game2 = Game(filename);
    game2.startGame();

    filename = "../levels/level3.txt";
    Game game3 = Game(filename);
    game3.startGame();

    filename="../levels/level4.txt";
    Game game4 = Game(filename);
    game4.startGame();*/



    
    
   return 0;
}

