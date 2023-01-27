#include <vector>
#include <fstream>
#include <iostream>
#include "../include/items.h"

Inventaire inventaire;

void printInventaire()
{
    unsigned int money = inventaire.gold;
    unsigned int pv = inventaire.life;  // faire attention que les méthodes sont bien les bonnes
    unsigned int life_max = inventaire.life_max;
    std::string weapon = inventaire.weapon;
    std::string armor = inventaire.armor;
    unsigned int potion_vie = inventaire.potions_vie;
    unsigned int potion_force = inventaire.potions_force;
    //std::string strength = inventaire.strength;    

    std::string LifeBar = "";
    for(unsigned int i=0;i<=pv;i++)
    {
        LifeBar + 'o' ;
    }
    for(unsigned int i=0;i<=life_max - pv;i++)
    {
        LifeBar + '-';
    }


    std::cout << "_____________________________" << std::endl ;
    std::cout << " PV : " << LifeBar << std::endl << " * : " << money << std::endl ;
    std::cout << " Armes : " << weapon << std::endl << " Armures : " << armor << std::endl << " Potions   " << "vie : " << potion_vie << "    force : " << potion_force << std::endl ;
    std::cout << "_____________________________" << std::endl ;
 
}
    
