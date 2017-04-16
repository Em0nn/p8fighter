#ifndef POINT_H_INCLUDED
#define POINT_H_INCLUDED

class Point
{

    private:

        unsigned int x;
        unsigned int y;

    public:

        Point();
        Point(unsigned int a, unsigned int b);

        unsigned int getx() const;
        unsigned int gety() const;

        void setx(unsigned int a);
        void sety(unsigned int b);

        void setxety(unsigned int a, unsigned int b);

        void testRegression();

        ~Point();


};


#endif // POINT_H_INCLUDED
