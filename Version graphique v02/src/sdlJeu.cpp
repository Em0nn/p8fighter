#include <cassert>
#include <time.h>
#include "sdlJeu.h"
#include <stdlib.h>
#include "Personnage.h"

#include <iostream>
using namespace std;

float temps ()
{
    return float(SDL_GetTicks()) / CLOCKS_PER_SEC;  // conversion des ms en secondes en divisant par 1000
}

// ============= CLASS IMAGE =============== //

Image::Image ()
{
    surface = NULL;
    texture = NULL;
    has_changed = false;
}

void Image::loadFromFile (const char* filename, SDL_Renderer * renderer)
{
    surface = IMG_Load(filename);
    if (surface == NULL) {
        string nfn = string("../") + filename;
        cout << "Error: cannot load "<< filename <<". Trying "<<nfn<<endl;
        surface = IMG_Load(nfn.c_str());
        if (surface == NULL) {
            nfn = string("../") + nfn;
            surface = IMG_Load(nfn.c_str());
        }
    }
    if (surface == NULL) {
        cout<<"Error: cannot load "<< filename <<endl;
        exit(1);
    }

    SDL_Surface * surfaceCorrectPixelFormat = SDL_ConvertSurfaceFormat(surface,SDL_PIXELFORMAT_ARGB8888,0);
    SDL_FreeSurface(surface);
    surface = surfaceCorrectPixelFormat;

    texture = SDL_CreateTextureFromSurface(renderer,surface);
    if (texture == NULL) {
        cout << "Error: problem to create the texture of "<< filename<< endl;
        exit(1);
    }
}

void Image::draw (SDL_Renderer * renderer, int x, int y, int w, int h) {
    int ok;
    SDL_Rect r;
    r.x = x;
    r.y = y;
    r.w = (w<0)?surface->w:w;
    r.h = (h<0)?surface->h:h;

    if (has_changed)
    {
        ok = SDL_UpdateTexture(texture,NULL,surface->pixels,surface->pitch);
        assert(ok == 0);
        has_changed = false;
    }

    ok = SDL_RenderCopy(renderer,texture,NULL,&r);
    assert(ok == 0);
}

// ============= CLASS SDLJEU =============== //

sdlJeu::sdlJeu ()
{
    // Initialisation de la SDL
    //The surface contained by the window SDL_Surface* screenSurface = NULL;
    SDL_Surface* screenSurface = NULL;

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        cout << "Erreur lors de l'initialisation de la SDL : " << SDL_GetError() << endl;SDL_Quit();exit(1);
    }

    if (TTF_Init() != 0) {
        cout << "Erreur lors de l'initialisation de la SDL_ttf : " << SDL_GetError() << endl;SDL_Quit();exit(1);
    }

    int imgFlags = IMG_INIT_PNG | IMG_INIT_JPG;
    if( !(IMG_Init(imgFlags) & imgFlags)) {
        cout << "SDL_image could not initialize! SDL_image Error: " << IMG_GetError() << endl;SDL_Quit();exit(1);
    }

	int dimx, dimy;
	dimx = 1000;
	dimy = 800;

    // Creation de la fenetre
    window = SDL_CreateWindow("P8_Fighter", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, dimx, dimy, SDL_WINDOW_SHOWN);
    if (window == NULL) {
        cout << "Erreur lors de la creation de la fenetre : " << SDL_GetError() << endl; SDL_Quit(); exit(1);
    }

    renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);



}

sdlJeu::~sdlJeu ()
{
    TTF_Quit();
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void sdlJeu::sdlAff (Personnage J, Personnage T) {
	//Remplir l'écran de blanc
    SDL_SetRenderDrawColor(renderer, 230, 240, 255, 255);
    SDL_RenderClear(renderer);

    im_classe.loadFromFile("data/classe.jpg",renderer);
    im_justine.loadFromFile(J.getnomImage(),renderer);
    im_tancrede.loadFromFile(T.getnomImage(),renderer);

	// Afficher le sprite de la classe
	im_classe.draw(renderer,0,0,1000,500);
	im_justine.draw(renderer,J.getposition().x,J.getposition().y,100,100);
	im_tancrede.draw(renderer,T.getposition().x,T.getposition().y,100,100);

}

void sdlJeu::sdlBoucle ()
{

    SDL_Point J = {100,350};
    SDL_Point T = {850,350};
    SDL_Rect r1 = {0,0,50,450};
    SDL_Rect r2 = {50,400,900,50};
    SDL_Rect r3 = {950,0,50,450};
    Zone decor(3);
    decor.settab(0, r1);
    decor.settab(0, r2);
    decor.settab(0, r3);
    Personnage Justine("data/justine.png", J);
    Personnage Tancrede("data/tancrede.png", T);

   bool quit = false;
   SDL_Event events;

	// tant que ce n'est pas la fin ...
	while (!quit) {

		// tant qu'il y a des evenements à traiter (cette boucle n'est pas bloquante)
		while (SDL_PollEvent(&events))
		{
			if (events.type == SDL_QUIT) quit = true;           // Si l'utilisateur a clique sur la croix de fermeture
			else if (events.type == SDL_KEYDOWN)
			{              // Si une touche est enfoncee
				switch (events.key.keysym.scancode)
				{
                    case SDL_SCANCODE_Q:
                        Justine.vaGauche(decor);
                        break;

                    case SDL_SCANCODE_D:
                        Justine.vaDroite(decor);
                        break;

                    case SDL_SCANCODE_4:
                        Tancrede.vaGauche(decor);
                        break;

                    case SDL_SCANCODE_6:
                        Tancrede.vaDroite(decor);
                        break;

                    case SDL_SCANCODE_ESCAPE:
                    case SDL_SCANCODE_G:
                        quit = true;
                        break;

                    default: break;
				}
			}
		}

		// on affiche le jeu sur le buffer caché
		sdlAff(Justine, Tancrede);

		// on permute les deux buffers (cette fonction ne doit se faire qu'une seule fois dans la boucle)
        SDL_RenderPresent(renderer);
        SDL_Delay(3000);
	}
}
