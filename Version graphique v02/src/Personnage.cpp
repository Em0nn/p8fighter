#include "Personnage.h"

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
Personnage::Personnage (const char* i, SDL_Point pos)
{
    nomImage = i;
    position=pos;
}

//fonctions get
const char* Personnage::getnomImage() const
{
    return nomImage;
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

void Personnage::setposition(SDL_Point p)
{
    position=p;
}


//fonctions de direction
void Personnage::vaGauche(const Zone& z)
{
    position = {position.x-10,position.y};
    /*if ((position.x - 1)>= 0)
    {
        SDL_Point p = {position.x-1,position.y};
        if (!z.inclusionPoint(&p))
        {
            position=p;
        }
    }*/

}

void Personnage::vaDroite(const Zone& z)
{

    position = {position.x+10,position.y};
    /*SDL_Point p = {position.x+1,position.y};
    if (!z.inclusionPoint(&p))
    {
        position=p;
    }*/
}

void Personnage::saute(const Zone& z)
{

}

Personnage::~Personnage() {

}
