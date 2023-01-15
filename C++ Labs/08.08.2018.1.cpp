//Напишите программу, которая в последовательности целых чисел выводит на экран максимальное четное число, кратное девяти .
//Программа получает на вход целые числа, количество введенных чисел неизвестно, последовательность чисел заканчивается числом ноль
//(ноль – признак окончания ввода, не входит в последовательность).
//Количество чисел не превышает 1000. Введенные числа по модулю не превышают 30000

#include <iostream>
#include <windows.h>
#include <cmath>

using namespace std;

int main()
{
    setlocale(LC_ALL,"RUS");

    int A[1000];
    int x;
    bool Finish = true;
    int i=0;
    int n=0;
    int max=0;

    A[i] = 1;

    cout<<"Выберите цикл для решения данной задачи: "<<endl;
    cout<<"1. While"<<endl;
    cout<<"2. Do..While"<<endl;
    cout<<"3. For"<<endl;
    cout<<"Ваш выбор: ";
    cin>>x;

    system("cls");

    switch(x)
    {
    case 1:
    {
        while (Finish)
        {
            while(abs(A[i])>30000)
            {
                cout<<"Введите число: ";
                cin>>A[i];
            }
            if (A[i]==0)
            {
                n--;
                Finish=false;
            }

            if (A[i]>max and A[i]%9==0 and A[i]%2==0)
                max = A[i];

            n++;
            i++;
        }
        system("cls");
        cout<<"Максимальное чётное число, кратное девяти: "<<max;
        break;
    }
    case 2:
    {
        do
        {
            do
            {
                cout<<"Введите число: ";
                cin>>A[i];
            }
            while(abs(A[i])>30000);

            if (A[i]==0)
            {
                n--;
                Finish=false;
            }

            if (A[i]>max and A[i]%9==0 and A[i]%2==0)
                max = A[i];

            n++;
            i++;
        }
        while(Finish);

        system("cls");

        cout<<"Максимальное чётное число, кратное девяти: "<<max;
        break;
    }
    case 3:
    {
        for(; Finish; i++,n++)
        {
            for(; abs(A[i])>30000;)
            {
                cout<<"Введите число: ";
                cin>>A[i];
            }

            if (A[i]==0)
            {
                n--;
                Finish=false;
            }

            if (A[i]>max and A[i]%9==0 and A[i]%2==0)
                max = A[i];

        }
        system("cls");
        cout<<"Максимальное чётное число, кратное девяти: "<<max;
        break;
    }
    default:
        cout<<"Такого варианта не существует."<<endl;
    }

}
