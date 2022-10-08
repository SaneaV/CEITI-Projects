//Дано расстояние в сантиметрах. Найти число полных метров в нем.

#include <iostream>

using namespace std;

main()
{
    setlocale(LC_ALL,"Russian");

    cout<<"Введите количество сантиметров: ";
    int cm,m;
    cin>>cm;
    m=cm/100;
    cout<<"Количество полных метров в ваших сантиметрах: "<<m;
}
