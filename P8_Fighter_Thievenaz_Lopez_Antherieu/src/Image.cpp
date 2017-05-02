#include <cassert>
#include <time.h>
#include <stdlib.h>

#include <iostream>
#include "Image.h"
using namespace std;

float temps ()
{
    return float(SDL_GetTicks()) / CLOCKS_PER_SEC;  // conversion des ms en secondes en divisant par 1000
}

// ============= CLASS IMAGE =============== //

/** \brief constructeur par défaut
 */Image::Image ()
{
    surface = NULL;
    texture = NULL;
    has_changed = false;
}

/** \brief fonction de chargement des images
 *
 * \param filename: nom du fichier
 * \param renderer: le rendu SDL
 */
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

/** \brief fonction qui dessine sur le buffer caché
 *
 * \param renderer: le rendu SDL
 * \param x: position x de l'image
 * \param y: position y de l'image
 * \param w: la largeur de l'image
 * \param h: la hauteur de l'image
 */
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
