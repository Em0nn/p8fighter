#ifndef EVENEMENT_H_INCLUDED
#define EVENEMENT_H_INCLUDED
#include "Effet.h"
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
class Evenement
{
    private:
        int idEvent;
        SDL_Rect zoneAction;
        bool saisissable;
        int duree;
        Effet effet;

    public:

        /** \brief constructeur par défaut
         */
        Evenement();


        /** \brief constructeur
         */
        Evenement(SDL_Rect zoneAct, int dure, bool saisiss, Effet eff);


        /** \brief destructeur
         */
        ~Evenement();

//accesseurs
        bool getSaisissable ();
        int getDuree ();
        SDL_Rect getZoneAction ();
        Effet getEffet ();
        int getIdEvent();

//mutateurs
        void setZoneAction (SDL_Rect za);
        void setSaisissable (bool  s);
        void setDuree (int d);
        void setEffet (Effet ef);
        void setIdEvent(int i);


//fonctions
        void NouvelEvent();
};
#endif
