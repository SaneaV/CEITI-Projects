//Даны три целых числа a,b,c. Проверить, выполняется ли условие a>b>c.

#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL,"RUS");

    int a,b,c;

    cout<<"Введите число: ";
    cin>>a;
    cout<<"Введите число: ";
    cin>>b;
    cout<<"Введите число: ";
    cin>>c;

    a>b and b>c? cout<<"Условие выполняется"<<endl:cout<<"Условие не выполняется"<<endl;
}
