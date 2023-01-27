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

