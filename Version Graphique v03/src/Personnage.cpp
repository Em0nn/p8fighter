#include "Personnage.h"
#include "Etat.h"
#include <cassert>
#include <iostream>
#include <string.h>
#include <fstream>

using namespace std;

//constructeur par défaut
Personnage::Personnage ()
{
    nomImage="NULL";
    position.x = position.y = 0.0;
}

//constructeur par copie
Personnage::Personnage (const char* i, SDL_Point pos, bool o)
{
    nomImage = i;
    orientation=o;
    position=pos;
}

//fonctions get
const char* Personnage::getnomImage() const
{
    return nomImage;
}

Etat Personnage::getetat() const
{
    return etat;
}

bool Personnage::getorientation() const
{
    return orientation;
}

SDL_Point Personnage::getposition() const
{
    return position;
}

//fonctions set
void Personnage::setnomImage(const char* i)
{
    nomImage=i;
}

void Personnage::setetat(Etat e)
{
    etat=e;
}

void Personnage::setposition(SDL_Point p)
{
    position=p;
}

void Personnage::setorientation(bool o)
{
    orientation = o;
}

//fonctions de direction
void Personnage::vaGauche(const Zone& z)
{
    if ((position.x - 1)>= 0)
    {
        SDL_Point p = {position.x-30,position.y};
        //if (!z.inclusionPoint(&p))
        //{
            position=p;
        //}
    }
    orientation = false;

}

void Personnage::vaDroite(const Zone& z)
{
    SDL_Point p = {position.x+30,position.y};
    if (!z.inclusionPoint(&p))
    {
        position=p;
    }
    orientation = true;
}

unsigned int Personnage::saute()
{
    position = {position.x,position.y-300};
    etat.sauter ();
    return SDL_GetTicks();
}

void Personnage::descendre()
{
    position = {position.x,position.y+300};
    etat.setSaut(false);
}

void Personnage::accroupir()
{
    etat.accroupir();
}

Personnage::~Personnage()
{

}
