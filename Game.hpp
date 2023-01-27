#ifndef GAME_HPP
#define GAME_HPP

struct Vect2{
    int x;
    int y;

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
  
  GridType background;
  
  Vect2 pos{};
  Vect2 dir{};
};

#endif