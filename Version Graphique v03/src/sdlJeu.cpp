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
	dimx = 2000;
	dimy = 1600;

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



	// Afficher le sprite de la classe
	im_classe.draw(renderer,0,0,2000,1000);

	//Affiche Justine
	if (!J.getetat().getSaut())
	{
        if (J.getorientation())
        {
            if (J.getetat().getAccroupi())
            {
                im_justineAccroupiD.draw(renderer,J.getposition().x,J.getposition().y,400,400);
            }
            else
            {
                im_justineD.draw(renderer,J.getposition().x,J.getposition().y,400,400);
            }
        }
        else
        {
            if (J.getetat().getAccroupi())
            {
                im_justineAccroupiG.draw(renderer,J.getposition().x,J.getposition().y,400,400);
            }
            else
            {
                im_justineG.draw(renderer,J.getposition().x,J.getposition().y,400,400);
            }
        }
	}
	else
	{
        if (J.getorientation())
        {
            im_justineSautD.draw(renderer,J.getposition().x,J.getposition().y,400,400);
        }
        else
        {
            im_justineSautG.draw(renderer,J.getposition().x,J.getposition().y,400,400);
        }
	}

	//Affiche Tancrede
    if (!T.getetat().getSaut())
	{
        if (T.getorientation())
        {
            if (T.getetat().getAccroupi())
            {
                im_tancredeAccroupiD.draw(renderer,T.getposition().x,T.getposition().y,400,400);
            }
            else
            {
                im_tancredeD.draw(renderer,T.getposition().x,T.getposition().y,400,400);
            }
        }
        else
        {
            if (T.getetat().getAccroupi())
            {
                im_tancredeAccroupiG.draw(renderer,T.getposition().x,T.getposition().y,400,400);
            }
            else
            {
                im_tancredeG.draw(renderer,T.getposition().x,T.getposition().y,400,400);
            }
        }
	}
	else
	{
        if (T.getorientation())
        {
            im_tancredeSautD.draw(renderer,T.getposition().x,T.getposition().y,400,400);
        }
        else
        {
            im_tancredeSautG.draw(renderer,T.getposition().x,T.getposition().y,400,400);
        }
	}
    //Affiche le second sprite de la classe
    im_classe2.draw(renderer,0,0,2000,1000);
}

void sdlJeu::sdlBoucle ()
{

    im_loading.loadFromFile("data/loading.jpg", renderer);
    SDL_RenderClear(renderer);
    im_loading.draw(renderer,0,0,2000,1000);
    SDL_RenderPresent(renderer);

    SDL_Point J = {300,500};
    SDL_Point T = {1400,500};
    SDL_Rect r1 = {0,0,300,1000};
    SDL_Rect r2 = {100,800,1800,100};
    SDL_Rect r3 = {1600,0,300,900};
    Zone decor(3);
    decor.settab(0, r1);
    decor.settab(1, r2);
    decor.settab(0, r3);
    Personnage Justine("data/justineD.png", J, true);
    Personnage Tancrede("data/tancredeG.png", T, false);
    //Variable pour gérer l'état accroupi
    Etat e;

   bool quit = false;
   SDL_Event events;

    im_classe.loadFromFile("data/classe.jpg",renderer);
    im_classe2.loadFromFile("data/classe2.png",renderer);

    im_justineD.loadFromFile(Justine.getnomImage(),renderer);
    im_justineSautD.loadFromFile("data/justineSautD.png",renderer);
    im_justineAccroupiD.loadFromFile("data/justineAccroupiD.png",renderer);
    im_justineG.loadFromFile("data/justineG.png",renderer);
    im_justineSautG.loadFromFile("data/justineSautG.png",renderer);
    im_justineAccroupiG.loadFromFile("data/justineAccroupiG.png",renderer);

    im_tancredeG.loadFromFile(Tancrede.getnomImage(),renderer);
    im_tancredeSautG.loadFromFile("data/tancredeSautG.png",renderer);
    im_tancredeAccroupiG.loadFromFile("data/tancredeAccroupiG.png",renderer);
    im_tancredeD.loadFromFile("data/tancredeD.png",renderer);
    im_tancredeSautD.loadFromFile("data/tancredeSautD.png",renderer);
    im_tancredeAccroupiD.loadFromFile("data/tancredeAccroupiD.png",renderer);

    unsigned int Jsaut, Tsaut;

    const Uint8 *state = SDL_GetKeyboardState(NULL);

	// tant que ce n'est pas la fin ...
	while (!quit) {

		// tant qu'il y a des evenements à traiter (cette boucle n'est pas bloquante)
		while (SDL_PollEvent(&events))
		{
		    if (events.type == SDL_QUIT) quit = true;           // Si l'utilisateur a clique sur la croix de fermeture
		    else if (events.type == SDL_KEYDOWN)
			{              // Si une touche est enfoncee ou si une touche n'est pas enfoncee (aka tout le temps)

				if(state[SDL_SCANCODE_A])
				{
                        Justine.vaGauche(decor);
				}

				if(state[SDL_SCANCODE_D])
				{
                        Justine.vaDroite(decor);
				}

				if(state[SDL_SCANCODE_S])
				{
                   Justine.accroupir();
				}


                if (state[SDL_SCANCODE_W] && !Justine.getetat().getSaut())
                {
                    Jsaut = Justine.saute();
                }

				if(state[SDL_SCANCODE_LEFT])
				{
                        Tancrede.vaGauche(decor);

				}

				if(state[SDL_SCANCODE_RIGHT])
				{
                        Tancrede.vaDroite(decor);
				}

                if(state[SDL_SCANCODE_DOWN])
				{
                        Tancrede.accroupir();
				}
				else
				{
                        Tancrede.getetat().lever();
				}

				if(state[SDL_SCANCODE_ESCAPE] || state[SDL_SCANCODE_G])
				{
                        quit = true;
				}

				if (state[SDL_SCANCODE_UP] && !Tancrede.getetat().getSaut())
                {
                    Tsaut = Tancrede.saute();
                }
            }

            const Uint8* pKeyStates = SDL_GetKeyboardState(NULL);
            if ( !pKeyStates[SDL_SCANCODE_S] )
            {
                e = Justine.getetat();
                e.setAccroupi(false);
                Justine.setetat(e);
            }

            if ( !pKeyStates[SDL_SCANCODE_DOWN] )
            {
                e = Tancrede.getetat();
                e.setAccroupi(false);
                Tancrede.setetat(e);
            }
		}

		if (Jsaut < SDL_GetTicks() - 500 && Justine.getetat().getSaut())
            {
                Justine.descendre();
            }

            if (Tsaut < SDL_GetTicks() - 500 && Tancrede.getetat().getSaut())
            {
                Tancrede.descendre();
            }
		// on affiche le jeu sur le buffer caché
		sdlAff(Justine, Tancrede);

		// on permute les deux buffers (cette fonction ne doit se faire qu'une seule fois dans la boucle)
        SDL_RenderPresent(renderer);
	}
}
