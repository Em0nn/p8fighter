#include <cassert>
#include <time.h>
#include "sdlJeu.h"
#include <stdlib.h>
#include "Personnage.h"
#include "Statistique.h"
#include "Evenement.h"

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
/*
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

*/sdlJeu::~sdlJeu ()
{
    TTF_Quit();
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}/*

/*void sdlJeu::sdlAff (Personnage J, Personnage T) {
	//Remplir l'écran de blanc
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
    SDL_RenderClear(renderer);



	// Afficher le sprite de la classe
	im_classe.draw(renderer,0,0,2000,1000);

    const SDL_Rect G = J.getHitBoxAtt();
    const SDL_Rect *ptrG = &G;
    const SDL_Rect H = T.getHitBoxPerso();
    const SDL_Rect *ptrH = &H;
    if (touche(ptrH,ptrH))
    {

        J.setvie(J.getvie() - 1);
        im_hitbox.draw(renderer, J.getHitBoxAtt().x, J.getHitBoxAtt().y, J.getHitBoxAtt().w, J.getHitBoxAtt().h);

    }
    //im_hitbox.draw(renderer, J.getHitBoxPerso().x, J.getHitBoxPerso().y, J.getHitBoxPerso().w, J.getHitBoxPerso().h);
    //im_hitbox.draw(renderer, T.getHitBoxAtt().x, T.getHitBoxAtt().y, T.getHitBoxAtt().w, T.getHitBoxAtt().h);
    //im_hitbox.draw(renderer, T.getHitBoxPerso().x, T.getHitBoxPerso().y, T.getHitBoxPerso().w, T.getHitBoxPerso().h);

	//affiche les barres de vie
    if (J.getstats().getvie() >= 10) im_VieJu100.draw(renderer,J.getposition().x + 20 + !J.getorientation()*150,J.getposition().y - 40 + J.getetat().getAccroupi()*150,200,25);
    else if (J.getstats().getvie() >= 9) im_VieJu90.draw(renderer,J.getposition().x + 20 + !J.getorientation()*150,J.getposition().y - 40 + J.getetat().getAccroupi()*150,200,25);
    else if (J.getstats().getvie() >= 8) im_VieJu80.draw(renderer,J.getposition().x + 20 + !J.getorientation()*150,J.getposition().y - 40 + J.getetat().getAccroupi()*150,200,25);
    else if (J.getstats().getvie() >= 7) im_VieJu70.draw(renderer,J.getposition().x + 20 + !J.getorientation()*150,J.getposition().y - 40 + J.getetat().getAccroupi()*150,200,25);
    else if (J.getstats().getvie() >= 6) im_VieJu60.draw(renderer,J.getposition().x + 20 + !J.getorientation()*150,J.getposition().y - 40 + J.getetat().getAccroupi()*150,200,25);
    else if (J.getstats().getvie() >= 5) im_VieJu50.draw(renderer,J.getposition().x + 20 + !J.getorientation()*150,J.getposition().y - 40 + J.getetat().getAccroupi()*150,200,25);
    else if (J.getstats().getvie() >= 4) im_VieJu40.draw(renderer,J.getposition().x + 20 + !J.getorientation()*150,J.getposition().y - 50 + J.getetat().getAccroupi()*150,200,25);
    else if (J.getstats().getvie() >= 3) im_VieJu30.draw(renderer,J.getposition().x + 20 + !J.getorientation()*150,J.getposition().y - 50 + J.getetat().getAccroupi()*150,200,25);
    else if (J.getstats().getvie() >= 2) im_VieJu20.draw(renderer,J.getposition().x + 20 + !J.getorientation()*150,J.getposition().y - 50 + J.getetat().getAccroupi()*150,200,25);
    else if (J.getstats().getvie() >= 1) im_VieJu10.draw(renderer,J.getposition().x + 20 + !J.getorientation()*150,J.getposition().y - 50 + J.getetat().getAccroupi()*150,200,25);
    else
    {
        im_VieJu00.draw(renderer,J.getposition().x + 20 + !J.getorientation()*150,J.getposition().y - 50 + J.getetat().getAccroupi()*150,200,25);
        J.setvie(10);
    }


    if (T.getstats().getvie() >= 10) im_VieTancou100.draw(renderer,T.getposition().x + 50 + !T.getorientation()*100,T.getposition().y - 80 + T.getetat().getAccroupi()*150,200,25);
    else if (T.getstats().getvie() >= 9) im_VieTancou90.draw(renderer,T.getposition().x + 50 + !T.getorientation()*100,T.getposition().y - 80 + T.getetat().getAccroupi()*150,200,25);
    else if (T.getstats().getvie() >= 8) im_VieTancou80.draw(renderer,T.getposition().x + 50 + !T.getorientation()*100,T.getposition().y - 80 + T.getetat().getAccroupi()*150,200,25);
    else if (T.getstats().getvie() >= 7) im_VieTancou70.draw(renderer,T.getposition().x + 50 + !T.getorientation()*100,T.getposition().y - 80 + T.getetat().getAccroupi()*150,200,25);
    else if (T.getstats().getvie() >= 6) im_VieTancou60.draw(renderer,T.getposition().x + 50 + !T.getorientation()*100,T.getposition().y - 80 + T.getetat().getAccroupi()*150,200,25);
    else if (T.getstats().getvie() >= 5) im_VieTancou50.draw(renderer,T.getposition().x + 50 + !T.getorientation()*100,T.getposition().y - 80 + T.getetat().getAccroupi()*150,200,25);
    else if (T.getstats().getvie() >= 4) im_VieTancou40.draw(renderer,T.getposition().x + 50 + !T.getorientation()*100,T.getposition().y - 80 + T.getetat().getAccroupi()*150,200,25);
    else if (T.getstats().getvie() >= 3) im_VieTancou30.draw(renderer,T.getposition().x + 50 + !T.getorientation()*100,T.getposition().y - 80 + T.getetat().getAccroupi()*150,200,25);
    else if (T.getstats().getvie() >= 2) im_VieTancou20.draw(renderer,T.getposition().x + 50 + !T.getorientation()*100,T.getposition().y - 80 + T.getetat().getAccroupi()*150,200,25);
    else if (T.getstats().getvie() >= 1) im_VieTancou10.draw(renderer,T.getposition().x + 50 + !T.getorientation()*100,T.getposition().y - 80 + T.getetat().getAccroupi()*150,200,25);
    else
    {
        im_VieTancou00.draw(renderer,T.getposition().x + 50 + !T.getorientation()*100,T.getposition().y - 80 + T.getetat().getAccroupi()*150,200,25);
    }

	//Affiche Justine
	if ( !J.getetat().getSaut() && J.getorientation() && J.getetat().getAccroupi() && J.getetat().getAttaque() == 0)
	{
        im_justineAccroupiD.draw(renderer,J.getposition().x,J.getposition().y,400,400);
	}
	else if ( !J.getetat().getSaut() && J.getorientation() && !J.getetat().getAccroupi() && J.getetat().getAttaque() == 0)
	{
        im_justineD.draw(renderer,J.getposition().x,J.getposition().y,400,400);
	}
	else if (J.getetat().getAttaque() == 1)
	{
        //im_hitbox.draw(renderer,J.getposition().x + 90,J.getposition().y,100,400);
        //im_hitbox.draw(renderer,J.getposition().x + 300,J.getposition().y + 10,100,100);
        im_justineDeb1D.draw(renderer,J.getposition().x,J.getposition().y,450,400);
	}
	else if (J.getetat().getAttaque() == 3)
	{
        //im_hitbox.draw(renderer,J.getposition().x + 20,J.getposition().y,100,400);
        //im_hitbox.draw(renderer,J.getposition().x + 250,J.getposition().y + 100,100,100);
        im_justineDeb2D.draw(renderer,J.getposition().x-50,J.getposition().y-50,400,450);
	}
	else if (J.getetat().getAttaque() == 5)
	{
        //im_hitbox.draw(renderer,J.getposition().x + 80,J.getposition().y + 180,100,200);
        //im_hitbox.draw(renderer,J.getposition().x + 325,J.getposition().y + 245,100,100);
        im_justineAcc1D.draw(renderer,J.getposition().x,J.getposition().y,450,400);
	}
	else if (J.getetat().getAttaque() == 7)
	{
        //im_hitbox.draw(renderer,J.getposition().x + 80,J.getposition().y + 180,100,200);
        //im_hitbox.draw(renderer,J.getposition().x + 280,J.getposition().y + 255,100,100);
        im_justineAcc2D.draw(renderer,J.getposition().x,J.getposition().y,400,400);
	}
	else if ( !J.getetat().getSaut() && !J.getorientation() && J.getetat().getAccroupi() && J.getetat().getAttaque() == 0)
	{
        //im_hitbox.draw(renderer,J.getposition().x + 225,J.getposition().y + 180,100,200);
        im_justineAccroupiG.draw(renderer,J.getposition().x,J.getposition().y,400,400);
	}
	else if ( !J.getetat().getSaut() && !J.getorientation() && !J.getetat().getAccroupi() && J.getetat().getAttaque() == 0)
	{
        //im_hitbox.draw(renderer,J.getposition().x + 225,J.getposition().y,100,400);
        im_justineG.draw(renderer,J.getposition().x,J.getposition().y,400,400);
	}
	else if (J.getetat().getAttaque() == 2)
	{
        //im_hitbox.draw(renderer,J.getposition().x + 220,J.getposition().y,100,400);
        //im_hitbox.draw(renderer,J.getposition().x,J.getposition().y,100,100);
        im_justineDeb1G.draw(renderer,J.getposition().x - 50,J.getposition().y,450,400);
	}
	else if (J.getetat().getAttaque() == 4)
	{
        //im_hitbox.draw(renderer,J.getposition().x + 300,J.getposition().y,100,400);
        //im_hitbox.draw(renderer,J.getposition().x + 40,J.getposition().y + 85,100,100);
        im_justineDeb2G.draw(renderer,J.getposition().x +50,J.getposition().y - 50,400,450);
	}
	else if (J.getetat().getAttaque() == 6)
	{
        //im_hitbox.draw(renderer,J.getposition().x + 220,J.getposition().y + 180,100,200);
        //im_hitbox.draw(renderer,J.getposition().x,J.getposition().y + 235,100,100);
        im_justineAcc1G.draw(renderer,J.getposition().x - 50,J.getposition().y,450,400);
	}
	else if (J.getetat().getAttaque() == 8)
	{
        //im_hitbox.draw(renderer,J.getposition().x + 220,J.getposition().y + 180,100,200);
        //im_hitbox.draw(renderer,J.getposition().x + 20,J.getposition().y + 250,100,100);
        im_justineAcc2G.draw(renderer,J.getposition().x,J.getposition().y,400,400);
	}
	else if ( J.getetat().getSaut() && J.getorientation())
	{
        //im_hitbox.draw(renderer,J.getposition().x + 60,J.getposition().y,100,250);
        im_justineSautD.draw(renderer,J.getposition().x,J.getposition().y,400,400);
	}
	else
	{
        //im_hitbox.draw(renderer,J.getposition().x + 240,J.getposition().y,100,250);
        im_justineSautG.draw(renderer,J.getposition().x,J.getposition().y,400,400);
	}



	//Affiche Tancrede
    if ( !T.getetat().getSaut() && T.getorientation() && T.getetat().getAccroupi() && T.getetat().getAttaque() == 0)
	{
        //im_hitbox.draw(renderer,T.getposition().x + 70,T.getposition().y + 180,100,200);
        im_tancredeAccroupiD.draw(renderer,T.getposition().x,T.getposition().y,400,400);
	}
	else if ( !T.getetat().getSaut() && T.getorientation() && !T.getetat().getAccroupi() && T.getetat().getAttaque() == 0)
	{
        //im_hitbox.draw(renderer,T.getposition().x + 90,T.getposition().y,100,400);
        im_tancredeD.draw(renderer,T.getposition().x,T.getposition().y,400,400);
	}
	else if (T.getetat().getAttaque() == 1)
	{
        //im_hitbox.draw(renderer,T.getposition().x + 90,T.getposition().y,100,400);
        //im_hitbox.draw(renderer,T.getposition().x + 300,T.getposition().y + 50,100,100);
        im_tancredeDeb1D.draw(renderer,T.getposition().x,T.getposition().y,400,400);
	}
	else if (T.getetat().getAttaque() == 3)
	{
        //im_hitbox.draw(renderer,T.getposition().x + 70,T.getposition().y,100,400);
        //im_hitbox.draw(renderer,T.getposition().x + 270,T.getposition().y + 160,100,100);
        im_tancredeDeb2D.draw(renderer,T.getposition().x,T.getposition().y,400,400);
	}
	else if (T.getetat().getAttaque() == 5)
	{
        //im_hitbox.draw(renderer,T.getposition().x + 70,T.getposition().y + 180,100,200);
        //im_hitbox.draw(renderer,T.getposition().x + 340,T.getposition().y + 190,100,100);
        im_tancredeAcc1D.draw(renderer,T.getposition().x,T.getposition().y,450,400);
	}
	else if (T.getetat().getAttaque() == 7)
	{
        //im_hitbox.draw(renderer,T.getposition().x + 80,T.getposition().y + 180,100,200);
        //im_hitbox.draw(renderer,T.getposition().x + 285,T.getposition().y + 260,100,100);
        im_tancredeAcc2D.draw(renderer,T.getposition().x,T.getposition().y,400,400);
	}
	else if ( !T.getetat().getSaut() && !T.getorientation() && T.getetat().getAccroupi() && T.getetat().getAttaque() == 0)
	{
        //im_hitbox.draw(renderer,T.getposition().x + 230,T.getposition().y + 180,100,200);
        im_tancredeAccroupiG.draw(renderer,T.getposition().x,T.getposition().y,400,400);
	}
	else if ( !T.getetat().getSaut() && !T.getorientation() && !T.getetat().getAccroupi() && T.getetat().getAttaque() == 0)
	{
        //im_hitbox.draw(renderer,T.getposition().x + 210,T.getposition().y,100,400);
        im_tancredeG.draw(renderer,T.getposition().x,T.getposition().y,400,400);
	}
	else if (T.getetat().getAttaque() == 2)
	{
        //im_hitbox.draw(renderer,T.getposition().x + 200,T.getposition().y,100,400);
        //im_hitbox.draw(renderer,T.getposition().x,T.getposition().y + 50,100,100);
        im_tancredeDeb1G.draw(renderer,T.getposition().x,T.getposition().y,400,400);
	}
	else if (T.getetat().getAttaque() == 4)
	{
        //im_hitbox.draw(renderer,T.getposition().x + 230,T.getposition().y,100,400);
        //im_hitbox.draw(renderer,T.getposition().x + 25,T.getposition().y + 160,100,100);
        im_tancredeDeb2G.draw(renderer,T.getposition().x,T.getposition().y,400,400);
	}
	else if (T.getetat().getAttaque() == 6)
	{
        //im_hitbox.draw(renderer,T.getposition().x + 230,T.getposition().y + 180,100,200);
        //im_hitbox.draw(renderer,T.getposition().x - 35,T.getposition().y + 190,100,100);
        im_tancredeAcc1G.draw(renderer,T.getposition().x - 50,T.getposition().y,450,400);
	}
	else if (T.getetat().getAttaque() == 8)
	{
        //im_hitbox.draw(renderer,T.getposition().x + 220,T.getposition().y + 180,100,200);
        //im_hitbox.draw(renderer,T.getposition().x + 20,T.getposition().y + 260,100,100);
        im_tancredeAcc2G.draw(renderer,T.getposition().x,T.getposition().y,400,400);
	}
	else if ( T.getetat().getSaut() && T.getorientation())
	{
        //im_hitbox.draw(renderer,T.getposition().x + 100,T.getposition().y,100,250);
        im_tancredeSautD.draw(renderer,T.getposition().x,T.getposition().y,400,400);
	}
	else
	{
        //im_hitbox.draw(renderer,T.getposition().x + 200,T.getposition().y,100,250);
        im_tancredeSautG.draw(renderer,T.getposition().x,T.getposition().y,400,400);
	}
    //Affiche le second sprite de la classe
    im_classe2.draw(renderer,0,0,2000,1000);

}*/
/*
void sdlJeu::sdlBoucle ()
{

    im_loading.loadFromFile("data/loading.jpg", renderer);
    SDL_RenderClear(renderer);
    im_loading.draw(renderer,0,0,2000,1000);
    SDL_RenderPresent(renderer);

    //Variable pour gérer l'état accroupi
    Etat e;

    bool quit = false;
    SDL_Event events;

    im_classe.loadFromFile("data/classe.png",renderer);
    im_classe2.loadFromFile("data/classe2.png",renderer);
    im_hitbox.loadFromFile("data/Zone.jpg",renderer);


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
			{              // Si une touche est enfoncee



				//Touches Justine
				if(state[SDL_SCANCODE_A] && Justine.getetat().getAttaque() == 0)
				{
                        Justine.vaGauche(decor);
				}

				if(state[SDL_SCANCODE_D] && Justine.getetat().getAttaque() == 0)
				{
                        Justine.vaDroite(decor);
				}

                if (state[SDL_SCANCODE_W] && !Justine.getetat().getSaut() && Justine.getetat().getAttaque() == 0)
                {
                    Jsaut = Justine.saute();
                }

                if (state[SDL_SCANCODE_T] && Justine.getetat().getAttaque() == 0 && !Justine.getetat().getSaut())
                {
                    if (Justine.getorientation() && !Justine.getetat().getAccroupi())
                    {
                        Jatt = Justine.attaquer(1);
                    }
                    else if (!Justine.getorientation() && !Justine.getetat().getAccroupi())
                    {
                        Jatt = Justine.attaquer(2);
                    }
                    else if (Justine.getorientation() && Justine.getetat().getAccroupi())
                    {
                        Jatt = Justine.attaquer(5);
                    }
                    else
                    {
                        Jatt = Justine.attaquer(6);
                    }

                     if (Tancrede.getstats().getvie() <= 0)
                    {
                        Tancrede.setvie(10);
                    }
                    else
                    {
                        ReinitHitBox(Justine, Tancrede);
                        const SDL_Rect A = Justine.getHitBoxAtt();
                        const SDL_Rect *ptrA = &A;
                        const SDL_Rect B = Tancrede.getHitBoxPerso();
                        const SDL_Rect *ptrB = &B;
                        if (touche(ptrA,ptrB)) Tancrede.setvie(Tancrede.getstats().getvie() - 1);
                    }
                }

                if (state[SDL_SCANCODE_Y] && Justine.getetat().getAttaque() == 0 && !Justine.getetat().getSaut())
                {
                    if (Justine.getorientation() && !Justine.getetat().getAccroupi())
                    {
                        Jatt = Justine.attaquer(3);
                    }
                    else if (!Justine.getorientation() && !Justine.getetat().getAccroupi())
                    {
                        Jatt = Justine.attaquer(4);
                    }
                    else if (Justine.getorientation() && Justine.getetat().getAccroupi())
                    {
                        Jatt = Justine.attaquer(7);
                    }
                    else
                    {
                        Jatt = Justine.attaquer(8);
                    }

                    if (Tancrede.getstats().getvie() <= 0)
                    {
                        Tancrede.setvie(10);
                    }
                    else
                    {
                        ReinitHitBox(Justine, Tancrede);
                        const SDL_Rect A = Justine.getHitBoxAtt();
                        const SDL_Rect *ptrA = &A;
                        const SDL_Rect B = Tancrede.getHitBoxPerso();
                        const SDL_Rect *ptrB = &B;
                        if (touche(ptrA,ptrB)) Tancrede.setvie(Tancrede.getstats().getvie() - 1);
                    }

                }



                //Touches Tancrède
				if(state[SDL_SCANCODE_LEFT] && Tancrede.getetat().getAttaque() == 0)
				{
                        Tancrede.vaGauche(decor);

				}

				if(state[SDL_SCANCODE_RIGHT] && Tancrede.getetat().getAttaque() == 0)
				{
                        Tancrede.vaDroite(decor);
				}

				if (state[SDL_SCANCODE_UP] && !Tancrede.getetat().getSaut() && Tancrede.getetat().getAttaque() == 0)
                {
                    Tsaut = Tancrede.saute();
                }

                if (state[SDL_SCANCODE_KP_4] && Tancrede.getetat().getAttaque() == 0 && !Tancrede.getetat().getSaut())
                {
                    if (Tancrede.getorientation() && !Tancrede.getetat().getAccroupi())
                    {
                        Tatt = Tancrede.attaquer(1);
                    }
                    else if (!Tancrede.getorientation() && !Tancrede.getetat().getAccroupi())
                    {
                        Tatt = Tancrede.attaquer(2);
                    }
                    else if (Tancrede.getorientation() && Tancrede.getetat().getAccroupi())
                    {
                        Tatt = Tancrede.attaquer(5);
                    }
                    else
                    {
                        Tatt = Tancrede.attaquer(6);
                    }

                    if (Justine.getstats().getvie() <= 0)
                    {
                        Justine.setvie(10);
                    }
                    else
                    {
                        ReinitHitBox(Justine, Tancrede);
                        const SDL_Rect C = Justine.getHitBoxPerso();
                        const SDL_Rect *ptrC = &C;
                        const SDL_Rect D = Tancrede.getHitBoxAtt();
                        const SDL_Rect *ptrD = &D;
                        if (touche(ptrC,ptrD)) Justine.setvie(Justine.getstats().getvie() - 1);
                    }

                }

                if (state[SDL_SCANCODE_KP_5] && Tancrede.getetat().getAttaque() == 0 && !Tancrede.getetat().getSaut())
                {
                    if (Tancrede.getorientation() && !Tancrede.getetat().getAccroupi())
                    {
                        Tatt = Tancrede.attaquer(3);
                    }
                    else if (!Tancrede.getorientation() && !Tancrede.getetat().getAccroupi())
                    {
                        Tatt = Tancrede.attaquer(4);
                    }
                    else if (Tancrede.getorientation() && Tancrede.getetat().getAccroupi())
                    {
                        Tatt = Tancrede.attaquer(7);
                    }
                    else
                    {
                        Tatt = Tancrede.attaquer(8);
                    }

                    if (Justine.getstats().getvie() <= 0)
                    {
                        Justine.setvie(10);
                    }
                    else
                    {
                        ReinitHitBox(Justine, Tancrede);
                        const SDL_Rect C = Justine.getHitBoxPerso();
                        const SDL_Rect *ptrC = &C;
                        const SDL_Rect D = Tancrede.getHitBoxAtt();
                        const SDL_Rect *ptrD = &D;
                        if (touche(ptrC,ptrD)) Justine.setvie(Justine.getstats().getvie() - 1);
                    }
                }


                //Sortie du jeu
                if(state[SDL_SCANCODE_ESCAPE])
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

        if (Tancrede.getetat().getAttaque() !=0)
        {
            if (Tancrede.getetat().getAttaque() == 3 || Tancrede.getetat().getAttaque() == 4 || Tancrede.getetat().getAttaque() == 7 || Tancrede.getetat().getAttaque() == 8) //coup de pied
            {
                if(Tatt < SDL_GetTicks() - Tancrede.getstats().getvitesse_att()*2) Tancrede.FinAtt();
            }
            else if (Tatt < SDL_GetTicks() - Tancrede.getstats().getvitesse_att()) Tancrede.FinAtt();
        }

        if (Justine.getetat().getAttaque() !=0)
        {
            if (Justine.getetat().getAttaque() == 3 || Justine.getetat().getAttaque() == 4 || Justine.getetat().getAttaque() == 7 || Justine.getetat().getAttaque() == 8) //coup de pied
            {
                if(Jatt < SDL_GetTicks() - Justine.getstats().getvitesse_att()*2) Justine.FinAtt();
            }
            else if (Jatt < SDL_GetTicks() - Justine.getstats().getvitesse_att()) Justine.FinAtt();
        }

        const Uint8* pKeyStates = SDL_GetKeyboardState(NULL);
        if ( !pKeyStates[SDL_SCANCODE_S] && Justine.getetat().getAttaque() == 0)
        {
            Justine.lever();
        }
        else if (Justine.getetat().getAttaque() == 0 && !Justine.getetat().getSaut())
        {
            Justine.accroupir();
        }

        if ( !pKeyStates[SDL_SCANCODE_DOWN] && Tancrede.getetat().getAttaque() == 0)
        {
            Tancrede.lever();
        }
        else if (Tancrede.getetat().getAttaque() == 0 && !Tancrede.getetat().getSaut())
        {
            Tancrede.accroupir();
        }




        // on affiche le jeu sur le buffer caché
        sdlAff(Justine, Tancrede);



		// on permute les deux buffers (cette fonction ne doit se faire qu'une seule fois dans la boucle)
        SDL_RenderPresent(renderer);

        //Raffraichissement des hitboxes en fonction des nouvelles actions
        ReinitHitBox(Justine, Tancrede);



	}
}

void sdlJeu::ReinitHitBox(Personnage & J, Personnage & T)
{



    if ( !J.getetat().getSaut() && J.getorientation() && J.getetat().getAccroupi() && J.getetat().getAttaque() == 0)
	{
        J.setHitBoxPerso(J.getposition().x + 75,J.getposition().y + 180,100,200); //im_hitbox.draw(renderer,J.getposition().x + 75,J.getposition().y + 180,100,200);
	}
	else if ( !J.getetat().getSaut() && J.getorientation() && !J.getetat().getAccroupi() && J.getetat().getAttaque() == 0)
	{
        J.setHitBoxPerso(J.getposition().x + 75,J.getposition().y,100,400);//im_hitbox.draw(renderer,J.getposition().x + 75,J.getposition().y,100,400);
	}
	else if (J.getetat().getAttaque() == 1)
	{
        J.setHitBoxPerso(J.getposition().x + 90,J.getposition().y,100,400);//im_hitbox.draw(renderer,);
        J.setHitBoxAtt(J.getposition().x + 300,J.getposition().y + 10,100,100);//im_hitbox.draw(renderer,);
	}
	else if (J.getetat().getAttaque() == 3)
	{
        J.setHitBoxPerso(J.getposition().x + 20,J.getposition().y,100,400);//im_hitbox.draw(renderer,);
        J.setHitBoxAtt(J.getposition().x + 250,J.getposition().y + 100,100,100);//im_hitbox.draw(renderer,);
	}
	else if (J.getetat().getAttaque() == 5)
	{
        J.setHitBoxPerso(J.getposition().x + 80,J.getposition().y + 180,100,200);//im_hitbox.draw(renderer,);
        J.setHitBoxAtt(J.getposition().x + 325,J.getposition().y + 245,100,100);//im_hitbox.draw(renderer,);
	}
	else if (J.getetat().getAttaque() == 7)
	{
        J.setHitBoxPerso(J.getposition().x + 80,J.getposition().y + 180,100,200);//im_hitbox.draw(renderer,J);
        J.setHitBoxAtt(J.getposition().x + 280,J.getposition().y + 255,100,100);//im_hitbox.draw(renderer,);
	}
	else if ( !J.getetat().getSaut() && !J.getorientation() && J.getetat().getAccroupi() && J.getetat().getAttaque() == 0)
	{
        J.setHitBoxPerso(J.getposition().x + 225,J.getposition().y + 180,100,200);//im_hitbox.draw(renderer,);
	}
	else if ( !J.getetat().getSaut() && !J.getorientation() && !J.getetat().getAccroupi() && J.getetat().getAttaque() == 0)
	{
        J.setHitBoxPerso(J.getposition().x + 225,J.getposition().y,100,400);//im_hitbox.draw(renderer,);
	}
	else if (J.getetat().getAttaque() == 2)
	{
        J.setHitBoxPerso(J.getposition().x + 220,J.getposition().y,100,400);//im_hitbox.draw(renderer,);
        J.setHitBoxAtt(J.getposition().x,J.getposition().y,100,100);//im_hitbox.draw(renderer);
	}
	else if (J.getetat().getAttaque() == 4)
	{
        J.setHitBoxPerso(J.getposition().x + 300,J.getposition().y,100,400);//im_hitbox.draw(renderer,);
        J.setHitBoxAtt(J.getposition().x + 40,J.getposition().y + 85,100,100);//im_hitbox.draw(renderer,);
	}
	else if (J.getetat().getAttaque() == 6)
	{
        J.setHitBoxPerso(J.getposition().x + 220,J.getposition().y + 180,100,200);//im_hitbox.draw(renderer,);
        J.setHitBoxAtt(J.getposition().x,J.getposition().y + 235,100,100);//im_hitbox.draw(renderer,);
	}
	else if (J.getetat().getAttaque() == 8)
	{
        J.setHitBoxPerso(J.getposition().x + 220,J.getposition().y + 180,100,200);//im_hitbox.draw(renderer,);
        J.setHitBoxAtt(J.getposition().x + 20,J.getposition().y + 250,100,100);//im_hitbox.draw(renderer,);
	}
	else if ( J.getetat().getSaut() && J.getorientation())
	{
        J.setHitBoxPerso(J.getposition().x + 60,J.getposition().y,100,250);//im_hitbox.draw(renderer,);
	}
	else
	{
        J.setHitBoxPerso(J.getposition().x + 240,J.getposition().y,100,250);//im_hitbox.draw(renderer,);
	}



	//Affiche Tancrede
    if ( !T.getetat().getSaut() && T.getorientation() && T.getetat().getAccroupi() && T.getetat().getAttaque() == 0)
	{
        T.setHitBoxPerso(T.getposition().x + 70,T.getposition().y + 180,100,200);//im_hitbox.draw(renderer,);
	}
	else if ( !T.getetat().getSaut() && T.getorientation() && !T.getetat().getAccroupi() && T.getetat().getAttaque() == 0)
	{
        T.setHitBoxPerso(T.getposition().x + 90,T.getposition().y,100,400);//im_hitbox.draw(renderer,);
	}
	else if (T.getetat().getAttaque() == 1)
	{
        T.setHitBoxPerso(T.getposition().x + 90,T.getposition().y,100,400);//im_hitbox.draw(renderer,);
        T.setHitBoxAtt(T.getposition().x + 300,T.getposition().y + 50,100,100);//im_hitbox.draw(renderer,);
	}
	else if (T.getetat().getAttaque() == 3)
	{
        T.setHitBoxPerso(T.getposition().x + 70,T.getposition().y,100,400);//im_hitbox.draw(renderer,);
        T.setHitBoxAtt(T.getposition().x + 270,T.getposition().y + 160,100,100);//im_hitbox.draw(renderer,);
	}
	else if (T.getetat().getAttaque() == 5)
	{
        T.setHitBoxPerso(T.getposition().x + 70,T.getposition().y + 180,100,200);//im_hitbox.draw(renderer,);
        T.setHitBoxAtt(T.getposition().x + 340,T.getposition().y + 190,100,100);//im_hitbox.draw(renderer,);
	}
	else if (T.getetat().getAttaque() == 7)
	{
        T.setHitBoxPerso(T.getposition().x + 80,T.getposition().y + 180,100,200);//im_hitbox.draw(renderer,);
        T.setHitBoxAtt(T.getposition().x + 285,T.getposition().y + 260,100,100);//im_hitbox.draw(renderer,);
	}
	else if ( !T.getetat().getSaut() && !T.getorientation() && T.getetat().getAccroupi() && T.getetat().getAttaque() == 0)
	{
        T.setHitBoxPerso(T.getposition().x + 230,T.getposition().y + 180,100,200);//im_hitbox.draw(renderer,);
	}
	else if ( !T.getetat().getSaut() && !T.getorientation() && !T.getetat().getAccroupi() && T.getetat().getAttaque() == 0)
	{
        T.setHitBoxPerso(T.getposition().x + 210,T.getposition().y,100,400);//im_hitbox.draw(renderer,);
	}
	else if (T.getetat().getAttaque() == 2)
	{
        T.setHitBoxPerso(T.getposition().x + 200,T.getposition().y,100,400);//im_hitbox.draw(renderer,);
        T.setHitBoxAtt(T.getposition().x,T.getposition().y + 50,100,100);//im_hitbox.draw(renderer,);
	}
	else if (T.getetat().getAttaque() == 4)
	{
        T.setHitBoxPerso(T.getposition().x + 230,T.getposition().y,100,400);//im_hitbox.draw(renderer,);
        T.setHitBoxAtt(T.getposition().x + 25,T.getposition().y + 160,100,100);//im_hitbox.draw(renderer,);
	}
	else if (T.getetat().getAttaque() == 6)
	{
        T.setHitBoxPerso(T.getposition().x + 230,T.getposition().y + 180,100,200);//im_hitbox.draw(renderer,);
        T.setHitBoxAtt(T.getposition().x - 35,T.getposition().y + 190,100,100);//im_hitbox.draw(renderer,);
	}
	else if (T.getetat().getAttaque() == 8)
	{
        T.setHitBoxPerso(T.getposition().x + 220,T.getposition().y + 180,100,200);//im_hitbox.draw(renderer,);
        T.setHitBoxAtt(T.getposition().x + 20,T.getposition().y + 260,100,100);//im_hitbox.draw(renderer,);
	}
	else if ( T.getetat().getSaut() && T.getorientation())
	{
        T.setHitBoxPerso(T.getposition().x + 100,T.getposition().y,100,250);//im_hitbox.draw(renderer,);
	}
	else
	{
        T.setHitBoxPerso(T.getposition().x + 200,T.getposition().y,100,250);//im_hitbox.draw(renderer,);
	}
}


bool sdlJeu::touche(const SDL_Rect *a, const SDL_Rect *b)
{
    //Points du rect a
    const SDL_Point A = {a->x,a->y};
    const SDL_Point B = {a->x + a->w,a->y};
    const SDL_Point C = {a->x,a->y + a->h};
    const SDL_Point D = {a->x + a->w,a->y + a->h};

    //Points du rect b
    const SDL_Point E = {b->x,b->y};
    const SDL_Point F = {b->x + b->w,b->y};
    const SDL_Point G = {b->x,b->y + b->h};
    const SDL_Point H = {b->x + b->w,b->y + b->h};

    const SDL_Point *ptrA = &A;
    const SDL_Point *ptrB = &B;
    const SDL_Point *ptrC = &C;
    const SDL_Point *ptrD = &D;
    const SDL_Point *ptrE = &E;
    const SDL_Point *ptrF = &F;
    const SDL_Point *ptrG = &G;
    const SDL_Point *ptrH = &H;

    return (SDL_EnclosePoints(ptrA,1,b,NULL) == SDL_TRUE
         || SDL_EnclosePoints(ptrB,1,b,NULL) == SDL_TRUE
         || SDL_EnclosePoints(ptrC,1,b,NULL) == SDL_TRUE
         || SDL_EnclosePoints(ptrD,1,b,NULL) == SDL_TRUE
         || SDL_EnclosePoints(ptrE,1,a,NULL) == SDL_TRUE
         || SDL_EnclosePoints(ptrF,1,a,NULL) == SDL_TRUE
         || SDL_EnclosePoints(ptrG,1,a,NULL) == SDL_TRUE
         || SDL_EnclosePoints(ptrH,1,a,NULL) == SDL_TRUE );

}

*/
