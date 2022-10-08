//Даны три целых числа a,b,c. Верно ли, что условие a<b<c.

#include <iostream>

using namespace std;

main()
{
    setlocale (LC_ALL,"RUS");

    cout<<"Введите число a: ";
    int a,b,c;
    cin>>a;
    cout<<"Введите число b: ";
    cin>>b;
    cout<<"Введите число c: ";
    cin>>c;

    cout<<"Верно ли, что условие a<b<c: "<<boolalpha<<(a<b and b<c);

}
