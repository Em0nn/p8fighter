#include "Rectangle.h"
#include <iostream>
#include <cassert>

using namespace std;

Rectangle::Rectangle()
{
    A->setxety(0,0);
    B->setxety(0,0);
    C->setxety(0,0);
    D->setxety(0,0);
}

Rectangle::Rectangle(Point * O, unsigned int largeur, unsigned int longueur)
{
    A->setxety(O->getx(), O->gety());
    B->setxety(O->getx() + largeur, O->gety());
    C->setxety(O->getx(), O->gety() + longueur);
    D->setxety(O->getx() + largeur, O->gety() + longueur);
}

Point * Rectangle::getA()
{
    return A;
}

Point * Rectangle::getB()
{
    return B;
}

Point * Rectangle::getC()
{
    return C;
}

Point * Rectangle::getD()
{
    return D;
}

void Rectangle::setA(unsigned int x, unsigned int y)
{
    A->setxety(x,y);
}

void Rectangle::setB(unsigned int x, unsigned int y)
{
    B->setxety(x,y);
    larg = B->getx() - A->getx();
}

void Rectangle::setC(unsigned int x, unsigned int y)
{
    C->setxety(x,y);
    haut = C->gety() - A->gety();
}

void Rectangle::setD(unsigned int x, unsigned int y)
{
    D->setxety(x,y);
    larg = D->getx() - A->getx();
    haut = D->gety() - A->gety();
}

void Rectangle::setLarg(unsigned int largeur)
{
    larg = largeur;
    B->setx(A->getx()+largeur);
    D->setx(A->getx()+largeur);
}

void Rectangle::setHaut(unsigned int hauteur)
{
    haut = hauteur;
    C->sety(A->gety()+hauteur);
    D->sety(A->gety()+hauteur);
}

bool Rectangle::inclusionPoint(const Point p)
{
    return(((A->getx())<=(p.getx()))&&(p.getx()<=B->getx())&&(A->gety()<=p.gety())&&(p.gety()<=C->gety()));
}

/*bool Rectangle::inclusionRect(const Rectangle * r)
{

}*/
