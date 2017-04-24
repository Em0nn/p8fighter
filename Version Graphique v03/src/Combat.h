#ifndef COMBAT_H_INCLUDED
#define COMBAT_H_INCLUDED

#include "Personnage.h"

class Combat
{
    private:
        Personnage J;
        Personnage T;
        bool event;
        SDL_Point posJ;
        SDL_Point posT;
        Zone decor;

    public:

        /** \brief constructeur par défaut
         */
        Combat();


        /** \brief constructeur
         *
         * \param
         * \param
         */
        Combat(Personnage J, Personnage T, bool e, SDL_Point posJ, SDL_Point posT);


        /** \brief destructeur
         */
        ~Combat();

//accesseurs
        Personnage getJ();
        Personnage getT();
        bool getevent();
        SDL_Point getPosJ ();
        SDL_Point getPosT ();
        Zone getDecor ();

//mutateurs
        void setJ (Personnage J);
        void setT (Personnage T);
        bool setevent(bool e);
        void setPosJ(SDL_Point r1);
        void setPosT(SDL_Point r2);
        void setDecor (Zone d);

//fonctions


};

#endif
