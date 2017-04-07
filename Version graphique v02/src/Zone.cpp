#include "Zone.h"
#include <iostream>

#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>

using namespace std;

Zone::Zone()
{
    SDL_Rect r;
    tab=new SDL_Rect[1];
    nb_rectangle=1;
    tab[0]=r;
}

Zone::Zone(int i)
{
    tab = new SDL_Rect[i];
    nb_rectangle=i;
    SDL_Rect r;
    for(int k=0; k<i; k++)
    {
        tab[k]=r;
    }
}

SDL_Rect Zone::gettab(int pos)
{
    return tab[pos];
}

unsigned int Zone::getnb_rectangle()
{
    return nb_rectangle;
}

void Zone::settab(int pos, SDL_Rect r)
{
    tab[pos]=r;
}

void Zone::setnb_rectangle(int n)
{
    nb_rectangle=n;
}

bool Zone::inclusionPoint(const SDL_Point * p)
{
    for(unsigned int i=0; i<nb_rectangle; i++)
    {
        SDL_Rect r;
        if(SDL_EnclosePoints(p, 1 , &tab[i], &r)==SDL_TRUE)
        {
            return true;
        }
    }
    return false;
}

/*void Zone::testRegression()
{
    Zone z;
    Zone z2(3);
    Zone z3(2);

    SDL_Rect r;
    SDL_Rect r2(3,3,3,3);

    SDL_Point p1;
    SDL_Point p2(3,3);

    // test du constructeur par défaut
    assert (((int)z.getnb_rectangle()==1)&&((int)z.gettab(0).getHaut()==0)&&((int)z.gettab(0).getLarg()==0)&&((int)z.gettab(0).getPosX()==0)&&((int)z.gettab(0).getPosY()==0));
    //test du constructeur par copie
    assert (((int)z2.getnb_rectangle()==3) && ((int)z2.gettab(0).getHaut()==0)&&((int)z2.gettab(0).getLarg()==0)&&((int)z2.gettab(0).getPosX()==0)&&((int)z2.gettab(0).getPosY()==0) && ((int)z2.gettab(1).getHaut()==0)&&((int)z2.gettab(1).getLarg()==0)&&((int)z2.gettab(1).getPosX()==0)&&((int)z2.gettab(1).getPosY()==0) && (z2.gettab(2).getHaut()==0)&&(z2.gettab(2).getLarg()==0)&&(z2.gettab(2).getPosX()==0)&&(z2.gettab(2).getPosY()==0));

    //test du get (un peu inutile)
    assert (((int)z3.getnb_rectangle()==2)&&((int)z3.gettab(0).getHaut()==0)&&((int)z3.gettab(0).getLarg()==0)&&((int)z3.gettab(0).getPosX()==0)&&((int)z3.gettab(0).getPosY()==0)&&((int)z3.gettab(1).getHaut()==0)&&((int)z3.gettab(1).getLarg()==0)&&((int)z3.gettab(1).getPosX()==0)&&((int)z3.gettab(1).getPosY()==0));

    //test des set
    z3.setnb_rectangle(3);
    assert ((int)z3.getnb_rectangle()==3);

    z3.settab(0, r2);
    assert ((z3.gettab(0).getPosX()==3)&&(z3.gettab(0).getPosY()==3)&&(z3.gettab(0).getLarg()==3)&&(z3.gettab(0).getHaut()==3));

    assert((z.inclusionRect(r))&&(!z.inclusionRect(r2))); //test régression pour l'inclusion d'un rectangle dans une zone (cas vrai puis cas faux)

    assert((z.inclusionPoint(p1))&&(!z.inclusionPoint(p2))); //test régression pour l'inclusion d'un point dans une zone (cas vrai puis cas faux)

}*/

Zone::~Zone()
{
    delete [] tab;
}
