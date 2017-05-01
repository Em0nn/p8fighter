//#include "Combat.h"
#include <cassert>
#include <iostream>
#include <string.h>
#include <fstream>

#include <stdlib.h>
#include <time.h>

#include "Combat.h"
#include "Personnage.h"

using namespace std;

Combat::Combat()
{
    SDL_Point ptJ = {300,500};
    SDL_Point ptT = {1400,500};
    Personnage Ju("data/justineD.png", ptJ, true, 10, 400.0, 5.0);
    Personnage Tancou("data/tancredeG.png", ptT, false, 10, 400.0, 5.0);

    J = Ju;
    T = Tancou;
    posJ = ptJ;
    posT = ptT;
    eventDispo = false;
}


Combat::Combat(Personnage Ju, Personnage Tancou, bool e, SDL_Point posJu, SDL_Point posTancou)
{
    J = Ju;
    T = Tancou;
    posJ = posJu;
    posT = posTancou;
    eventDispo = e;
}

Personnage Combat::getJ()
{
    return J;
}

Personnage Combat::getT()
{
    return T;
}

Evenement Combat::getevent()
{
    return event;
}

bool Combat::geteventDispo()
{
    return eventDispo;
}

SDL_Point Combat::getPosJ()
{
    return posJ;
}

SDL_Point Combat::getPosT()
{
    return posT;
}

void Combat::setJ(Personnage Ju)
{
    J = Ju;
}

void Combat::setT(Personnage Tancou)
{
    T = Tancou;
}

void Combat::setevent(Evenement e)
{
    event= e;
}

void Combat::seteventDispo(bool e)
{
    eventDispo =e;
}

void Combat::setPosJ(SDL_Point ptJ)
{
    posJ = ptJ;
}

void Combat::setPosT(SDL_Point ptT)
{
    posT = ptT;
}

void Combat::AffCombat()
{


    AffBarresDeVie();
    AffJustine();
    AffTancrede();

	// Affiche le sprite de particules supplémentaires de la classe
	im_classe2.draw(renderer,0,0,2000,1000);
}

void Combat::InitSDL()
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

void Combat::ChargementImages()
{
    im_loading.loadFromFile("data/loading.jpg", renderer);
    SDL_RenderClear(renderer);
    im_loading.draw(renderer,0,0,2000,1000);
    SDL_RenderPresent(renderer);

    im_classe.loadFromFile("data/classe.png",renderer);
    im_classe2.loadFromFile("data/classe2.png",renderer);
    im_hitbox.loadFromFile("data/Zone.jpg",renderer);


    //Sprites Justine
    im_justineD.loadFromFile(J.getnomImage(),renderer);
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
    im_tancredeG.loadFromFile(T.getnomImage(),renderer);

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

    im_Google.loadFromFile("data/Mama0.png",renderer);
    im_Mama.loadFromFile("data/Mama0b.png",renderer);
    im_Mama0.loadFromFile("data/Mama1.png",renderer);
    im_Mama1.loadFromFile("data/Mama2.png",renderer);
    im_Mama2.loadFromFile("data/Mama3.png",renderer);
    im_Mama3.loadFromFile("data/Mama4.png",renderer);

    im_InfuV.loadFromFile("data/InfuV.png",renderer);
    im_InfuP.loadFromFile("data/InfuP.png",renderer);
    im_RomainEntre.loadFromFile("data/RomainE.png",renderer);
    im_RomainVerse.loadFromFile("data/RomainS.png",renderer);

    im_FelixEntre0.loadFromFile("data/FelixE1.png",renderer);
    im_FelixEntre1.loadFromFile("data/FelixE2.png",renderer);
    im_FelixAction.loadFromFile("data/FelixS.png",renderer);
    im_Rayon.loadFromFile("data/RayonLumiere.png",renderer);

    im_Dejou.loadFromFile("data/Dejou.png",renderer);
    im_Attal.loadFromFile("data/Attal.png",renderer);

    im_VictoireJustine.loadFromFile("data/VictoireJustine.png",renderer);
    im_VictoireTancrede.loadFromFile("data/VictoireTancrede.png",renderer);

}


void Combat::AffBarresDeVie()
{
    //affiche les barres de vie
    if (J.getstats().getvie() >= 10) im_VieJu100.draw(renderer,J.getposition().x + 20 + !J.getorientation()*150,J.getposition().y - 60 + J.getetat().getAccroupi()*150,200,25);
    else if (J.getstats().getvie() >= 9) im_VieJu90.draw(renderer,J.getposition().x + 20 + !J.getorientation()*150,J.getposition().y - 60 + J.getetat().getAccroupi()*150,200,25);
    else if (J.getstats().getvie() >= 8) im_VieJu80.draw(renderer,J.getposition().x + 20 + !J.getorientation()*150,J.getposition().y - 60 + J.getetat().getAccroupi()*150,200,25);
    else if (J.getstats().getvie() >= 7) im_VieJu70.draw(renderer,J.getposition().x + 20 + !J.getorientation()*150,J.getposition().y - 60 + J.getetat().getAccroupi()*150,200,25);
    else if (J.getstats().getvie() >= 6) im_VieJu60.draw(renderer,J.getposition().x + 20 + !J.getorientation()*150,J.getposition().y - 60 + J.getetat().getAccroupi()*150,200,25);
    else if (J.getstats().getvie() >= 5) im_VieJu50.draw(renderer,J.getposition().x + 20 + !J.getorientation()*150,J.getposition().y - 60 + J.getetat().getAccroupi()*150,200,25);
    else if (J.getstats().getvie() >= 4) im_VieJu40.draw(renderer,J.getposition().x + 20 + !J.getorientation()*150,J.getposition().y - 60 + J.getetat().getAccroupi()*150,200,25);
    else if (J.getstats().getvie() >= 3) im_VieJu30.draw(renderer,J.getposition().x + 20 + !J.getorientation()*150,J.getposition().y - 60 + J.getetat().getAccroupi()*150,200,25);
    else if (J.getstats().getvie() >= 2) im_VieJu20.draw(renderer,J.getposition().x + 20 + !J.getorientation()*150,J.getposition().y - 60 + J.getetat().getAccroupi()*150,200,25);
    else if (J.getstats().getvie() >= 1) im_VieJu10.draw(renderer,J.getposition().x + 20 + !J.getorientation()*150,J.getposition().y - 60 + J.getetat().getAccroupi()*150,200,25);
    else
    {
        im_VieJu00.draw(renderer,J.getposition().x + 20 + !J.getorientation()*150,J.getposition().y - 50 + J.getetat().getAccroupi()*150,200,25);
    }


    if (T.getstats().getvie() >= 10) im_VieTancou100.draw(renderer,T.getposition().x + 50 + !T.getorientation()*100,T.getposition().y - 90 + T.getetat().getAccroupi()*150,200,25);
    else if (T.getstats().getvie() >= 9) im_VieTancou90.draw(renderer,T.getposition().x + 50 + !T.getorientation()*100,T.getposition().y - 90 + T.getetat().getAccroupi()*150,200,25);
    else if (T.getstats().getvie() >= 8) im_VieTancou80.draw(renderer,T.getposition().x + 50 + !T.getorientation()*100,T.getposition().y - 90 + T.getetat().getAccroupi()*150,200,25);
    else if (T.getstats().getvie() >= 7) im_VieTancou70.draw(renderer,T.getposition().x + 50 + !T.getorientation()*100,T.getposition().y - 90 + T.getetat().getAccroupi()*150,200,25);
    else if (T.getstats().getvie() >= 6) im_VieTancou60.draw(renderer,T.getposition().x + 50 + !T.getorientation()*100,T.getposition().y - 90 + T.getetat().getAccroupi()*150,200,25);
    else if (T.getstats().getvie() >= 5) im_VieTancou50.draw(renderer,T.getposition().x + 50 + !T.getorientation()*100,T.getposition().y - 90 + T.getetat().getAccroupi()*150,200,25);
    else if (T.getstats().getvie() >= 4) im_VieTancou40.draw(renderer,T.getposition().x + 50 + !T.getorientation()*100,T.getposition().y - 90 + T.getetat().getAccroupi()*150,200,25);
    else if (T.getstats().getvie() >= 3) im_VieTancou30.draw(renderer,T.getposition().x + 50 + !T.getorientation()*100,T.getposition().y - 90 + T.getetat().getAccroupi()*150,200,25);
    else if (T.getstats().getvie() >= 2) im_VieTancou20.draw(renderer,T.getposition().x + 50 + !T.getorientation()*100,T.getposition().y - 90 + T.getetat().getAccroupi()*150,200,25);
    else if (T.getstats().getvie() >= 1) im_VieTancou10.draw(renderer,T.getposition().x + 50 + !T.getorientation()*100,T.getposition().y - 90 + T.getetat().getAccroupi()*150,200,25);
    else
    {
        im_VieTancou00.draw(renderer,T.getposition().x + 50 + !T.getorientation()*100,T.getposition().y - 80 + T.getetat().getAccroupi()*150,200,25);
    }
}

void Combat::AffJustine()
{
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
        im_justineDeb1D.draw(renderer,J.getposition().x,J.getposition().y,450,400);
	}
	else if (J.getetat().getAttaque() == 3)
	{
        im_justineDeb2D.draw(renderer,J.getposition().x-50,J.getposition().y-50,400,450);
	}
	else if (J.getetat().getAttaque() == 5)
	{
        im_justineAcc1D.draw(renderer,J.getposition().x,J.getposition().y,450,400);
	}
	else if (J.getetat().getAttaque() == 7)
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
	else if (J.getetat().getAttaque() == 2)
	{
        im_justineDeb1G.draw(renderer,J.getposition().x - 50,J.getposition().y,450,400);
	}
	else if (J.getetat().getAttaque() == 4)
	{
        im_justineDeb2G.draw(renderer,J.getposition().x +50,J.getposition().y - 50,400,450);
	}
	else if (J.getetat().getAttaque() == 6)
	{
        im_justineAcc1G.draw(renderer,J.getposition().x - 50,J.getposition().y,450,400);
	}
	else if (J.getetat().getAttaque() == 8)
	{
        im_justineAcc2G.draw(renderer,J.getposition().x,J.getposition().y,400,400);
	}
	else if ( J.getetat().getSaut() && J.getorientation())
	{
        im_justineSautD.draw(renderer,J.getposition().x,J.getposition().y,400,400);
	}
	else
	{
        im_justineSautG.draw(renderer,J.getposition().x,J.getposition().y,400,400);
	}
}

void Combat::AffTancrede()
{
    //Affiche Tancrede
    if ( !T.getetat().getSaut() && T.getorientation() && T.getetat().getAccroupi() && T.getetat().getAttaque() == 0)
	{
        im_tancredeAccroupiD.draw(renderer,T.getposition().x,T.getposition().y,400,400);
	}
	else if ( !T.getetat().getSaut() && T.getorientation() && !T.getetat().getAccroupi() && T.getetat().getAttaque() == 0)
	{
        im_tancredeD.draw(renderer,T.getposition().x,T.getposition().y,400,400);
	}
	else if (T.getetat().getAttaque() == 1)
	{
        im_tancredeDeb1D.draw(renderer,T.getposition().x,T.getposition().y,400,400);
	}
	else if (T.getetat().getAttaque() == 3)
	{
        im_tancredeDeb2D.draw(renderer,T.getposition().x,T.getposition().y,400,400);
	}
	else if (T.getetat().getAttaque() == 5)
	{
        im_tancredeAcc1D.draw(renderer,T.getposition().x,T.getposition().y,450,400);
	}
	else if (T.getetat().getAttaque() == 7)
	{
        im_tancredeAcc2D.draw(renderer,T.getposition().x,T.getposition().y,400,400);
	}
	else if ( !T.getetat().getSaut() && !T.getorientation() && T.getetat().getAccroupi() && T.getetat().getAttaque() == 0)
	{
        im_tancredeAccroupiG.draw(renderer,T.getposition().x,T.getposition().y,400,400);
	}
	else if ( !T.getetat().getSaut() && !T.getorientation() && !T.getetat().getAccroupi() && T.getetat().getAttaque() == 0)
	{
        im_tancredeG.draw(renderer,T.getposition().x,T.getposition().y,400,400);
	}
	else if (T.getetat().getAttaque() == 2)
	{
        im_tancredeDeb1G.draw(renderer,T.getposition().x,T.getposition().y,400,400);
	}
	else if (T.getetat().getAttaque() == 4)
	{
        im_tancredeDeb2G.draw(renderer,T.getposition().x,T.getposition().y,400,400);
	}
	else if (T.getetat().getAttaque() == 6)
	{
        im_tancredeAcc1G.draw(renderer,T.getposition().x - 50,T.getposition().y,450,400);
	}
	else if (T.getetat().getAttaque() == 8)
	{
        im_tancredeAcc2G.draw(renderer,T.getposition().x,T.getposition().y,400,400);
	}
	else if ( T.getetat().getSaut() && T.getorientation())
	{
        im_tancredeSautD.draw(renderer,T.getposition().x,T.getposition().y,400,400);
	}
	else
	{
        im_tancredeSautG.draw(renderer,T.getposition().x,T.getposition().y,400,400);
	}
}

void Combat::BoucleCombat()
{
    InitSDL();

    //Initialisation de la boucle en fontion du temps
    int temps_avantCombat = SDL_GetTicks();

    //Chargement des images
    ChargementImages();

    //Initialisation de la fonction rand
    srand(time(NULL));

    //Variable pour gérer l'état accroupi
    Etat e;

    //Variables pour l'affichage des animations adjuvants
    int tMama = 0;
    int tAttal = 0;
    int tDejou = 0;
    int tFelix = 0;
    int tRomain = 0;
    int RomainX = 0;
    int RomainY = 0;

    bool objDejaPris= false;

    bool quit = false;
    SDL_Event events;

    unsigned int Jsaut, Tsaut, Jatt, Tatt;

    const Uint8 *state = SDL_GetKeyboardState(NULL);
    SDL_Delay(3000);

	// tant que ce n'est pas la fin ...
	while (!quit && J.getstats().getvie() > 0 && T.getstats().getvie() > 0)
	{

		// tant qu'il y a des evenements à traiter (cette boucle n'est pas bloquante)

        const Uint8* pKeyStates = SDL_GetKeyboardState(NULL);
        if ( !pKeyStates[SDL_SCANCODE_S] && J.getetat().getAttaque() == 0)
        {
            J.lever();
        }
        else if (J.getetat().getAttaque() == 0 && !J.getetat().getSaut())
        {
            J.accroupir();
        }

        if ( !pKeyStates[SDL_SCANCODE_DOWN] && T.getetat().getAttaque() == 0)
        {
            T.lever();
        }
        else if (T.getetat().getAttaque() == 0 && !T.getetat().getSaut())
        {
            T.accroupir();
        }

        if ( pKeyStates[SDL_SCANCODE_A] && J.getetat().getAttaque() == 0)
        {
                J.vaGauche();
        }

        if ( pKeyStates[SDL_SCANCODE_D] && J.getetat().getAttaque() == 0)
        {
                J.vaDroite();
        }



        if(pKeyStates[SDL_SCANCODE_LEFT] && T.getetat().getAttaque() == 0)
        {
                T.vaGauche();

        }

        if(pKeyStates[SDL_SCANCODE_RIGHT] && T.getetat().getAttaque() == 0)
        {
                T.vaDroite();
        }







        if  (SDL_PollEvent(&events))
		{

		    if (events.type == SDL_QUIT) quit = true;           // Si l'utilisateur a clique sur la croix de fermeture
		    else if (events.type == SDL_KEYDOWN)
			{              // Si une touche est enfoncee

                if ( state[SDL_SCANCODE_W] && !J.getetat().getSaut() && J.getetat().getAttaque() == 0)
                {
                    Jsaut = J.saute();
                }

                if (state[SDL_SCANCODE_T] && J.getetat().getAttaque() == 0 && !J.getetat().getSaut())
                {
                    if (J.getorientation() && !J.getetat().getAccroupi())
                    {
                        Jatt = J.attaquer(1);
                    }
                    else if (!J.getorientation() && !J.getetat().getAccroupi())
                    {
                        Jatt = J.attaquer(2);
                    }
                    else if (J.getorientation() && J.getetat().getAccroupi())
                    {
                        Jatt = J.attaquer(5);
                    }
                    else
                    {
                        Jatt = J.attaquer(6);
                    }

                    ReinitHitBox();
                    const SDL_Rect A = J.getHitBoxAtt();
                    const SDL_Rect *ptrA = &A;
                    const SDL_Rect B = T.getHitBoxPerso();
                    const SDL_Rect *ptrB = &B;
                    if (touche(ptrA,ptrB))
                    {
                        if (J.getbouclier())
                        {
                            J.setbouclier(false);
                        }
                        else
                        {
                            T.setvie(T.getstats().getvie() - 1);
                        }
                    }
                }

                if (state[SDL_SCANCODE_Y] && J.getetat().getAttaque() == 0 && !J.getetat().getSaut())
                {
                    if (J.getorientation() && !J.getetat().getAccroupi())
                    {
                        Jatt = J.attaquer(3);
                    }
                    else if (!J.getorientation() && !J.getetat().getAccroupi())
                    {
                        Jatt = J.attaquer(4);
                    }
                    else if (J.getorientation() && J.getetat().getAccroupi())
                    {
                        Jatt = J.attaquer(7);
                    }
                    else
                    {
                        Jatt = J.attaquer(8);
                    }

                    ReinitHitBox();
                    const SDL_Rect A = J.getHitBoxAtt();
                    const SDL_Rect *ptrA = &A;
                    const SDL_Rect B = T.getHitBoxPerso();
                    const SDL_Rect *ptrB = &B;
                    if (touche(ptrA,ptrB))
                    {
                        if (T.getbouclier())
                        {
                            T.setbouclier(false);
                        }
                        else
                        {
                            T.setvie(T.getstats().getvie() - 2);
                        }
                    }

                }



                //Touches Tancrède


				if (state[SDL_SCANCODE_UP] && !T.getetat().getSaut() && T.getetat().getAttaque() == 0)
                {
                    Tsaut = T.saute();
                }

                if (state[SDL_SCANCODE_KP_4] && T.getetat().getAttaque() == 0 && !T.getetat().getSaut())
                {
                    if (T.getorientation() && !T.getetat().getAccroupi())
                    {
                        Tatt = T.attaquer(1);
                    }
                    else if (!T.getorientation() && !T.getetat().getAccroupi())
                    {
                        Tatt = T.attaquer(2);
                    }
                    else if (T.getorientation() && T.getetat().getAccroupi())
                    {
                        Tatt = T.attaquer(5);
                    }
                    else
                    {
                        Tatt = T.attaquer(6);
                    }

                    ReinitHitBox();
                    const SDL_Rect C = J.getHitBoxPerso();
                    const SDL_Rect *ptrC = &C;
                    const SDL_Rect D = T.getHitBoxAtt();
                    const SDL_Rect *ptrD = &D;
                    if (touche(ptrC,ptrD))
                    {
                        if (J.getbouclier())
                        {
                            J.setbouclier(false);
                        }
                        else
                        {
                            J.setvie(J.getstats().getvie() - 1);
                        }
                    }

                }

                if (state[SDL_SCANCODE_KP_5] && T.getetat().getAttaque() == 0 && !T.getetat().getSaut())
                {
                    if (T.getorientation() && !T.getetat().getAccroupi())
                    {
                        Tatt = T.attaquer(3);
                    }
                    else if (!T.getorientation() && !T.getetat().getAccroupi())
                    {
                        Tatt = T.attaquer(4);
                    }
                    else if (T.getorientation() && T.getetat().getAccroupi())
                    {
                        Tatt = T.attaquer(7);
                    }
                    else
                    {
                        Tatt = T.attaquer(8);
                    }

                    ReinitHitBox();
                    const SDL_Rect C = J.getHitBoxPerso();
                    const SDL_Rect *ptrC = &C;
                    const SDL_Rect D = T.getHitBoxAtt();
                    const SDL_Rect *ptrD = &D;
                    if (touche(ptrC,ptrD))
                    {
                        if (J.getbouclier())
                        {
                            J.setbouclier(false);
                        }
                        else
                        {
                            J.setvie(J.getstats().getvie() - 2);
                        }
                    }
                }


                //Sortie du jeu
                if(state[SDL_SCANCODE_ESCAPE])
				{
                        quit = true;
				}

            }

		}

		if (Jsaut < SDL_GetTicks() - 500 && J.getetat().getSaut())
        {
            J.descendre();
        }

        if (Tsaut < SDL_GetTicks() - 500 && T.getetat().getSaut())
        {
            T.descendre();
        }

        if (T.getetat().getAttaque() !=0)
        {
            if (T.getetat().getAttaque() == 3 || T.getetat().getAttaque() == 4 || T.getetat().getAttaque() == 7 || T.getetat().getAttaque() == 8) //coup de pied
            {
                if(Tatt < SDL_GetTicks() - T.getstats().getvitesse_att()*2) T.FinAtt();
            }
            else if (Tatt < SDL_GetTicks() - T.getstats().getvitesse_att()) T.FinAtt();
        }

        if (J.getetat().getAttaque() !=0)
        {
            if (J.getetat().getAttaque() == 3 || J.getetat().getAttaque() == 4 || J.getetat().getAttaque() == 7 || J.getetat().getAttaque() == 8) //coup de pied
            {
                if(Jatt < SDL_GetTicks() - J.getstats().getvitesse_att()*2) J.FinAtt();
            }
            else if (Jatt < SDL_GetTicks() - J.getstats().getvitesse_att()) J.FinAtt();
        }




         //Remplir l'écran de blanc
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
        SDL_RenderClear(renderer);

        // Afficher le sprite de la classe
        im_classe.draw(renderer,0,0,2000,1000);

        Adjuvants(tMama,tAttal,tDejou,tFelix,tRomain, RomainX, RomainY, objDejaPris);
        ReinitHitBox();

        RecupererEffets(objDejaPris);

        // on affiche le jeu sur le buffer caché
        AffCombat();

		// on permute les deux buffers (cette fonction ne doit se faire qu'une seule fois dans la boucle)
        SDL_RenderPresent(renderer);
	}

    SDL_Delay(500);
    //Initialisation des personnages pour la pause finale
	SDL_Point ptJustine = {200,500};
    SDL_Point ptTancrede = {1500,500};
	J.setposition(ptJustine);
	J.setorientation(true);
	T.setposition(ptTancrede);
	T.setorientation(false);
    J.FinAtt();
    T.FinAtt();

    im_classe.draw(renderer,0,0,2000,1000);

	if (T.getstats().getvie() == 0 || T.getstats().getvie() <= J.getstats().getvie())
	{
        J.saute();

        im_VictoireJustine.draw(renderer, 0, 0, 2000, 1000);
	}
	else
	{
        T.saute();
        im_VictoireTancrede.draw(renderer, 0, 0, 2000, 1000);

	}

    AffCombat();
    SDL_RenderPresent(renderer);
	SDL_Delay(5000);



}

void Combat::Adjuvants(int & tMama, int & tAttal, int & tDejou, int & tFelix, int & tRomain, int &RomainX, int &RomainY, bool& objDejaPris)
{
    if (tMama == 0 && tAttal == 0 && tDejou == 0 && tFelix == 0 && tRomain == 0)
    {
        tMama = SDL_GetTicks();
        event.NouvelEvent();
    }
    else if (tMama > SDL_GetTicks() - 500)
    {
        im_Google.draw(renderer,700,0,500,360);
    }
    else if (tMama > SDL_GetTicks() - 2000)
    {
        im_Mama.draw(renderer,700,0,500,360);
    }
    else if (tMama > SDL_GetTicks() - 4000 && event.getIdEvent() == 0) //Dejou
    {
        im_Mama2.draw(renderer,700,0,500,360);
        tDejou = SDL_GetTicks();
    }
    else if (tMama > SDL_GetTicks() - 4000 && event.getIdEvent() == 1) //Attal
    {
        im_Mama3.draw(renderer,700,0,500,360);
        tAttal = SDL_GetTicks();
    }
    else if (tMama > SDL_GetTicks() - 4000 && event.getIdEvent() == 2) //Felix
    {
        im_Mama0.draw(renderer,700,0,500,360);
        tFelix = SDL_GetTicks();
    }
    else if (tMama > SDL_GetTicks() - 4000 && event.getIdEvent() >= 3) //Romain
    {
        im_Mama1.draw(renderer,700,0,500,360);
        tRomain = SDL_GetTicks();
        RomainX = event.getZoneAction().x;
        RomainY = event.getZoneAction().y;
    }
    else
    {
        tMama = 0;
    }


    //Dejou
    if (tMama == 0 && tDejou != 0)
    {
        if (tDejou > SDL_GetTicks() - 2500)
        {

        }
        else if (tDejou > SDL_GetTicks() - 3000)
        {
            im_Dejou.draw(renderer,event.getZoneAction().x - 125,event.getZoneAction().y,100,100);
            if (!eventDispo && !objDejaPris)
            {
                eventDispo = true;
            }
        }
        else if (tDejou > SDL_GetTicks() - 6500 && eventDispo)
        {
            im_Dejou.draw(renderer,event.getZoneAction().x - 125,event.getZoneAction().y,100,100);
        }
        else if (tDejou < SDL_GetTicks() - 9500)
        {
            tDejou = 0;
            eventDispo = false;
            objDejaPris = false;
            J.setvitesse_att(400.0);
            T.setvitesse_att(400.0);
            J.setvitesse_depl(5.0);
            T.setvitesse_depl(5.0);
        }
    }

    //Attal
    if (tMama == 0 && tAttal != 0)
    {
        if (tAttal > SDL_GetTicks() - 2500)
        {

        }
        else if (tAttal > SDL_GetTicks() - 3000)
        {
            im_Attal.draw(renderer,event.getZoneAction().x - 125,event.getZoneAction().y,100,100);
            if (!eventDispo && !objDejaPris)
            {
                eventDispo = true;
            }
        }
        else if (tAttal > SDL_GetTicks() - 6500 && eventDispo)
        {
            im_Attal.draw(renderer,event.getZoneAction().x - 125,event.getZoneAction().y,100,100);

        }
        else
        {
            tAttal = 0;
            eventDispo = false;
            objDejaPris = false;
        }
    }

    //Felix
    if (tMama == 0 && tFelix != 0)
    {
        if (tFelix > SDL_GetTicks() - 2500)
        {

        }
        else if (tFelix > SDL_GetTicks() - 2750)
        {
            im_FelixEntre0.draw(renderer,event.getZoneAction().x - 150 ,0,300,300);
        }
        else if (tFelix > SDL_GetTicks() - 3000)
        {
            im_FelixEntre1.draw(renderer,event.getZoneAction().x - 150,0,300,300);
        }
        else if (tFelix > SDL_GetTicks() - 7000)
        {
            im_Rayon.draw(renderer,event.getZoneAction().x - 75,200,150,700);
            im_FelixAction.draw(renderer,event.getZoneAction().x - 150,0,300,300);
            eventDispo = true;
        }
        else if (tFelix > SDL_GetTicks() - 10000)
        {
            tFelix = 0;
            eventDispo = false;
        }
    }

    //Romain
    if (tMama == 0 && tRomain != 0)
    {
        if (tRomain > SDL_GetTicks() - 2500)
        {

        }
        else if (tRomain > SDL_GetTicks() - 3000)
        {
            im_InfuV.draw(renderer,event.getZoneAction().x - 350,event.getZoneAction().y - 300,400,400);
        }
        else if (tRomain > SDL_GetTicks() - 5000)
        {
            if (!eventDispo && !objDejaPris)
            {
                eventDispo = true;
            }
            im_RomainVerse.draw(renderer,event.getZoneAction().x - 350,event.getZoneAction().y - 300,400,400);
        }
        else if (tRomain > SDL_GetTicks() - 8000)
        {
            RomainX = RomainX + 8;
            RomainY = RomainY - 4;

            im_RomainEntre.draw(renderer, RomainX - 350, RomainY - 300, 400, 400);
            if (!objDejaPris)
            {
                im_InfuP.draw(renderer,event.getZoneAction().x - 350,event.getZoneAction().y -300,400,400);
            }
        }
        else if (tRomain < SDL_GetTicks() - 11000)
        {
            tRomain = 0;
            RomainX = 0;
            RomainY = 0;
            eventDispo = false;
            objDejaPris = false;
            J.setvitesse_att(400.0);
            T.setvitesse_att(400.0);
            J.setvitesse_depl(5.0);
            T.setvitesse_depl(5.0);
        }
    }






}

void Combat::RecupererEffets(bool& objDejaPris)
{
    if(eventDispo)
    {
        const SDL_Point objet = {event.getZoneAction().x,event.getZoneAction().y};
        const SDL_Point *ptrobjet = &objet;

        const SDL_Rect  rJ = J.getHitBoxPerso();
        const SDL_Rect *ptrrJ = &rJ;

        const SDL_Rect  rT = T.getHitBoxPerso();
        const SDL_Rect *ptrrT = &rT;


        if (event.getSaisissable() && SDL_EnclosePoints(ptrobjet,1,ptrrJ,NULL) == SDL_TRUE)
        {
            cout << "Justine :";
            eventDispo = false;
            objDejaPris = true;
            if (event.getEffet().getstat_modif() == 0 && !event.getEffet().getbouclier())
            {
                J.setvie(J.getstats().getvie() + event.getEffet().getval_modif());
                if (J.getstats().getvie() > 10)
                {
                    J.setvie(10);
                }
                eventDispo = false;
                cout << "Romain" << endl;
            }
            else if (event.getEffet().getstat_modif() == 1 && !event.getEffet().getbouclier())
            {
                if (J.getstats().getvitesse_att() >= 300.0)
                {
                    J.setvitesse_att(J.getstats().getvitesse_att() / event.getEffet().getval_modif());
                    J.setvitesse_depl(J.getstats().getvitesse_depl() * event.getEffet().getval_modif());
                }
                eventDispo = false;
            }
            else
            {
                J.setbouclier(true);
                eventDispo = false;
            }
        }
        else if (event.getSaisissable() && SDL_EnclosePoints(ptrobjet,1,ptrrT,NULL) == SDL_TRUE)
        {
            cout << "Tancrede :";
            eventDispo = false;
            objDejaPris = true;
            if (event.getEffet().getstat_modif() == 0 && !event.getEffet().getbouclier())
            {
                T.setvie(T.getstats().getvie() + event.getEffet().getval_modif());
                if (J.getstats().getvie() > 10)
                {
                    J.setvie(10);
                }
                eventDispo = false;
                cout << "Romain" << endl;
            }
            else if (event.getEffet().getstat_modif() == 1 && !event.getEffet().getbouclier())
            {
                if (T.getstats().getvitesse_att() >= 300.0)
                {
                    T.setvitesse_att(T.getstats().getvitesse_att() / event.getEffet().getval_modif());
                    T.setvitesse_depl(T.getstats().getvitesse_depl() * event.getEffet().getval_modif());
                }
                eventDispo = false;
            }
            else
            {
                T.setbouclier(true);
                eventDispo = false;
            }
        }
        else
        {
            if (SDL_EnclosePoints(ptrobjet,1,ptrrJ,NULL) == SDL_TRUE)
            {
                J.setvie(J.getstats().getvie() + event.getEffet().getval_modif());
                if (J.getstats().getvie() > 10)
                {
                    J.setvie(10);
                }
            }
            if (SDL_EnclosePoints(ptrobjet,1,ptrrT,NULL) == SDL_TRUE)
            {
                T.setvie(T.getstats().getvie() + event.getEffet().getval_modif());
                if (T.getstats().getvie() > 10)
                {
                    T.setvie(10);
                }
            }
        }



    }
}

void Combat::ReinitHitBox()
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

bool Combat::touche(const SDL_Rect *a, const SDL_Rect *b)
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



Combat::~Combat()
{
    TTF_Quit();
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}




