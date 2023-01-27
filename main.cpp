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

void maj_pos(Vect2 pos,std::vector<std::vector<char>>& frame){
    /*if(frame[x][y]=='-' || frame[x][y]=='|' || frame[x][y]==' '){
        
    }*/
    frame[pos.x][pos.y]='@';
}
Vect2 update_wall_colision(Vect2 pos,Vect2 dir,std::vector<std::vector<char>>& frame){
    Vect2 newpos;
    newpos.x =pos.x+dir.x;
    newpos.y=pos.y+dir.y;
    switch(frame[newpos.x][newpos.y]){
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

void update_dir(Vect2& dir ,Vect2 pos,std::vector<std::vector<char>> frame){
    char key;
    if( internal::keyEvent() ){
        key = internal::getch();
    }
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
    pos = update_wall_colision(pos,dir,frame);

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

int main(){
    std::string filename = "../levels/level0.txt";
    GridType background = read_level(filename);

    display(background);
    
   return 0;
}

