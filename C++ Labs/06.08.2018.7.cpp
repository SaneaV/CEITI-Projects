//Даны два числа. Если оба числа положительные, то найти их сумму, иначе вывести сообщение «условие не выполняется».

#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL,"RUS");

    int A,B;

    cout<<"Введите число: ";
    cin>>A;
    cout<<"Введите число: ";
    cin>>B;

    A>=0 and B>=0? cout<<"Сумма чисел: "<<A+B<<endl:cout<<"Условие не выполняется"<<endl;
}
