#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include <vector>
#include "Personnage.h"
#include "magicien.h"

using namespace std;

class Monstre;
class Combat;

class Game : public QGraphicsView
{
public:
    Game(QWidget *parent=nullptr);
    ~Game();
    void SetPersoMagicien(Magicien *p);
    QGraphicsScene* GetScene();
    void setpos(int a, int x, int y, int new_x=-1, int new_y=-1);
    void startcombat();
    Personnage GetClass();
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
    void gennivo(QString name);
    void move();
    bool canmove(int a, int b);

private:
    QGraphicsScene *scene;
    QGraphicsPixmapItem *perso;
    int nivo[100][100];
    vector<vector<int>> pos_all;
    int where_x = 10;
    int where_y = 5;
    bool key_up = false;
    bool key_down = false;
    bool key_right = false;
    bool key_left = false;
    Monstre *monstre;
    Combat *combat;
    int nbmonstre;

};

#endif // GAME_H
