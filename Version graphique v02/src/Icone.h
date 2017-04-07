#ifndef ICONE_H_INCLUDED
#define ICONE_H_INCLUDED

class Icone
{
    private:

        string nom;
        string image;
        string son;

    public:

        /** \brief constructeur par défaut
         */
        Icone();


        /** \brief constructeur
         */
        Icone(string nom, string im, string son);


        /** \brief destructeur
         */
        ~Icone();

//accesseurs
        string getNom ();
        string getImage ();
        string getSon ();

//mutateurs
        void setNom (string nom);
        void setImage (string im);
        void setSon (string son);

};
#endif
