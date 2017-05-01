#ifndef STATISTIQUE_H
#define STATISTIQUE_H
#include "Action.h"

class Statistique
{
    private:

        int vie;
        float vitesse_att;
        float vitesse_depl;

    public:

        Statistique();

        Statistique(int v, float v_att, float v_depl);

        //get
        int getvie();
        float getvitesse_att();
        float getvitesse_depl();

        //set
        void setvie(int v);
        void setvitesse_att(float v_att);
        void setvitesse_depl(float v_depl);

        ~Statistique();
};


#endif // STATISTIQUE_H
