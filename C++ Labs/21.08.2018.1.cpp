/*Для каждого из заданных параллелограммов известно:
-обозначение(например, ABCD, MNKP);
-размеры;
-величина одного из его углов.
Напишите программу, которая:
• Определяет вид каждого параллелограмма (произвольный, ромб, прямоугольник, квадрат)
• Находит периметр и площадь каждого параллелограмма.
*/

#include <iostream>
#include <windows.h>
#include <cstring>
#include <cmath>

using namespace std;

int main()
{
    setlocale(LC_ALL,"rus");

    cout<<"Введите количество фигур: ";
    int n;
    cin>>n;

    system("cls");

    struct Paral
    {
        char Name[5];
        int A;
        int B;
        int C;
        int D;
        int AngVal;
    } P[n];

    bool Check = false;

    for(int i=0; i<n; i++)
    {
        do
        {
            cout<<"Введите обозначение четырёхугольника(ABCD): ";
            cin>>P[i].Name;
        }
        while(strlen(P[i].Name)>4 or strlen(P[i].Name)<4);

        do
        {
            cout<<"Введите первую сторону четырёхугольника: ";
            cin>>P[i].A;

            cout<<"Введите вторую сторону четырёхугольника: ";
            cin>>P[i].B;

            cout<<"Введите третью сторону четырёхугольника: ";
            cin>>P[i].C;

            cout<<"Введите четвёрту сторону четырёхугольника: ";
            cin>>P[i].D;

            if(P[i].A > P[i].B + P[i].C + P[i].D or
                    P[i].B > P[i].A + P[i].C + P[i].D or
                    P[i].C > P[i].B + P[i].A + P[i].D or
                    P[i].D > P[i].B + P[i].C + P[i].A)
                cout<<"Одна из сторон больше суммы всех остальных. Повторите ввод."<<endl;

        }
        while(P[i].A > P[i].B + P[i].C + P[i].D or
                P[i].B > P[i].A + P[i].C + P[i].D or
                P[i].C > P[i].B + P[i].A + P[i].D or
                P[i].D > P[i].B + P[i].C + P[i].A);

        do
        {
            Check = false;
            cout<<"Введите величину угла: ";
            cin>>P[i].AngVal;
        }
        while(P[i].AngVal<1 or P[i].AngVal>180);

        system("cls");

    }

    int Selection;
    int Reselection;
    bool FinishProgram = false;


    while(!FinishProgram)
    {
        cout<<"1.Определить вид каждой фигуры."<<endl;
        cout<<"2.Найти периметр и площадь каждой фигуры."<<endl;
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
            for(int i=0; i<n; i++)
            {
                if((P[i].A == P[i].B and P[i].D == P[i].C and P[i].C!=P[i].A and P[i].AngVal==90) or
                        (P[i].A == P[i].D and P[i].B == P[i].C and P[i].C!=P[i].A and P[i].AngVal==90) or
                        (P[i].A == P[i].C and P[i].B == P[i].D and P[i].B!=P[i].A and P[i].AngVal==90))
                    cout<<P[i].Name<<" - "<<"прямоугольник"<<endl;

                else if((P[i].A == P[i].B and P[i].D == P[i].C and P[i].C!=P[i].A and P[i].AngVal!=90) or
                        (P[i].A == P[i].D and P[i].B == P[i].C and P[i].C!=P[i].A and P[i].AngVal!=90) or
                        (P[i].A == P[i].C and P[i].B == P[i].D and P[i].B!=P[i].A and P[i].AngVal!=90))
                    cout<<P[i].Name<<" - "<<"параллелограмм"<<endl;

                else if((P[i].A == P[i].B and P[i].D == P[i].C and P[i].A==P[i].D and P[i].AngVal!=90) or
                        (P[i].A == P[i].D and P[i].B == P[i].C and P[i].C==P[i].A and P[i].AngVal!=90) or
                        (P[i].A == P[i].C and P[i].B == P[i].D and P[i].B==P[i].A and P[i].AngVal!=90))
                    cout<<P[i].Name<<" - "<<"ромб"<<endl;

                else if((P[i].A == P[i].B and P[i].D == P[i].C and P[i].A==P[i].D and P[i].AngVal==90) or
                        (P[i].A == P[i].D and P[i].B == P[i].C and P[i].C==P[i].A and P[i].AngVal==90) or
                        (P[i].A == P[i].C and P[i].B == P[i].D and P[i].B==P[i].A and P[i].AngVal==90))
                    cout<<P[i].Name<<" - "<<"квадрат"<<endl;

                else
                    cout<<P[i].Name<<" - "<<"произвольный четырёхугольник"<<endl;
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
            for(int i=0; i<n; i++)
            {
                if((P[i].A == P[i].B and P[i].D == P[i].C and P[i].A==P[i].D and P[i].AngVal==90) or
                        (P[i].A == P[i].D and P[i].B == P[i].C and P[i].C==P[i].A and P[i].AngVal==90) or
                        (P[i].A == P[i].C and P[i].B == P[i].D and P[i].B==P[i].A and P[i].AngVal==90))
                    cout<<P[i].Name<<" - "<<"квадрат"<<" -  периметр - "<<4*P[i].A<<" - площадь - "<<2*P[i].A<<endl;

                if(P[i].A == P[i].B and P[i].D == P[i].C and P[i].C!=P[i].A and P[i].AngVal==90)
                    cout<<P[i].Name<<" - "<<"прямоугольник"<<" -  периметр - "<<2*(P[i].A+P[i].D)<<" - площадь - "<<P[i].A*P[i].D<<endl;
                else if ((P[i].A == P[i].D and P[i].B == P[i].C and P[i].C!=P[i].A and P[i].AngVal==90) or
                         (P[i].A == P[i].C and P[i].B == P[i].D and P[i].B!=P[i].A and P[i].AngVal==90))
                    cout<<P[i].Name<<" - "<<"прямоугольник"<<" -  периметр - "<<2*(P[i].A+P[i].B)<<" - площадь - "<<P[i].A*P[i].B<<endl;


                if(P[i].A == P[i].B and P[i].D == P[i].C and P[i].C!=P[i].A and P[i].AngVal!=90)
                    cout<<P[i].Name<<" - "<<"параллелограмм"<<" -  периметр - "<<2*(P[i].A+P[i].D)<<" - площадь - "<<P[i].A*P[i].D*sin(P[i].AngVal)<<endl;
                else if((P[i].A == P[i].D and P[i].B == P[i].C and P[i].C!=P[i].A and P[i].AngVal!=90) or
                        (P[i].A == P[i].C and P[i].B == P[i].D and P[i].B!=P[i].A and P[i].AngVal!=90))
                    cout<<P[i].Name<<" - "<<"параллелограмм"<<" -  периметр - "<<2*(P[i].A+P[i].B)<<" - площадь - "<<P[i].A*P[i].B*sin(P[i].AngVal)<<endl;


                if((P[i].A == P[i].B and P[i].D == P[i].C and P[i].A==P[i].D and P[i].AngVal!=90) or
                        (P[i].A == P[i].D and P[i].B == P[i].C and P[i].C==P[i].A and P[i].AngVal!=90) or
                        (P[i].A == P[i].C and P[i].B == P[i].D and P[i].B==P[i].A and P[i].AngVal!=90))
                    cout<<P[i].Name<<" - "<<"ромб"<<" -  периметр - "<<4*P[i].A<<" - площадь - "<<pow(P[i].A,2)*sin(P[i].AngVal)<<endl;
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
        }



    }
}
