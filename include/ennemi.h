#pragma once
#include <iostream>
#include <vector>

struct Vect2{ // Volé au main mais amélioré
    int x;
    int y;
    bool est_egal(Vect2 v)
    {
        return (this->x == v.x) && (this->y == v.y);
    }
};


class Ennemi
{
    protected :
    

    public :


    Vect2 pos;
};

class Zombie : public Ennemi
{
    unsigned int strength = 1;

};



class Kombie : public Ennemi
{

};