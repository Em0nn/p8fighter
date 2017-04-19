#include "Action.h"
#include "Zone.h"
using namespace std;

Action::Action()
{
    temps_app = 0;
    duree = 1;
    zone_action = Zone();
}


Action::Action(int tps, int dur, Zone z)
{
    temps_app = tps;
    duree = dur;
    zone_action = z;
}

int Action::gettemps_app()
{
    return temps_app;
}

int Action::getduree()
{
    return duree;
}

Zone Action::getzone_action()
{
    return zone_action;
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
