#ifndef _SDLJEU_H
#define _SDLJEU_H

#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
#include "Personnage.h"


//! \brief Pour gérer une image avec SDL2
class Image {

private:

    SDL_Surface * surface;
    SDL_Texture * texture;
    bool has_changed;

public:
    Image () ;
    void loadFromFile (const char* filename, SDL_Renderer * renderer);
    void draw (SDL_Renderer * renderer, int x, int y, int w=-1, int h=-1);
};



/**
    La classe gérant le jeu avec un affichage SDL
*/
class sdlJeu {

private :

	//Jeu jeu;

    SDL_Window * window;
    SDL_Renderer * renderer;
    TTF_Font * font;

    Image im_loading;

    Image im_classe;
    Image im_classe2;

    Image im_justineG;
    Image im_justineSautG;
    Image im_justineAccroupiG;
    Image im_justineD;
    Image im_justineSautD;
    Image im_justineAccroupiD;

    Image im_tancredeG;
    Image im_tancredeSautG;
    Image im_tancredeAccroupiG;
    Image im_tancredeD;
    Image im_tancredeSautD;
    Image im_tancredeAccroupiD;


public :

    sdlJeu ();
    ~sdlJeu ();
    void sdlBoucle ();
    void sdlAff (Personnage J, Personnage T);

};

#endif
