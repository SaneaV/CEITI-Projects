//Числа, которые одинаково читаются как сначала, так и с конца называются палиндромами. Например, 33, 121, 14541, 7887.
//Напиште программу, которая определяет являеется ли введенное с клавиатуры натуральное число палиндромом.

#include <iostream>
#include <windows.h>

using namespace std;

int main()
{
    setlocale(LC_ALL,"RUS");

    int Select;
    int Number;

    cout<<"Введите число: ";
    cin>>Number;

    system("cls");


    cout<<"Выберите цикл для решения данной задачи: "<<endl;
    cout<<"1. While"<<endl;
    cout<<"2. Do..While"<<endl;
    cout<<"3. For"<<endl;
    cout<<"Ваш выбор: ";
    cin>>Select;

    float Palendrom=0;
    int i = 1;
    int MainNumber = Number;

    switch(Select)
    {
    case 1:
    {
        while (Number!=0)
        {
            Palendrom *=i;
            Palendrom +=Number%10;
            i=10;
            Number /= 10;
        }

        if ((MainNumber*1.0/Palendrom*1.0)==1.0)
            cout<<"Число является палиндромом"<<endl;
        else
            cout<<"Число не является палиндромом"<<endl;
            break;
    }
    case 2:
    {
        do
        {
            Palendrom *=i;
            Palendrom +=Number%10;
            i=10;
            Number /= 10;
        }
        while(Number!=0);

        if ((MainNumber*1.0/Palendrom*1.0)==1.0)
            cout<<"Число является палиндромом"<<endl;
        else
            cout<<"Число не является палиндромом"<<endl;
            break;
    }

    case 3:
    {
        for (; Number!=0;)
        {
            Palendrom *=i;
            Palendrom +=Number%10;
            i=10;
            Number /= 10;
        }

        if ((MainNumber*1.0/Palendrom*1.0)==1.0)
            cout<<"Число является палиндромом"<<endl;
        else
            cout<<"Число не является палиндромом"<<endl;
            break;
    }

    default: cout<<"Такого варианта не существует"<<endl;
    }
}
