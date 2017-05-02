#ifndef COMBAT_H_INCLUDED
#define COMBAT_H_INCLUDED
#include "Image.h"
#include "Personnage.h"
#include "Evenement.h"

#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>

class Combat
{
    private:

        //Variables SDL
        SDL_Window * window;
        SDL_Renderer * renderer;
        TTF_Font * font;

        //Variables du combat
        Personnage J;
        Personnage T;
        Evenement event;
        bool eventDispo;
        SDL_Point posJ;
        SDL_Point posT;

        //Images
        Image im_loading;
        Image im_classe;
        Image im_classe2;
        Image im_hitbox;

        //Adjuvants
        Image im_Google;
        Image im_Mama;
        Image im_Mama0;
        Image im_Mama1;
        Image im_Mama2;
        Image im_Mama3;

        Image im_InfuV;
        Image im_InfuP;
        Image im_RomainEntre;
        Image im_RomainVerse;

        Image im_FelixEntre0;
        Image im_FelixEntre1;
        Image im_FelixAction;
        Image im_Rayon;

        Image im_Dejou;
        Image im_Attal;

        Image im_VieJu100;
        Image im_VieJu90;
        Image im_VieJu80;
        Image im_VieJu70;
        Image im_VieJu60;
        Image im_VieJu50;
        Image im_VieJu40;
        Image im_VieJu30;
        Image im_VieJu20;
        Image im_VieJu10;
        Image im_VieJu00;

        Image im_VieTancou100;
        Image im_VieTancou90;
        Image im_VieTancou80;
        Image im_VieTancou70;
        Image im_VieTancou60;
        Image im_VieTancou50;
        Image im_VieTancou40;
        Image im_VieTancou30;
        Image im_VieTancou20;
        Image im_VieTancou10;
        Image im_VieTancou00;

        //Images Justine
        Image im_justineG;
        Image im_justineD;

        Image im_justineDeb1G; //coup de poing debout
        Image im_justineDeb1D;

        Image im_justineDeb2G; //coup de pied debout
        Image im_justineDeb2D;

        Image im_justineSautG;
        Image im_justineSautD;

        Image im_justineAccroupiG;
        Image im_justineAccroupiD;

        Image im_justineAcc1G; //coup de poing accroupi
        Image im_justineAcc1D;

        Image im_justineAcc2G; //coup de pied accroupi
        Image im_justineAcc2D;


        //Images Tancrede
        Image im_tancredeG;
        Image im_tancredeD;

        Image im_tancredeDeb1G;
        Image im_tancredeDeb1D;

        Image im_tancredeDeb2G;
        Image im_tancredeDeb2D;

        Image im_tancredeSautG;
        Image im_tancredeSautD;

        Image im_tancredeAccroupiG;
        Image im_tancredeAccroupiD;

        Image im_tancredeAcc1G;
        Image im_tancredeAcc1D;

        Image im_tancredeAcc2G;
        Image im_tancredeAcc2D;

        Image im_VictoireJustine;
        Image im_VictoireTancrede;

    public:

        /** \brief constructeur par défaut
         */
        Combat();


        /** \brief constructeur
         *
         * \param
         * \param
         */
        Combat(Personnage J, Personnage T, bool e, SDL_Point posJu, SDL_Point posTancou);


        /** \brief destructeur
         */
        ~Combat();

//accesseurs
        Personnage getJ();
        Personnage getT();
        Evenement getevent();
        bool geteventDispo();
        SDL_Point getPosJ ();
        SDL_Point getPosT ();

//mutateurs
        void setJ (Personnage Ju);
        void setT (Personnage Tancou);
        void setevent(Evenement e);
        void seteventDispo(bool e);
        void setPosJ(SDL_Point ptJ);
        void setPosT(SDL_Point ptT);

//fonctions d'affichage
        void InitSDL();
        void ChargementImages();
        void AffAdjuvants();
        void AffCombat();
        void AffBarresDeVie();
        void AffJustine();
        void AffTancrede();

//Boucle de combat
        void BoucleCombat();
        void Adjuvants(int & tMama, int & tAttal, int & tDejou, int & tFelix, int & tRomain, int& RomainX, int& RomainY, bool& objDejaPris);
        void RecupererEffets(bool& objDejaPris);
        void ReinitHitBox();
        bool touche(const SDL_Rect *a, const SDL_Rect *b);

};

#endif
