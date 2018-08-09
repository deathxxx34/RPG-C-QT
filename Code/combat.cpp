#include <QProgressBar>
#include "combat.h"
#include "Personnage.h"

Combat::Combat(Game *scene)
{
    m_scene = scene->GetScene();
    m_game = scene;


    if(QString(typeid(m_game->GetClass()).name()).contains("Magicien"))
    {
        *persoclass = m_game->GetClass();
    }


    m_scene->setSceneRect(0,0,640,640);

    m_scene->clear();

    QGraphicsPixmapItem *image;

    image = new QGraphicsPixmapItem(QPixmap::fromImage(QImage("images/decor combat.png")).scaled(640,640));
    image->setPos(0,0);
    m_scene->addItem(image);

    image = new QGraphicsPixmapItem(QPixmap::fromImage(QImage("images/perso.png")).scaled(200,270));
    image->setPos(50,120);
    m_scene->addItem(image);

    image = new QGraphicsPixmapItem(QPixmap::fromImage(QImage("images/monstre_3.png")).scaled(200,270));
    image->setPos(390,120);
    m_scene->addItem(image);

    //merlin = new Magicien;
    tueur = new Monstre;

    vie_1 = new QProgressBar;
    vie_2 = new QProgressBar;
    mana_1 = new QProgressBar;
    mana_2 = new QProgressBar;
    this->reload();
    vie_1->setGeometry(QRect(50,25,200,25));
    vie_2->setGeometry(QRect(390,25,200,25));
    mana_1->setGeometry(QRect(50,75,200,25));
    mana_2->setGeometry(QRect(390,75,200,25));
    vie_1->setAlignment(Qt::AlignCenter);
    //vie_2->setAlignment(Qt::AlignCenter);
    mana_1->setAlignment(Qt::AlignCenter);
    //mana_2->setAlignment(Qt::AlignCenter);
    vie_2->setTextVisible(false);
    mana_2->setTextVisible(false);
    m_scene->addWidget(vie_1);
    m_scene->addWidget(vie_2);
    m_scene->addWidget(mana_1);
    m_scene->addWidget(mana_2);

    persoclass->SetAttack(1,"Brise Regeneratrice");
    persoclass->SetAttack(2,"Caresse de l'ocean");

    QPushButton *b_attack1 = new QPushButton;
    b_attack1->setText(persoclass->GetAttack(1));
    b_attack1->setGeometry(QRect(25,440,150,50));
    m_scene->addWidget(b_attack1);

    QPushButton *b_attack2 = new QPushButton;
    b_attack2->setText(persoclass->GetAttack(2));
    b_attack2->setGeometry(QRect(200,440,150,50));
    m_scene->addWidget(b_attack2);

    QPushButton *b_attack3 = new QPushButton;
    b_attack3->setText("Rien");
    b_attack3->setGeometry(QRect(25,540,150,50));
    m_scene->addWidget(b_attack3);

    QPushButton *b_attack4 = new QPushButton;
    b_attack4->setText("Petit test 40");
    b_attack4->setGeometry(QRect(200,540,150,50));
    m_scene->addWidget(b_attack4);


    merlin = new Magicien;
    connect(b_attack1, &QPushButton::clicked, [=](){ merlin->attaquer(1,*merlin); this->reload(); });
    connect(b_attack2, &QPushButton::clicked, [=](){ merlin->attaquer(2,*tueur); this->reload(); });
}

void Combat::test() {QApplication::exit();}

void Combat::reload()
{
    vie_1->setValue(merlin->Cmbvie());
    vie_2->setValue(tueur->Cmbvie());
    mana_1->setValue(merlin->Cmbmana());
    mana_2->setValue(tueur->Cmbmana());
    vie_1->setFormat(QString::number(merlin->Cmbvie()));
    //vie_2->setFormat(QString::number(tueur->Cmbvie()));
    mana_1->setFormat(QString::number(merlin->Cmbmana()));
    //mana_2->setFormat(QString::number(tueur->Cmbmana()));
}

