#ifndef TANK_H
#define TANK_H

#include <QString>
#include "Personnage.h"

class Tank : public Personnage  //defence tres importante et seul attack moins puissante que la moyenne
{

public:
    Tank();
    Tank(QString nom);
    void dernierrempart(Personnage &cible); // les ennemis sont obliger d'attaquer le tank
    void protectiondivine(Personnage &cible); // up defence
    void epeesacre(Personnage &cible); // attack
    void chargedubouclier(Personnage &cible); // attack
    void transfertvitale(Personnage &cible); // donne des pv aux allie et subi des degat

private:
    void (Tank::*attack1)(Personnage &cible);
    void (Tank::*attack2)(Personnage &cible);

};

#endif // TANK_H
