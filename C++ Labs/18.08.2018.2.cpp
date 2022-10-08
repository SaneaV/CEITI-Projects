//»спользу€ тип данных запись с именем STUDENT, содержащую следующие пол€:
//Х NAME Ц фамили€ и инициалы;
//Х GROUP Ц номер группы;
//Х SES Ц успеваемость (массив из 5 элементов).
//Ќаписать программу, выполн€ющую следующие действи€:
//Х ввод с клавиатуры данных в массив STUD1, состо€щий из 10 записей типа STUDENT;
//Х вывод на экран †фамилий и номеров групп дл€ всех студентов, включенных в массив, если средний балл студента больше 5.0;
//если таких студентов нет, вывести соответствующее сообщение.
//Х вывод на экран †фамилий и номеров групп дл€ всех студентов, имеющих оценки 9 и 10;если таких студентов нет, вывести соответствующее сообщение

#include <iostream>
#include <windows.h>
#include <stdio.h>

using namespace std;

int main()
{
    setlocale(LC_ALL,"RUS");

    struct Student
    {
        char Name[30];
        int Group;
        int Ses[5];
    } STUD1[9];

    int j;

    for(int i=0; i<10; i++)
    {
        cout<<"¬ведите им€ ученика и его инициалы (‘амили€».ќ.): ";
        cin>>STUD1[i].Name;

        cout<<"¬ведите номер группы ученика(только цифры): ";
        cin>>STUD1[i].Group;

        j = 0;
        do{
        cout<<"¬ведите оценку ученика по математике: ";
        cin>>STUD1[i].Ses[j];
        }while(STUD1[i].Ses[j]>10 or STUD1[i].Ses[j]<1);


        j++;
        do{
        cout<<"¬ведите оценку ученика по румынскому €зыку: ";
        cin>>STUD1[i].Ses[j];
        }while(STUD1[i].Ses[j]>10 or STUD1[i].Ses[j]<1);


        j++;
        do{
        cout<<"¬ведите оценку ученика по русскому €зыку: ";
        cin>>STUD1[i].Ses[j];
        }while(STUD1[i].Ses[j]>10 or STUD1[i].Ses[j]<1);

        j++;
        do{
        cout<<"¬ведите оценку ученика по английскому €зыку: ";
        cin>>STUD1[i].Ses[j];
        }while(STUD1[i].Ses[j]>10 or STUD1[i].Ses[j]<1);

        j++;
        do{
        cout<<"¬ведите оценку ученика по инфоматике: ";
        cin>>STUD1[i].Ses[j];
        }while(STUD1[i].Ses[j]>10 or STUD1[i].Ses[j]<1);

        system("cls");
    }

    int Select;
    int RepeatSelect;
    bool Menu = true;

    while(Menu)
    {
        cout<<"1. ¬ывести на экран учеников со средним баллом выше 5.0"<<endl;
        cout<<"2. ¬ывести на экран учеников, имеющих оценку 9 или 10"<<endl;
        cout<<"¬аш выбор: ";
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
            float MediumNote = 0;

            for(int i=0; i<10; i++)
            {
                MediumNote = 0;
                for(int j=0; j<5; j++)
                {
                    MediumNote+=STUD1[i].Ses[j];
                }
                if ((MediumNote/5*1.0)>=5)
                    cout<<(STUD1[i].Name)<<" из группы є"<<STUD1[i].Group<<" со средним баллом: "<<MediumNote/5*1.0<<endl;
            }

            cout<<endl<<endl;
            cout<<"1. ¬ернутьс€ в меню."<<endl;
            cout<<"2. ¬ыйти из программы."<<endl;
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
            bool NineOrTen = false;
            for(int i=0; i<10; i++)
            {
                NineOrTen = false;
                for(int j=0; j<5; j++)
                {
                    if(STUD1[i].Ses[j]>=9)
                    {
                        NineOrTen = true;
                        break;
                    }
                }

                if (NineOrTen)
                    cout<<STUD1[i].Name<<" из группы є"<<STUD1[i].Group<<" имеет оценки: "<<STUD1[i].Ses[0]<<" "<<STUD1[i].Ses[1]<<" "<<STUD1[i].Ses[2]<<" "<<STUD1[i].Ses[3]<<" "<<STUD1[i].Ses[4]<<endl;
            }

            cout<<endl<<endl;
            cout<<"1. ¬ернутьс€ в меню."<<endl;
            cout<<"2. ¬ыйти из программы."<<endl;
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
