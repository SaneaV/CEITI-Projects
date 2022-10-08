//Известны ширина и длина прямоугольника. Сколько квадратов со стороной А можно вырезать из данного прямоугольника

#include <iostream>
#include <cmath>

using namespace std;

main()
{
    setlocale (LC_ALL,"Rus");

    cout<<"Введите длину прямоугольника: ";
    int dlina,shirina,kvadrat;
    cin>>dlina;
    cout<<"Введите ширину прямоугольника: ";
    cin>>shirina;
    cout<<"Введите сторону квадрата: ";
    cin>>kvadrat;

    int otvet;

    otvet = (dlina*shirina)/kvadrat*kvadrat;

    cout<<"В этом прямоугольнике получается "<<otvet<<" квадратов.";

}
