#include "Personnage.h"
#include "Etat.h"
#include "Action.h"
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
    vie = 10;
}

//constructeur par copie
Personnage::Personnage (const char* i, SDL_Point pos, bool o)
{
    nomImage = i;
    orientation=o;
    position=pos;
    Action Deb1D(); //1 <- code attaque
    Action Deb1G(); //2
    Action Deb2D(); //3
    Action Deb2G(); //4
    Action Acc1D(); //5
    Action Acc1G(); //6
    Action Acc2D(); //7
    Action Acc2G(); //8
    vie = 10;

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
Action Personnage::getDeb1D()
{
    return Deb1D;
}
Action Personnage::getDeb1G()
{
    return Deb1G;
}
Action Personnage::getDeb2D()
{
    return Deb2D;
}
Action Personnage::getDeb2G()
{
    return Deb2G;
}
Action Personnage::getAcc1D()
{
    return Acc1D;
}
Action Personnage::getAcc1G()
{
    return Acc1G;
}
Action Personnage::getAcc2D()
{
    return Acc2D;
}
Action Personnage::getAcc2G()
{
    return Acc2G;
}
SDL_Rect Personnage::getHitBoxAtt() const
{
    return HitBoxAtt;
}
SDL_Rect Personnage::getHitBoxPerso() const
{
    return HitBoxPerso;
}
int Personnage::getvie()
{
    return vie;
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
void Personnage::setDeb1D(Action a)
{
    Deb1D = a;
}
void Personnage::setDeb1G(Action a)
{
    Deb1G = a;
}
void Personnage::setDeb2D(Action a)
{
    Deb2D = a;
}
void Personnage::setDeb2G(Action a)
{
    Deb2G = a;
}
void Personnage::setAcc1D(Action a)
{
    Acc1D = a;
}
void Personnage::setAcc1G(Action a)
{
    Acc1G = a;
}
void Personnage::setAcc2D(Action a)
{
    Acc2D = a;
}
void Personnage::setAcc2G(Action a)
{
    Acc2G = a;
}
void Personnage::setHitBoxAtt(int a, int b, int c, int d)
{
    HitBoxAtt.x = a;
    HitBoxAtt.y = b;
    HitBoxAtt.w = c;
    HitBoxAtt.h = d;
}
void Personnage::setHitBoxPerso(int a, int b, int c, int d)
{
    HitBoxPerso.x = a;
    HitBoxPerso.y = b;
    HitBoxPerso.w = c;
    HitBoxPerso.h = d;
}
void Personnage::setvie(int i)
{
    vie = i;
}


//fonctions de direction
void Personnage::vaGauche(const Zone& z)
{
    if ((position.x - 30)>= 0)
    {
        SDL_Point p = {position.x-50,position.y};
        if (!z.inclusionPoint(&p))
        {
            position=p;
        }
    }
    orientation = false;

}

void Personnage::vaDroite(const Zone& z)
{
    SDL_Point p = {position.x+50,position.y};
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

void Personnage::lever()
{
    etat.lever();
}

unsigned int Personnage::attaquer(int i)
{
    etat.attaquer(i);
    return SDL_GetTicks();
}

void Personnage::FinAtt()
{
    etat.setAttaque(0);
}

Personnage::~Personnage()
{

}
