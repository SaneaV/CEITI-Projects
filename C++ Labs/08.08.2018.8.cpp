//Напишите программу, которая в последовательности целых чисел определяет сумму всех чисел, кратных 4 и оканчивающихся на 6.
//Программа получает на вход целые числа, количество введенных чисел неизвестно, последовательность чисел заканчивается числом ноль
//(ноль – признак окончания ввода, не входит в последовательность).
//Количество чисел не превышает 1000. Введенные числа по модулю не превышают 30000.

#include <iostream>
#include <windows.h>
#include <cmath>

using namespace std;

int main()
{
    setlocale(LC_ALL,"RUS");

    int A[1000];
    int i=0;
    int n=0;
    A[i]=1;
    int Sum=0;
    bool Finish = true;

    int Select;

    cout<<"Выберите цикл для решения данной задачи: "<<endl;
    cout<<"1. While"<<endl;
    cout<<"2. Do..While"<<endl;
    cout<<"3. For"<<endl;
    cout<<"Ваш выбор: ";
    cin>>Select;

    system("cls");

    switch(Select)
    {
    case 1:
    {
        while(Finish)
        {
            while(abs(A[i])>30000)
            {
                cout<<"Введите число: ";
                cin>>A[i];
                if (A[i]%4==0 and A[i]%10==6 and A[i]!=0)
                {
                    Sum+=A[i];
                }
            }
            n++;

            if(A[i]==0)
            {
                n--;
                Finish=false;
            }
            i++;
        }
        cout<<"Сумма чисел: "<<Sum<<endl;
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
                if (A[i]%4==0 and A[i]%10==6 and A[i]!=0)
                {
                    Sum+=A[i];
                }
            }
            while(abs(A[i])>30000);

            n++;

            if(A[i]==0)
            {
                n--;
                Finish=false;
            }
            i++;
        }
        while(Finish);
        cout<<"Сумма чисел: "<<Sum<<endl;
        break;
    }
    case 3:
    {
        for(; Finish;)
        {
            for(; abs(A[i])>30000;)
            {
                cout<<"Введите число: ";
                cin>>A[i];
                if (A[i]%4==0 and A[i]%10==6 and A[i]!=0)
                {
                    Sum+=A[i];
                }

            }
            if(A[i]==0)
            {
                n--;
                Finish=false;
            }
            i++;
            n++;
        }
        cout<<"Сумма чисел: "<<Sum<<endl;
        break;
    }
    default:
        cout<<"Такого варианта нет"<<endl;
    }

}
