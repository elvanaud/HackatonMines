#include "Game.hpp"
#include <fstream>
#include <iostream>
#include "internals.h"
#include "display.h"
#include "items.h"
#include <cstdlib>
#include "ennemi.h"
#include <cmath>

#include <SFML/Graphics.hpp>

void Game::processLevel()
{
  levelHeight = background.size();
  
  for(int y = 0; y < levelHeight; y++){
      int currentWidth = background[y].size();
      if(currentWidth >= levelWidth)  levelWidth = currentWidth;
      for(int x = 0; x < currentWidth; x++){
          if(background[y][x]=='@'){
              pos.x=x;
              pos.y=y;
              background[y][x]='.';
          }
          if (background[y][x] == 'Z'){
            Zombie zombie;
            zombie.pos.x = x;
            zombie.pos.y = y;
            zombie.symbol = 'Z';
            background[y][x] = '.';
            ennemis.push_back(zombie);
          }
          if (background[y][x] == 'K'){
            Kombie kombie;
            kombie.pos.x = x;
            kombie.pos.y = y;
            kombie.symbol = 'K';
            background[y][x] = '.';
            ennemis.push_back(kombie);
            
          }
      }
  }
}

GridType Game::read_level(const std::string &filename)
{
  GridType bg;
  std::vector<char> line;
  char ch;
  std::fstream f(filename, std::fstream::in);
  while (f >> std::noskipws >> ch)
  {
    if (ch == '\n')
    {
      bg.push_back(line);
      line.clear();
    }
    else
    {
      line.push_back(ch);
    }
  }
  return bg;
}

Game::Game(const std::string &filename)
{
  background = read_level(filename);
  processLevel();
}

void Game::attack_enemy(){
  int j = pos.x;
  int i = pos.y;
  
  /*if(background.at(i-1).at(j)=='K' || background.at(i-1).at(j)=='Z'){
    background[i-1][j]='.';
  }
  else if (background.at(i+1).at(j)=='K' || background.at(i+1).at(j)=='Z'){
    background[i+1][j]='.';
  }
  else if (background.at(i).at(j-1)=='K' || background.at(i).at(j-1)=='Z'){
    background[i][j-1]='.';
  }
  else if (background.at(i).at(j+1)=='K' || background.at(i).at(j+1)=='Z'){
    background[i][j+1]='.';
  }*/

  int removeEnemy = -1;
  for(int i = 0; i < ennemis.size(); i++)
  {
    Ennemi e = ennemis[i];
    int dist = std::pow(pos.x - e.pos.x,2)+std::pow(pos.y - e.pos.y,2);
    if(dist == 1)
    {
      removeEnemy = i;
      break;
    }
  }
  if(removeEnemy != -1)
  {
    ennemis.erase(ennemis.begin() + removeEnemy);
  }
  
};

void Game::drink_lifepotion(){
  if(inv.life<5 && inv.life_potions>0){
    inv.life++;
    inv.life_potions--;
  }
}

void Game::update_dir(char key)
{
  dir.x = dir.y = 0;
  switch (key)
  {
  case 'q':
    dir.x = -1;
    break;
  case 'd':
    dir.x = +1;
    break;
  case 's':
    dir.y = +1;
    break;
  case 'z':
    dir.y = -1;
    break;
  case ' ':
    attack_enemy();
    break;
  case 'p':
    drink_lifepotion();
  
  }
}



Vect2 update_wall_colision(Vect2 pos, Vect2 dir, const GridType &background)
{
  Vect2 newpos;
  newpos.x = pos.x + dir.x;
  newpos.y = pos.y + dir.y;

  try
  {
    char cell = background.at(newpos.y).at(newpos.x);
    switch (cell)
    {
    case '-':
    case '|':
    case ' ':
      return pos;
    default:;
    }
    return newpos;
  }
  catch (std::exception &e)
  {
    return pos;
  }
}

GridType Game::generate_frame(){
    GridType screen = background;
    try{
        screen.at(pos.y).at(pos.x)='@';
        for (auto ennemi: ennemis){
          char symbol = ennemi.symbol;
          screen.at(ennemi.pos.y).at(ennemi.pos.x) = symbol;
        }
        return screen;
    }
    catch(std::exception & e){
        return background;
    }
}

void display(const GridType &background)
{
  for (auto &line : background)
  {
    for (char c : line)
      std::cout << c;
    std::cout << std::endl;
  }
}
void Game::startGame()
{
  bool win = false;
 // while (life>0 && win ==false)
  //Inventaire inv;
  int lap = 200;

  //while (inv.life>0 && win ==false)
  sf::RenderWindow app(sf::VideoMode(600,600,32), "Donjon");
  while(app.isOpen())
  {
    //internal::frameSleep(lap);
    Vect2 oldpos = pos;
    char key;
    /*if (internal::keyEvent())
    {
      char key = internal::getch();

      update_dir(key);
      pos = update_wall_colision(pos, dir, background);
    }*/
    sf::Event e;
    while(app.pollEvent(e))
    {
      switch(e.type)
      {
      case sf::Event::Closed: 
        app.close();
        break;
      case sf::Event::TextEntered:
        key = (char) e.text.unicode;
        update_dir(key);
        pos = update_wall_colision(pos, dir, background);
        break;
        default:;
      }
    }
    
    try{
    switch (background.at(pos.y).at(pos.x))
    {
    case '*':
      background[pos.y][pos.x] = '.';
      inv.gold+=1;
      break;
    case 'j': // Potion
      inv.life_potions+=1;
      background[pos.y][pos.x] = '.';
      break;
    case '=':
      win=true;
      break;
    }}catch(std::exception & e) {}

    for(auto vilain : ennemis){
      if(pos.x==vilain.pos.x && pos.y ==vilain.pos.y){
        inv.life-=1;
        pos=oldpos;
      }
    }

    auto screen = generate_frame();
    //backgroundClear();
    //display(screen);

    //inv.printInventaire();
    /*std::cout << "$ = " << inv.gold << std::endl;
    std::cout << "life = " << inv.life << std::endl;
    std::cout << "life potions = " << inv.life_potions << std::endl;*/

    app.clear(sf::Color(170,185,185));
    sf::RectangleShape tile(sf::Vector2f(16,16));
    for(int y = 0; y < screen.size(); y++)
    {
      for(int x = 0; x < screen[y].size(); x++)
      {
        switch(screen[y][x])
        {
          case ' ': 
            tile.setFillColor(sf::Color(170,185,185)); break;
          case '|':
          case '-':
            tile.setFillColor(sf::Color::Red);
            break;
          case '*': 
            tile.setFillColor(sf::Color::Yellow); break;
          case 'K':
            tile.setFillColor(sf::Color(50,200,120)); break;
          case '@':
            tile.setFillColor(sf::Color::Black); break;
          case 'j':
            tile.setFillColor(sf::Color(200,120,120)); break;
          default:
            tile.setFillColor(sf::Color::White); break;
        }
        tile.setPosition(x*16,y*16);
        app.draw(tile);
      }
    }
    
    
    //tile.setFillColor(sf::Color::Black);
    //tile.setPosition(pos.x*16, pos.y*16);
    //app.draw(tile);
    app.display();

    
  }
  
  std::cout<<';'<<std::endl;
  if(win){
    std::cout<< "YOU WIN"<<std::endl;
  }
  else{
  std::cout<< "GAME OVER"<<std::endl;
  }
}