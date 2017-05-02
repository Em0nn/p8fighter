#ifndef EFFET_H
#define EFFET_H
#include <cassert>
#include <cstring>

class Effet
{

    private:

        bool bouclier;
        float stat_modif;
        float val_modif;

    public:

        Effet();

        Effet(bool b, float stat, float val);

        //get
        bool getbouclier();
        float getstat_modif();
        float getval_modif();

        //set
        void setbouclier(bool b);
        void setstat_modif(float stat);
        void setval_modif(float val);

        ~Effet();


};

#endif // EFFET_H
