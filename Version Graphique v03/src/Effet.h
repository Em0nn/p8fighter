#ifndef EFFET_H
#define EFFET_H
#include <cassert>
#include <cstring>

class Effet
{

    private:

        bool bouclier;
        std::string stat_modif;
        int val_modif;
        std::string son;

    public:

        Effet();

        Effet(bool b, std::string stat, int val, std::string son);

        //get
        bool getbouclier();
        std::string getstat_modif();
        int getval_modif();
        std::string getson();


        //set
        void setbouclier(bool b);
        void setstat_modif(std::string stat);
        void setval_modif(int val);
        void setson(std::string son);


        ~Effet();


};

#endif // EFFET_H
