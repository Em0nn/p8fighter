#ifndef ACTION_H
#define ACTION_H

#include "Zone.h"
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
//#include "Animation.h"
//#include "Etat.h"
#include <cassert>

class Action
{
    private:

        //int deplacement;
        int temps_app;
        int duree;
        //int valeur;
        SDL_Rect Hit;
        //Animation anim;
        //Etat etat;
        //std::string son;

    public:

        Action();

        Action(/*int dep,*/ int tps, int dur/*, int val*/, SDL_Rect r/*, Animation a, Etat e, std::string s*/);

        //get
        //int getdeplacement();
        int gettemps_app();
        int getduree();
        //int getvaleur();
        SDL_Rect getHit();
        //Animation getanim();
        //Etat getetat();
        //std::string getson();


        //set
        //void setdeplacement(int dep);
        void settemps_app(int tps);
        void setduree(int dur);
        //void setvaleur(int val);
        void setzone_action(SDL_Rect);
        //void setanim(Animation a);
        //void setetat(Etat e);
        //void setson(std::string s);


        ~Action();




};



#endif // ACTION_H
