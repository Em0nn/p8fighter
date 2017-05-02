#ifndef ACTION_H
#define ACTION_H


#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
#include <cassert>

class Action
{
    private:

        int temps_app;
        int duree;
        SDL_Rect Hit;

    public:

        Action();

        Action(int tps, int dur, SDL_Rect r);

        //get
        int gettemps_app();
        int getduree();
        SDL_Rect getHit();


        //set
        void settemps_app(int tps);
        void setduree(int dur);
        void setHit(SDL_Rect r);


        ~Action();




};



#endif // ACTION_H
