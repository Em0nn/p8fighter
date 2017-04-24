#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#include "Icone.h"
#include "Animation.h"

class Menu
{
    private:

        Icone * persos;
        Icone j1;
        Icone j2;
        Animation animation;

    public:

        /** \brief constructeur par défaut
         */
        Menu();


        /** \brief constructeur
         */
        Menu(Icone * persos, Icone j1, Icone j2, Animation anim);


        /** \brief destructeur
         */
        ~Menu();

//accesseurs
        Icone * getPersos ();
        Icone getJ1 ();
        Icone getJ2 ();
        Icone getAnimation ();

//mutateurs
        void setPersos (Icone * persos);
        void setJ1 (Icone j1);
        void setJ2 (Icone j2);
        void setAnimation (Animation anim);
};
#endif
