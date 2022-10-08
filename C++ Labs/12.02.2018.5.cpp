//Найти площадь круга, если известен радиус.

#include <iostream>
#include <cmath>

using namespace std;

main()
{
    setlocale (LC_ALL,"Rus");

    int R=0;
    cout<<"Введите радиус круга: ";
    cin>>R;

    float S;
    S=M_PI*(R*R);

    cout<<"Площадь круга: "<<S;
}
