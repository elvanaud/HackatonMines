#ifndef GAME_HPP
#define GAME_HPP

#include <vector>
#include <string>

struct Vect2{
    int x;
    int y;
    bool est_egal(Vect2 v)
    {
        return (this->x == v.x) && (this->y == v.y);
    }
};

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
  
  GridType background;

  void attack_enemy();
  
  Vect2 pos{};
  Vect2 dir{};
};

#endif