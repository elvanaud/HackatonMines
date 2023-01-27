#pragma once
#include <iostream>
#include <vector>

 
struct Vect2{
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
    unsigned int life;
    unsigned int strength;
    unsigned int vitesse;

    public :

    void Deplacement(){ }

    Vect2 pos;
};

class Zombie : public Ennemi
{
    unsigned int strength = 1;
    unsigned int life = 2;
    unsigned int vitesse = 1;

    Vect2 pos;
    };



class Kombie : public Ennemi
{
    unsigned int strength = 2;
    unsigned int life = 4;
    unsigned int vitesse = 1;

    Vect2 pos;

};

