/*#include <iostream>
#include <cassert>

//librairie propre au P8_Fighter
#include "Rectangle.h"
#include "Environnement.h"
#include "Zone.h"
#include "Point.h"*/
#include "sdlJeu.h"

//Librairie utile au SDL
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>


int main(int argc, char *argv[])
{

    sdlJeu sj;
    sj.sdlBoucle();

    return 0;

}


