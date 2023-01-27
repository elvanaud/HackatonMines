#pragma once
#include <iostream>
#include <vector>
#include "items.h"

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

