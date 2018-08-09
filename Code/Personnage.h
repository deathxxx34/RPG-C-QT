#ifndef PERSONNAGE_H
#define PERSONNAGE_H

#include <QString>
#include <QTextStream>
#include <QIODevice>
#include <QFile>
#include <QApplication>

class Personnage
{
    // Personnages ont 4 attack : 2 dependants du personnages que le joueurpeut choisir et 2 de l'armes equipe
    // chaque attaque a 2 attributs : degat, vitesse
    // chaque personnage a 5 attack que le joueur choisi
public:
    Personnage();
    Personnage(QString nom);
    void DegatRecois(int nb, int v_attack, int v_attackant, int spe = -1);
    void DegatRecoisEffet(int nb);
    void DegatEnvoie(Personnage &perso,int nb,int vi) const;
    void VieAdd(int nb);
    void AttackAdd(int nb);
    void DefenceAdd(int nb);
    void VitesseAdd(int nb);
    void EffetAdd(int nb);
    void ManaAdd(int nb);
    void ManaRemove(int nb);
    void Upattr(int what,int nb);
    void SetAttack(int a, QString b);
    QString GetAttack(int a);
    int Cmblvl();
    int Cmbvie();
    int Cmbvieper();
    int Cmbmana();
    int Cmbstatic(int a);
    int Cmbvitessecombat();
    int WhatEffet();
    int InfoAtt(QString name, int nb_att, int info);

private:
    int m_vie;
    int m_vie_static;
    int m_mana;
    int m_mana_static;
    int m_attaque;
    int m_defence;
    int m_vitesse;
    int m_lvl;
    int m_c_att;
    int m_c_def;
    int m_c_vit;
    int m_effet;
    QString m_nom;
    QString nom_attack1;
    QString nom_attack2;
};

#endif // PERSONNAGE_H
