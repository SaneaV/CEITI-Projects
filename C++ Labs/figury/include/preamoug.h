#ifndef PREAMOUG_H
#define PREAMOUG_H

#include <paralel.h>


class preamoug : public paralel
{
    public:
        preamoug(int,int);
        void show();

    protected:

    private:
        int a;
        int b;
};

#endif // PREAMOUG_H
