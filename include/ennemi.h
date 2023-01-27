#pragma once
#include <iostream>
#include <vector>
#include "items.h"
#include "Vect2.hpp"

class Ennemi
{
    protected :
    unsigned int life;
    unsigned int strength;
    unsigned int vitesse;

    public :

    void Deplacement(){ }

    Vect2 pos{};
    char symbol;
};

class Zombie : public Ennemi
{
    public:
    unsigned int strength = 1;
    unsigned int life = 2;
    unsigned int vitesse = 1;
};



class Kombie : public Ennemi
{
    public:
    unsigned int strength = 2;
    unsigned int life = 4;
    unsigned int vitesse = 1;

};

