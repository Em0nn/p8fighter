//#include "Combat.h"
#include <cassert>
#include <iostream>
#include <string.h>
#include <fstream>

#include "Combat.h"
#include "Personnage.h"

using namespace std;

Combat::Combat()
{

    SDL_Point ptJ = {300,500};
    SDL_Point ptT = {1400,500};
    SDL_Rect r1 = {0,0,50,1000};
    SDL_Rect r2 = {100,800,1800,100};
    SDL_Rect r3 = {1550,0,300,900};
    Zone d(3);
    d.settab(0, r1);
    d.settab(1, r2);
    d.settab(2, r3);
    Personnage Ju("data/justineD.png", ptJ, true);
    Personnage Tancou("data/tancredeG.png", ptT, false);

    J = Ju;
    T = Tancou;
    event = false;
    posJ = ptJ;
    posT = ptT;
    decor = d;
}


Combat::Combat(Personnage Ju, Personnage Tancou, bool e, SDL_Point posJ, SDL_Point posT)
{
    J = Ju;
    T = Tancou;
}
