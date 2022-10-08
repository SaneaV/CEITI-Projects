//Вычислить радиус окружности, если известна длина окружности.

#include <iostream>
#include <cmath>

using namespace std;

main()
{
    setlocale (LC_ALL,"Rus");

    cout<<"Введите длину окружности: ";
    int dlina;
    cin>>dlina;

    float R;
    R=dlina/(2*M_PI);

    cout<<"Радиус окружности: "<<R;
}
