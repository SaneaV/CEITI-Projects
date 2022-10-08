//Для репрезентативной выборки граждан известно:
//-количество граждан;
//-возраст каждого гражданина;
//-рост каждого гражданина;
//-вес каждого гражданина;
//-пол каждого гражданина;
//-гражданское состояние (семейный или холост).
//Напишите программу, которая определяет:
//• Сколько процентов от количества лиц мужского пола составляют неженатые, старшие 25 лет юноши;
//• Сколько процентов от количества граждан в возрасте от 30 до 40 лет составляют граждане, вес которых меньше среднего веса.

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
    int AllWeight = 0;

    for(int i=0; i<n; i++)
    {
        system("cls");
        cout<<"Возраст человека: ";
        cin>>P[i].Age;

        cout<<"Рост человека (см): ";
        cin>>P[i].Height;

        cout<<"Вес человека (кг): ";
        cin>>P[i].Weight;
        AllWeight += P[i].Weight;

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
        cout<<"1.Cколько процентов от количества лиц мужского пола составляют неженатые, старшие 25 лет девушки"<<endl;
        cout<<"2.Сколько процентов от количества граждан в возрасте от 30 до 40 лет составляют граждане, вес которых меньше среднего веса."<<endl;
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
            int k=0;

            for(int i=0; i<n; i++)
            {
                if(P[i].Status=='s')
                {
                    if(P[i].Gender=='m')
                    {
                        if (P[i].Age>25)
                            k++;
                    }
                }
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
            int k=0;
            int MediumWeight = AllWeight / (n-1);
            for(int i=0; i<n; i++)
            {
                if(P[i].Age>30 and P[i].Age<40)
                {
                    if(P[i].Weight<MediumWeight)
                        k++;
                }
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
        }
    }


}
