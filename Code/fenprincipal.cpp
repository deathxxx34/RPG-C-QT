#include "fenprincipal.h"
//#include "combat.h"
#include "magicien.h"
#include "assassin.h"
#include <QApplication>
#include <QtDebug>
#include <QtWidgets>
#include <iostream>

FenPrincipal::FenPrincipal() : QMainWindow()
{
    /*setFixedSize(640, 640);

    setWindowIcon(QIcon("icon.png"));

    perso1 = new Magicien;
    perso2 = new Assassin;

    QWidget *zoneCentrale = new QWidget;

    QHBoxLayout *a_magicien = new QHBoxLayout;
    a_magicien->setAlignment(Qt::AlignRight);

    QPushButton *m_a_1 = new QPushButton("Brise regeneratrice");
    QPushButton *m_a_2 = new QPushButton("Caresse de l'ocean", this);
    QPushButton *m_a_3 = new QPushButton("Braise incandescente", this);
    QPushButton *m_a_4 = new QPushButton("Tremblement de terre", this);
    QPushButton *m_a_5 = new QPushButton("Brise roche", this);

    a_magicien->addWidget(m_a_1);
    a_magicien->addWidget(m_a_2);
    a_magicien->addWidget(m_a_3);
    a_magicien->addWidget(m_a_4);
    a_magicien->addWidget(m_a_5);

    QGroupBox *g_a_magicien = new QGroupBox("Attaque Magicien");
    g_a_magicien->setLayout(a_magicien);

    QHBoxLayout *a_assassin = new QHBoxLayout;
    a_magicien->setAlignment(Qt::AlignRight);

    QPushButton *a_a_1 = new QPushButton("Lancer de dague");
    QPushButton *a_a_2 = new QPushButton("Arrache coeur", this);
    QPushButton *a_a_3 = new QPushButton("Boost", this);
    QPushButton *a_a_4 = new QPushButton("Assassina", this);
    QPushButton *a_a_5 = new QPushButton("Lame du serpent", this);

    a_assassin->addWidget(a_a_1);
    a_assassin->addWidget(a_a_2);
    a_assassin->addWidget(a_a_3);
    a_assassin->addWidget(a_a_4);
    a_assassin->addWidget(a_a_5);

    QGroupBox *g_a_assassin = new QGroupBox("Attaque Assassin");
    g_a_assassin->setLayout(a_assassin);

    QLCDNumber *m_vie = new QLCDNumber();
    QLCDNumber *m_mana = new QLCDNumber();
    QLCDNumber *a_vie = new QLCDNumber();
    QLCDNumber *a_mana = new QLCDNumber();
    QLabel *l_m_vie = new QLabel("Vie Magicien");
    QLabel *l_m_mana = new QLabel("Mana Magicien");
    QLabel *l_a_vie = new QLabel("Vie Assassin");
    QLabel *l_a_mana = new QLabel("Mana Assassin");
    QSpacerItem *espace1 = new QSpacerItem(80,20);
    QSpacerItem *espace2 = new QSpacerItem(80,20);
    QGridLayout *vie_mana = new QGridLayout;
    vie_mana->addWidget(l_m_vie, 0, 0);
    vie_mana->addWidget(m_vie, 0, 1);
    vie_mana->addItem(espace1, 0, 2);
    vie_mana->addWidget(l_m_mana, 0, 3);
    vie_mana->addWidget(m_mana, 0, 4);
    vie_mana->addWidget(l_a_vie, 1, 0);
    vie_mana->addWidget(a_vie, 1, 1);
    vie_mana->addItem(espace2, 1, 2);
    vie_mana->addWidget(l_a_mana, 1, 3);
    vie_mana->addWidget(a_mana, 1, 4);
    m_vie->display(perso1->Cmbvie());
    m_mana->display(perso1->Cmbmana());
    a_vie->display(perso2->Cmbvie());
    a_mana->display(perso2->Cmbmana());

    connect(m_a_1, &QPushButton::clicked, [=](){perso1->briseregeneratrice();m_vie->display(perso1->Cmbvie());m_mana->display(perso1->Cmbmana());a_vie->display(perso2->Cmbvie());a_mana->display(perso2->Cmbmana());});
    connect(m_a_2, &QPushButton::clicked, [=](){perso1->caressedelocean(*perso2);m_vie->display(perso1->Cmbvie());m_mana->display(perso1->Cmbmana());a_vie->display(perso2->Cmbvie());a_mana->display(perso2->Cmbmana());});
    connect(m_a_3, &QPushButton::clicked, [=](){perso1->braiseincandescente(*perso2);m_vie->display(perso1->Cmbvie());m_mana->display(perso1->Cmbmana());a_vie->display(perso2->Cmbvie());a_mana->display(perso2->Cmbmana());});
    connect(m_a_4, &QPushButton::clicked, [=](){perso1->tremblementdeterre(*perso2);m_vie->display(perso1->Cmbvie());m_mana->display(perso1->Cmbmana());a_vie->display(perso2->Cmbvie());a_mana->display(perso2->Cmbmana());});
    connect(m_a_5, &QPushButton::clicked, [=](){perso1->briseroche(*perso2);m_vie->display(perso1->Cmbvie());m_mana->display(perso1->Cmbmana());a_vie->display(perso2->Cmbvie());a_mana->display(perso2->Cmbmana());});

    connect(a_a_1, &QPushButton::clicked, [=](){perso2->lancerdedague(*perso1);m_vie->display(perso1->Cmbvie());m_mana->display(perso1->Cmbmana());a_vie->display(perso2->Cmbvie());a_mana->display(perso2->Cmbmana());});
    connect(a_a_2, &QPushButton::clicked, [=](){perso2->arrachecoeur(*perso1);m_vie->display(perso1->Cmbvie());m_mana->display(perso1->Cmbmana());a_vie->display(perso2->Cmbvie());a_mana->display(perso2->Cmbmana());});
    connect(a_a_3, &QPushButton::clicked, [=](){perso2->boost();m_vie->display(perso1->Cmbvie());m_mana->display(perso1->Cmbmana());a_vie->display(perso2->Cmbvie());a_mana->display(perso2->Cmbmana());});
    connect(a_a_4, &QPushButton::clicked, [=](){perso2->assassina(*perso1);m_vie->display(perso1->Cmbvie());m_mana->display(perso1->Cmbmana());a_vie->display(perso2->Cmbvie());a_mana->display(perso2->Cmbmana());});
    connect(a_a_5, &QPushButton::clicked, [=](){perso2->lameduserpent(*perso1);m_vie->display(perso1->Cmbvie());m_mana->display(perso1->Cmbmana());a_vie->display(perso2->Cmbvie());a_mana->display(perso2->Cmbmana());});

    QWidget *gridlayoutwidget = new QWidget;
    gridlayoutwidget->setLayout(vie_mana);

    QVBoxLayout *layoutPrincipal = new QVBoxLayout;
    layoutPrincipal->addWidget(g_a_magicien);
    layoutPrincipal->addWidget(g_a_assassin);
    layoutPrincipal->addWidget(gridlayoutwidget);

    zoneCentrale->setLayout(layoutPrincipal);

    setCentralWidget(zoneCentrale);*/

    setFixedSize(640, 640);
    setWindowIcon(QIcon("icon.png"));

    gennivo("grotte_1_1");

    QWidget *zoneCentrale = new QWidget;

    affichage = new QGridLayout;
    affichage->setContentsMargins(0,0,0,0);
    affichage->setSpacing(0);

    affnivo();

    /*QWidget *gridlayoutwidget = new QWidget;
    gridlayoutwidget->setLayout(affichage);

    QVBoxLayout *layoutPrincipal = new QVBoxLayout;
    layoutPrincipal->addWidget(gridlayoutwidget);*/

    zoneCentrale->setLayout(affichage);

    setCentralWidget(zoneCentrale);

    statusBar()->hide();
    centralWidget()->layout()->setContentsMargins(0,0,0,0);

}

void FenPrincipal::gennivo(QString name)
{
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
        fichier.close();
    }
}

void FenPrincipal::move()
{
    if(key_right && where_x<100 && canmove(where_y,where_x+1)) { where_x+=1; affnivo(); }
    if(key_left && where_x>0 && canmove(where_y,where_x-1))
    {
        where_x-=1;
        if(!key_right) { affnivo(); }
    }
    if(key_up && where_y>0 && canmove(where_y-1,where_x))
    {
        where_y-=1;
        if(!(key_right || key_left)) { affnivo(); }
    }
    if(key_down && where_y<100 && canmove(where_y+1,where_x))
    {
        where_y+=1;
        if(!(key_right || key_left || key_up)) { affnivo(); }
    }
}

bool FenPrincipal::canmove(int a, int b)
{
    int listeblockyes[2] = {1,2};
    for(int i(0); i < 2; i++)
    {
        if(nivo[a][b]==listeblockyes[i]) { return true; }
    }
    return false;
}

void FenPrincipal::affnivo()
{
    QString namebloc;
    QLabel *image;

    for(int i(0); i<20; i++) {
        for(int j(0); j<20; j++) {
            if(where_y-5+i<0 || where_x-10+j<0 || where_y-5+i>100 || where_x-10+j>100) { namebloc="VOID"; }
            else if(nivo[where_y-5+i][where_x-10+j]==0) { namebloc="VOID"; }
            else if(nivo[where_y-5+i][where_x-10+j]==1) { namebloc="STONE"; }
            else if(nivo[where_y-5+i][where_x-10+j]==2) { namebloc="SAND"; }
            image = new QLabel;
            image->setPixmap(QPixmap("images/"+namebloc+".png"));
            affichage->addWidget(image, i, j);
        }
    }
    image = new QLabel;
    image->setPixmap(QPixmap("images/perso.png"));
    affichage->addWidget(image, 5, 10);

    qDebug() << "hi";
}

void FenPrincipal::genplan() // A revoir
{
    QGridLayout *planniv = new QGridLayout;
    planniv->setContentsMargins(0,0,0,0);
    planniv->setSpacing(0);

    for(int i(0); i<100; i++) {
        for(int j(0); j<100; j++) {
            QString namebloc = "";
            if(nivo[i][j]==0) { namebloc="VOID"; }
            else if(nivo[i][j]==1) { namebloc="STONE"; }
            else if(nivo[i][j]==2) { namebloc="SAND"; }
            QLabel *image = new QLabel;
            image->setPixmap(QPixmap("images/"+namebloc+".png"));
            planniv->addWidget(image, i, j);
        }
    }

    QWidget *plannivo = new QWidget(this);
    plannivo->setGeometry(QRect(510, 30, 100, 100)); // fait bugue
    plannivo->setLayout(planniv);
}

void FenPrincipal::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Up) { key_up = true; }
    else if(event->key() == Qt::Key_Down) { key_down = true; }
    else if(event->key() == Qt::Key_Right) { key_right = true; }
    else if(event->key() == Qt::Key_Left) { key_left = true; }
    move();
    //else if(event->key() == Qt::Key_B) { Combat(); }

 }

void FenPrincipal::keyReleaseEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Up) { key_up = false; }
    else if(event->key() == Qt::Key_Down) { key_down = false; }
    else if(event->key() == Qt::Key_Right) { key_right = false; }
    else if(event->key() == Qt::Key_Left) { key_left = false; }
}
