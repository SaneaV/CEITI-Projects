//О группе студентов известны следующие сведения:
//-количество студентов;
//-количество экзаменов на сессии;
//-фамилия и имя каждого студента;
//-пол каждого студента;
//-дата рождения каждого студента;
//-оценки, полученные на экзаменационной сессии каждым студентом.
//Напишите программу, которая:
//• Выводит на экран список студентов-задолжников;
//• Определяет размер стипендии каждого студента по формуле
//-0 леев, если средний балл m ниже 7;
//-100 леев, если 7<= m < 8,5
//-20* m, если m <=8,5
//• Выводит на экран список студенток, которым исполнилось 20 лет

#include <iostream>
#include <windows.h>

using namespace std;

int main()
{
    setlocale(LC_ALL,"RUS");

    int Number, Exams;

    cout<<"Количество студентов: ";
    cin>>Number;
    cout<<"Количество экзаменов: ";
    cin>>Exams;

    system("cls");

    struct Student
    {
        char Name[20];
        char Surname[20];
        char Gender;
        int DayB;
        int MonthB;
        int YearB;
        int ExamsNote[50];
    } S[Number];

    char l;

    for(int i=0; i<Number; i++)
    {
        cout<<"Введите имя студента: ";
        cin>>S[i].Name;

        cout<<"Введите фамилию студента: ";
        cin>>S[i].Surname;

        cout<<"Пол студента (m или f): ";
        cin>>S[i].Gender;

        cout<<"Введите дату рожения студента(дд.мм.гггг): ";
        cin>>S[i].DayB>>l>>S[i].MonthB>>l>>S[i].YearB;

        for(int j=0; j<Exams; j++)
        {
            do
            {
                cout<<"Введите оценку за экзамен №"<<j+1<<": ";
                cin>>S[i].ExamsNote[j];
            }
            while(S[i].ExamsNote[j]>10 or S[i].ExamsNote[j]<1);
        }

        system("cls");
    }

    int Select;
    int RepeatSelect;
    bool Menu = true;

    while(Menu)
    {
        cout<<"1. Вывести на экран всех задолжников."<<endl;
        cout<<"2. Степендии студентов."<<endl;
        cout<<"3. Студенты старше 20 лет."<<endl;
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
            bool Zadoljnosti = false;
            for(int i=0; i<Number; i++)
            {
                Zadoljnosti = false;
                for(int j=0; j<Exams; j++)
                {
                    if(S[i].ExamsNote[j]<5)
                    {
                        Zadoljnosti = true;
                    }
                }
                if(Zadoljnosti)
                {
                    cout<<S[i].Name<<" "<<S[i].Surname<<endl;
                    cout<<"Пол: "<<S[i].Gender<<", дата рождения: "<<S[i].DayB<<"."<<S[i].MonthB<<"."<<S[i].YearB<<endl;
                    cout<<"Оценки: ";
                    for(int k=0; k<Exams; k++)
                    {
                        cout<<S[i].ExamsNote[k]<<" ";
                    }
                    cout<<endl<<endl;
                }
            }
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
                int m = 0;
                for(int i=0;i<Number;i++)
                {
                    m = 0;
                    for(int j=0;j<Exams;j++)
                    {
                        m+= S[i].ExamsNote[j];
                    }
                    if((m*1.0/Exams)<7) cout<<"Ученик: "<<S[i].Name<<" "<<S[i].Surname<<" не получает стипендию"<<endl;
                    if((m*1.0/Exams)>=7 and (m*1.0/Exams)<8.5) cout<<"Ученик: "<<S[i].Name<<" "<<S[i].Surname<<" получает стипеднию 100 лей"<<endl;
                    if((m*1.0/Exams)>=8.5) cout<<"Ученик: "<<S[i].Name<<" "<<S[i].Surname<<" получает стипендию в размере: "<<m*20<<" лей."<<endl;
                }

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
        case 3:
            {
                cout<<"Введите текущую дату(дд.мм.гггг): ";
                int Day,Month,Year;
                cin>>Day>>l>>Month>>l>>Year;

                int Age;
                for(int i=0;i<Number;i++)
                {
                    Age = Year - S[i].YearB;

                    if(Month<S[i].MonthB) Age--;
                    if(Month==S[i].MonthB)
                    {
                        if(S[i].DayB>Day) Age--;
                    }

                    if(Age>=20) cout<<"Студенту - "<<S[i].Name<<" "<<S[i].Surname<<" - "<<Age<<" лет"<<endl;
                }

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
