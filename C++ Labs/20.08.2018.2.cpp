//Для каждого из заданных треугольников известно:
//-обозначение(например, ABC, MNK);
//-длины сторон;
//-величины двух углов.
//Напишите программу, которая:
//• Определяет вид каждого треугольника (прямоугольный, остроугольный, тупоугольный, равнобедренный, равносторонний)
//• Находит периметр и площадь каждого треугольника.

#include <iostream>
#include <windows.h>
#include <cstring>
#include <cmath>

using namespace std;

int main()
{
    setlocale(LC_ALL,"RUS");

    int Amount;
    cout<<"Введите количество треугольников: ";
    cin>>Amount;

    system("cls");

    struct Triangle
    {
        char NameTriangle[5];
        int Lenght1;
        int Lenght2;
        int Lenght3;
        int AngleValue1;
        int AngleValue2;
    } T[Amount];

    int AngleValue3;

    for(int i=0; i<Amount; i++)
    {
        do
        {
            cout<<"Введите обозначение треугольника(ABC): ";
            cin>>T[i].NameTriangle;
            if(strlen(T[i].NameTriangle)>3 or strlen(T[i].NameTriangle)<3)
            {
                cout<<endl<<"Убедитесь, что название состоит из 3 букв"<<endl;
            }
        }
        while(strlen(T[i].NameTriangle)>3 or strlen(T[i].NameTriangle)<3);

        do
        {
            cout<<"Введите длину первой стороны: ";
            cin>>T[i].Lenght1;

            cout<<"Введите длину второй стороны: ";
            cin>>T[i].Lenght2;

            cout<<"Введите длину третьей стороны: ";
            cin>>T[i].Lenght3;

            if(T[i].Lenght1<=0 or T[i].Lenght2<=0 or T[i].Lenght3<=0 or
                    (T[i].Lenght1+T[i].Lenght2)<T[i].Lenght3 or
                    (T[i].Lenght1+T[i].Lenght3)<T[i].Lenght2 or
                    (T[i].Lenght3+T[i].Lenght2)<T[i].Lenght1)
                cout<<"Треугольник с такими сторонами невозможно построить."<<endl<<"Повторите ввод."<<endl;

        }
        while(T[i].Lenght1<=0 or T[i].Lenght2<=0 or T[i].Lenght3<=0 or
                (T[i].Lenght1+T[i].Lenght2)<T[i].Lenght3 or
                (T[i].Lenght1+T[i].Lenght3)<T[i].Lenght2 or
                (T[i].Lenght3+T[i].Lenght2)<T[i].Lenght1);

        do
        {
            cout<<"Введите величину первого угла: ";
            cin>>T[i].AngleValue1;

            cout<<"Введите величину второго угла: ";
            cin>>T[i].AngleValue2;

            AngleValue3 = 180 - T[i].AngleValue1 - T[i].AngleValue2;

            if((AngleValue3+T[i].AngleValue1+T[i].AngleValue2)<180 or (AngleValue3+T[i].AngleValue1+T[i].AngleValue2)>180
                    or AngleValue3==0 or T[i].AngleValue1==0 or T[i].AngleValue2==0)
                cout<<"Треугольник с такими углами невозможно построить."<<endl<<"Повторите ввод."<<endl;

        }
        while((AngleValue3+T[i].AngleValue1+T[i].AngleValue2)<180 or (AngleValue3+T[i].AngleValue1+T[i].AngleValue2)>180
              or AngleValue3==0 or T[i].AngleValue1==0 or T[i].AngleValue2==0);

        system("cls");
    }

    int Selection;
    int Reselection;
    bool FinishProgram = false;

    while(!FinishProgram)
    {
        cout<<"1. Определить вид каждого треугольника."<<endl;
        cout<<"2. Найти периметр и площадь каждого треугольника."<<endl;
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
            for(int i=0; i<Amount; i++)
            {
                AngleValue3 = 180 - T[i].AngleValue1 - T[i].AngleValue2;

                if(T[i].Lenght1==T[i].Lenght2 and T[i].Lenght1==T[i].Lenght3)
                    cout<<T[i].NameTriangle<<" треугольник равносторонний."<<endl;

                if((T[i].Lenght1==T[i].Lenght2 and T[i].Lenght3!=T[i].Lenght1) or
                        (T[i].Lenght1==T[i].Lenght3 and T[i].Lenght1!=T[i].Lenght2) or
                        (T[i].Lenght2==T[i].Lenght3 and T[i].Lenght1!=T[i].Lenght2))
                {
                    cout<<T[i].NameTriangle<<" треугольник равнобедренный, ";

                    if (T[i].AngleValue1==T[i].AngleValue2 and AngleValue3<90 or
                            T[i].AngleValue1==AngleValue3 and T[i].AngleValue2<90 or
                            AngleValue3==T[i].AngleValue2 and T[i].AngleValue1<90)
                        cout<<"остроугольный."<<endl;

                    if(T[i].AngleValue1>90 or T[i].AngleValue2>90 or AngleValue3>90)
                        cout<<"тупоугольный."<<endl;

                    if((T[i].AngleValue1+T[i].AngleValue2)==90 or
                            (T[i].AngleValue1+AngleValue3)==90 or
                            (T[i].AngleValue2+AngleValue3)==90)
                        cout<<"прямоугольный"<<endl;

                }

                if(T[i].Lenght1!=T[i].Lenght2 and
                        T[i].Lenght1!=T[i].Lenght3 and
                        T[i].Lenght2!=T[i].Lenght3)
                {
                    cout<<T[i].NameTriangle<<" треугольник разносторонний, ";

                    if(T[i].AngleValue1<90 and T[i].AngleValue2<90 and AngleValue3<90)
                        cout<<"остроугольный."<<endl;

                    if(T[i].AngleValue1>90 or T[i].AngleValue2>90 or AngleValue3>90)
                        cout<<"тупоугольный."<<endl;
                    if(T[i].AngleValue1==90 or T[i].AngleValue2==90 or AngleValue3==90)
                        cout<<"прямоугольный."<<endl;

                }

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
            float p;
            float S;
            for(int i=0; i<Amount; i++)
            {
                p = (T[i].Lenght1+T[i].Lenght2+T[i].Lenght3)/2.0;
                S = sqrt(p*(p-T[i].Lenght1)*(p-T[i].Lenght2)*(p-T[i].Lenght3));
                         cout<<"Периметр треугольника "<<T[i].NameTriangle<<" - "<<T[i].Lenght1+T[i].Lenght2+T[i].Lenght3<<endl;
                         cout<<"Площадь треугольника "<<T[i].NameTriangle<<" - "<<S<<endl<<endl;
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
