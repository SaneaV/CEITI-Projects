/*Каждая точка на евклидовой плоскости координатами xi, yi. Расстояние между двумя точками вычисляется по формуле
d=((x_1-x_2 )^2+(y_1-y_2 )^2 )
Площадь треугольника вычисляется по формуле Герона
S =(p(p-a)(p-b)(p-c)),
где р - полупериметр, a, b и с - длины соответствующих сторон.
Используя типы данных запись с именем Punct и Triunghi, напишите программу,
которая считывает с клавиатуры информацию о n треугольниках (n<10) и выводит на экран:
 площадь каждого треугольника;
 координаты вершин треугольника, площадь которого минимальна;
*/

#include <iostream>
#include <windows.h>
#include <cmath>

using namespace std;

int main()
{
    setlocale(LC_ALL,"RUS");

    int n;
    cout<<"Введите количество треугольников: ";
    do
    {
        cin>>n;
    }
    while(n>10 or n<0);

    system("cls");

    struct PUNTC
    {
        float x1;
        float x2;
        float x3;
        float y1;
        float y2;
        float y3;
    } P[n];

    struct TRIUNGHI
    {
        float a;
        float b;
        float c;
    } T[n];

    for(int i=0; i<n; i++)
    {
        cout<<"Введите вершину (x1;y1)(через enter): "<<endl;
        cin>>P[i].x1>>P[i].y1;

        cout<<"Введите вершину (x2;y2)(через enter): "<<endl;
        cin>>P[i].x2>>P[i].y2;

        cout<<"Введите вершину (x3;y3)(через enter): "<<endl;
        cin>>P[i].x3>>P[i].y3;

        system("cls");
    }

    for(int i=0; i<n; i++)
    {
        T[i].a = sqrt(pow((P[i].x2-P[i].x1),2)+pow((P[i].y2-P[i].y1),2));
        T[i].b = sqrt(pow((P[i].x3-P[i].x2),2)+pow((P[i].y3-P[i].y2),2));
        T[i].c = sqrt(pow((P[i].x1-P[i].x3),2)+pow((P[i].y1-P[i].y3),2));
    }

    int Selection;
    int Reselection;
    bool FinishProgram = false;

    while(!FinishProgram)
    {
        cout<<"1. Площадь каждого треугольника."<<endl;
        cout<<"2. Координаты вершин треугольника, площадь которого минимальна."<<endl;
        cout<<"Ваш выбор: ";
        do
        {
            cin>>Selection;
        }
        while(Selection>2 or Selection<1);

        system("cls");

        switch(Selection)
        {
        case 1:
        {
            float p = 0;
            float S = 0;
            for(int i=0; i<n; i++)
            {
                p = (T[i].a + T[i].b + T[i].c)/2.0;
                S=sqrt(p*(p-T[i].a)*(p-T[i].b)*(p-T[i].c));

                cout<<"Треугольник №"<<i+1<<" - площадь треугольника - "<<S<<endl;
            }

            cout<<endl<<endl;
            cout<<"1.Вернуться в меню."<<endl;
            cout<<"2.Выйти из программы."<<endl;
            do
            {
                cin>>Reselection;
            }
            while(Reselection>2 or Reselection<1);

            if (Reselection==1)
                system("cls");
            if(Reselection==2)
                FinishProgram=true;
            break;
        }
        case 2:
        {
            int min = INT_MAX;
            int p = 0;
            int S = 0;
            int pmin = 0;

            for(int i=0; i<n; i++)
            {
                p = (T[i].a + T[i].b + T[i].c)/2.0;
                S=sqrt(p*(p-T[i].a)*(p-T[i].b)*(p-T[i].c));

                if(S<min)
                {
                    min = S;
                    pmin = i;
                }
            }

            cout<<"Координаты треугольника с самой маленькой площадью: "<<endl;
            cout<<"x1 = "<<P[pmin].x1<<": x2 = "<<P[pmin].x2<<" : x3 = "<<P[pmin].x3<<endl;
            cout<<"y1 = "<<P[pmin].y1<<": y2 = "<<P[pmin].y2<<" : y3 = "<<P[pmin].y3<<endl;


            cout<<endl<<endl;
            cout<<"1.Вернуться в меню."<<endl;
            cout<<"2.Выйти из программы."<<endl;
            do
            {
                cin>>Reselection;
            }
            while(Reselection>2 or Reselection<1);

            if (Reselection==1)
                system("cls");
            if(Reselection==2)
                FinishProgram=true;
            break;
        }
        }
    }


}
