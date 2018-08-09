#ifndef MAGICIEN_H
#define MAGICIEN_H

#include <QString>
#include "Personnage.h"

class Magicien : public Personnage   // doit avoir des stat minable mais des attack forte pour reequilibrer
{

public:
    Magicien();
    Magicien(QString nom);
    void briseregeneratrice(Personnage &cible); // soin que pour lui //air
    void caressedelocean(Personnage &cible); // attack //eau
    void braiseincandescente(Personnage &cible); //attack et 70% de bruler //feu
    void tremblementdeterre(Personnage &cible); // attack et 20% d'etourdir et donc de passer leur tour //terre
    void briseroche(Personnage &cible); // attack //metal
    void attaquer(int a,Personnage &cible);

private:
    void (Magicien::*attack1)(Personnage &cible) = &Magicien::briseregeneratrice;
    void (Magicien::*attack2)(Personnage &cible) = &Magicien::caressedelocean;


};

#endif // MAGICIEN_H
