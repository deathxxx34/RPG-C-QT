#include <QIODevice>
#include <QTime>
#include <QCoreApplication>
#include "Monstre.h"

Monstre::Monstre() : Personnage()
{

}

Monstre::Monstre(Game *scene) : Personnage()
{
    m_scene = scene->GetScene();
    m_game = scene;
    perso = new QGraphicsPixmapItem(QPixmap::fromImage(QImage("images/monstre_1.png")));
}

void Monstre::spawn()
{
    int a(rand() % 100), b(rand() % 100);
    do {
    a = rand() % 100;
    b = rand() % 100;
    } while(!(m_game->canmove(a,b)));
    perso->setPos(32*b,32*a);
    pos_x = a;
    pos_y = b;
    m_scene->addItem(perso);
    m_game->setpos(2,b,a);
}

void Monstre::move()
{
    /*listemove[8][2] = {{a,b},...}
     * a = direction : 0/1/2/3 -> Haut/Droite/Bas/Gauche
     * b = nombre de pas : pas separait de 0.1s
     */
    int listemove[8][2] = {{0,3},{0,5},{1,3},{1,5},{2,3},{2,5},{3,3},{3,5}};
    int a(rand() % 8);
    for(int i(0); i < listemove[a][1]; i++)
    {
        if(listemove[a][0]==0 && m_game->canmove(pos_x, pos_y-1)) { pos_y-=1; perso->moveBy(0,-32); }
        else if(listemove[a][0]==1 && m_game->canmove(pos_x+1, pos_y)) { pos_x+=1; perso->moveBy(32,0); }
        else if(listemove[a][0]==2 && m_game->canmove(pos_x, pos_y+1)) { pos_y+=1; perso->moveBy(0,32); }
        else if(listemove[a][0]==3 && m_game->canmove(pos_x-1, pos_y)) { pos_x-=1; perso->moveBy(-32,0); }
        QTime dieTime = QTime::currentTime().addMSecs(100);
        while (QTime::currentTime() < dieTime)
            QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
    }
    int b(rand() % 3000);
    QTime dieTime = QTime::currentTime().addMSecs(b);
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
    //this->move();
}

void Monstre::attack()
{

}


