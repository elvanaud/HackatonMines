#include <iostream>
#include <vector>
#include <deque>
#include <utility>
//#include <conio.h>
#include <ctime>
//#include "sys/ioctl.h"

#include "stdlib.h"

#include "internals.h"
#include "display.h"
#include "food.h"
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


struct Vect2{
    int x;
    int y;

};

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

std::vector<int> backgroundSetup( const int& nx, const int& ny ){
  std::vector<int> bg(nx*ny, 0);
  int i;
  for( i=0; i<nx; i++){
      bg[i] = 1;
  }
  for( i=0; i<nx; i++){
      bg[(ny-1)*nx + i] = 1;
  }
  for( i=0; i<ny; i++){
      bg[i*nx] = 1;
  }
  for( i=0; i<ny; i++){
      bg[i*nx+nx-1] = 1;
  }


  return bg; 
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



int main(){
    const int nx = 50;
    const int ny = 25;
    const int lap=200;//200
    srand(time(nullptr));
    
    std::vector<int> background = backgroundSetup(nx, ny);
    printFrame(nx,ny, background);

    
    startGame(lap, nx, ny, background);
    
   return 0;
}



