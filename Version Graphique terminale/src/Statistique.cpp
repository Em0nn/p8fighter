#include "Statistique.h"


Statistique::Statistique()
{
    vie = 10;            //0
    vitesse_att = 300.0; //1
    vitesse_depl = 7.0;  //1
}


Statistique::Statistique(int v, float v_att, float v_depl)
{
    vie = v;
    vitesse_att = v_att;
    vitesse_depl = v_depl;
}

int Statistique::getvie()
{
    return vie;
}


float Statistique::getvitesse_att()
{
    return vitesse_att;
}

float Statistique::getvitesse_depl()
{
    return vitesse_depl;
}

void Statistique::setvie(int v)
{
    vie = v;
}

void Statistique::setvitesse_att(float v_att)
{
    vitesse_att = v_att;
}

void Statistique::setvitesse_depl(float v_depl)
{
    vitesse_depl = v_depl;
}

Statistique::~Statistique()
{

}
