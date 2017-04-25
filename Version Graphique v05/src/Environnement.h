#ifndef ENVIRONNEMENT_H_INCLUDED
#define ENVIRONNEMENT_H_INCLUDED

#include <string.h>
#include "Zone.h"


class Environnement
{
    private:

        Zone limite;
        unsigned int xmax;
        unsigned int ymax;
        unsigned int * decor;


    public:


        Environnement();

        Environnement(Zone z, unsigned int x, unsigned int y);




        //Fonctions get
        Zone getlimite() const;

        unsigned int getxmax() const;

        unsigned int getymax() const;

        unsigned int getdecor(Point p) const;


        //Fonctions set
        void setlimite(Zone z);

        void setxmax(unsigned int x);

        void setymax(unsigned int y);

        void setdecor(unsigned int x, unsigned int y, unsigned int c);

        void testRegression();

        ~Environnement();
};

#endif // ENVIRONNEMENT_H_INCLUDED
