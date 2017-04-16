#ifndef ZONE_H
#define ZONE_H
#include <iostream>
#include <cassert>

#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>

class Zone
{
    private:

        SDL_Rect * tab;
        unsigned int nb_rectangle;

    public:

        Zone();

        Zone(int i);

        //get

        SDL_Rect gettab(int pos);
        unsigned int getnb_rectangle();

        //set

        void settab(int pos, SDL_Rect r);
        void setnb_rectangle(int n);

        bool inclusionPoint(const SDL_Point * p) const;

        void testRegression();

        ~Zone();

};

#endif // ZONE_H

