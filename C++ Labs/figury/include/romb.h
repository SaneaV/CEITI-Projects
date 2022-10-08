#ifndef ROMB_H
#define ROMB_H

#include <paralel.h>


class romb : public paralel
{
    public:
        romb(int, int);
         void show();

    protected:

    private:
        int a;
        int u;
};

#endif // ROMB_H
