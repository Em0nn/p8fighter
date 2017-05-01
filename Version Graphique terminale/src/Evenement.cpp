#include "Evenement.h"
#include "Zone.h"
#include "Animation.h"
#include "Effet.h"
#include <stdlib.h>
#include <time.h>

using namespace std;

Evenement::Evenement()
{
    idEvent = 0;
    zoneAction = {0,0,0,0};
    saisissable = false;
    duree = 0;
    effet.setbouclier(false);
    effet.setstat_modif(0.0);
    effet.setval_modif(0.0);
}

Evenement::Evenement(SDL_Rect zoneAct, int dure, bool saisiss, Effet eff)
{
    zoneAction = zoneAct;
    duree = dure;
    saisissable = saisiss;
    effet = eff;
}

bool Evenement::getSaisissable()
{
    return saisissable;
}

int Evenement::getDuree()
{
    return duree;
}

SDL_Rect Evenement::getZoneAction()
{
    return zoneAction;
}

Effet Evenement::getEffet()
{
    return effet;
}

int Evenement::getIdEvent()
{
    return idEvent;
}

void Evenement::setZoneAction(SDL_Rect za)
{
    zoneAction = za;
}

void Evenement::setSaisissable(bool s)
{
    saisissable = s;
}

void Evenement::setEffet(Effet ef)
{
    effet = ef;
}

void Evenement::setIdEvent(int i)
{
    idEvent = i;
}

void Evenement::NouvelEvent()
{
    idEvent = (rand()%4);

    if(idEvent == 0)//Dejou
    {
        zoneAction = {(rand()%1300) + 300,750,50,50};
        saisissable = true;
        duree = 3000;
        effet.setbouclier(false);
        effet.setstat_modif(1.0);
        effet.setval_modif(2.0);
    }

    else if(idEvent == 1)//Attal
    {
        zoneAction = {(rand()%1300) + 300,750,50,50};
        saisissable = true;
        effet.setbouclier(true);
        effet.setstat_modif(0.0);
        effet.setval_modif(0.0);
    }

    else if(idEvent == 2)//Felix
    {
        zoneAction = {(rand()%1100) + 300,750,100,1750};
        saisissable = false;
        duree = 3000;
        effet.setbouclier(false);
        effet.setstat_modif(0.0);
        effet.setval_modif(1.0);
    }

    else if(idEvent == 3)//Romain heal
    {
        idEvent = idEvent + (rand()%4);

        if(idEvent == 3)
        {
            zoneAction = {(rand()%1300) + 300,750,50,550};
            saisissable = true;
            effet.setbouclier(false);
            effet.setstat_modif(0.0);
            effet.setval_modif(2.0);
        }

        else if(idEvent == 4)//Romain DMG up
        {
            zoneAction = {(rand()%1300) + 300,750,50,550};
            saisissable = true;
            effet.setbouclier(false);
            effet.setstat_modif(0.0);
            effet.setval_modif(-2.0);
        }

        else if(idEvent == 5)// Romain speed up
        {
            zoneAction = {(rand()%1300) + 300,750,50,550};
            saisissable = true;
            duree = 3000;
            effet.setbouclier(false);
            effet.setstat_modif(1.0);
            effet.setval_modif(2.0);
        }

        else// Romain speed down
        {
            zoneAction = {(rand()%1300) + 300,750,50,550};
            saisissable = true;
            duree = 3000;
            effet.setbouclier(false);
            effet.setstat_modif(1.0);
            effet.setval_modif(0.5);
        }
    }
}

Evenement::~Evenement()
{

}
