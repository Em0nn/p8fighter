#ifndef PERSONNAGE_H
#define PERSONNAGE_H

//#include <cstring>
#include "Etat.h"
#include "Action.h"
#include "Statistique.h"
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>

class Personnage
{
    private:

        const char* nomImage;
        Statistique stats;
        Etat etat;
        Action Deb1D; //1 <- code attaque
        Action Deb1G; //2
        Action Deb2D; //3
        Action Deb2G; //4
        Action Acc1D; //5
        Action Acc1G; //6
        Action Acc2D; //7
        Action Acc2G; //8
        bool orientation;
        bool bouclier;
        SDL_Point position;
        SDL_Rect HitBoxPerso;
        SDL_Rect HitBoxAtt;

    public:

        Personnage();

        Personnage(const char* i,SDL_Point p, bool o, int val_vie, int val_att, int val_depl);

        //fonctions get
        const char* getnomImage() const;
        Etat getetat() const;
        Action getDeb1D();
        Action getDeb1G();
        Action getDeb2D();
        Action getDeb2G();
        Action getAcc1D();
        Action getAcc1G();
        Action getAcc2D();
        Action getAcc2G();
        bool getorientation() const;
        bool getbouclier();
        SDL_Point getposition() const;
        SDL_Rect getHitBoxPerso() const;
        SDL_Rect getHitBoxAtt() const;
        Statistique getstats();


        //fonctions set
        void setnomImage(const char* i);
        //void setaspect(Animation an);
        //void setulti(Competence u);
        //void setstats(Statistique s);
        void setetat(Etat e);
        void setDeb1D(Action a);
        void setDeb1G(Action a);
        void setDeb2D(Action a);
        void setDeb2G(Action a);
        void setAcc1D(Action a);
        void setAcc1G(Action a);
        void setAcc2D(Action a);
        void setAcc2G(Action a);
        void setorientation(bool o);
        void setbouclier(bool b);
        void setposition(SDL_Point p);
        void setHitBoxPerso(int a, int b, int c, int d);
        void setHitBoxAtt(int a, int b, int c, int d);
        void setstats(Statistique s);
        void setvie(int v);
        void setvitesse_att(int v);
        void setvitesse_depl(int v);

        void vaGauche();
        void vaDroite();
        unsigned int saute();
        void accroupir();
        void descendre();
        void lever();
        unsigned int attaquer(int i);
        void FinAtt();


        ~Personnage();
};

#endif // PERSONNAGE_H
