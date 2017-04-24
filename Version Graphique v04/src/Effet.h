#ifndef EFFET_H
#define EFFET_H
#include <cassert>
#include <cstring>

class Effet
{

    private:

        bool bouclier;
        int stat_modif;
        int val_modif;
        /*
        std::string son;
        */

    public:

        Effet();

        Effet(bool b, int stat, int val/*, std::string son*/);

        //get
        bool getbouclier();
        int getstat_modif();
        int getval_modif();
        /*
        std::string getson();
        */

        //set
        void setbouclier(bool b);
        void setstat_modif(int stat);
        void setval_modif(int val);
        /*
        void setson(std::string son);
        */

        ~Effet();


};

#endif // EFFET_H
