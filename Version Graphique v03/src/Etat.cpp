#include "Etat.h"

using namespace std;

Etat::Etat()
{
    accroupi = false;
    couche = false;
    saut = false;
}

Etat::Etat (bool a, bool c, bool s)
{
    accroupi = a;
    couche = c;
    saut = s;
}

Etat::~Etat()
{

}

bool Etat::getAccroupi()
{
    return accroupi;
}

bool Etat::getCouche()
{
    return couche;
}

bool Etat::getSaut()
{
    return saut;
}

void Etat::setAccroupi(bool a)
{
    accroupi = a;
}

void Etat::setCouche (bool c)
{
    couche = c;
}

void Etat::setSaut(bool s)
{
    saut = s;
}

void Etat::accroupir ()
{
    accroupi=true;
    couche= false;
}

void Etat::coucher ()
{
    accroupi=false;
    couche=true;
    saut=false;
}

void Etat::sauter ()
{
    couche = false;
    accroupi=false;
    saut = true;
}

void Etat::lever ()
{
    couche = false;
    accroupi = false;
    saut = false;
}
