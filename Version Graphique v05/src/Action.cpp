#include "Action.h"
#include "Zone.h"
using namespace std;

Action::Action()
{
    temps_app = 0;
    duree = 0;
    Hit = {0,0,0,0};

}


Action::Action(int tps, int dur, SDL_Rect r)
{
    temps_app = tps;
    duree = dur;
    Hit = r;
}

int Action::gettemps_app()
{
    return temps_app;
}

int Action::getduree()
{
    return duree;
}

SDL_Rect Action::getHit()
{
    return Hit;
}

void Action::settemps_app(int tps)
{
    temps_app = tps;
}

void Action::setduree(int dur)
{
    duree = dur;
}

Action::~Action()
{

}
