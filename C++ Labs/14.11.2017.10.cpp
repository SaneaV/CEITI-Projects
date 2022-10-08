//Подсчитать количество кг в 10 футах.

#include <iostream>

using namespace std;

main()
{
    setlocale(0,"Rus");
    float funt=1,kg=0;
    for (;funt<=10;funt+=0.5)
    {
        kg+=0.4;
        cout<<"В "<<funt<<" фунтах "<<kg<<" килограмм"<<endl;

    }
}
