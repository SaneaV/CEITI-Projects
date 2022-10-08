//Известна площадь круга. Найти его радиус.

#include <iostream>
#include <cmath>

using namespace std;

main()
{
    setlocale (LC_ALL,"Rus");

    cout<<"Введите площадь круга: ";
    int S;
    cin>>S;
    float r=sqrt(S)/3.14;
    cout<<endl<<"Радиус круга: "<<r;
}
