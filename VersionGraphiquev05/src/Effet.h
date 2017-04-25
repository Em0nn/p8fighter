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
        /*
        std::string son;
        */

    public:

        Effet();

        Effet(bool b, float stat, float val/*, std::string son*/);

        //get
        bool getbouclier();
        float getstat_modif();
        float getval_modif();
        /*
        std::string getson();
        */

        //set
        void setbouclier(bool b);
        void setstat_modif(float stat);
        void setval_modif(float val);
        /*
        void setson(std::string son);
        */

        ~Effet();


};

#endif // EFFET_H
