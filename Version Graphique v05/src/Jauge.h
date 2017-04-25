#ifndef JAUGE_H_INCLUDED
#define JAUGE_H_INCLUDED
#include "Rectangle.h"
#include "Animation.h"

class Jauge
{
    private:

        int valeur;
        Rectangle position;
        Animation graphisme;

    public:

        /** \brief constructeur par défaut
         */
        Jauge();


        /** \brief constructeur
         */
        Jauge(int val, Rectangle pos, Animation graph);


        /** \brief destructeur
         */
        ~Jauge();

//accesseurs
        int  getValeur ();
        Rectangle getPosition ();
        Animation getGraphisme ();

//mutateurs
        void setValeur (int v);
        void setPosition (Rectangle pos);
        void setGraphisme (Animation graph);

//fonctions
};
#endif
