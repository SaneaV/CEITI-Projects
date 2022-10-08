//Напишите эффективную программ, которая по двум данным натуральным числам х и у, не превосходящим 10000,
//подсчитывает количество натуральных чисел, заканчивающихся нулем, на отрезке [х,у] (включая концы отрезка).

#include <iostream>
#include <windows.h>

using namespace std;

int main()
{
    setlocale(LC_ALL,"RUS");

    int x,y;
    int k=0;

    while(x>10000 or y>10000)
    {
    cout<<"Введите число: ";
    cin>>x;
    cout<<"Введите второе число: ";
    cin>>y;
    }

    system("cls");


    if (x>y)
    {
        int c = x;
        x = y;
        y = c;
    }

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
            while(x<=y)
            {
                if(x%10==0) k++;
                x++;
            }
            cout<<"Количество чисел, оканчивающихся на ноль: "<<k<<endl;
            break;

        }
    case 2:
        {
            do
            {
                if(x%10==0) k++;
                x++;
            }while(x<=y);
            cout<<"Количество чисел, оканчивающихся на ноль: "<<k<<endl;
            break;
        }
    case 3:
        {
            for(;x<=y;x++)
            {
              if(x%10==0) k++;
            }
            cout<<"Количество чисел, оканчивающихся на ноль: "<<k<<endl;
            break;
        }
    default: cout<<"Такого варианта нет."<<endl;
    }
}
