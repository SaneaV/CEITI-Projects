//Найти площадь прямоугольного треугольника по известным сторонам: гипотенузе и катету.

#include <iostream>
#include <cmath>

using namespace std;

main()
{
    setlocale(LC_ALL,"Russian");

    cout<<"Введите гипотенузу: ";
    int g,k;
    cin>>g;
    cout<<endl<<"Введите катет: ";
    cin>>k;
    int k1=sqrt(pow(g,2)*pow(k,2));
    float S=0.5*k*k1;
    cout<<"Площадь прямоугольного треугольника: "<<S;
}

