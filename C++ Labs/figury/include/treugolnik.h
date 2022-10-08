#ifndef TREUGOLNIK_H
#define TREUGOLNIK_H

#include <suglamy.h>


class treugolnik : public suglamy
{
    public:
        treugolnik(int,int,int);
        void show();

    protected:

    private:
        int a;
        int b;
        int c;
};

#endif // TREUGOLNIK_H
