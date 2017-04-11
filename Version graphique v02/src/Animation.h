#ifndef ANIMATION_H_INCLUDED
#define ANIMATION_H_INCLUDED

class Animation
{
    private:

        char * graphisme;

    public:

        /** \brief constructeur par défaut
         */
        Animation();


        /** \brief constructeur
         */
        Animation(char * graph);


        /** \brief destructeur
         */
        ~Animation();

//accesseurs
        char * getGraphisme ();

//mutateurs
        void setGraphisme (char * graph);

};
#endif
