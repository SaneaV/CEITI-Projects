//Какое расстояние проехала машина за время Т со скоростью V км/ч?

#include <iostream>
#include <cmath>

using namespace std;

main()
{
    setlocale(LC_ALL,"Russian");

    cout<<"Введите скорость автомобиля(км/ч): ";
    int V;
    cin>>V;
    cout<<endl<<"Введите время, за которое автомобиль проехал расстояние(часы): ";
    float T;
    cin>>T;
    float S=V*1.0*T;
    cout<<endl<<"Расстояние, который проехал автомобиль: "<<S;
}


