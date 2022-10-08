//Напишите эффективную программу, которая по двум данным натуральным числам х и у, не превосходящим 10000,
//подсчитывает количество натуральных чисел,
//кратных пяти на отрезке [х,у] (включая концы отрезка).

#include <iostream>
#include <windows.h>
#include <cmath>

using namespace std;

int main()
{
    setlocale(LC_ALL,"RUS");

    int x,y;
    int k=0;

    do
    {
    cout<<"Введите начальную точку: ";
    cin>>x;
    cout<<"Введите конечную точку: ";
    cin>>y;
    }while(abs(x)>30000 or abs(y)>30000);

    if(x>y)
    {
        int c = y;
        x = y;
        y = c;
    }

    system("cls");

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
            while(x<=y)
            {
                if (x%5==0) k++;
                x++;
            }
            cout<<"Количетсво чисел, кратных пяти: "<<k;
            break;
        }
    case 2:
        {
            do
            {
                if(x%5==0) k++;
                x++;
            }while(x<=y);
            cout<<"Количетсво чисел, кратных пяти: "<<k;
            break;
        }
    case 3:
        {
            for(;x<=y;x++)
            {
                if(x%5==0) k++;
            }
            cout<<"Количетсво чисел, кратных пяти: "<<k;
            break;
        }
    default: cout<<"Такого варианта нет"<<endl;
    }

}
