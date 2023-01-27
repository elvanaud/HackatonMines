#include "Game.hpp"
#include <fstream>
#include <iostream>
#include "internals.h"
#include "display.h"
#include "items.h"

void Game::processLevel()
{
  bool player_not_found = true;
  for (int y = 0; player_not_found && y < background.size(); y++)
  {
    for (int x = 0; player_not_found && x < background[y].size(); x++)
    {
      if (background[y][x] == '@')
      {
        player_not_found = false;
        pos.x = x;
        pos.y = y;
        background[y][x] = '.';
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
  
  if(background.at(i-1).at(j)=='K' || background.at(i-1).at(j)=='Z'){
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
  }
  
};

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

GridType generate_frame(Vect2 pos, const GridType &background)
{
  GridType screen = background;
  try
  {
    screen.at(pos.y).at(pos.x) = '@';
    return screen;
  }
  catch (std::exception &e)
  {
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
  Inventaire inv;
  int lap = 200;

  while (inv.life>0)
  {
    internal::frameSleep(lap);
    Vect2 oldpos = pos;
    if (internal::keyEvent())
    {
      char key = internal::getch();

      update_dir(key);
      pos = update_wall_colision(pos, dir, background);
    }

    auto screen = generate_frame(pos, background);

    switch (background[pos.y][pos.x])
    {
    case '*':
      background[pos.y][pos.x] = '.';
      inv.gold += 1;
      break;
    case 'K':
      inv.life -= 1;
      pos = oldpos;
      break;
    }

    screen = generate_frame(pos, background);
    backgroundClear();
    display(screen);

    inv.printInventaire()
    // std::cout << "$ = " << inv.gold << std::endl;
    // std::cout << "life = " << inv.life << std::endl;

    
  }
  std::cout<<';'<<std::endl;

  std::cout<< "GAME OVER"<<std::endl;
}