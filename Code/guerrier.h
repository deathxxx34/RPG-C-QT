#ifndef GUERRIER_H
#define GUERRIER_H

#include <QString>
#include "Personnage.h"

class Guerrier : public Personnage    // attack et defence un peu plus eleve
{

public:
    Guerrier();
    Guerrier(QString nom);
    void attaqueeclair(Personnage &cible); //attack
    void chargemeurtriere(Personnage &cible); //attack
    void rage(Personnage &cible); //up attack
    void frappeacrobatique(Personnage &cible); //attack
    void lameetdague(Personnage &cible); // attack 2 fois de suite

private:
    void (Guerrier::*attack1)(Personnage &cible);
    void (Guerrier::*attack2)(Personnage &cible);

};

#endif // GUERRIER_H
