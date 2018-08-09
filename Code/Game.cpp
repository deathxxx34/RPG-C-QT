#include <QGraphicsItem>
#include <QKeyEvent>
#include <QDebug>
#include "Game.h"
#include "Monstre.h"
#include "combat.h"

Game::Game(QWidget *parent) : nbmonstre(0){


    //persoclass = n_class;

    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(640,640);

    gennivo("grotte_1_1");

    show();
}

extern Magicien *persoclass;

void Game::SetPersoMagicien(Magicien *p)
{
    persoclass = p;
}

Game::~Game()
{
    delete scene;
}

QGraphicsScene* Game::GetScene()
{
    return scene;
}

void Game::setpos(int a, int x, int y, int new_x, int new_y)
{
    if(new_x==-1) { pos_all.push_back({a,x,y}); }
    else {
        for(int i(0); i<int(pos_all.size()); i++)
        {
            if(x==int(pos_all[i][1]) && y==int(pos_all[i][2]))
            {
                pos_all[i] = { pos_all[i][0], new_x, new_y};
                return;
            }
        }
    }
}

void Game::startcombat()
{
    int x(0),y(0);
    for(int i(0); i<int(pos_all.size()); i++)
    {
        if(pos_all[i][0]==1) { x=pos_all[i][1]; y=pos_all[i][2]; }
    }
    for(int i(0); i<int(pos_all.size()); i++)
    {
        if(pos_all[i][0]==2 && x==pos_all[i][1] && y==pos_all[i][2]) { combat = new Combat(this); }
    }
}

Personnage Game::GetClass()
{
    return *persoclass;
}

void Game::gennivo(QString name)
{
    int pos_x(32*(where_x-10)),pos_y(32*(where_y-5));
    if(pos_x<0) { pos_x = 0; }
    else if(pos_x>2560) { pos_x = 2560; }
    if(pos_y<0) { pos_y = 0; }
    else if(pos_y>2560) { pos_y = 2560; }

    scene = new QGraphicsScene();
    scene->setSceneRect(pos_x,pos_y,640,640);

    setScene(scene);

    QString fileName = "niveau/"+name+".txt";
    QFile fichier(fileName);
    if(fichier.open(QIODevice::ReadOnly))
    {
        QTextStream flux(&fichier);
        QString text;
        QStringList ligne, structure;
        text = flux.readAll();
        text.replace("/n","");
        text.replace("\n","");
        for(int i(0); i<100; i++) {
            for(int j(0); j<100; j++) {
                nivo[i][j]=text[j+(i*101)].digitValue();
            }
        }
        QString namebloc;
        QGraphicsPixmapItem *image;
        for(int i(0); i<100; i++) {
            for(int j(0); j<100; j++) {
                if(nivo[i][j]==0) { namebloc="VOID"; }
                else if(nivo[i][j]==1) { namebloc="STONE"; }
                else if(nivo[i][j]==2) { namebloc="SAND"; }
                image = new QGraphicsPixmapItem(QPixmap::fromImage(QImage("images/"+namebloc+".png")));
                image->setPos(32*j,32*i);
                scene->addItem(image);
            }
        }
        fichier.close();
    }
    QString namebloc;
    QGraphicsPixmapItem *image;
    for(int i(0); i<int(pos_all.size()); i++)
    {
        if (pos_all[i][0]==2) { namebloc="monstre_1"; }
        image = new QGraphicsPixmapItem(QPixmap::fromImage(QImage("images/"+namebloc+".png")));
        image->setPos(32*pos_all[i][1],32*pos_all[i][2]);
        scene->addItem(image);
    }
    perso = new QGraphicsPixmapItem(QPixmap::fromImage(QImage("images/perso.png")));
    perso->setPos(32*where_x,32*where_y);
    scene->addItem(perso);
    setpos(1, where_x, where_y);
    for(int i(0); i<20; i++)
    {
        if(nbmonstre < 21) {
            nbmonstre+=1;
            monstre = new Monstre(this);
            monstre->spawn();
            //monstre->move();
        }
    }
}

void Game::move()
{
    if(key_right && where_x<100 && canmove(where_y,where_x+1))
        { where_x+=1; setpos(1, where_x-1, where_y, where_x, where_y); perso->moveBy(32,0); }
    if(key_left && where_x>0 && canmove(where_y,where_x-1))
        { where_x-=1; setpos(1, where_x+1, where_y, where_x, where_y); perso->moveBy(-32,0); }
    if(key_up && where_y>0 && canmove(where_y-1,where_x))
        { where_y-=1; setpos(1, where_x, where_y+1, where_x, where_y); perso->moveBy(0,-32); }
    if(key_down && where_y<100 && canmove(where_y+1,where_x))
        { where_y+=1; setpos(1, where_x, where_y-1, where_x, where_y); perso->moveBy(0,32); }
    if(key_down || key_left || key_right || key_up)
    {
        int pos_x(32*(where_x-10)),pos_y(32*(where_y-5));
        if(pos_x<0) { pos_x = 0; }
        else if(pos_x>2560) { pos_x = 2560; }
        if(pos_y<0) { pos_y = 0; }
        else if(pos_y>2560) { pos_y = 2560; }
        scene->setSceneRect(pos_x,pos_y,640,640);
    }
    startcombat();
}

bool Game::canmove(int a, int b)
{
    int listeblockyes[2] = {1,2};
    for(int i(0); i < 2; i++)
    {
        if(nivo[a][b]==listeblockyes[i]) { return true; }
    }
    return false;
}

void Game::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Up) { key_up = true; }
    else if(event->key() == Qt::Key_Down) { key_down = true; }
    else if(event->key() == Qt::Key_Right) { key_right = true;}
    else if(event->key() == Qt::Key_Left) { key_left = true; }
    else if(event->key() == Qt::Key_B) { combat = new Combat(this); }
    move();

 }

void Game::keyReleaseEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Up) { key_up = false; }
    else if(event->key() == Qt::Key_Down) { key_down = false; }
    else if(event->key() == Qt::Key_Right) { key_right = false; }
    else if(event->key() == Qt::Key_Left) { key_left = false; }
}
