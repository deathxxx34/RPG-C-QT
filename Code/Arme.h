#ifndef ARME_H
#define ARME_H

#include <QApplication>
#include <QWidget>

class Arme : public QWidget
{
    // chaque arme a 2 attack aleatoires
    // des armes peuvent avoir des attaques precise
    // d'autre des caracteristiques : ex arc de feu a des attaque precise nul mais qui equipe a un archer
    //                      permet a ce dernier de bruler avec 50% de chance l'adversaire a chaque attack
    // des armes peuvent etre adapte a une certaine class : arc pour archer, dague pour assassin ...
    // chaque arme possede 3 attribut : degat, nom, caracteristique particuliere (si rien vaut None)
    public:
        Arme();

   private:


};

#endif // ARME_H
