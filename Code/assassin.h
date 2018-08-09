#ifndef ASSASSIN_H
#define ASSASSIN_H

#include <QString>
#include "Personnage.h"

class Assassin : public Personnage  // vitesse importante et defence nul
{

public:
    Assassin();
    Assassin(QString nom);
    void lancerdedague(Personnage &cible); //attack
    void arrachecoeur(Personnage &cible); //attack
    void boost(Personnage &cible); // up attack
    void assassina(Personnage &cible); //attack et si v.cible < v_perso : (30+ 1 ts les 2 lvl) % de tuer
    void lameduserpent(Personnage &cible); // attack sur

private:
    void (Assassin::*attack1)(Personnage &cible);
    void (Assassin::*attack2)(Personnage &cible);

};

#endif // ASSASSIN_H
