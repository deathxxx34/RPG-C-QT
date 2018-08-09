#ifndef COMBAT_H
#define COMBAT_H

#include <QtWidgets>
#include "Game.h"
#include "magicien.h"
#include "Monstre.h"


class Combat : public QGraphicsView
{
public:
    Combat(Game *scene);
    void test();
    void reload();

private:
    QGraphicsScene *scene_combat;
    QGraphicsScene *m_scene;
    Game *m_game;
    QProgressBar *vie_1;
    QProgressBar *vie_2;
    QProgressBar *mana_1;
    QProgressBar *mana_2;
    Personnage *persoclass;
    Magicien *merlin;
    Monstre *tueur;
};

#endif // COMBAT_H
