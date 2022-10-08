//Известна площадь и длина прямоугольника. Найти его ширину.

#include <iostream>

using namespace std;

main()
{
    setlocale(LC_ALL,"Russian");

    cout<<"Введите площадь прямоугольника: ";
    int S,a,b=0;;
    cin>>S;
    cout<<endl<<"Введите длину прямоугольника: ";
    cin>>a;
    b=S/a;
    cout<<endl<<"Ширина прямоугольника: "<<b<<endl;
}
