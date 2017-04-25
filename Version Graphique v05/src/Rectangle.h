#ifndef RECTANGLE_H_INCLUDED
#define RECTANGLE_H_INCLUDED
#include "Point.h"

class Rectangle
{
private:

    Point * A;
    Point * B;
    Point * C;
    Point * D;
    int larg = B->getx() - A->getx();
    int haut = C->gety() - A->gety();

public:

    Rectangle();

    Rectangle(Point * O, unsigned int largeur, unsigned int hauteur);

    ~Rectangle();

    Point * getA();

    Point * getB();

    Point * getC();

    Point * getD();

    void setA(unsigned int x, unsigned int y);

    void setB(unsigned int x, unsigned int y);

    void setC(unsigned int x, unsigned int y);

    void setD(unsigned int x, unsigned int y);

    void setLarg(unsigned int largeur);

    void setHaut(unsigned int hauteur);

    void testRegression();

    bool inclusionRect(Rectangle r2);

    bool inclusionPoint(Point p);

};



#endif // RECTANGLE_H_INCLUDED
