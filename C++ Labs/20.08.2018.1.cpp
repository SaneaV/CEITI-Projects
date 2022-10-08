//Для репрезентативной выборки граждан известно:
//-количество граждан;
//-возраст каждого гражданина;
//-рост каждого гражданина;
//-вес каждого гражданина;
//-пол каждого гражданина;
//-гражданское состояние (семейный или холост).
//Напишите программу, которая определяет:
//• Сколько процентов составляют граждане моложе 20 лет;
//• Самого высокого гражданина;
//• Чему равен средний вес гражданина старше 18 лет.

#include <iostream>
#include <windows.h>
#include <stdio.h>
#include <cstring>

using namespace std;

int main()
{
    setlocale(LC_ALL,"RUS");

    int n;

    cout<<"Количество граждан для репрезентативной выборки: ";
    cin>>n;

    struct People
    {
        int Age;
        int Height;
        int Weight;
        char Gender;
        char Status;
    } P[n];

    for(int i=0; i<n; i++)
    {
        system("cls");
        cout<<"Возраст человека: ";
        cin>>P[i].Age;

        cout<<"Рост человека (см): ";
        cin>>P[i].Height;

        cout<<"Вес человека (кг): ";
        cin>>P[i].Weight;

        cout<<"Пол человека (m или f): ";
        cin>>P[i].Gender;

        cout<<"Статус человека (s - Одинокий или m - Семейный): ";
        cin>>P[i].Status;
    }

    system("cls");
    bool Repeat = true;
    int SelectRepeat;
    int Select;

    while(Repeat)
    {
        cout<<"1.Cколько процентов составляют граждане, моложе 20 лет"<<endl;
        cout<<"2.Чему равен средний вес гражданина старше 18 лет."<<endl;
        cout<<"3.Самый высокий гражданин."<<endl;
        cout<<"Ваш выбор: ";
        do
        {
            cin>>Select;
        }
        while(Select>3 or Select<1);

        system("cls");

        switch(Select)
        {
        case 1:
        {
            int k=0;

            for(int i=0; i<n; i++)
            {

                if (P[i].Age<20)
                    k++;

            }

            cout<<"Процент людей с данной характеристикой: "<<k*100.0/n<<endl;

            cout<<"1.Вернуться в меню."<<endl;
            cout<<"2.Выйти из программы."<<endl;
            do
            {
                cin>>SelectRepeat;
            }
            while(SelectRepeat>2 or SelectRepeat<1);

            if(SelectRepeat==2)
                Repeat=false;
            if (SelectRepeat==1)
                system("cls");
            break;
        }
        case 2:
        {
            int MediumWeight=0;
            int k=0;

            for(int i=0; i<n; i++)
            {
                if(P[i].Age>18)
                {
                    MediumWeight += P[i].Weight;
                    k++;
                }
            }

            cout<<"Средний вес гражданина старше 18 лет: "<<MediumWeight/k<<endl;

            cout<<"1.Вернуться в меню."<<endl;
            cout<<"2.Выйти из программы."<<endl;
            do
            {
                cin>>SelectRepeat;
            }
            while(SelectRepeat>2 or SelectRepeat<1);

            if(SelectRepeat==2)
                Repeat=false;
            if (SelectRepeat==1)
                system("cls");
            break;
        }
        case 3:
        {
            int PHeight =0;
            int Pmax;
            for(int i=0; i<n; i++)
            {
                if(P[i].Height>PHeight)
                {
                    PHeight=P[i].Height;
                    Pmax=i;
                }
            }

            cout<<"Самый высокий гражданин имеет рост: "<<P[Pmax].Height<<endl;

            cout<<"1.Вернуться в меню."<<endl;
            cout<<"2.Выйти из программы."<<endl;
            do
            {
                cin>>SelectRepeat;
            }
            while(SelectRepeat>2 or SelectRepeat<1);

            if(SelectRepeat==2)
                Repeat=false;
            if (SelectRepeat==1)
                system("cls");
            break;
        }
        }
    }


}
