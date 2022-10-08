#ifndef CIRCLE_H
#define CIRCLE_H

#include <figury.h>


class circle : public figury
{
    public:
        circle( unsigned int);
        void show();

    protected:

    private:
        unsigned int r;
};

#endif // CIRCLE_H
