//Известна диагональ и ширина прямоугольника. Найти его периметр.

#include <iostream>
#include <cmath>

using namespace std;

main()
{
    setlocale(LC_ALL,"Rus");

    cout<<"Введите диагональ прямоугольника: ";
    int diagonali, shirina,P,dlina=0;
    cin>>diagonali;
    cout<<"Введите ширину прямоугольника: ";
    cin>>shirina;

    dlina = sqrt ((diagonali*diagonali)-(shirina*shirina));

    P=2*(dlina+shirina);

    cout<<"Периметр прямоугольника: "<<P;
}
