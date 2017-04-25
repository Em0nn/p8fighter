#include "Environnement.h"
#include <cassert>
#include <iostream>
#include <string.h>
#include <fstream>

using namespace std;

Environnement::Environnement()
{
    decor = new unsigned int[1];
    Zone limite();
    decor[0]=0;

    xmax=0;
    ymax=0;
}


Environnement::Environnement(Zone z, unsigned int x, unsigned int y)
{
//    Zone limite(z);

    xmax=x;
    ymax=y;

    decor = new unsigned int[x*y];
    Point p(0, 0);
    for (unsigned int j=0; j<y; j++)
    {
        for (unsigned int i=0; i<x; i++)
        {
            p.setx(i);
            p.sety(j);
            if (z.inclusionPoint(p))
            {
                decor[i+j*x]=1;
            }
            else
            {
                decor[i+j*x]=0;
            }
        }
    }
}




//Fonctions get
Zone Environnement::getlimite() const
{
    return limite;
}

unsigned int Environnement::getdecor(Point p) const
{
    return decor[p.getx()+p.gety()*xmax];
}

unsigned int Environnement::getxmax() const
{
    return xmax;
}

unsigned int Environnement::getymax() const
{
    return ymax;
}



//Fonctions set
void Environnement::setlimite(Zone l)
{
    limite=l;
}

void Environnement::setxmax(unsigned int x)
{
    xmax=x;
}

void Environnement::setymax(unsigned int y)
{
    ymax=y;
}

void Environnement::setdecor(unsigned int x, unsigned int y, unsigned int c)
{
    decor[x+y*xmax]=c;
}


void Environnement::testRegression()
{
    Environnement e();

    assert(((int)getxmax()==0)
         &&((int)getymax()==0));

    assert((int)getlimite().gettab(0).getPosX()==0);
    //assert((int)getlimite().gettab(0).getPosY()==0);
    //assert((int)getlimite().gettab(0).getHaut()==0);
    //assert((int)getlimite().gettab(0).getLarg()==0);

    assert((int)decor[0]==0);
           // Test de régression du constructeur par défaut


    Point p00(0,0);
    Point p01(0,1);
    Point p10(1,0);
    Point p11(1,1);
    Rectangle r(0,0,0,0);
    Zone z(1);
    z.settab(0, r);
//    Environnement e1(z,2,2);

    //assert(((int)getxmax()==0)&&((int)getymax()==0)&& ((int)getdecor(p00)==1) && ((int)getdecor(p01)==0) && ((int)getdecor(p10)==0) && ((int)getdecor(p11)==0)); //Teste si le rectangle 2x2 avec le point 0x0 faisant partie du décors est correctement géré par le constructeur par copie

    //Test de regression des fonctions set
    setxmax(3);
    assert((int)getxmax()==3);

    setymax(4);
    assert((int)getymax()==4);

    setdecor(0,1,2);
    assert((int)getdecor(p01)==2);

    r.setPosX(1);
    z.settab(0,r);
    /*setlimite(z);
    assert((int)getlimite().gettab(0).getPosX()==1);*/
}



Environnement::~Environnement()
{
    //
    limite.~Zone();
}
