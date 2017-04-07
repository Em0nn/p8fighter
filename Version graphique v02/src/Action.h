#ifndef ACTION_H
#define ACTION_H
#include "Zone.h"
#include "Animation.h"
#include "Etat.h"
#include <cassert>

class Action
{
    private:

        int deplacement;
        int temps_app;
        int duree;
        int valeur;
        Zone zone_action;
        Animation anim;
        Etat etat;
        std::string son;

    public:

        Action();

        Action(int dep, int tps, int dur, int val, Zone z, Animation a, Etat e, std::string s);

        //get
        int getdeplacement();
        int gettemps_app();
        int getduree();
        int getvaleur();
        Zone getzone_action();
        Animation getanim();
        Etat getetat();
        std::string getson();


        //set
        void setdeplacement(int dep);
        void settemps_app(int tps);
        void setduree(int dur);
        void setvaleur(int val);
        void setzone_action(Zone z);
        void setanim(Animation a);
        void setetat(Etat e);
        void setson(std::string s);


        ~Action();




};



#endif // ACTION_H
