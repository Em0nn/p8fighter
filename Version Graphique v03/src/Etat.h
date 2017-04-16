#ifndef ETAT_H_INCLUDED
#define ETAT_H_INCLUDED

class Etat
{
    private:

        bool accroupi;
        bool couche;
        bool saut;

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

//mutateurs
        void setAccroupi (bool a);
        void setCouche (bool  c);
        void setSaut (bool s);

//fonctions
        void accroupir ();
        void coucher ();
        void sauter ();
        void lever ();
};
#endif
