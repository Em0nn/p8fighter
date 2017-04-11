#ifndef PERSONNAGE_H
#define PERSONNAGE_H

#include <cstring>
/*#include "Animation.h"
#include "Competence.h"
#include "Statistique.h"
#include "Etat.h"
#include "Action.h"*/
#include "Zone.h"
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>

class Personnage
{
    private:

        const char* nomImage;
//        Animation aspect;
//        Competence ulti;
//        Statistique stats;
//        Etat etat;
//        Action * tab;
//        bool orientation;
//        bool bouclier;
        SDL_Point position;

    public:

        Personnage();

        Personnage(const char* i, /*Animation an, Competence u, Statistique s, Etat e, Action * ac, bool o, bool b, */SDL_Point p);

        //fonctions get
        const char* getnomImage() const;
/*        Animation getaspect();
        Competence getulti();
        Statistique getstats();
        Etat getetat();
        Action * gettab();
        bool getorientation();
        bool getbouclier();*/
        SDL_Point getposition() const;

        //fonctions set
        void setnomImage(const char* i);
/*        void setaspect(Animation an);
        void setulti(Competence u);
        void setstats(Statistique s);
        void setetat(Etat e);
        void settab(Action * ac);
        void setorientation(bool o);
        void setbouclier(bool b);*/
        void setposition(SDL_Point p);

        void vaGauche(const Zone& z);
        void vaDroite(const Zone& z);
        void saute(const Zone& z);

        ~Personnage();




};

#endif // PERSONNAGE_H
