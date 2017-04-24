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

