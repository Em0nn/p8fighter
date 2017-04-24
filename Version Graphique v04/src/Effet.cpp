#include "Effet.h"

using namespace std;

Effet::Effet()
{
    bouclier = false;
    stat_modif = 0;
    val_modif = 0;
}

Effet::Effet(bool b, int stat, int val)
{
    bouclier = b;
    stat_modif = stat;
    val_modif = val;
}

bool Effet::getbouclier()
{
    return bouclier;
}

int Effet::getstat_modif()
{
    return stat_modif;
}

int Effet::getval_modif()
{
    return val_modif;
}

void Effet::setbouclier(bool b)
{
    bouclier = b;
}

void Effet::setstat_modif(int stat)
{
    stat_modif = stat;
}

void Effet::setval_modif(int val)
{
    val_modif = val;
}

Effet::~Effet()
{

}
