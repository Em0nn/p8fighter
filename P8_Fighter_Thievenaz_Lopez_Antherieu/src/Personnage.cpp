#include "Personnage.h"
#include "Etat.h"
#include "Action.h"
#include <cassert>
#include <iostream>
#include <string.h>
#include <fstream>

using namespace std;

//constructeur par défaut
/** \brief constructeur par défaut
 */
Personnage::Personnage ()
{
    nomImage="NULL";
    position.x = 0;
    position.y = 0;
    Action Deb1D(); //1 <- code attaque
    Action Deb1G(); //2
    Action Deb2D(); //3
    Action Deb2G(); //4
    Action Acc1D(); //5
    Action Acc1G(); //6
    Action Acc2D(); //7
    Action Acc2G(); //8
    stats.setvie(10);
    stats.setvitesse_att(400.0);
    stats.setvitesse_depl(5.0);
    bouclier = false;
}

/** \brief constructeur par copie
 *
 * \param i : pointeur sur l'image du personnage
 * \param pos : la position du personnage
 * \param o : l'orientation du sprite
 * \param val_vie: points de vie du personnage
 * \param val_att: vitesse d'attaque du personnage
 * \param val_depl: vitesse de déplacement du personnage
 *
 */
Personnage::Personnage (const char* i, SDL_Point pos, bool o, int val_vie, int val_att, int val_depl)
{
    nomImage = i;
    orientation = o;
    position = pos;
    Action Deb1D(); //1 <- code attaque
    Action Deb1G(); //2
    Action Deb2D(); //3
    Action Deb2G(); //4
    Action Acc1D(); //5
    Action Acc1G(); //6
    Action Acc2D(); //7
    Action Acc2G(); //8
    stats.setvie(val_vie);
    stats.setvitesse_att(val_att);
    stats.setvitesse_depl(val_depl);
    bouclier = false;
}





//fonctions get
/** \brief accesseur du nom de l'image du personnage
 *
 * \return le nom de l'image du personnage
 *
 */
const char* Personnage::getnomImage() const
{
    return nomImage;
}


/** \brief accesseur de l'état du personnage
 *
 * \return l'état du personnage
 *
 */
Etat Personnage::getetat() const
{
    return etat;
}


/** \brief accesseur de l'orientation de l'image du personnage
 *
 * \return l'orientation du personnage (gauche/droite)
 *
 */
bool Personnage::getorientation() const
{
    return orientation;
}


/** \brief accesseur de la position du personnage
 *
 * \return le point originaire de la position du personnage
 *
 */
SDL_Point Personnage::getposition() const
{
    return position;
}
/** \brief accesseur de l'action associée à un coup de poing droit debout du personnage
 *
 * \return l'action associée.
 *
 */
Action Personnage::getDeb1D()
{
    return Deb1D;
}
/** \brief accesseur de l'action associée à un coup de poing gauche debout du personnage
 *
 * \return l'action associée.
 *
 */
Action Personnage::getDeb1G()
{
    return Deb1G;
}
/** \brief accesseur de l'action associée à un coup de pied droit debout du personnage
 *
 * \return l'action associée.
 *
 */
Action Personnage::getDeb2D()
{
    return Deb2D;
}
/** \brief accesseur de l'action associée à un coup de pied gauche debout du personnage
 *
 * \return l'action associée.
 *
 */
Action Personnage::getDeb2G()
{
    return Deb2G;
}
/** \brief accesseur de l'action associée à un coup de poing droit accroupi du personnage
 *
 * \return l'action associée.
 *
 */
Action Personnage::getAcc1D()
{
    return Acc1D;
}
/** \brief accesseur de l'action associée à un coup de poing gauche accroupi du personnage
 *
 * \return l'action associée.
 *
 */
Action Personnage::getAcc1G()
{
    return Acc1G;
}
/** \brief accesseur de l'action associée à un coup de pied droit accroupi du personnage
 *
 * \return l'action associée.
 *
 */
Action Personnage::getAcc2D()
{
    return Acc2D;
}
/** \brief accesseur de l'action associée à un coup de pied gauche accroupi du personnage
 *
 * \return l'action associée.
 *
 */
Action Personnage::getAcc2G()
{
    return Acc2G;
}
/** \brief accesseur de la hitbox de l'attaque
 *
 * \return la hitbox de l'attaque
 *
 */
SDL_Rect Personnage::getHitBoxAtt() const
{
    return HitBoxAtt;
}
/** \brief accesseur de la hitbox du personnage
 *
 * \return la hitbox du personnage
 *
 */
SDL_Rect Personnage::getHitBoxPerso() const
{
    return HitBoxPerso;
}

/** \brief accesseur des statistiques du personnage
 *
 * \return les statistiques du personnage
 *
 */
Statistique Personnage::getstats()
{
    return stats;
}
/** \brief accesseur de l'état du bouclier du personnage
 *
 * \return vrai si le bouclier est actif, faux sinon
 *
 */
bool Personnage::getbouclier()
{
    return bouclier;
}



//fonctions set
/** \brief mutateur de l'image du personnage
 *
 * \param i : le nom de la nouvelle image du personnage
 *
 */
void Personnage::setnomImage(const char* i)
{
    nomImage=i;
}
/** \brief mutateur de l'état du personnage
 *
 * \param e : le nouvel état du personnage
 *
 */
void Personnage::setetat(Etat e)
{
    etat=e;
}
/** \brief mutateur de la position du personnage
 *
 * \param p: la nouvelle position du personnage
 *
 */
void Personnage::setposition(SDL_Point p)
{
    position=p;
}
/** \brief mutateur de l'orientation du personnage
 *
 * \param o : l'orientation du personnage (gauche/droite)
 *
 */
void Personnage::setorientation(bool o)
{
    orientation = o;
}
/** \brief mutateur du coup de poing droit debout du personnage
 *
 * \param a : la nouvelle action a effectuer lorsqu'un coup de poing droit debout est déclenché
 *
 */
void Personnage::setDeb1D(Action a)
{
    Deb1D = a;
}
/** \brief mutateur du coup de poing gauche debout du personnage
 *
 * \param a : la nouvelle action a effectuer lorsqu'un coup de poing gauche debout est déclenché
 *
 */
void Personnage::setDeb1G(Action a)
{
    Deb1G = a;
}
/** \brief mutateur du coup de pied droit debout du personnage
 *
 * \param a : la nouvelle action a effectuer lorsqu'un coup de pied droit debout est déclenché
 *
 */
void Personnage::setDeb2D(Action a)
{
    Deb2D = a;
}
/** \brief mutateur du coup de poing gauche debout du personnage
 *
 * \param a : la nouvelle action a effectuer lorsqu'un coup de poing gauche debout est déclenché
 *
 */
void Personnage::setDeb2G(Action a)
{
    Deb2G = a;
}
/** \brief mutateur du coup de poing droit accroupi du personnage
 *
 * \param a : la nouvelle action a effectuer lorsqu'un coup de poing droit accroupi est déclenché
 *
 */
void Personnage::setAcc1D(Action a)
{
    Acc1D = a;
}
/** \brief mutateur du coup de poing gauche accroupi du personnage
 *
 * \param a : la nouvelle action a effectuer lorsqu'un coup de poing gauche accroupi est déclenché
 *
 */
void Personnage::setAcc1G(Action a)
{
    Acc1G = a;
}
/** \brief mutateur du coup de pied droit accroupi du personnage
 *
 * \param a : la nouvelle action a effectuer lorsqu'un coup de pied droit accroupi est déclenché
 *
 */
void Personnage::setAcc2D(Action a)
{
    Acc2D = a;
}
/** \brief mutateur du coup de pied gauche accroupi du personnage
 *
 * \param a : la nouvelle action a effectuer lorsqu'un coup de pied gauche accroupi est déclenché
 *
 */
void Personnage::setAcc2G(Action a)
{
    Acc2G = a;
}

/** \brief mutateur de la hitbox d'une attaque
 *
 * \param a: la nouvelle coordonnée x du point d'origine du nouveau rectangle
 * \param b: la nouvelle coordonnée y du point d'origine du nouveau rectangle
 * \param c: la nouvelle largeur du nouveau rectangle
 * \param d: la nouvelle hauteur du nouveau rectangle
 *
 */
void Personnage::setHitBoxAtt(int a, int b, int c, int d)
{
    HitBoxAtt.x = a;
    HitBoxAtt.y = b;
    HitBoxAtt.w = c;
    HitBoxAtt.h = d;
}
/** \brief mutateur de la hitbox d'un personnage
 *
 * \param a: la nouvelle coordonnée x du point d'origine du nouveau rectangle
 * \param b: la nouvelle coordonnée y du point d'origine du nouveau rectangle
 * \param c: la nouvelle largeur du nouveau rectangle
 * \param d: la nouvelle hauteur du nouveau rectangle
 *
 */
void Personnage::setHitBoxPerso(int a, int b, int c, int d)
{
    HitBoxPerso.x = a;
    HitBoxPerso.y = b;
    HitBoxPerso.w = c;
    HitBoxPerso.h = d;
}
/** \brief mutateur des statistiques d'un personnage
 *
 * \param s: les nouvelles statistiques du personnage
 *
 */
void Personnage::setstats(Statistique s)
{
    stats = s;
}
/** \brief mutateur des points de vie du personnafe
 *
 * \param v: les nouveaux points de vie du personnage
 *
 */
void Personnage::setvie(int v)
{
    stats.setvie(v);
}
/** \brief mutateur de la vitesse d'attaque du personnage
 *
 * \param v : la nouvelle vitesse d'attaque
 *
 */
void Personnage::setvitesse_att(int v)
{
    stats.setvitesse_att(v);
}
/** \brief mutateur de la vitesse de déplacement du personnage
 *
 * \param v : la nouvelle vitesse de déplacement
 *
 */
void Personnage::setvitesse_depl(int v)
{
    stats.setvitesse_depl(v);
}
/** \brief mutateur de l'état du bouclier du personnage
 *
 * \param b: la valeur de bouclier, vrai pour actif, faux sinon
 *
 */
void Personnage::setbouclier(bool b)
{
    bouclier = b;
}


//fonctions de direction
/** \brief calcule la position puis déplace le personnage à gauche
 *
 */
void Personnage::vaGauche()
{
    if ((position.x - stats.getvitesse_depl())>= 30)
    {
        SDL_Point p = {position.x - stats.getvitesse_depl(),position.y};
        position=p;
    }
    orientation = false;

}

/** \brief calcule la position puis déplace le personnage à droite
 *
 */
void Personnage::vaDroite()
{
    SDL_Point p = {position.x + stats.getvitesse_depl(),position.y};
    if (p.x <= 1700)
    {
        position=p;
    }
    orientation = true;
}

/** \brief calcule la position puis fait sauter le personnage et change son état
 *
 *
 */
unsigned int Personnage::saute()
{
    position = {position.x,position.y - 300};
    etat.sauter ();
    return SDL_GetTicks();
}

/** \brief calcule la position puis fait atterir le personnage
 */
void Personnage::descendre()
{
    position = {position.x,position.y + 300};
    etat.setSaut(false);
}

/** \brief mutateur de l'état du personnage en accroupi
 */
void Personnage::accroupir()
{
    etat.accroupir();
}

/** \brief mutateur de l'état du personnage en debout
*/
void Personnage::lever()
{
    etat.lever();
}

/** \brief fais attaquer le personnage
 *
 * \param i: l'identifiant de l'attaque
 * \return le nombre de ticks pendant lequel le personnage attaque
 *
 */
unsigned int Personnage::attaquer(int i)
{
    etat.attaquer(i);
    return SDL_GetTicks();
}

/** \brief finit l'attaque du personnage
 */
void Personnage::FinAtt()
{
    etat.setAttaque(0);
}

/** \brief destructeur du personnage
 */
Personnage::~Personnage()
{

}
