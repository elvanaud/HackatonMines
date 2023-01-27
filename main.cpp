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

class Game{

};

using GridType = std::vector<std::vector<char>>;

void startGame(int lap, const int nx, const int ny, std::vector<int> &bg){
    char key;
    while( true ){
        internal::frameSleep(lap);
        if( internal::keyEvent() ){
            key = internal::getch();
        }
        backgroundClear();
        printFrame(nx, ny, bg);
        
        /*bool out =  verifyBorder(snake, nx, ny);
        if( out == false){
            std::cerr << "" << std::endl;
            exit(1);
        }*/
    }
}
Vect2 update_wall_colision(Vect2 pos,Vect2 dir,const GridType& background){
    Vect2 newpos;
    newpos.x =pos.x+dir.x;
    newpos.y=pos.y+dir.y;

    int ly = background.size();
    int lx = background[0].size();
    //if(pos.x<lx && pos.y <ly && pos.x>=0 && pos.y>=0){
    try{
      char cell = background.at(newpos.y).at(newpos.x);
      switch(cell){
        case '-':
            newpos=pos;
            break;
        case '|':
            newpos=pos;
            break;
        case ' ':
            newpos=pos;
            
      }
    return newpos;
    }
    catch(std::exception & e)
    {
      return pos;
    }
    /*}
    else{
        return pos;
    }*/
}



void update_dir(char key, Vect2& dir){
    //char key;
    
    /*if( internal::keyEvent() ){
        key = internal::getch();
    }*/
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
    int ly = background.size();
    int lx = background[0].size();
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
    int coin = 0;
    int life = 5;
    
    int lap = 500;
    Vect2 pos{};
    Vect2 dir{};
    int ly = background.size();
    int lx = background[1].size();
    
    bool player_not_found=true;
    for(int y = 0; player_not_found && y< background.size() ;y++){
        for(int x = 0;player_not_found && x< background[y].size() ;x++){
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
          Vect2 oldpos = pos;
          char key = internal::getch();
          update_dir(key, dir);
          pos = update_wall_colision(pos,dir,background);

          switch(background[pos.y][pos.x]){
            case '*':
                background[pos.y][pos.x]='.';
                coin+=1;
                break;
            case 'K':
                life-=1;
                pos=oldpos;
                

            
          }
          
          auto screen=generate_frame(pos,background);
          backgroundClear();
          display(screen);
          std::cout<< "$ = "<<coin<<std::endl;
          std::cout<< "life = "<<life <<std::endl;
        }
        
        
        //update_dir(dir,pos,background);
        
        //internal::frameSleep(lap);
    }

}

int main(){
    std::string filename = "../levels/level0.txt";
    startGame(filename);
   return 0;
}

