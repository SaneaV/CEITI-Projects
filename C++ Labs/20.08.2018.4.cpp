//»спользу€ тип данных запись с именем NOTE, содержащую следующие пол€:
//Х NAME Ц фамили€, им€;
//Х TELE Ц номер телефона;
//Х BDAY Ц день рождени€ (массив из трех чисел).
//Ќаписать программу, выполн€ющую следующие действи€:
//Х ввод с клавиатуры данных в массив BLOCKNOTE, состо€щий из 8 записей типа NOTE;
//Х вывод на экран †информации о человеке, номер телефона которого введен с клавиатуры;
//если такого нет, вывести соответствующее сообщение.
//Х вывод на экран †информации о человеке, чь€ фамили€ введена с клавиатуры;
//если такого нет, вывести соответствующее сообщение.
//Х вывод на экран †информации о человеке, чьи дни рождени€ приход€тс€ на мес€ц, значение которого введено с клавиатуры;
//если такого нет, вывести соответствующее сообщение.

#include <iostream>
#include <windows.h>
#include <cstring>

using namespace std;

int main()
{
    setlocale(LC_ALL,"RUS");

    struct BIRTHDAY
    {
        int Bday;
        int Bmonth;
        int Byear;
    };

    struct NOTE
    {
        char Name[20];
        char Surname[20];
        char Tele[7];
        struct BIRTHDAY BDAY[10];
    } BLOCKNOTE[8];

    char l;
    int j=0;

    for(int i=0; i<8; i++)
    {
        cout<<"¬ведите им€ и фамилию человека(через пробел): ";
        cin>>BLOCKNOTE[i].Name>>BLOCKNOTE[i].Surname;

        do
        {
            cout<<"¬ведите номер телефона человека(6 цифр): ";
            cin>>BLOCKNOTE[i].Tele;
        }
        while(strlen(BLOCKNOTE[i].Tele)>6 or strlen(BLOCKNOTE[i].Tele)<6);

        cout<<"¬ведите дату рождени€ человека(дд.мм.гггг): ";
        cin>>BLOCKNOTE[i].BDAY[i].Bday>>l>>BLOCKNOTE[i].BDAY[i].Bmonth>>l>>BLOCKNOTE[i].BDAY[i].Byear;

        system("cls");
    }

    int Selection;
    int Reselection;
    bool FinishProgram = false;

    while(!FinishProgram)
    {
        cout<<"1. »нформаци€ о человеке по телефоному номеру."<<endl;
        cout<<"2. »нформаци€ о человеке по фамилии."<<endl;
        cout<<"3.  то родилс€ в мес€ц є... ."<<endl;
        cout<<"¬аш выбор: ";
        do
        {
            cin>>Selection;
        }
        while(Selection<1 or Selection>3);

        system("cls");

        switch(Selection)
        {
        case 1:
        {
            char Tel[7];
            int k = 0;

            cout<<"¬ведите номер человека: ";
            do
            {
                cin>>Tel;
            }
            while(strlen(Tel)>6 or strlen(Tel)<6);

            for(int i=0; i<8; i++)
                if(strcmp(Tel,BLOCKNOTE[i].Tele)==0)
                {
                    cout<<BLOCKNOTE[i].Name<<" "<<BLOCKNOTE[i].Surname<<" - номер телефона - "<<BLOCKNOTE[i].Tele<<" - дата рождени€ - "<<
                        BLOCKNOTE[i].BDAY[i].Bday<<"."<<BLOCKNOTE[i].BDAY[i].Bmonth<<"."<<BLOCKNOTE[i].BDAY[i].Byear<<endl;
                    k++;
                }

            if(k==0)
                cout<<"  сожалению, человек не найден"<<endl;

            cout<<endl<<endl;
            cout<<"1.¬ернутьс€ в меню."<<endl;
            cout<<"2.¬ыйти из программы."<<endl;
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
            char Fam[20];
            int k = 0;

            cout<<"¬ведите фамилию человека: ";
            cin>>Fam;

            for(int i=0; i<8; i++)
                if(strcmp(Fam,BLOCKNOTE[i].Surname)==0)
                {
                    cout<<BLOCKNOTE[i].Name<<" "<<BLOCKNOTE[i].Surname<<" - номер телефона - "<<BLOCKNOTE[i].Tele<<" - дата рождени€ - "<<
                        BLOCKNOTE[i].BDAY[i].Bday<<"."<<BLOCKNOTE[i].BDAY[i].Bmonth<<"."<<BLOCKNOTE[i].BDAY[i].Byear<<endl;
                    k++;
                }

            if(k==0)
                cout<<"  сожалению, человек не найден"<<endl;

            cout<<endl<<endl;
            cout<<"1.¬ернутьс€ в меню."<<endl;
            cout<<"2.¬ыйти из программы."<<endl;
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
        case 3:
        {
            int Month;
            int k=0;

            cout<<"¬ведите номер мес€ца: ";
            do
            {
                cin>>Month;
            }
            while(Month>12 or Month<1);

            for(int i=0; i<8; i++)
                if(Month==BLOCKNOTE[i].BDAY[i].Bmonth)
                {
                    cout<<BLOCKNOTE[i].Name<<" "<<BLOCKNOTE[i].Surname<<" - номер телефона - "<<BLOCKNOTE[i].Tele<<" - дата рождени€ - "<<
                        BLOCKNOTE[i].BDAY[i].Bday<<"."<<BLOCKNOTE[i].BDAY[i].Bmonth<<"."<<BLOCKNOTE[i].BDAY[i].Byear<<endl;
                    k++;
                }

            if(k==0)
                cout<<"  сожалению, человек не найден"<<endl;

            cout<<endl<<endl;
            cout<<"1.¬ернутьс€ в меню."<<endl;
            cout<<"2.¬ыйти из программы."<<endl;
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
