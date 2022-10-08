/*Для заданного списка телевизионных программ известно:
-общее количество передач;
-название каждой передачи;
-телевизионный канал, на котором запрограммирована передача;
-вид каждой передачи (художественный фильм, новости, документальный фильм, развлекательная передача, мультфильм и т.д.);
-начало каждой передачи;
-конец каждой передачи.
Напишите программу, которая выводит на экран:
• Список передач заданного телевизионного канала;
• Список художественных фильмов;
• Количество выходов в эфир новостей.*/

#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <windows.h>

using namespace std;

main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    struct TV
    {
        int Number; //Номер телепередачи
        char NameTelecast [30]; //Название телепередачи
        char NameChannel [15]; //Название телеканала
        char TypeTelecast [15]; //Жанр телепередачи
        int TimeStart; //Начало телепередачи
        int TimeFinish; //Конец телепередачи
    } InfoTV[30];


    int n; //количество передач


    cout<<"Введите количество передач: ";
    while (!(cin>>n))//Вводим значение и если это не цифра, начинается цикл (! - not)
    {
        cout<<"Ошибка, вы ввели что-то не то.\n ";
        cin.clear();//Очищает поток
        cin.sync();//Удаляет данные из буффера
        cout<<"\nВведите количество передач: ";
    }
    system("cls");

    cin.ignore();//Очищаем буфер

    for (int i=0; i<n; i++)
    {
        InfoTV[i].Number=i+1;//Порялковый номер телепередачи будет равен i++
        cout<<"Введите название телепередачи: ";
        gets(InfoTV[i].NameTelecast);
        cout<<"Введите название телеканала: ";
        gets(InfoTV[i].NameChannel);
        cout<<"Введите жанр телепередачи(фильма): ";
        gets(InfoTV[i].TypeTelecast);
        cout<<"Введите время начала телепередачи (Только часы(hh)): ";
        while (!(cin>>InfoTV[i].TimeStart) or InfoTV[i].TimeStart>=24 or InfoTV[i].TimeStart<=-1)//Вводим значение и если это не цифра, начинается цикл (! - not)
        {
            cout<<"Ошибка, вы ввели что-то не то.\n ";
            cin.clear();//Очищает поток
            cin.sync();//Удаляет данные из буффера
            cout<<"\nВведите время начала телепередачи (Только часы(hh)): ";
        }
        cout<<"Введите время конца телепередачи (Только часы (hh)): ";
        while (!(cin>>InfoTV[i].TimeFinish) or InfoTV[i].TimeFinish>=24 or InfoTV[i].TimeFinish<=-1)//Вводим значение и если это не цифра, начинается цикл (! - not)
        {
            cout<<"Ошибка, вы ввели что-то не то.\n ";
            cin.clear();//Очищает поток
            cin.sync();//Удаляет данные из буффера
            cout<<"\nВведите время конца телепередачи (Только часы (hh)): ";
        }

        system("cls");//Очищаем консоль
        cin.ignore();//Очищаем буфер
    }



    bool y=true;
    char vib1;


    do
    {
        bool x=true;
        cout<<setw(40)<<"Вы находитесь в меню."<<endl<<endl;

        cout<<"1. Просмотреть весь список программ."<<endl;
        cout<<"2. Просмотреть список передач заданного канала."<<endl;
        cout<<"3. Просмотреть список художественных телепрограмм."<<endl;
        cout<<"4. Просмотреть количество выходов новостных программ."<<endl;
        cout<<"5. Выход из программы."<<endl;

        cout<<"\n\nВведите ваш выбор: ";
        int vib;
        while (!(cin>>vib) or vib>6 or vib<1)//Вводим значение и если это не цифра, начинается цикл (! - not)
        {
            cout<<"Ошибка, вы ввели что-то не то.\n ";
            cin.clear();//Очищает поток
            cin.sync();//Удаляет данные из буффера
            cout<<"\nВведите ваш выбор: ";
        }

        system("cls");


        switch (vib)
        {
        case 1:
        {
            cout<<"1. Просмотреть весь список программ. ";
            cout<<"\n\n\n";

            cout << "№" <<setw(30)<< "Телепрограмма" <<setw(20)<< "Телеканал " <<setw(16)<<"Жанр\t" <<setw(5)<< "Начало\t" <<setw(5)<< "Конец"<< endl;
            cout << "==============================================================================================" << endl;
            for (int i=0; i<n; i++)
            {
                cout<<InfoTV[i].Number<<setw(30)<<InfoTV[i].NameTelecast<<setw(20)<<InfoTV[i].NameChannel<<setw(15)<<InfoTV[i].TypeTelecast<<setw(8)<<InfoTV[i].TimeStart<<":00"<<setw(5)<<InfoTV[i].TimeFinish<<":00"<<endl;
            }
            cout<<endl<<endl<<"Если вы хотите вернуться в меню - y/Y или д/Д";
            cout<<endl<<"Если вы хотите выйти из программы - n/N или н/Н";
            cout<<endl<<endl<<"Вы выбираете: ";

            while (x)
            {
                cin>>vib1;
                if (vib1=='y' or vib1=='n' or vib1=='Y' or vib1=='N' or vib1=='д' or vib1=='Д' or vib1=='Н' or vib1=='н')
                    x=false;
                else
                    cout<<"\n\nПовторите ввод: ";

            }
            break;
        }
        case 2:
        {
            cout<<"2. Просмотреть список передач заданного канала.";
            cout<<"\n\n\n";
            int k=0;

            cout<<"Введите название телеканала: ";
            char Channel[15];
            cin.ignore();
            gets(Channel);

            cout << "№" <<setw(30)<< "Телепрограмма" <<setw(20)<< "Телеканал " <<setw(16)<<"Жанр\t" <<setw(5)<< "Начало\t" <<setw(5)<< "Конец"<< endl;
            cout << "==============================================================================================" << endl;
            for (int i=0; i<n; i++)
            {
                if (strcmp(Channel,InfoTV[i].NameChannel)==0)
                {
                    k++;
                    cout<<InfoTV[i].Number<<setw(30)<<InfoTV[i].NameTelecast<<setw(20)<<InfoTV[i].NameChannel<<setw(15)<<InfoTV[i].TypeTelecast<<setw(8)<<InfoTV[i].TimeStart<<":00"<<setw(5)<<InfoTV[i].TimeFinish<<":00"<<endl;
                }

            }

            if (k==0)
            {
                system("cls");
                cout<<"2. Просмотреть список передач заданного канала.";
                cout<<"\n\n\n";

                cout<<"Программы передач для этого канала отсутсвуют.";
            }
            cout<<endl<<endl<<"Если вы хотите вернуться в меню - y/Y или д/Д";
            cout<<endl<<"Если вы хотите выйти из программы - n/N или н/Н";
            cout<<endl<<endl<<"Вы выбираете: ";

            while (x)
            {
                cin>>vib1;
                if (vib1=='y' or vib1=='n' or vib1=='Y' or vib1=='N' or vib1=='д' or vib1=='Д' or vib1=='Н' or vib1=='н')
                    x=false;
                else
                    cout<<"\n\nПовторите ввод: ";

            }
            break;
        }

        case 3:
        {
            {
                cout<<"3. Просмотреть список художественных телепрограмм.";
                cout<<"\n\n\n";
                int t=0;

                cout << "№" <<setw(30)<< "Телепрограмма" <<setw(20)<< "Телеканал " <<setw(16)<<"Жанр\t" <<setw(5)<< "Начало\t" <<setw(5)<< "Конец"<< endl;
                cout << "==============================================================================================" << endl;
                for (int i=0; i<n; i++)
                {
                    if (InfoTV[i].TypeTelecast[0]=='Х' or InfoTV[i].TypeTelecast[0]=='х' and InfoTV[i].TypeTelecast[1]=='у' and InfoTV[i].TypeTelecast[2]=='д')
                    {
                        t++;
                        cout<<InfoTV[i].Number<<setw(30)<<InfoTV[i].NameTelecast<<setw(20)<<InfoTV[i].NameChannel<<setw(15)<<InfoTV[i].TypeTelecast<<setw(8)<<InfoTV[i].TimeStart<<":00"<<setw(5)<<InfoTV[i].TimeFinish<<":00"<<endl;
                    }

                }

                if (t==0)
                {
                    system("cls");
                    cout<<"3. Просмотреть список художественных телепрограмм.";
                    cout<<"\n\n\n";

                    cout<<"Художественные программы отсутсвуют";
                }
                cout<<endl<<endl<<"Если вы хотите вернуться в меню - y/Y или д/Д";
                cout<<endl<<"Если вы хотите выйти из программы - n/N или н/Н";
                cout<<endl<<endl<<"Вы выбираете: ";

                while (x)
                {
                    cin>>vib1;
                    if (vib1=='y' or vib1=='n' or vib1=='Y' or vib1=='N' or vib1=='д' or vib1=='Д' or vib1=='Н' or vib1=='н')
                        x=false;
                    else
                        cout<<"\n\nПовторите ввод: ";

                }
                break;
            }
        }
        case 4:

        {
            cout<<"4. Просмотреть количество выходов новостных программ.";
            cout<<"\n\n\n";
            int c=0;

            cout<<"В поле жанр должно быть записано \"Новости\" или \"новости\""<<endl<<endl;
            char N1[15]="Новости";
            char N2[15]="новости";


            cout<<"1. Узнать только количество новостных программ."<<endl;
            cout<<"2. Узнать время и канал на котором будут новости."<<endl;
            cout<<"Введите ваш выбор: ";
            int vib3;

            while (!(cin>>vib3) or vib3>2 or vib3<1)//Вводим значение и если это не цифра, начинается цикл (! - not)
            {
                cout<<"Ошибка, вы ввели что-то не то.\n ";
                cin.clear();//Очищает поток
                cin.sync();//Удаляет данные из буффера
                cout<<"\nВведите ваш выбор: ";
            }

            if (vib3==2)
            {
                cout << "№" <<setw(30)<< "Телепрограмма" <<setw(20)<< "Телеканал " <<setw(16)<<"Жанр\t" <<setw(5)<< "Начало\t" <<setw(5)<< "Конец"<< endl;
                cout << "==============================================================================================" << endl;
            }
            for (int i=0; i<n; i++)
            {
                if (strcmp(InfoTV[i].TypeTelecast,N1)==0 or strcmp(InfoTV[i].TypeTelecast,N2)==0)
                {
                    c++;
                    if (vib3==2)
                        cout<<InfoTV[i].Number<<setw(30)<<InfoTV[i].NameTelecast<<setw(20)<<InfoTV[i].NameChannel<<setw(15)<<InfoTV[i].TypeTelecast<<setw(8)<<InfoTV[i].TimeStart<<":00"<<setw(5)<<InfoTV[i].TimeFinish<<":00"<<endl;
                }

            }
            cout<<endl<<"Количество новостных программ: "<< c;

            if (c==0)
            {
                system("cls");
                cout<<"4. Просмотреть количество выходов новостных программ.";
                cout<<"\n\n\n";

                cout<<"Новостные программы отсутсвуют";
            }
            cout<<endl<<endl<<"Если вы хотите вернуться в меню - y/Y или д/Д";
            cout<<endl<<"Если вы хотите выйти из программы - n/N или н/Н";
            cout<<endl<<endl<<"Вы выбираете: ";

            while (x)
            {
                cin>>vib1;
                if (vib1=='y' or vib1=='n' or vib1=='Y' or vib1=='N' or vib1=='д' or vib1=='Д' or vib1=='Н' or vib1=='н')
                    x=false;
                else
                    cout<<"\n\nПовторите ввод: ";

            }
            break;
        }

        case 5:
        {
            y=false;
            vib1='n';
            break;
        }
        }

        if (vib1=='y' or vib1=='Y' or vib1=='д' or vib1=='Д')
            y=true;
        else if (vib1=='n' or vib1=='N' or vib1=='Н' or vib1=='н')
            y=false;

        system("cls");

    }
    while (y);

}



