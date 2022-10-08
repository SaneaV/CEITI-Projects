//Даны два числа. Если оба числа положительные, то найти их сумму,
//иначе вывести сообщение «условие не выполняется».

#include <iostream>

using namespace std;

main()
{
    setlocale (0,"Russian");
    cout<<"Ведите x: ";
    int x;
    cin>>x;
    cout<<"Введите y: ";
    int y;
    cin>>y;
    if (x>0 and y>0) cout<<x+y;
    else cout<<"Условие не выполняется";

}


