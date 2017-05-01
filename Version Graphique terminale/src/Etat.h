#ifndef ETAT_H_INCLUDED
#define ETAT_H_INCLUDED

class Etat
{
    private:

        bool accroupi;
        bool couche;
        bool saut;
        int attaque;

    public:

        /** \brief constructeur par défaut
         */
        Etat();


        /** \brief constructeur
         */
        Etat(bool accroup, bool couch, bool sau);


        /** \brief destructeur
         */
        ~Etat();

//accesseurs
        bool  getAccroupi ();
        bool  getCouche ();
        bool  getSaut ();
        int  getAttaque ();

//mutateurs
        void setAccroupi (bool a);
        void setCouche (bool  c);
        void setSaut (bool s);
        void setAttaque (int a);

//fonctions
        void accroupir ();
        void coucher ();
        void sauter ();
        void lever ();
        void attaquer (int i);
};
#endif
