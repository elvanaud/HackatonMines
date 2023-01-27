// Code à ranger à la fin

// Génération random d'items à faire à la fin si on a le temps

#include <string>
#include <vector>
#include <map>

class Inventaire
{ // Proposition : accéder aux potions de vie par une certaine touche, force par une autre, et 
// Afficher quelque part sur l'écran le nombre de chaque potion en temps réel.
    public:
    /*
    Ouvrir l'inventaire, sélectionner un objet ou quitter, utiliser l'objet
    */

    unsigned int life_max; // Vie maximale du héros 
    unsigned int life; // Vie actuelle du héros
    unsigned int gold; // Quantité d'or sur le héros
    unsigned int strength; // Force du héros
    unsigned int potions_vie;
    unsigned int potions_force;
};

class Item
{

    public:
    /*
    Prendre l'item
    */
    void take(Item i);

    std::string name;
    std::pair<int,int> coord;
};

class Gold : public Item
{
    public:
    Gold(const unsigned int& a) : amount(a) {};
    int get_amount()
    {
        return this->amount;
    }
    void store(Inventaire inv)
    {
        int a = this->get_amount();
        inv.gold += a;
    }
    private:
    unsigned int amount;
};

class Potion : public Item
{
    void store(Inventaire inv)
    {
        int n = this->type;
        if(n==0)
        { // Potion de vie
            inv.potions_vie += 1;
        }
        else if(n==1)
        { // Potion de force
            inv.potions_force += 1;
        }
    }
    int type; // 0 : vie, 1 : force
};


// Classe Inventaire



// Classe Item

void Item::take(Item i)
{
    if(/*coordonnées joueur == coordonnées Item*/ 0)
    {
        // Ranger l'item dans l'inventaire
    }
}



// Classe Gold



// Classe Potion

const std::map<short unsigned int, std::string> potion_type = {{0, "life"}, {1, "strenght"}};