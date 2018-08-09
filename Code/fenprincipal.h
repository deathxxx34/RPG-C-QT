#ifndef FENPRINCIPAL_H
#define FENPRINCIPAL_H

#include "magicien.h"
#include "assassin.h"
#include <QtWidgets>

class FenPrincipal : public QMainWindow
{
    public:
    FenPrincipal();
    void gennivo(QString nom);
    void move();
    bool canmove(int a, int b);
    void affnivo();
    void genplan();
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);

    private:
    QGridLayout *affichage;
    Magicien *perso1;
    Assassin *perso2;
    int where_x = 10;
    int where_y = 5;
    int nivo[100][100];
    bool key_up = false;
    bool key_down = false;
    bool key_right = false;
    bool key_left = false;

};

#endif // FENPRINCIPAL_H
