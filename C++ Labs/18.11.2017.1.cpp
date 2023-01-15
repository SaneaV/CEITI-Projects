//Напишите программу, которая в последовательности целых чисел определяет сумму положительных чисел, кратных девяти.
//Программа получает на вход целые числа, количество введенных чисел неизвестно, последовательность чисел заканчивается числом ноль
//(ноль – признак окончания ввода, не входит в последовательность).
//Количество чисел не превышает 1000. Введенные числа по модулю не превышают 30000.

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    setlocale (0, "");

    int x = 0;
    int summ = 0;
    int k=0;

    cout << "Нажмите: \n[1] для :for: \n[2] для :while:\n[3] для :do while:"<<endl;
    cin >> x;
    switch(x)
    {
    case(1):
    {
        cout<<"Вы выбрали оператор цикла for"<<endl;
        for(; x!=0 and k<1000 and x<abs(30000); )
        {
            cout<<"Ввведите число:"<<endl;
            cin>>x;
            if(x>0 and x%9==0) summ+=x;
            k++;
        }
        cout <<"Сумма чисел кратных девяти = "<< summ;
        break;
    }

    case(2):
    {
        cout<<"Вы выбрали оператор цикла while"<<endl;
        while(x!=0 and k<1000 and x<abs(30000))
        {
            cout<<"Ввведите число:"<<endl;
            cin >> x;
            if(x>0 and x%9==0) summ+=x;
            k++;
        }
        cout<<"Сумма чисел кратных девяти = "<<summ;
        break;
    }

    case(3):
    {
        cout<<"Вы выбрали оператор цикла do-while"<<endl;
        do
        {
            cout<<"Ввведите число:"<<endl;
            cin >> x;
            if(x>0 and x%9==0) summ+=x;
            k++;

        }
        while(x!=0 and k<1000 and x<abs(30000));
        cout <<"Сумма чисел кратных девяти = "<<summ;
        break;
    }

    default:
        cout<<"Только 3 оператора цикла.";

    }
}
