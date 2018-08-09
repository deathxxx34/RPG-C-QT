#ifndef MONSTRE_H
#define MONSTRE_H

#include <QGraphicsPixmapItem>
#include "Game.h"
#include "Personnage.h"

class Monstre : public Personnage
{
public:
    Monstre();
    Monstre(Game *scene);
    void spawn();
    //int nbmonstre();
    void move();
    void attack();

private:
    QGraphicsPixmapItem *perso;
    QGraphicsScene *m_scene;
    Game *m_game;
    int pos_x;
    int pos_y;
};

#endif // MONSTRE_H
