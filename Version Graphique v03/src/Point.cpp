#include "Point.h"
#include <cassert>
#include <iostream>

using namespace std;

Point::Point()
{
    x=0;
    y=0;
}

Point::Point(unsigned int a, unsigned int b)
{
    x=a;
    y=b;
}


//get
unsigned int Point::getx() const
{
    return x;
}

unsigned int Point::gety() const
{
    return y;
}


//set
void Point::setx(unsigned int a)
{
    x=a;
}

void Point::sety(unsigned int b)
{
    y=b;
}

void Point::setxety(unsigned int a, unsigned int b)
{
    x=a;
    y=b;
}

void Point::testRegression()
{

    Point p1;

    assert(((int)p1.getx()==0)&&((int)p1.gety()==0)); // test régression pour constructeur par def.

    p1.setx(80);p1.sety(81);

    assert(((int)p1.getx()==80)&&((int)p1.gety()==81)); // test régression pour valeurs arbitraires positives (set)

    Point p2(3,6);

    assert(((int)p2.getx()==3)&&((int)p2.gety()==6)); // test régression pour constructeur par copie

}

Point::~Point()
{

}
