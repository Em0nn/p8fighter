#ifndef COMBAT_H_INCLUDED
#define COMBAT_H_INCLUDED

#include "Personnage.h"

class Combat
{
    private:
        Personnage J1;
        Personnage J2;
        //Evenement * event;
        //Icone J1_icone;
        //Icone J2_icone;
        //Jauge vieJ1;
        //Jauge vieJ2;
        //Jauge ultiJ1;
        //Jauge ultiJ2;
        SDL_Point posJ1Init;
        SDL_Point posJ2Init;
        //Animation compte_a_rebours;
        //Animation entreeJ1;
        //Animation entreeJ2;
        //int temps_av_cb;
        //Environnement decor;
        //Rectangle fenetre;

    public:

        /** \brief constructeur par défaut
         */
        Combat();


        /** \brief constructeur
         *
         * \param
         * \param
         */
        Combat(Personnage j1, Personnage j2, Evenement * e, Icone i_j1, Icone i_j2, Jauge v_j1, Jauge v_j2, Jauge u_j1, Jauge u_j2, Rectangle posj1, Rectangle posj2, Animation compte, Animation e_j1, Animation e_j2, int temps, Environnement d, Rectangle r);


        /** \brief destructeur
         */
        ~Combat();

//accesseurs
        Personnage getJ1();
        Personnage getJ2();
/*        Evenement * getEvent ();
        Icone getJ1_icone ();
        Icone getJ2_icone ();
        Jauge getVieJ1 ();
        Jauge getVieJ2 ();
        Jauge getUltiJ1 ();
        Jauge getUltiJ2 (); */
        Rectangle getPosJ1Init ();
        Rectangle getPosJ2Init ();
/*        Animation getCompte_a_rebours ();
        Animation getEntreeJ1 ();
        Animation getEntreeJ2 ();*/
        int temps_av_cb ();
        Environnement getDecor ();
        Rectangle getFenetre();

//mutateurs
        void setJ1 (Personnage j1);
        void setJ2 (Personnage j2);
        void setEvent (Evenement * e);
/*        void setJ1_Icone (Icone i_j1);
        void setJ2_Icone (Icone i_j2);
        void setVieJ1 (Jauge v_j1);
        void setVieJ2 (Jauge v_j2);
        void setUltiJ1 (Jauge u_j1);
        void setUltiJ2 (Jauge u_j2);*/
        void setPosJ1Init(Rectangle r1);
        void setPosJ2Init(Rectangle r2);
        void setCompte_a_rebours (animation compte);
        void setEntreeJ1 (Animation a_j1);
        void setEntreeJ2 (Animation a_j2);
        void setTemps-av-cb (int temps);
        void setDecor (Environnement d);
        void setFenetre (rectangle f);

};
#endif
