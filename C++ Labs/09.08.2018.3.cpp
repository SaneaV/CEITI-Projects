//Напишите программу, которая вычисляет произведение членов последовательности, кратных тринадцати.
//Программа получает на вход целые числа, количество введенных чисел неизвестно, последовательность чисел заканчивается числом ноль
//(ноль – признак окончания ввода, не входит в последовательность).
//Количество чисел не превышает 1000. Введенные числа по модулю не превышают 30000.

#include <iostream>
#include <cmath>
#include <windows.h>

using namespace std;

int main()
{
    setlocale(LC_ALL,"RUS");

    int A[1000];
    int i = 0;
    A[i] = 1;
    int n = 0;
    bool Finish = true;
    int Amount=1;

    int Select;
    cout<<"Выберите цикл для рещения данной задачи: "<<endl;
    cout<<"1.While"<<endl;
    cout<<"2.Do...While"<<endl;
    cout<<"3.For"<<endl;
    cout<<"Ваш выбор: ";
    cin>>Select;

    system("cls");

    switch(Select)
    {
    case 1:
        {
            while(Finish)
            {
                while(abs(A[i]>30000))
                {
                    cout<<"Введите число: ";
                    cin>>A[i];
                    if(A[i]!=0 and A[i]%13==0) Amount*=A[i];
                }
                n++;
                if (A[i]==0)
                {
                    n--;
                    Finish = false;
                }
                i++;
            }
            cout<<"Произведение чисел, кратных тринадцати: "<<Amount<<endl;
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
                    if(A[i]!=0 and A[i]%13==0) Amount*=A[i];

                }while(abs(A[i])>30000);

                n++;
                if (A[i]==0)
                {
                    n--;
                    Finish = false;
                }
                i++;

            }while(Finish);

            cout<<"Произведение чисел, кратных тринадцати: "<<Amount<<endl;
            break;
        }
    case 3:
        {
            for(;Finish;)
            {
                for(;abs(A[i])>30000;)
                {
                    cout<<"Введите число: ";
                    cin>>A[i];
                    if(A[i]!=0 and A[i]%13==0) Amount*=A[i];
                }

                n++;
                if (A[i]==0)
                {
                    n--;
                    Finish = false;
                }
                i++;
            }
            cout<<"Произведение чисел, кратных тринадцати: "<<Amount<<endl;
            break;
        }
        default:cout<<"Такого варианта нет"<<endl;
    }
}
