// Code à ranger à la fin

// Génération random d'items à faire à la fin si on a le temps
#pragma once
#include <string>
#include <vector>
#include <map>
#include <iostream>
 
 #include "Vect2.hpp"

class Inventaire
{ // Proposition : accéder aux potions de vie par une certaine touche, force par une autre, et 
// Afficher quelque part sur l'écran le nombre de chaque potion en temps réel.
    public:
    void change_life(int increment)
    { // L'incrément est algébrique
        this->life += increment;
    }
    void game_over()
    {
        if(this->life <= 0)
        {
            // Commande de fin du jeu
            std::cout << "Game Over...";
        }
    }

    unsigned int life_max = 5; // Vie maximale du héros 
    unsigned int life = 5; // Vie actuelle du héros
    unsigned int gold = 0; // Quantité d'or sur le héros
    unsigned int strength = 1; // Force du héros
    unsigned int life_potions = 0;
    unsigned int potions_force = 0;
    // 0 : n'a pas ; 1 : a
    unsigned int casque = 0;
    unsigned int armure = 0;
    unsigned int epee = 0;
    unsigned int bouclier = 0;
    std::string weapon = ""; // Nom de l'arme
    std::string armor = ""; // Nom de l'armure

    void printInventaire();
};

class Gold
{
    public:
    Gold(const unsigned int& a) : amount(a) {}
    int get_amount()
    {
        return this->amount;
    }
    void store(Inventaire inv)
    {
        int a = this->get_amount();
        inv.gold += a;
    }
    void take(Vect2 pos, Inventaire inv)
    {
        if( pos.est_egal(this->coord) )
        { // coordonnées joueur == coordonnées Item
            store(inv);
        }
    }
    Vect2 coord;
    private:
    unsigned int amount;
};

class Potion
{
    public:
    Potion(const int& n) : type(n) {}
    void store(Inventaire inv)
    {
        int n = this->type;
        if(n==0)
        { // Potion de vie
            inv.life_potions += 1;
        }
        else if(n==1)
        { // Potion de force
            inv.potions_force += 1;
        }
    }
    void take(Vect2 pos, Inventaire inv)
    {
        if( pos.est_egal(this->coord) )
        { // coordonnées joueur == coordonnées Item
            store(inv);
        }
    }
    int type; // 0 : vie, 1 : force
    Vect2 coord;
};


const std::map<short unsigned int, std::string> potion_type = {{0, "life"}, {1, "strenght"}};