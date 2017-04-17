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

    Image im_VieJu100;
    Image im_VieJu90;
    Image im_VieJu80;
    Image im_VieJu70;
    Image im_VieJu60;
    Image im_VieJu50;
    Image im_VieJu40;
    Image im_VieJu30;
    Image im_VieJu20;
    Image im_VieJu10;
    Image im_VieJu00;

    Image im_VieTancou100;
    Image im_VieTancou90;
    Image im_VieTancou80;
    Image im_VieTancou70;
    Image im_VieTancou60;
    Image im_VieTancou50;
    Image im_VieTancou40;
    Image im_VieTancou30;
    Image im_VieTancou20;
    Image im_VieTancou10;
    Image im_VieTancou00;

    //Images Justine
    Image im_justineG;
    Image im_justineD;

    Image im_justineDeb1G; //coup de poing debout
    Image im_justineDeb1D;

    Image im_justineDeb2G; //coup de pied debout
    Image im_justineDeb2D;

    Image im_justineSautG;
    Image im_justineSautD;

    Image im_justineAccroupiG;
    Image im_justineAccroupiD;

    Image im_justineAcc1G; //coup de poing accroupi
    Image im_justineAcc1D;

    Image im_justineAcc2G; //coup de pied accroupi
    Image im_justineAcc2D;


    //Images Tancrede
    Image im_tancredeG;
    Image im_tancredeD;

    Image im_tancredeDeb1G;
    Image im_tancredeDeb1D;

    Image im_tancredeDeb2G;
    Image im_tancredeDeb2D;

    Image im_tancredeSautG;
    Image im_tancredeSautD;

    Image im_tancredeAccroupiG;
    Image im_tancredeAccroupiD;

    Image im_tancredeAcc1G;
    Image im_tancredeAcc1D;

    Image im_tancredeAcc2G;
    Image im_tancredeAcc2D;




public :

    sdlJeu ();
    ~sdlJeu ();
    void sdlBoucle ();
    void sdlAff (Personnage J, Personnage T);

};

#endif
