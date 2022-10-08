//Количество урожая каждые два года падает на 0,8 процентов
//Определить год, когда соберут менее 5 кг
//Определить год, когда общий объём урожая будет равен 90 кг

#include <iostream>
#include <cmath>

using namespace std;

main ()
{
    setlocale (LC_ALL,"Rus");
    float ton=20.0, S=0;
    int god=1990;

    for (;S<=90.0;)
    {
        S+=ton;
        cout<<"В "<<god<<" собрали: "<< ton<<"\n";
        god+=2;
        ton*=0.8;
        if (ton<6.0 and ton>5.0) cout<<"В"<<god<<" собрали менее 5 кг";
        if (S<=90.0 and S>=89.0) cout<<"В"<<god<<" собрали в общем 90 кг";
    }

}
