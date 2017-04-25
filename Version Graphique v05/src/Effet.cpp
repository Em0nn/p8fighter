#include "Effet.h"

using namespace std;

Effet::Effet()
{
    bouclier = false;
    stat_modif = 0.0;
    val_modif = 0.0;
}

Effet::Effet(bool b, float stat, float val)
{
    bouclier = b;
    stat_modif = stat;
    val_modif = val;
}

bool Effet::getbouclier()
{
    return bouclier;
}

float Effet::getstat_modif()
{
    return stat_modif;
}

float Effet::getval_modif()
{
    return val_modif;
}

void Effet::setbouclier(bool b)
{
    bouclier = b;
}

void Effet::setstat_modif(float stat)
{
    stat_modif = stat;
}

void Effet::setval_modif(float val)
{
    val_modif = val;
}

Effet::~Effet()
{

}
