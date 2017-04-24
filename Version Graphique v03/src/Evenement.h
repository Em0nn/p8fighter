#ifndef EVENEMENT_H_INCLUDED
#define EVENEMENT_H_INCLUDED
#include "Zone.h"
#include "Animation.h"
#include "Effet.h"

class Evenement
{
    private:

        SDL_Rect zoneAction;
        bool saisissable;
        int duree;
        Animation animation;
        Effet effet;

    public:

        /** \brief constructeur par défaut
         */
        Evenement();


        /** \brief constructeur
         */
        Evenement(Zone zoneAct, int duree, bool saisiss, Animation anim, Effet eff);


        /** \brief destructeur
         */
        ~Evenement();

//accesseurs
        bool getSaisissable ();
        int getDuree ();
        Zone getZoneAction ();
        Animation getAnimation ();
        Effet getEffet ();

//mutateurs
        void setZoneAction (Zone a);
        void setSaisissable (bool  s);
        void setDuree (int d);
        void setAnimation (Animation anim);
        void setAnimation (Effet effet);

//fonctions
};
#endif
