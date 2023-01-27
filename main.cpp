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

void maj_pos(const int x,const int y,std::vector<std::vector<char>>& frame){
    int lx = frame.size();
    int ly = frame[0].size();
    /*if(frame[x][y]=='-' || frame[x][y]=='|' || frame[x][y]==' '){
        
    }*/
    frame[x][y]='@';
}
void update_dir(int x, int y){
    char key;
    if( internal::keyEvent() ){
        key = internal::getch();
    }
    switch( key ){
        case  'q' :
            x--;
            break;
        case  'd':
            x++;
            break;
        case 'z':
            y++;
            break;
        case 's':
            y--;
            break;
    }


    
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



