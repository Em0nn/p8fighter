#ifndef STATISTIQUE_H
#define STATISTIQUE_H
#include "Action.h"

class Statistique
{
    private:

        int vie;
        int vitesse_att;
        int ulti;
        int vitesse_depl;
        int portee;
        Action * tab;

    public:

        Statistique();

        Statistique(int vie, int vitesse_att, int u, int vitesse_depl, int p, Action * t);

        //get
        int getvie();
        int getvitesse_att();
        int getulti();
        int getvitesse_depl();
        int getportee();
        Action * gettab();

        //set
        void setvie(int vie);
        void setvitesse_att(int vitesse_att);
        void setulti(int u);
        void setvitesse_depl(int vitesse_depl);
        void setportee(int p);
        void settab(Action * t);

        ~Statistique();




};


#endif // STATISTIQUE_H
