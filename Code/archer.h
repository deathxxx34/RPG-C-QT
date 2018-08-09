#ifndef ARCHER_H
#define ARCHER_H

#include <QString>
#include "Personnage.h"

class Archer : public Personnage   // vitesse plus eleve de quelque points
{

public:
    Archer();
    Archer(QString nom);
    void tirdefeu(Personnage &cible); // attack et 50% de bruler
    void tirsanglant(Personnage &cible) ; // attack et 30% de saigner (effet qui fait subir des degat)
    void delugedefleche(Personnage &cible) ; // attack sur tous les ennemis
    void flecheempoisonne(Personnage &cible) ; // attack et 50% de poison
    void coupsur(Personnage &cible) ; // attack sur

private:
    void (Archer::*attack1)(Personnage &cible);
    void (Archer::*attack2)(Personnage &cible);

};

#endif // ARCHER_H
