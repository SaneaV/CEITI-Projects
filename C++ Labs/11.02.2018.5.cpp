//Найти площадь параллелограмма, если его основание равно А см, а высота, проведенная к основанию равна В см.
//Ответ выразить квадратных метрах.


#include <iostream>

using namespace std;

main()
{
    setlocale(LC_ALL,"Rus");

    int A,h,S;

    cout<<"Введите основание параллелограмма: ";
    cin>>A;

    cout<<"Введите высоту параллелограмма: ";
    cin>>h;

    S=A*h;

    cout<<"Площадь параллелограмма: "<<S;
}
