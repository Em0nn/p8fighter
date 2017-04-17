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
	dimy = 1500;

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
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
    SDL_RenderClear(renderer);



	// Afficher le sprite de la classe
	im_classe.draw(renderer,0,0,2000,1000);

	//Affiche Justine
	if ( !J.getetat().getSaut() && J.getorientation() && J.getetat().getAccroupi() && J.getetat().getAttaque() == 0)
	{
        im_justineAccroupiD.draw(renderer,J.getposition().x,J.getposition().y,400,400);
	}
	else if ( !J.getetat().getSaut() && J.getorientation() && !J.getetat().getAccroupi() && J.getetat().getAttaque() == 0)
	{
        im_justineD.draw(renderer,J.getposition().x,J.getposition().y,400,400);
	}
	else if ( !J.getetat().getSaut() && J.getorientation() && !J.getetat().getAccroupi() && J.getetat().getAttaque() == 1)
	{
        im_justineDeb1D.draw(renderer,J.getposition().x,J.getposition().y,450,400);
	}
	else if ( !J.getetat().getSaut() && J.getorientation() && !J.getetat().getAccroupi() && J.getetat().getAttaque() == 2)
	{
        im_justineDeb2D.draw(renderer,J.getposition().x-50,J.getposition().y-50,400,450);
	}
	else if ( !J.getetat().getSaut() && J.getorientation() && J.getetat().getAccroupi() && J.getetat().getAttaque() == 1)
	{
        im_justineAcc1D.draw(renderer,J.getposition().x - 50,J.getposition().y,450,400);
	}
	else if ( !J.getetat().getSaut() && J.getorientation() && J.getetat().getAccroupi() && J.getetat().getAttaque() == 2)
	{
        im_justineAcc2D.draw(renderer,J.getposition().x,J.getposition().y,400,400);
	}
	else if ( !J.getetat().getSaut() && !J.getorientation() && J.getetat().getAccroupi() && J.getetat().getAttaque() == 0)
	{
        im_justineAccroupiG.draw(renderer,J.getposition().x,J.getposition().y,400,400);
	}
	else if ( !J.getetat().getSaut() && !J.getorientation() && !J.getetat().getAccroupi() && J.getetat().getAttaque() == 0)
	{
        im_justineG.draw(renderer,J.getposition().x,J.getposition().y,400,400);
	}
	else if ( !J.getetat().getSaut() && !J.getorientation() && !J.getetat().getAccroupi() && J.getetat().getAttaque() == 1)
	{
        im_justineDeb1G.draw(renderer,J.getposition().x - 50,J.getposition().y,450,400);
	}
	else if ( !J.getetat().getSaut() && !J.getorientation() && !J.getetat().getAccroupi() && J.getetat().getAttaque() == 2)
	{
        im_justineDeb2G.draw(renderer,J.getposition().x +50,J.getposition().y - 50,400,450);
	}
	else if ( !J.getetat().getSaut() && !J.getorientation() && J.getetat().getAccroupi() && J.getetat().getAttaque() == 1)
	{
        im_justineAcc1G.draw(renderer,J.getposition().x - 50,J.getposition().y,450,400);
	}
	else if ( !J.getetat().getSaut() && !J.getorientation() && J.getetat().getAccroupi() && J.getetat().getAttaque() == 2)
	{
        im_justineAcc2G.draw(renderer,J.getposition().x - 50,J.getposition().y,450,400);
	}
	else if ( J.getetat().getSaut() && J.getorientation())
	{
        im_justineSautD.draw(renderer,J.getposition().x,J.getposition().y,400,400);
	}
	else
	{
        im_justineSautG.draw(renderer,J.getposition().x,J.getposition().y,400,400);
	}



	//Affiche Tancrede
    if ( !T.getetat().getSaut() && T.getorientation() && T.getetat().getAccroupi())
	{
        im_tancredeAccroupiD.draw(renderer,T.getposition().x,T.getposition().y,400,400);
	}
	else if ( !T.getetat().getSaut() && T.getorientation() && !T.getetat().getAccroupi() && T.getetat().getAttaque() == 0)
	{
        im_tancredeD.draw(renderer,T.getposition().x,T.getposition().y,400,400);
	}
	else if ( !T.getetat().getSaut() && T.getorientation() && !T.getetat().getAccroupi() && T.getetat().getAttaque() == 1)
	{
        im_tancredeDeb1D.draw(renderer,T.getposition().x,T.getposition().y,400,400);
	}
	else if ( !T.getetat().getSaut() && T.getorientation() && !T.getetat().getAccroupi() && T.getetat().getAttaque() == 2)
	{
        im_tancredeDeb2D.draw(renderer,T.getposition().x - 50,T.getposition().y,400,400);
	}
	else if ( !T.getetat().getSaut() && !T.getorientation() && T.getetat().getAccroupi())
	{
        im_tancredeAccroupiG.draw(renderer,T.getposition().x,T.getposition().y,400,400);
	}
	else if ( !T.getetat().getSaut() && !T.getorientation() && !T.getetat().getAccroupi() && T.getetat().getAttaque() == 0)
	{
        im_tancredeG.draw(renderer,T.getposition().x,T.getposition().y,400,400);
	}
	else if ( !T.getetat().getSaut() && !T.getorientation() && !T.getetat().getAccroupi() && T.getetat().getAttaque() == 1)
	{
        im_tancredeDeb1G.draw(renderer,T.getposition().x,T.getposition().y,400,400);
	}
	else if ( !T.getetat().getSaut() && !T.getorientation() && !T.getetat().getAccroupi() && T.getetat().getAttaque() == 2)
	{
        im_tancredeDeb2G.draw(renderer,T.getposition().x + 50,T.getposition().y,400,400);
	}
	else if ( T.getetat().getSaut() && T.getorientation())
	{
        im_tancredeSautD.draw(renderer,T.getposition().x,T.getposition().y,400,400);
	}
	else
	{
        im_tancredeSautG.draw(renderer,T.getposition().x,T.getposition().y,400,400);
	}


    //Affiche le second sprite de la classe
    im_classe2.draw(renderer,0,0,2000,1000);

    //affiche les barres de vie
    im_VieJu40.draw(renderer,475,25,500,50);
    im_VieTancou70.draw(renderer,1075,25,500,50);
}

void sdlJeu::sdlBoucle ()
{

    im_loading.loadFromFile("data/loading.jpg", renderer);
    SDL_RenderClear(renderer);
    im_loading.draw(renderer,0,0,2000,1000);
    SDL_RenderPresent(renderer);

    SDL_Point J = {300,500};
    SDL_Point T = {1400,500};
    SDL_Rect r1 = {0,0,50,1000};
    SDL_Rect r2 = {100,800,1800,100};
    SDL_Rect r3 = {1550,0,300,900};
    Zone decor(3);
    decor.settab(0, r1);
    decor.settab(1, r2);
    decor.settab(2, r3);
    Personnage Justine("data/justineD.png", J, true);
    Personnage Tancrede("data/tancredeG.png", T, false);

    //Variable pour gérer l'état accroupi
    Etat e;

    bool quit = false;
    SDL_Event events;

    im_classe.loadFromFile("data/classe.png",renderer);
    im_classe2.loadFromFile("data/classe2.png",renderer);


    //Sprites Justine
    im_justineD.loadFromFile(Justine.getnomImage(),renderer);
    im_justineG.loadFromFile("data/justineG.png",renderer);

    im_justineDeb1D.loadFromFile("data/juDeb1D.png",renderer);
    im_justineDeb1G.loadFromFile("data/juDeb1G.png",renderer);

    im_justineDeb2D.loadFromFile("data/juDeb2D.png",renderer);
    im_justineDeb2G.loadFromFile("data/juDeb2G.png",renderer);

    im_justineSautD.loadFromFile("data/justineSautD.png",renderer);
    im_justineSautG.loadFromFile("data/justineSautG.png",renderer);

    im_justineAccroupiD.loadFromFile("data/justineAccroupiD.png",renderer);
    im_justineAccroupiG.loadFromFile("data/justineAccroupiG.png",renderer);

    im_justineAcc1D.loadFromFile("data/juAcc1D.png",renderer);
    im_justineAcc1G.loadFromFile("data/juAcc1G.png",renderer);

    im_justineAcc2D.loadFromFile("data/juAcc2D.png",renderer);
    im_justineAcc2G.loadFromFile("data/juAcc2G.png",renderer);




    //Sprites Tancrede
    im_tancredeD.loadFromFile("data/tancredeD.png",renderer);
    im_tancredeG.loadFromFile(Tancrede.getnomImage(),renderer);

    im_tancredeDeb1D.loadFromFile("data/tancredeDeb1D.png",renderer);
    im_tancredeDeb1G.loadFromFile("data/tancredeDeb1G.png",renderer);

    im_tancredeDeb2D.loadFromFile("data/tancredeDeb2D.png",renderer);
    im_tancredeDeb2G.loadFromFile("data/tancredeDeb2G.png",renderer);

    im_tancredeSautD.loadFromFile("data/tancredeSautD.png",renderer);
    im_tancredeSautG.loadFromFile("data/tancredeSautG.png",renderer);

    im_tancredeAccroupiD.loadFromFile("data/tancredeAccroupiD.png",renderer);
    im_tancredeAccroupiG.loadFromFile("data/tancredeAccroupiG.png",renderer);

    im_tancredeAcc1D.loadFromFile("data/tancredeAcc1D.png",renderer);
    im_tancredeAcc1G.loadFromFile("data/tancredeAcc1G.png",renderer);

    im_tancredeAcc2D.loadFromFile("data/tancredeAcc2D.png",renderer);
    im_tancredeAcc2G.loadFromFile("data/tancredeAcc2G.png",renderer);





    //Barres de vie
    im_VieJu100.loadFromFile("data/VieJu100.png",renderer);
    im_VieJu90.loadFromFile("data/VieJu90.png",renderer);
    im_VieJu80.loadFromFile("data/VieJu80.png",renderer);
    im_VieJu70.loadFromFile("data/VieJu70.png",renderer);
    im_VieJu60.loadFromFile("data/VieJu60.png",renderer);
    im_VieJu50.loadFromFile("data/VieJu50.png",renderer);
    im_VieJu40.loadFromFile("data/VieJu40.png",renderer);
    im_VieJu30.loadFromFile("data/VieJu30.png",renderer);
    im_VieJu20.loadFromFile("data/VieJu20.png",renderer);
    im_VieJu10.loadFromFile("data/VieJu10.png",renderer);
    im_VieJu00.loadFromFile("data/VieJu00.png",renderer);

    im_VieTancou100.loadFromFile("data/VieTancou100.png",renderer);
    im_VieTancou90.loadFromFile("data/VieTancou90.png",renderer);
    im_VieTancou80.loadFromFile("data/VieTancou80.png",renderer);
    im_VieTancou70.loadFromFile("data/VieTancou70.png",renderer);
    im_VieTancou60.loadFromFile("data/VieTancou60.png",renderer);
    im_VieTancou50.loadFromFile("data/VieTancou50.png",renderer);
    im_VieTancou40.loadFromFile("data/VieTancou40.png",renderer);
    im_VieTancou30.loadFromFile("data/VieTancou30.png",renderer);
    im_VieTancou20.loadFromFile("data/VieTancou20.png",renderer);
    im_VieTancou10.loadFromFile("data/VieTancou10.png",renderer);
    im_VieTancou00.loadFromFile("data/VieTancou00.png",renderer);

    unsigned int Jsaut, Tsaut, Jatt, Tatt;

    const Uint8 *state = SDL_GetKeyboardState(NULL);

	// tant que ce n'est pas la fin ...
	while (!quit) {

		// tant qu'il y a des evenements à traiter (cette boucle n'est pas bloquante)
		while (SDL_PollEvent(&events))
		{
		    if (events.type == SDL_QUIT) quit = true;           // Si l'utilisateur a clique sur la croix de fermeture
		    else if (events.type == SDL_KEYDOWN)
			{              // Si une touche est enfoncee ou si une touche n'est pas enfoncee (aka tout le temps)

				//Touches Justine

				if(state[SDL_SCANCODE_A])
				{
                        Justine.vaGauche(decor);
				}

				if(state[SDL_SCANCODE_D])
				{
                        Justine.vaDroite(decor);
				}

                if (state[SDL_SCANCODE_W] && !Justine.getetat().getSaut())
                {
                    Jsaut = Justine.saute();
                }

                if (state[SDL_SCANCODE_T] && !Justine.getetat().getAttaque() && !Justine.getetat().getSaut())
                {
                    Jatt = Justine.attaquer(1);
                }

                if (state[SDL_SCANCODE_Y] && !Justine.getetat().getAttaque() && !Justine.getetat().getSaut())
                {
                    Jatt = Justine.attaquer(2);
                }

                //Touches Tancrède
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

				if (state[SDL_SCANCODE_UP] && !Tancrede.getetat().getSaut() && !Tancrede.getetat().getAttaque())
                {
                    Tsaut = Tancrede.saute();
                }

                if (state[SDL_SCANCODE_KP_4] && !Tancrede.getetat().getAttaque() && !Tancrede.getetat().getSaut())
                {
                    Tatt = Tancrede.attaquer(1);
                }

                if (state[SDL_SCANCODE_KP_5] && !Tancrede.getetat().getAttaque() && !Tancrede.getetat().getSaut())
                {
                    Tatt = Tancrede.attaquer(2);
                }


                //Sortie du jeu
                if(state[SDL_SCANCODE_ESCAPE] || state[SDL_SCANCODE_G])
				{
                        quit = true;
				}

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

        if (Tatt < SDL_GetTicks() - 250 && Tancrede.getetat().getAttaque())
        {
            Tancrede.FinAtt();
        }

        if (Jatt < SDL_GetTicks() - 250 && Justine.getetat().getAttaque())
        {
            Justine.FinAtt();
        }

        // on affiche le jeu sur le buffer caché
        sdlAff(Justine, Tancrede);

        const Uint8* pKeyStates = SDL_GetKeyboardState(NULL);
        if ( !pKeyStates[SDL_SCANCODE_S] )
        {
            Justine.lever();
        }
        else
        {
            Justine.accroupir();
        }

        if ( !pKeyStates[SDL_SCANCODE_DOWN] )
        {
            Tancrede.lever();
        }


		// on permute les deux buffers (cette fonction ne doit se faire qu'une seule fois dans la boucle)
        SDL_RenderPresent(renderer);
	}
}
