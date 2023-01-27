#include <iostream>
#include <vector>
#include <fstream>
#include <deque>
#include <utility>
#include <ctime>
#include "stdlib.h"

#include "internals.h"
#include "display.h"

struct Vect2{
    int x;
    int y;

};
using GridType = std::vector<std::vector<char>>;

Vect2 update_wall_colision(Vect2 pos,Vect2 dir,const GridType& background){
    Vect2 newpos;
    newpos.x = pos.x + dir.x;
    newpos.y = pos.y + dir.y;

    try{
      char cell = background.at(newpos.y).at(newpos.x);
      switch(cell){
        case '-':
        case '|':
        case ' ':
            return pos;
        default: ;
      }
      return newpos;
    }
    catch(std::exception & e)
    {
      return pos;
    }
}

void update_dir(char key, Vect2& dir){
    dir.x = dir.y = 0;
    switch( key ){
        case  'q' :
            dir.x=-1;
            break;
        case  'd':
            dir.x=+1;
            break;
        case 's':
            dir.y=+1;
            break;
        case 'z':
            dir.y=-1;
            break;
    }
}
 
GridType read_level(const std::string& filename){
  GridType background;
  std::vector<char> line;
  char ch;
  std::fstream f(filename, std::fstream::in);
  while (f >> std::noskipws >> ch){
    if (ch == '\n'){
      background.push_back(line);
      line.clear();
    }
    else{
      line.push_back(ch);
    }
  }
  return background;
}

void display(const GridType& background){
  for(auto & line : background)
  {
    for(char c : line)
      std::cout << c;
    std::cout << std::endl;
  }
}
GridType generate_frame(Vect2 pos,const GridType& background){
    GridType screen = background;
    try{
        screen.at(pos.y).at(pos.x)='@';
        return screen;
    }
    catch(std::exception & e){
        return background;
    }
}
void startGame(const std::string& filename){
    GridType background = read_level(filename);
    
    int lap = 200;
    Vect2 pos{};
    Vect2 dir{};
    
    bool player_not_found=true;
    for(int y = 0; player_not_found && y<background.size();y++){
        for(int x = 0;player_not_found && x<background[y].size();x++){
            if(background[y][x]=='@'){
                player_not_found=false;
                pos.x=x;
                pos.y=y;
                background[y][x]='.';
            }
        }
    }


    while( true )
    {
        if(internal::keyEvent())
        {
          char key = internal::getch();
          update_dir(key, dir);
          pos = update_wall_colision(pos,dir,background);
          
        }
        
        
        //update_dir(dir,pos,background);
        auto screen=generate_frame(pos,background);
        backgroundClear();
        display(screen);
        internal::frameSleep(lap);
    }

}

int main(){
    std::string filename = "../levels/level0.txt";
    startGame(filename);
   return 0;
}

