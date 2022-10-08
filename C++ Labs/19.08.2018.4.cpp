//Окружность может быть задана через координаты х, у центра и радиус r. Напишите программу,
//которая считывает с клавиатуры данные об n окружностях (n<50) и выводит на экран:
//• координаты центра и радиус окружности, которая описывает круг максимальной площади;
//количество окружностей, входящих в круг с максимальным радиусом, и координаты соответствующих центров;"

#include <iostream>
#include <windows.h>
#include <cmath>

using namespace std;

struct OKRUJNOSTI
{
    int x;
    int y;
    int r;
};

int main()
{
    setlocale(LC_ALL,"RUS");

    int n;

    do
    {
        cout<<"Введите количество окружностей: ";
        cin>>n;
    }
    while(n>50);

    struct OKRUJNOSTI OKR[n];

    int rmax = 0;

    for(int i=0; i<n; i++)
    {
        cout<<"Введите координату \"x\": ";
        cin>>OKR[i].x;

        cout<<"Введите координату \"y\": ";
        cin>>OKR[i].y;

        cout<<"Введите радиус окружности: ";
        cin>>OKR[i].r;

        if(rmax<OKR[i].r) rmax = OKR[i].r;

        system("cls");
    }

    int Select;
    int RepeatSelect;
    bool Menu = true;

    while(Menu)
    {
        cout<<"1. Информация о окружности с самой большой площадью."<<endl;
        cout<<"2. Количество окружностей которые входят в самую большой круг."<<endl;
        cout<<"Ваш выбор: ";
        do
        {
            cin>>Select;
        }
        while(Select>2 or Select<1);

        system("cls");

        switch(Select)
        {
        case 1:
        {
            int max=0;
            int pmax;
            float S = 0;

            for(int i=0; i<n; i++)
            {
                S = 3.14 * pow(OKR[i].r,2);

                if(S>max)
                {
                    max = S;
                    pmax=i;
                }
            }

            cout<<"Координаты центра окружности: ("<<OKR[pmax].x<<":"<<OKR[pmax].y<<"), радиус окружности - "<<OKR[pmax].r<<endl;

            cout<<endl<<endl;
            cout<<"1. Вернуться в меню."<<endl;
            cout<<"2. Выйти из программы."<<endl;
            do
            {
                cin>>RepeatSelect;

            }
            while(RepeatSelect<1 or RepeatSelect>2);

            if (RepeatSelect==1)
                system("cls");
            if (RepeatSelect==2)
            {
                system("cls");
                Menu = false;
            }

            break;
        }
        case 2:
            {
                int k = 0;

                for(int i=0;i<n;i++)
                {
                    if(rmax>OKR[i].r) k++;
                }

                cout<<"Количество окружностей, которые входят в самую большую по радиусу окружности: "<<k<<endl;

                cout<<endl<<endl;
            cout<<"1. Вернуться в меню."<<endl;
            cout<<"2. Выйти из программы."<<endl;
            do
            {
                cin>>RepeatSelect;

            }
            while(RepeatSelect<1 or RepeatSelect>2);

            if (RepeatSelect==1)
                system("cls");
            if (RepeatSelect==2)
            {
                system("cls");
                Menu = false;
            }

            break;
            }
        }
    }

}
