//Даны два целых числа. Составить программу, которая большее число возводит в квадрат, а меньшее увеличивает на 10.
//Если числа равны, то вывести сообщение «ЧИСЛА РАВНЫ».


#include <iostream>

using namespace std;

main()
{
    setlocale(LC_ALL,"RUS");

    int a,b;
    cout<<"Введите число а: ";
    cin>>a;
    cout<<"Введите число b: ";
    cin>>b;


    a==b? cout<<"ЧИСЛА РАВНЫ!"<<endl: a>b and a!=b? cout<<"Большое число: "<<a*a<<endl<<"Меньшее число: "<<b*10<<endl: cout<<"Большое число: "<<b*b<<endl<<"Меньшее число: "<<a*10<<endl;

}
