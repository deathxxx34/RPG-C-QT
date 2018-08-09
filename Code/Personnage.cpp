#include "Personnage.h"
#include "archer.h"
#include "assassin.h"
#include "guerrier.h"
#include "magicien.h"
#include "pretre.h"
#include "tank.h"

Personnage::Personnage() : m_vie(100), m_vie_static(m_vie), m_mana(100), m_mana_static(m_mana),\
    m_attaque(10), m_defence(10), m_vitesse(10), m_lvl(1), m_c_att(m_attaque),\
    m_c_def(m_defence), m_c_vit(m_vitesse), m_effet(-1)
{   }

Personnage::Personnage(QString nom) : m_nom(nom)
{   Personnage(); }

void Personnage::DegatRecois(int nb, int v_attack, int v_attackant, int spe)
{
    /* demarche combat :
     * P1 : vitesse = a
     * P2 : vitesse = b
     * P2 attack P1
     * chance de P1 = 10 + 2*vitesse_de_la_victim
     * chance de P2 = 90 + 2*vitesse_de_lattackant + vitesse_de_lattack
     * on additione ces 2 chances que l'on met dans res
     * on determine grace a la chance de P2 si l'action a frappe
    */

    /// ne prend pas en compte l'attack et la defence des joueurs

    int c_a(90+v_attackant*2+v_attack), c_v(10+m_vitesse*2);
    int res = c_a + c_v;
    if(spe==1) {
        c_a = res;
    }
    if(spe==2) {
        m_vie = 0;
    }
    else if (rand() % res < c_a) { // pour la "chance"
        m_vie = (m_vie > nb) ? m_vie-nb : 0;
    }
}

void Personnage::DegatRecoisEffet(int nb)
{ m_vie = (m_vie > nb) ? m_vie-nb : 0; }

void Personnage::VieAdd(int nb)
{   m_vie = (m_vie < 100-nb) ? m_vie+nb : 100; }

void Personnage::AttackAdd(int nb)
{   m_c_att+=nb; }

void Personnage::DefenceAdd(int nb)
{   m_c_def+=nb; }

void Personnage::VitesseAdd(int nb)
{   m_c_vit+=nb; }

void Personnage::EffetAdd(int nb)
{ m_effet=nb; }

void Personnage::ManaAdd(int nb)
{   m_mana = (m_mana < 100-nb) ? m_mana+nb : 100; }

void Personnage::ManaRemove(int nb)
{   m_mana = (m_mana > nb) ? m_mana-nb : 0; }

void Personnage::Upattr(int what,int nb)
{
    switch (what) {
        case 1:
            m_c_att+=nb;
            break;

        case 2:
            m_c_vit+=nb;
            break;

        default:
            break;
    }
}

void Personnage::SetAttack(int a, QString b)
{
    if(a==1) { nom_attack1 = b; }
    if(a==2) { nom_attack2 = b; }
}

QString Personnage::GetAttack(int a)
{
    if(a==1) { return nom_attack1; }
    if(a==2) { return nom_attack2; }
}

int Personnage::Cmblvl()
{   return m_lvl; }

int Personnage::Cmbvie()
{   return m_vie; }

int Personnage::Cmbvieper()
{   return ((m_vie*100)/m_vie_static); }

int Personnage::Cmbmana()
{   return m_mana; }

int Personnage::Cmbstatic(int a)
{   if(a==1) {return m_vie_static;}
    else {return m_mana_static;} }

int Personnage::Cmbvitessecombat()
{   return m_c_vit; }

int Personnage::WhatEffet()
{   return m_effet; }

int Personnage::InfoAtt(QString name, int nb_att, int info)
{
    QString fileName = "Information.txt";
    QFile fichier(fileName);
    if(fichier.open(QIODevice::ReadOnly))
    {
        QTextStream flux(&fichier);
        QString ligne;
        QStringList liste;
        while(! flux.atEnd())
        {
            ligne = flux.readLine();
            liste = ligne.split(" : ");
            if(liste.at(0)==name && (liste.at(1)).toInt()==nb_att) {
                QStringList listebis = (liste.at(2)).split(",");
                return (listebis.at(info)).toInt();
            }
        }
        fichier.close();
    }
    return 1;
}

Magicien::Magicien() : Personnage()
{   }

Magicien::Magicien(QString nom): Personnage(nom)
{   }

void Magicien::briseregeneratrice(Personnage &cible)
{
    this->VieAdd(this->InfoAtt("Magicien",1,0)); // this-> == Personnage::
    this->ManaAdd(this->InfoAtt("Magicien",1,1));
}

void Magicien::caressedelocean(Personnage &cible)
{
    if(Cmbmana() >= this->InfoAtt("Magicien",2,0)) {
        cible.DegatRecois(this->InfoAtt("Magicien",2,1),this->InfoAtt("Magicien",2,2),this->Cmbvitessecombat());
        this->ManaRemove(this->InfoAtt("Magicien",2,0));
    }
}

void Magicien::braiseincandescente(Personnage &cible)
{
    if(Cmbmana() >= this->InfoAtt("Magicien",3,0)) {
        cible.DegatRecois(this->InfoAtt("Magicien",3,1),this->InfoAtt("Magicien",3,2),this->Cmbvitessecombat());
        this->ManaRemove(this->InfoAtt("Magicien",3,0));
        if(rand() % 100 < 70) {
            cible.EffetAdd(1);
        }
    }
}

void Magicien::tremblementdeterre(Personnage &cible)
{
    if(Cmbmana() >= this->InfoAtt("Magicien",4,0)) {
        cible.DegatRecois(this->InfoAtt("Magicien",4,1),this->InfoAtt("Magicien",4,2),this->Cmbvitessecombat());
        this->ManaRemove(this->InfoAtt("Magicien",4,0));
        if(rand() % 100 < 20) {
            cible.EffetAdd(2);
        }
    }
}

void Magicien::briseroche(Personnage &cible)
{
    if(Cmbmana() >= this->InfoAtt("Magicien",5,0)) {
        cible.DegatRecois(this->InfoAtt("Magicien",5,1),this->InfoAtt("Magicien",5,2),this->Cmbvitessecombat());
        this->ManaRemove(this->InfoAtt("Magicien",5,0));
    }
}

void Magicien::attaquer(int a,Personnage &cible)
{
    if(a==1) {(this->*attack1)(cible);}
    if(a==2) {(this->*attack2)(cible);}
}

Assassin::Assassin() : Personnage()
{   }

Assassin::Assassin(QString nom): Personnage(nom)
{   }

void Assassin::lancerdedague(Personnage &cible)
{
    if(Cmbmana() >= this->InfoAtt("Assassin",1,0)) {
        cible.DegatRecois(this->InfoAtt("Assassin",1,1),this->InfoAtt("Assassin",1,2),this->Cmbvitessecombat());
        this->ManaRemove(this->InfoAtt("Assassin",1,0));
    }
}

void Assassin::arrachecoeur(Personnage &cible)
{
    if(Cmbmana() >= this->InfoAtt("Assassin",2,0)) {
        cible.DegatRecois(this->InfoAtt("Assassin",2,1),this->InfoAtt("Assassin",2,2),this->Cmbvitessecombat());
        this->ManaRemove(this->InfoAtt("Assassin",2,0));
    }
}

void Assassin::boost(Personnage &cible)
{
    if(Cmbmana() >= this->InfoAtt("Assassin",3,0)) {
        Upattr(this->InfoAtt("Assassin",3,1),this->InfoAtt("Assassin",3,2));
        this->ManaRemove(this->InfoAtt("Assassin",3,0));
    }
}

void Assassin::assassina(Personnage &cible)
{
    if(Cmbmana() >= this->InfoAtt("Assassin",4,0)) {
        this->ManaRemove(this->InfoAtt("Assassin",4,0));
        if(this->Cmbvitessecombat() > cible.Cmbvitessecombat()){
            if (rand() % 100 < (30+(this->Cmblvl() / 2))) {
                cible.DegatRecois(0,0,0,2);
                return;
            }
        }
        cible.DegatRecois(this->InfoAtt("Assassin",4,1),this->InfoAtt("Assassin",4,2),this->Cmbvitessecombat());
    }
}

void Assassin::lameduserpent(Personnage &cible)
{
    if(Cmbmana() >= this->InfoAtt("Assassin",5,0)) {
        cible.DegatRecois(this->InfoAtt("Assassin",5,1),this->InfoAtt("Assassin",5,2),this->Cmbvitessecombat(),1);
        this->ManaRemove(this->InfoAtt("Assassin",5,0));
    }
}

Archer::Archer() : Personnage()
{   }

Archer::Archer(QString nom): Personnage(nom)
{   }

void Archer::tirdefeu(Personnage &cible)
{
    if(Cmbmana() >= this->InfoAtt("Archer",1,0)) {
        cible.DegatRecois(this->InfoAtt("Archer",1,1),this->InfoAtt("Archer",1,2),this->Cmbvitessecombat());
        this->ManaRemove(this->InfoAtt("Archer",1,0));
        if(rand() % 100 < 50) {
            cible.EffetAdd(1);
        }
    }
}

void Archer::tirsanglant(Personnage &cible)
{
    if(Cmbmana() >= this->InfoAtt("Archer",2,0)) {
        cible.DegatRecois(this->InfoAtt("Archer",2,1),this->InfoAtt("Archer",2,2),this->Cmbvitessecombat());
        this->ManaRemove(this->InfoAtt("Archer",2,0));
        if(rand() % 100 < 30) {
            cible.EffetAdd(4);
        }
    }
}

void Archer::delugedefleche(Personnage &cible)
{
    if(Cmbmana() >= this->InfoAtt("Archer",3,0)) {
        cible.DegatRecois(this->InfoAtt("Archer",3,1),this->InfoAtt("Archer",3,2),this->Cmbvitessecombat());
        this->ManaRemove(this->InfoAtt("Archer",3,0));
    }
}

void Archer::flecheempoisonne(Personnage &cible)
{
    if(Cmbmana() >= this->InfoAtt("Archer",4,0)) {
        cible.DegatRecois(this->InfoAtt("Archer",4,1),this->InfoAtt("Archer",4,2),this->Cmbvitessecombat());
        this->ManaRemove(this->InfoAtt("Archer",4,0));
        if(rand() % 100 < 50) {
            cible.EffetAdd(3);
        }
    }
}

void Archer::coupsur(Personnage &cible)
{
    if(Cmbmana() >= this->InfoAtt("Archer",5,0)) {
        cible.DegatRecois(this->InfoAtt("Archer",5,1),this->InfoAtt("Archer",5,2),this->Cmbvitessecombat(),1);
        this->ManaRemove(this->InfoAtt("Archer",5,0));
    }
}

Guerrier::Guerrier() : Personnage()
{   }

Guerrier::Guerrier(QString nom): Personnage(nom)
{   }

void Guerrier::attaqueeclair(Personnage &cible)
{
    if(Cmbmana() >= this->InfoAtt("Guerrier",1,0)) {
        cible.DegatRecois(this->InfoAtt("Guerrier",1,1),this->InfoAtt("Guerrier",1,2),this->Cmbvitessecombat());
        this->ManaRemove(this->InfoAtt("Guerrier",1,0));
    }
}

void Guerrier::chargemeurtriere(Personnage &cible)
{
    if(Cmbmana() >= this->InfoAtt("Guerrier",2,0)) {
        cible.DegatRecois(this->InfoAtt("Guerrier",2,1),this->InfoAtt("Guerrier",2,2),this->Cmbvitessecombat());
        this->ManaRemove(this->InfoAtt("Guerrier",2,0));
    }
}

void Guerrier::rage(Personnage &cible)
{
    if(Cmbmana() >= this->InfoAtt("Guerrier",3,0)) {
        this->Upattr(this->InfoAtt("Guerrier",3,1),this->InfoAtt("Guerrier",3,2));
        this->ManaRemove(this->InfoAtt("Guerrier",3,0));
    }
}

void Guerrier::frappeacrobatique(Personnage &cible)
{
    if(Cmbmana() >= this->InfoAtt("Guerrier",4,0)) {
        cible.DegatRecois(this->InfoAtt("Guerrier",4,1),this->InfoAtt("Guerrier",4,2),this->Cmbvitessecombat());
        this->ManaRemove(this->InfoAtt("Guerrier",4,0));
    }
}

void Guerrier::lameetdague(Personnage &cible)
{
    if(Cmbmana() >= this->InfoAtt("Guerrier",5,0)) {
        cible.DegatRecois(this->InfoAtt("Guerrier",5,1),this->InfoAtt("Guerrier",5,2),this->Cmbvitessecombat(),1);
        cible.DegatRecois(this->InfoAtt("Guerrier",5,1),this->InfoAtt("Guerrier",5,2),this->Cmbvitessecombat(),1);
        this->ManaRemove(this->InfoAtt("Guerrier",5,0));
    }
}

Pretre::Pretre() : Personnage()
{   }

Pretre::Pretre(QString nom): Personnage(nom)
{   }

void Pretre::benedictiondivine(Personnage &cible)
{
    if(Cmbmana() >= this->InfoAtt("Pretre",1,0)) {
        this->VieAdd(this->InfoAtt("Pretre",1,1));
        this->ManaRemove(this->InfoAtt("Pretre",1,0));
    }
}

void Pretre::attaquedivine(Personnage &cible)
{
    if(Cmbmana() >= this->InfoAtt("Pretre",2,0)) {
        cible.DegatRecois(this->InfoAtt("Pretre",2,1),this->InfoAtt("Pretre",2,2),this->Cmbvitessecombat());
        this->ManaRemove(this->InfoAtt("Pretre",2,0));
    }
}

void Pretre::aidemiracle(Personnage &cible)
{
    if(Cmbmana() >= this->InfoAtt("Pretre",3,0)) {
        if(this->Cmbvieper()<=50){
            this->DefenceAdd(this->InfoAtt("Pretre",3,1));
            this->AttackAdd(this->InfoAtt("Pretre",3,2));
            this->VitesseAdd(this->InfoAtt("Pretre",3,3));
            this->VieAdd(this->InfoAtt("Pretre",3,4));
        }
        this->ManaRemove(this->InfoAtt("Pretre",3,0));
    }
}

void Pretre::purification(Personnage &cible)
{
    if(Cmbmana() >= this->InfoAtt("Pretre",4,0)) {
        this->ManaRemove(this->InfoAtt("Pretre",4,0));
        this->EffetAdd(-1);
    }
}

void Pretre::reveildumort(Personnage &cible)
{
    if(Cmbmana() >= this->InfoAtt("Pretre",5,0)) {
        this->ManaRemove(this->InfoAtt("Pretre",5,0));
    }
}

Tank::Tank() : Personnage()
{   }

Tank::Tank(QString nom): Personnage(nom)
{   }

void Tank::dernierrempart(Personnage &cible)
{
    if(Cmbmana() >= this->InfoAtt("Tank",1,0)) {
        this->ManaRemove(this->InfoAtt("Tank",1,0));
    }
}

void Tank::protectiondivine(Personnage &cible)
{
    if(Cmbmana() >= this->InfoAtt("Tank",2,0)) {
        this->DefenceAdd(this->InfoAtt("Tank",2,1));
        this->ManaRemove(this->InfoAtt("Tank",2,0));
    }
}

void Tank::epeesacre(Personnage &cible)
{
    if(Cmbmana() >= this->InfoAtt("Tank",3,0)) {
        cible.DegatRecois(this->InfoAtt("Tank",3,1),this->InfoAtt("Tank",3,2),this->Cmbvitessecombat());
        this->ManaRemove(this->InfoAtt("Tank",3,0));
    }
}

void Tank::chargedubouclier(Personnage &cible)
{
    if(Cmbmana() >= this->InfoAtt("Tank",4,0)) {
        cible.DegatRecois(this->InfoAtt("Tank",4,1),this->InfoAtt("Tank",4,2),this->Cmbvitessecombat());
        this->ManaRemove(this->InfoAtt("Tank",4,0));
    }
}

void Tank::transfertvitale(Personnage &cible)
{
    if(Cmbmana() >= this->InfoAtt("Tank",5,0)) {
        this->ManaRemove(this->InfoAtt("Tank",5,0));
    }
}
