#ifndef Pretre_H
#define Pretre_H

#include <QString>
#include "Personnage.h"

class Pretre : public Personnage   //attack et defence nul mais la seul attack est puissance mais pas autant que le mage
{

public:
    Pretre();
    Pretre(QString nom);
    void benedictiondivine(Personnage &cible); // soin
    void attaquedivine(Personnage &cible); //attack
    void aidemiracle(Personnage &cible); // up defence,vitesse et attaque pour perso avec vie <50%
    void purification(Personnage &cible); //enleve les effects de poison, de feu ...
    void reveildumort(Personnage &cible); // ressucite 1 joueur

private:
    void (Pretre::*attack1)(Personnage &cible);
    void (Pretre::*attack2)(Personnage &cible);

};

#endif // Pretre_H
