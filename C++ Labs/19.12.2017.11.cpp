//Найти высоту равнобедренного треугольника со сторонами а,в,с, если а=в.

#include <iostream>
#include <cmath>

using namespace std;

main()
{
    setlocale(LC_ALL,"Russian");

    cout<<"Введите сторону b: ";
    int b,c;
    cin>>b;
    int a=b;
    cout<<endl<<"Введите сторону c: ";
    cin>>c;
    float h=sqrt((a*a)-(c*c)/4);
    cout<<endl<<"Высота треугольника: "<<h;
}
