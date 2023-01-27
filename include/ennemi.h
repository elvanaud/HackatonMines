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
    ~Ennemi() // Destructeur
    {
        // instruction pour virer le 'K' ou 'Z' de la map
    }
    void Deplacement() {}
    void subir_degat(Inventaire inv)
    {
        this->life -= inv.strength;
        if(this->life <= 0)
        {
            
        }
    }

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

