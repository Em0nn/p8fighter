#ifndef COMPETENCE_H_INCLUDED
#define COMPETENCE_H_INCLUDED
#include <cstring>
#include "Animation.h"
#include "Effet.h"

class Competence
{
    private:

        std::string nomPerso;
        Animation animation;
        Effet effet;

    public:

        /** \brief constructeur par défaut
         */
        Competence();


        /** \brief constructeur
         */
        Competence(std::string nom, Animation anim, Effet eff);


        /** \brief destructeur
         */
        ~Competence();

//accesseurs
        std::string getNomPerso ();
        Animation getAnimation ();
        Effet getEffet ();

//mutateurs
        void setNomPerso (std::string nom);
        void setAnimation (Animation anim);
        void setEffet (Effet eff);

//fonctions
        void ulti (std::string & NomLanceur, std::string & NomReceveur);
};
#endif
