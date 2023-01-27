#ifndef GAME_HPP
#define GAME_HPP

#include <vector>
#include <string>
#include "ennemi.h"

#include "Vect2.hpp"

using GridType = std::vector<std::vector<char>>;

class Game
{
public:
  Game(const std::string& filename);
  void startGame();
private:
  void processLevel();
  void update_dir(char key);
  GridType read_level(const std::string& filename);
  GridType generate_frame();
  
  GridType background{};

  void attack_enemy();
  void drink_lifepotion();
  
  Vect2 pos{};
  Vect2 dir{};
  //int life=5;
  //int life_potions=0;
  Inventaire inv;

  std::vector<Ennemi> ennemis;
};

#endif