#include "event.h"
#include "Personnage.h"

Event::Event()
{ }

void Event::EnCombat(Personnage &perso1, Personnage &perso2)
{
    int c_p1(50+perso1.Cmbvitessecombat()),c_p2(50+perso2.Cmbvitessecombat());
    int tour;
    if(rand() % (c_p1+c_p2) < c_p1) {  tour=0; }
    else { tour=1; }
    Personnage *tourperso;
    while(perso1.Cmbvie()!=0 || perso2.Cmbvie()!=0){
        if(tour==0) { tourperso = &perso1; }
        else { tourperso = &perso2; }
        if(tourperso->WhatEffet()!=2) {

            //Mettre en code : Attend que perso attack

            (tour+=1)%=2;
            switch (tourperso->WhatEffet()) {
                case 1:
                    tourperso->DegatRecoisEffet(tourperso->InfoAtt("Effet",1,0));
                    break;
                case 3:
                    tourperso->DegatRecoisEffet(tourperso->InfoAtt("Effet",3,0));
                    break;
                case 4:
                    tourperso->DegatRecoisEffet(tourperso->InfoAtt("Effet",4,0));
                    break;
            }
        }
    }
}



