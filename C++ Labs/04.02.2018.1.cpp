#include <ctime>
#include <iostream>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>
#include <iomanip>
#include <stdio.h>


using namespace std;

main()
{
    srand(time(0));
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout<<setw(40)<<"Александр P1713"<<endl;
    Sleep(1000);
    system("cls");

    cout<<fixed<<setw(40)<<"Ваши предложения на почту: SaneaVicev@mail.ru"<<endl;
    Sleep(2000);
    system("cls");

    cout<<"Выбери себе никнейм: ";
    char nik[20];

    gets(nik);
    Sleep(500);



    system ("cls");

    cout<<setw(50)<<nik<<", добро пожаловать в 99 games in 1"<<endl;

    cout<<"\nНа данный момент вы можете поиграть в: ";
    cout<<"\n\n1. Виселица.";
    cout<<"\n2. Поле Чудес.";
    cout<<"\n\nВо что будете играть: ";

    int vib;

    while (!(cin>>vib))//Вводим значение и если это не цифра, начинается цикл (! - not)
    {
        cout<<"Ошибка, вы ввели что-то не то. ";
        cin.clear();//Очищает поток
        cin.sync();//Удаляет данные из буффера
        cout<<"\nВо что будете играть: ";
    }

    switch (vib)
    {
    case 1:
    {
        char Slova[1000]= {"смех, любовь, дружба, семечки, водоворот, телефон, смартфон, кит, морж, дождь, экскаватор, арифметика, реальность, правда, честность, доверие, музыка, чистота, свежесть, река, море, океан, остров, суша, восток, север, запад, юг, крем, клавиатура, монитор, учёба, математика, программирование, доброта, клавиши, обшага, суматоха, детство, дедушка, бабушка, морфема, косинус, синус, параметр, дорога, путь, единорог, сплочённость, коллектив, фейхуа, апельсин, мандарин, яблоко, год, месяц, зима, весна, висилица, александр"};
        char Razdel[5]=", ";

        char *pch=strtok(Slova,Razdel);

        int randomvisel= (rand() % 28);

        char slovovisel[30];
        int k;

        while (pch!=NULL)
        {
            if (k==randomvisel) strcpy(slovovisel,pch);
            pch=strtok(NULL,Razdel);
            k++;
        }

        system("cls");
        cout<<setw(40)<<"Виселица"<<endl;
        cout<<"1. С друзьями (4 человека)";
        cout<<"\n2. С другом. (2 человека)";
        cout<<"\n3. C ботами. (1 человек)";
        cout<<"\n4. С ботом. (1 человек)";

        cout<<"\n\nТы будешь играть: ";

        int ViselitaVib;

        while (!(cin>>ViselitaVib))//Вводим значение и если это не цифра, начинается цикл (! - not)
        {
            cout<<"Ошибка, вы ввели что-то не то. ";
            cin.clear();//Очищает поток
            cin.sync();//Удаляет данные из буффера
            cout<<"\nC кем ты будешь играть?: ";
        }
        system("cls");

        switch (ViselitaVib)
        {
        case 1:
        {
            cout<<"В эту игру максимум могут играть только 4 человека.";
            cout<<endl<<nik<<", мы уже знакомы, а как зовут других игроков?";
            cout<<endl<<endl<<"Игрок номер 1 - "<< nik;
            cout<<endl<<endl<<"Игрок номер 2 - ";
            char nik2[20];
            cin>>nik2;
            cout<<endl<<"Игрок номер 3 - ";
            char nik3[20];
            cin>>nik3;
            cout<<endl<<"Игрок номер 4 - ";
            char nik4[20];
            cin>>nik4;

            system("cls");

            int dlinaslova = strlen(slovovisel);
            int schetchik=0;
            char bukva;
            int bukva2=0;
            char vivodslova[30];
            bool y=false;

            for (int i=0; i<dlinaslova; i++)
            {
                vivodslova[i]='.';
                vivodslova[dlinaslova]=NULL;
            }

            int shag=0, ugadal=1;
            int pobeda = 1;

            int score1=0,score2=0,score3=0,score4=0;
            int live1=10,live2=10,live3=10,live4=10;


            char x[40];
            int proverka=0;
            int proverkahoda=-1;

            while (schetchik!=999)
            {

                y=false;
                cout<<setw(40)<<"Виселица!";
                cout<<endl<<endl;
                shag=0, ugadal=1;
                proverkahoda++;
                while (ugadal>shag and schetchik!=999 and live1!=0)
                {
                    schetchik=0, bukva2=0;
                    ++shag;
                    puts(vivodslova);
                    cout<<endl<<endl;
                    cout<<endl<<"\nБукву говорит "<<nik<<": ";
                    cin>>bukva;
                    for (int i=proverkahoda; i<=proverkahoda; i++)
                    {
                        x[proverkahoda]=bukva;
                    }
                    cout<<endl<<endl<<"Ваш счёт: "<<score1<<endl;

                    for (int i=0; i<dlinaslova; i++)
                    {
                        if (slovovisel[i]==bukva)
                        {
                            y=true;
                            score1+=10;
                            schetchik++;
                            ugadal++;
                            for (int pobeda=0,j=0; j<dlinaslova; j++)
                            {
                                if (slovovisel[j]==bukva and vivodslova[j]=='.') vivodslova[j]=slovovisel[i];
                                if (vivodslova[j]!='.') pobeda++;
                                if (pobeda==dlinaslova)
                                {
                                    schetchik=999;
                                    ugadal--;
                                }
                                while (shag>=0 or ugadal>=1)
                                {
                                    if (shag>=0) shag--;
                                    if (ugadal>=1) ugadal--;
                                }
                            }
                        }
                    }

                    if (schetchik==bukva2)
                    {
                        cout<<endl<<"Игрок не угадал букву. ";
                        cout<<endl<<"Количество ваших жизней: "<<live1--<<endl;
                        if (live1==0) cout<<endl<<"Вы проиграли."<<endl;
                        if (live1==9) cout<<"\n\n\n\n\n__()__";
                        if (live1==8)
                        {
                            cout<<"  ()"<<endl;
                            cout<<"  ()"<<endl;
                            cout<<"  ()"<<endl;
                            cout<<"__()__";
                        }
                        if (live1==7)
                        {
                            cout<<"  >>>>>>>"<<endl;
                            cout<<"  ()"<<endl;
                            cout<<"  ()"<<endl;
                            cout<<"  ()"<<endl;
                            cout<<"__()__";
                        }
                        if (live1==6)
                        {
                            cout<<"  >>>>>>>"<<endl;
                            cout<<"  ()    |"<<endl;
                            cout<<"  ()"<<endl;
                            cout<<"  ()"<<endl;
                            cout<<"__()__";
                        }
                        if (live1==5)
                        {
                            cout<<"  >>>>>>>"<<endl;
                            cout<<"  ()    |"<<endl;
                            cout<<"  ()    o"<<endl;
                            cout<<"  ()"<<endl;
                            cout<<"__()__";
                        }
                        if (live1==4)
                        {
                            cout<<"  >>>>>>>"<<endl;
                            cout<<"  ()    |"<<endl;
                            cout<<"  ()    o"<<endl;
                            cout<<"  ()    |"<<endl;
                            cout<<"__()__";
                        }
                        if (live1==3)
                        {
                            cout<<"  >>>>>>>"<<endl;
                            cout<<"  ()    |"<<endl;
                            cout<<"  ()    o"<<endl;
                            cout<<"  ()   /|"<<endl;
                            cout<<"__()__ ";
                        }
                        if (live1==2)
                        {
                            cout<<"  >>>>>>>"<<endl;
                            cout<<"  ()    |"<<endl;
                            cout<<"  ()    o"<<endl;
                            cout<<"  ()   /|"<<endl;
                            cout<<"__()__ / ";
                        }
                        if (live1==1)
                        {
                            cout<<"  >>>>>>>"<<endl;
                            cout<<"  ()    |"<<endl;
                            cout<<"  ()    o"<<endl;
                            cout<<"  ()   /|"<<endl;
                            cout<<"__()__ / \\";
                        }
                        if (live1==0)
                        {
                            cout<<"  >>>>>>>"<<endl;
                            cout<<"  ()    |"<<endl;
                            cout<<"  ()    o"<<endl;
                            cout<<"  ()   /|\\"<<endl;
                            cout<<"__()__ / \\";
                        }
                    }
                    else
                    {
                        proverka=0;
                        for (int i=0; i<dlinaslova; i++)
                        {
                            if (slovovisel[i]==bukva) proverka++;
                            if (proverka>=1) bukva2++;
                        }
                        cout<<endl<<"Игрок угадал букву!"<<endl<<endl;

                    }

                    cout<<endl<<endl<<"Буквы, которые уже называли: ";
                    for (int i=0; i<=proverkahoda; i++)
                    {
                        cout<<x[i]<<" ";
                    }
                    cout<<endl<<endl;
                    Sleep(3000);
                    if (schetchik!=0 or y) cout<<"##########################################################################################"<<endl<<endl;
                }
                if (live1!=0) system("cls");


                y=false;
                cout<<setw(40)<<"Виселица!";
                cout<<endl<<endl;
                shag=0, ugadal=1;
                proverkahoda++;
                while (ugadal>shag and schetchik!=999 and live2!=0)
                {
                    schetchik=0, bukva2=0;
                    ++shag;
                    puts(vivodslova);
                    cout<<endl<<endl;
                    cout<<endl<<"\nБукву говорит "<<nik2<<": ";
                    cin>>bukva;
                    for (int i=proverkahoda; i<=proverkahoda; i++)
                    {
                        x[proverkahoda]=bukva;
                    }
                    cout<<endl<<endl<<"Ваш счёт: "<<score2<<endl;

                    for (int i=0; i<dlinaslova; i++)
                    {
                        if (slovovisel[i]==bukva)
                        {
                            y=true;
                            score2+=10;
                            schetchik++;
                            ugadal++;
                            for (int pobeda=0,j=0; j<dlinaslova; j++)
                            {
                                if (slovovisel[j]==bukva and vivodslova[j]=='.') vivodslova[j]=slovovisel[i];
                                if (vivodslova[j]!='.') pobeda++;
                                if (pobeda==dlinaslova)
                                {
                                    schetchik=999;
                                    ugadal--;
                                }
                                while (shag>=0 or ugadal>=1)
                                {
                                    if (shag>=0) shag--;
                                    if (ugadal>=1) ugadal--;
                                }
                            }
                        }
                    }

                    if (schetchik==bukva2)
                    {
                        cout<<endl<<"Игрок не угадал букву. ";
                        cout<<endl<<"Количество ваших жизней: "<<live2--<<endl;
                        if (live2==0) cout<<endl<<"Вы проиграли."<<endl;
                        if (live2==9) cout<<"\n\n\n\n\n__()__";
                        if (live2==8)
                        {
                            cout<<"  ()"<<endl;
                            cout<<"  ()"<<endl;
                            cout<<"  ()"<<endl;
                            cout<<"__()__";
                        }
                        if (live2==7)
                        {
                            cout<<"  >>>>>>>"<<endl;
                            cout<<"  ()"<<endl;
                            cout<<"  ()"<<endl;
                            cout<<"  ()"<<endl;
                            cout<<"__()__";
                        }
                        if (live2==6)
                        {
                            cout<<"  >>>>>>>"<<endl;
                            cout<<"  ()    |"<<endl;
                            cout<<"  ()"<<endl;
                            cout<<"  ()"<<endl;
                            cout<<"__()__";
                        }
                        if (live2==5)
                        {
                            cout<<"  >>>>>>>"<<endl;
                            cout<<"  ()    |"<<endl;
                            cout<<"  ()    o"<<endl;
                            cout<<"  ()"<<endl;
                            cout<<"__()__";
                        }
                        if (live2==4)
                        {
                            cout<<"  >>>>>>>"<<endl;
                            cout<<"  ()    |"<<endl;
                            cout<<"  ()    o"<<endl;
                            cout<<"  ()    |"<<endl;
                            cout<<"__()__";
                        }
                        if (live2==3)
                        {
                            cout<<"  >>>>>>>"<<endl;
                            cout<<"  ()    |"<<endl;
                            cout<<"  ()    o"<<endl;
                            cout<<"  ()   /|"<<endl;
                            cout<<"__()__ ";
                        }
                        if (live2==2)
                        {
                            cout<<"  >>>>>>>"<<endl;
                            cout<<"  ()    |"<<endl;
                            cout<<"  ()    o"<<endl;
                            cout<<"  ()   /|"<<endl;
                            cout<<"__()__ / ";
                        }
                        if (live2==1)
                        {
                            cout<<"  >>>>>>>"<<endl;
                            cout<<"  ()    |"<<endl;
                            cout<<"  ()    o"<<endl;
                            cout<<"  ()   /|"<<endl;
                            cout<<"__()__ / \\";
                        }
                        if (live2==0)
                        {
                            cout<<"  >>>>>>>"<<endl;
                            cout<<"  ()    |"<<endl;
                            cout<<"  ()    o"<<endl;
                            cout<<"  ()   /|\\"<<endl;
                            cout<<"__()__ / \\";
                        }
                    }
                    else
                    {
                        proverka=0;
                        for (int i=0; i<dlinaslova; i++)
                        {
                            if (slovovisel[i]==bukva) proverka++;
                            if (proverka>=1) bukva2++;
                        }
                        cout<<endl<<"Игрок угадал букву!"<<endl<<endl;
                    }
                    cout<<endl<<endl<<"Буквы, которые уже называли: ";
                    for (int i=0; i<=proverkahoda; i++)
                    {
                        cout<<x[i]<<" ";
                    }
                    cout<<endl<<endl;
                    Sleep(3000);
                    if (schetchik!=0 or y) cout<<"##########################################################################################"<<endl<<endl;
                }
                if (live2!=0) system("cls");




                y=false;
                cout<<setw(40)<<"Виселица!";
                cout<<endl<<endl;
                shag=0, ugadal=1;
                proverkahoda++;
                while (ugadal>shag and schetchik!=999 and live3!=0)
                {
                    schetchik=0, bukva2=0;
                    ++shag;
                    puts(vivodslova);
                    cout<<endl<<endl;
                    cout<<endl<<"\nБукву говорит "<<nik3<<": ";
                    cin>>bukva;
                    for (int i=proverkahoda; i<=proverkahoda; i++)
                    {
                        x[proverkahoda]=bukva;
                    }
                    cout<<endl<<endl<<"Ваш счёт: "<<score3<<endl;

                    for (int i=0; i<dlinaslova; i++)
                    {
                        if (slovovisel[i]==bukva)
                        {
                            y=true;
                            score3+=10;
                            schetchik++;
                            ugadal++;
                            for (int pobeda=0,j=0; j<dlinaslova; j++)
                            {
                                if (slovovisel[j]==bukva and vivodslova[j]=='.') vivodslova[j]=slovovisel[i];
                                if (vivodslova[j]!='.') pobeda++;
                                if (pobeda==dlinaslova)
                                {
                                    schetchik=999;
                                    ugadal--;
                                }
                                while (shag>=0 or ugadal>=1)
                                {
                                    if (shag>=0) shag--;
                                    if (ugadal>=1) ugadal--;
                                }
                            }
                        }
                    }

                    if (schetchik==bukva2)
                    {
                        cout<<endl<<"Игрок не угадал букву. ";
                        cout<<endl<<"Количество ваших жизней: "<<live3--<<endl;
                        if (live3==0) cout<<endl<<"Вы проиграли."<<endl;
                        if (live3==9) cout<<"\n\n\n\n\n__()__";
                        if (live3==8)
                        {
                            cout<<"  ()"<<endl;
                            cout<<"  ()"<<endl;
                            cout<<"  ()"<<endl;
                            cout<<"__()__";
                        }
                        if (live3==7)
                        {
                            cout<<"  >>>>>>>"<<endl;
                            cout<<"  ()"<<endl;
                            cout<<"  ()"<<endl;
                            cout<<"  ()"<<endl;
                            cout<<"__()__";
                        }
                        if (live3==6)
                        {
                            cout<<"  >>>>>>>"<<endl;
                            cout<<"  ()    |"<<endl;
                            cout<<"  ()"<<endl;
                            cout<<"  ()"<<endl;
                            cout<<"__()__";
                        }
                        if (live3==5)
                        {
                            cout<<"  >>>>>>>"<<endl;
                            cout<<"  ()    |"<<endl;
                            cout<<"  ()    o"<<endl;
                            cout<<"  ()"<<endl;
                            cout<<"__()__";
                        }
                        if (live3==4)
                        {
                            cout<<"  >>>>>>>"<<endl;
                            cout<<"  ()    |"<<endl;
                            cout<<"  ()    o"<<endl;
                            cout<<"  ()    |"<<endl;
                            cout<<"__()__";
                        }
                        if (live3==3)
                        {
                            cout<<"  >>>>>>>"<<endl;
                            cout<<"  ()    |"<<endl;
                            cout<<"  ()    o"<<endl;
                            cout<<"  ()   /|"<<endl;
                            cout<<"__()__ ";
                        }
                        if (live3==2)
                        {
                            cout<<"  >>>>>>>"<<endl;
                            cout<<"  ()    |"<<endl;
                            cout<<"  ()    o"<<endl;
                            cout<<"  ()   /|"<<endl;
                            cout<<"__()__ / ";
                        }
                        if (live3==1)
                        {
                            cout<<"  >>>>>>>"<<endl;
                            cout<<"  ()    |"<<endl;
                            cout<<"  ()    o"<<endl;
                            cout<<"  ()   /|"<<endl;
                            cout<<"__()__ / \\";
                        }
                        if (live3==0)
                        {
                            cout<<"  >>>>>>>"<<endl;
                            cout<<"  ()    |"<<endl;
                            cout<<"  ()    o"<<endl;
                            cout<<"  ()   /|\\"<<endl;
                            cout<<"__()__ / \\";
                        }
                    }
                    else
                    {
                        proverka=0;
                        for (int i=0; i<dlinaslova; i++)
                        {
                            if (slovovisel[i]==bukva) proverka++;
                            if (proverka>=1) bukva2++;
                        }
                        cout<<endl<<"Игрок угадал букву!"<<endl<<endl;
                    }
                    cout<<endl<<endl<<"Буквы, которые уже называли: ";
                    for (int i=0; i<=proverkahoda; i++)
                    {
                        cout<<x[i]<<" ";
                    }
                    cout<<endl<<endl;
                    Sleep(3000);
                    if (schetchik!=0 or y) cout<<"##########################################################################################"<<endl<<endl;
                }
                if (live3!=0) system("cls");




                y=false;
                cout<<setw(40)<<"Виселица!";
                cout<<endl<<endl;
                shag=0, ugadal=1;
                proverkahoda++;
                while (ugadal>shag and schetchik!=999 and live4!=0)
                {
                    schetchik=0, bukva2=0;
                    ++shag;
                    puts(vivodslova);
                    cout<<endl<<endl;
                    cout<<endl<<"\nБукву говорит "<<nik4<<": ";
                    cin>>bukva;
                    for (int i=proverkahoda; i<=proverkahoda; i++)
                    {
                        x[proverkahoda]=bukva;
                    }
                    cout<<endl<<endl<<"Ваш счёт: "<<score4<<endl;

                    for (int i=0; i<dlinaslova; i++)
                    {
                        if (slovovisel[i]==bukva)
                        {
                            y=true;
                            score4+=10;
                            schetchik++;
                            ugadal++;
                            for (int pobeda=0,j=0; j<dlinaslova; j++)
                            {
                                if (slovovisel[j]==bukva and vivodslova[j]=='.') vivodslova[j]=slovovisel[i];
                                if (vivodslova[j]!='.') pobeda++;
                                if (pobeda==dlinaslova)
                                {
                                    schetchik=999;
                                    ugadal--;
                                }
                                while (shag>=0 or ugadal>=1)
                                {
                                    if (shag>=0) shag--;
                                    if (ugadal>=1) ugadal--;
                                }
                            }
                        }
                    }

                    if (schetchik==bukva2)
                    {
                        cout<<endl<<"Игрок не угадал букву. ";
                        cout<<endl<<"Количество ваших жизней: "<<live4--<<endl;
                        if (live4==0) cout<<endl<<"Вы проиграли."<<endl;
                        if (live4==9) cout<<"\n\n\n\n\n__()__";
                        if (live4==8)
                        {
                            cout<<"  ()"<<endl;
                            cout<<"  ()"<<endl;
                            cout<<"  ()"<<endl;
                            cout<<"__()__";
                        }
                        if (live4==7)
                        {
                            cout<<"  >>>>>>>"<<endl;
                            cout<<"  ()"<<endl;
                            cout<<"  ()"<<endl;
                            cout<<"  ()"<<endl;
                            cout<<"__()__";
                        }
                        if (live4==6)
                        {
                            cout<<"  >>>>>>>"<<endl;
                            cout<<"  ()    |"<<endl;
                            cout<<"  ()"<<endl;
                            cout<<"  ()"<<endl;
                            cout<<"__()__";
                        }
                        if (live4==5)
                        {
                            cout<<"  >>>>>>>"<<endl;
                            cout<<"  ()    |"<<endl;
                            cout<<"  ()    o"<<endl;
                            cout<<"  ()"<<endl;
                            cout<<"__()__";
                        }
                        if (live4==4)
                        {
                            cout<<"  >>>>>>>"<<endl;
                            cout<<"  ()    |"<<endl;
                            cout<<"  ()    o"<<endl;
                            cout<<"  ()    |"<<endl;
                            cout<<"__()__";
                        }
                        if (live4==3)
                        {
                            cout<<"  >>>>>>>"<<endl;
                            cout<<"  ()    |"<<endl;
                            cout<<"  ()    o"<<endl;
                            cout<<"  ()   /|"<<endl;
                            cout<<"__()__ ";
                        }
                        if (live4==2)
                        {
                            cout<<"  >>>>>>>"<<endl;
                            cout<<"  ()    |"<<endl;
                            cout<<"  ()    o"<<endl;
                            cout<<"  ()   /|"<<endl;
                            cout<<"__()__ / ";
                        }
                        if (live4==1)
                        {
                            cout<<"  >>>>>>>"<<endl;
                            cout<<"  ()    |"<<endl;
                            cout<<"  ()    o"<<endl;
                            cout<<"  ()   /|"<<endl;
                            cout<<"__()__ / \\";
                        }
                        if (live4==0)
                        {
                            cout<<"  >>>>>>>"<<endl;
                            cout<<"  ()    |"<<endl;
                            cout<<"  ()    o"<<endl;
                            cout<<"  ()   /|\\"<<endl;
                            cout<<"__()__ / \\";
                        }
                    }
                    else
                    {
                        proverka=0;
                        for (int i=0; i<dlinaslova; i++)
                        {
                            if (slovovisel[i]==bukva) proverka++;
                        }
                        if (proverka>=1) bukva2++;
                        cout<<endl<<"Игрок угадал букву!"<<endl<<endl;
                    }
                    cout<<endl<<endl<<"Буквы, которые уже называли: ";
                    for (int i=0; i<=proverkahoda; i++)
                    {
                        cout<<x[i]<<" ";
                    }
                    cout<<endl<<endl;
                    Sleep(3000);
                    if (schetchik!=0 or y) cout<<"##########################################################################################"<<endl<<endl;
                }
                if (live4!=0) system("cls");

                if (live1==0 and live2==0 and live3==0 and live4==0)
                {
                    system("cls");
                    schetchik=999;
                }

            }

            if (score1>=score2 and score1>=score3 and score1>=score4) cout<<"Самое большое количество очков набрал: "<<nik<<" - "<<score1<<endl;
            if (score2>=score1 and score2>=score3 and score2>=score4) cout<<"Самое большое количество очков набрал: "<<nik2<<" - "<<score2<<endl;
            if (score3>=score2 and score3>=score1 and score3>=score4) cout<<"Самое большое количество очков набрал: "<<nik3<<" - "<<score3<<endl;
            if (score4>=score2 and score4>=score3 and score4>=score1) cout<<"Самое большое количество очков набрал: "<<nik4<<" - "<<score4<<endl;
            break;
        }
        case 2:
        {
            cout<<"В эту игру максимум могут играть 2 человека.";
            cout<<endl<<nik<<", мы уже знакомы, а как зовут других игроков?";
            cout<<endl<<endl<<"Игрок номер 1 - "<< nik;
            cout<<endl<<endl<<"Игрок номер 2 - ";
            char nik2[20];
            cin>>nik2;

            system("cls");

            int dlinaslova = strlen(slovovisel);
            int schetchik=0;
            char bukva;
            int bukva2=0;
            char vivodslova[30];
            bool y;

            for (int i=0; i<dlinaslova; i++)
            {
                vivodslova[i]='.';
                vivodslova[dlinaslova]=NULL;
            }

            int shag=0, ugadal=1;
            int pobeda = 1;

            int score1=0,score2=0;
            int live1=10,live2=10;


            char x[40];
            int proverka=0;
            int proverkahoda=-1;

            while (schetchik!=999)
            {
                y=false;
                cout<<setw(40)<<"Виселица!";
                cout<<endl<<endl;
                shag=0, ugadal=1;
                proverkahoda++;
                while (ugadal>shag and schetchik!=999 and live1!=0)
                {
                    schetchik=0, bukva2=0;
                    ++shag;
                    puts(vivodslova);
                    cout<<endl<<endl;
                    cout<<endl<<"\nБукву говорит "<<nik<<": ";
                    cin>>bukva;
                    for (int i=proverkahoda; i<=proverkahoda; i++)
                    {
                        x[proverkahoda]=bukva;
                    }
                    cout<<endl<<endl<<"Ваш счёт: "<<score1<<endl;

                    for (int i=0; i<dlinaslova; i++)
                    {
                        if (slovovisel[i]==bukva)
                        {
                            y=true;
                            score1+=10;
                            schetchik++;
                            ugadal++;
                            for (int pobeda=0,j=0; j<dlinaslova; j++)
                            {
                                if (slovovisel[j]==bukva and vivodslova[j]=='.') vivodslova[j]=slovovisel[i];
                                if (vivodslova[j]!='.') pobeda++;
                                if (pobeda==dlinaslova)
                                {
                                    schetchik=999;
                                    ugadal--;
                                }
                                while (shag>=0 or ugadal>=1)
                                {
                                    if (shag>=0) shag--;
                                    if (ugadal>=1) ugadal--;
                                }
                            }
                        }
                    }


                    if (schetchik==bukva2)
                    {
                        cout<<endl<<"Игрок не угадал букву. ";
                        cout<<endl<<"Количество ваших жизней: "<<live1--<<endl;
                        if (live1==0) cout<<endl<<"Вы проиграли."<<endl;
                        if (live1==9) cout<<"\n\n\n\n\n__()__";
                        if (live1==8)
                        {
                            cout<<"  ()"<<endl;
                            cout<<"  ()"<<endl;
                            cout<<"  ()"<<endl;
                            cout<<"__()__";
                        }
                        if (live1==7)
                        {
                            cout<<"  >>>>>>>"<<endl;
                            cout<<"  ()"<<endl;
                            cout<<"  ()"<<endl;
                            cout<<"  ()"<<endl;
                            cout<<"__()__";
                        }
                        if (live1==6)
                        {
                            cout<<"  >>>>>>>"<<endl;
                            cout<<"  ()    |"<<endl;
                            cout<<"  ()"<<endl;
                            cout<<"  ()"<<endl;
                            cout<<"__()__";
                        }
                        if (live1==5)
                        {
                            cout<<"  >>>>>>>"<<endl;
                            cout<<"  ()    |"<<endl;
                            cout<<"  ()    o"<<endl;
                            cout<<"  ()"<<endl;
                            cout<<"__()__";
                        }
                        if (live1==4)
                        {
                            cout<<"  >>>>>>>"<<endl;
                            cout<<"  ()    |"<<endl;
                            cout<<"  ()    o"<<endl;
                            cout<<"  ()    |"<<endl;
                            cout<<"__()__";
                        }
                        if (live1==3)
                        {
                            cout<<"  >>>>>>>"<<endl;
                            cout<<"  ()    |"<<endl;
                            cout<<"  ()    o"<<endl;
                            cout<<"  ()   /|"<<endl;
                            cout<<"__()__ ";
                        }
                        if (live1==2)
                        {
                            cout<<"  >>>>>>>"<<endl;
                            cout<<"  ()    |"<<endl;
                            cout<<"  ()    o"<<endl;
                            cout<<"  ()   /|"<<endl;
                            cout<<"__()__ / ";
                        }
                        if (live1==1)
                        {
                            cout<<"  >>>>>>>"<<endl;
                            cout<<"  ()    |"<<endl;
                            cout<<"  ()    o"<<endl;
                            cout<<"  ()   /|"<<endl;
                            cout<<"__()__ / \\";
                        }
                        if (live1==0)
                        {
                            cout<<"  >>>>>>>"<<endl;
                            cout<<"  ()    |"<<endl;
                            cout<<"  ()    o"<<endl;
                            cout<<"  ()   /|\\"<<endl;
                            cout<<"__()__ / \\";
                        }
                    }
                    else
                    {
                        proverka=0;
                        for (int i=0; i<dlinaslova; i++)
                        {
                            if (slovovisel[i]==bukva) proverka++;
                            if (proverka>=1) bukva2++;
                        }
                        cout<<endl<<"Игрок угадал букву!"<<endl<<endl;

                    }

                    cout<<endl<<endl<<"Буквы, которые уже называли: ";
                    for (int i=0; i<=proverkahoda; i++)
                    {
                        cout<<x[i]<<" ";
                    }
                    cout<<endl<<endl;
                    Sleep(3000);
                    if (schetchik!=0 or y) cout<<"##########################################################################################"<<endl<<endl;
                }
                if (live1!=0) system("cls");



                y=false;
                cout<<setw(40)<<"Виселица!";
                cout<<endl<<endl;
                shag=0, ugadal=1;
                proverkahoda++;
                while (ugadal>shag and schetchik!=999 and live2!=0)
                {
                    schetchik=0, bukva2=0;
                    ++shag;
                    puts(vivodslova);
                    cout<<endl<<endl;
                    cout<<endl<<"\nБукву говорит "<<nik2<<": ";
                    cin>>bukva;
                    for (int i=proverkahoda; i<=proverkahoda; i++)
                    {
                        x[proverkahoda]=bukva;
                    }
                    cout<<endl<<endl<<"Ваш счёт: "<<score1<<endl;

                    for (int i=0; i<dlinaslova; i++)
                    {
                        if (slovovisel[i]==bukva)
                        {
                            y=true;
                            score2+=10;
                            schetchik++;
                            ugadal++;
                            for (int pobeda=0,j=0; j<dlinaslova; j++)
                            {
                                if (slovovisel[j]==bukva and vivodslova[j]=='.') vivodslova[j]=slovovisel[i];
                                if (vivodslova[j]!='.') pobeda++;
                                if (pobeda==dlinaslova)
                                {
                                    schetchik=999;
                                    ugadal--;
                                }
                                while (shag>=0 or ugadal>=1)
                                {
                                    if (shag>=0) shag--;
                                    if (ugadal>=1) ugadal--;
                                }
                            }
                        }
                    }

                    if (schetchik==bukva2)
                    {
                        cout<<endl<<"Игрок не угадал букву. ";
                        cout<<endl<<"Количество ваших жизней: "<<live2--<<endl;
                        if (live2==0) cout<<endl<<"Вы проиграли."<<endl;
                        if (live2==9) cout<<"\n\n\n\n\n__()__";
                        if (live2==8)
                        {
                            cout<<"  ()"<<endl;
                            cout<<"  ()"<<endl;
                            cout<<"  ()"<<endl;
                            cout<<"__()__";
                        }
                        if (live2==7)
                        {
                            cout<<"  >>>>>>>"<<endl;
                            cout<<"  ()"<<endl;
                            cout<<"  ()"<<endl;
                            cout<<"  ()"<<endl;
                            cout<<"__()__";
                        }
                        if (live2==6)
                        {
                            cout<<"  >>>>>>>"<<endl;
                            cout<<"  ()    |"<<endl;
                            cout<<"  ()"<<endl;
                            cout<<"  ()"<<endl;
                            cout<<"__()__";
                        }
                        if (live2==5)
                        {
                            cout<<"  >>>>>>>"<<endl;
                            cout<<"  ()    |"<<endl;
                            cout<<"  ()    o"<<endl;
                            cout<<"  ()"<<endl;
                            cout<<"__()__";
                        }
                        if (live2==4)
                        {
                            cout<<"  >>>>>>>"<<endl;
                            cout<<"  ()    |"<<endl;
                            cout<<"  ()    o"<<endl;
                            cout<<"  ()    |"<<endl;
                            cout<<"__()__";
                        }
                        if (live2==3)
                        {
                            cout<<"  >>>>>>>"<<endl;
                            cout<<"  ()    |"<<endl;
                            cout<<"  ()    o"<<endl;
                            cout<<"  ()   /|"<<endl;
                            cout<<"__()__ ";
                        }
                        if (live2==2)
                        {
                            cout<<"  >>>>>>>"<<endl;
                            cout<<"  ()    |"<<endl;
                            cout<<"  ()    o"<<endl;
                            cout<<"  ()   /|"<<endl;
                            cout<<"__()__ / ";
                        }
                        if (live2==1)
                        {
                            cout<<"  >>>>>>>"<<endl;
                            cout<<"  ()    |"<<endl;
                            cout<<"  ()    o"<<endl;
                            cout<<"  ()   /|"<<endl;
                            cout<<"__()__ / \\";
                        }
                        if (live2==0)
                        {
                            cout<<"  >>>>>>>"<<endl;
                            cout<<"  ()    |"<<endl;
                            cout<<"  ()    o"<<endl;
                            cout<<"  ()   /|\\"<<endl;
                            cout<<"__()__ / \\";
                        }
                    }
                    else
                    {
                        proverka=0;
                        for (int i=0; i<dlinaslova; i++)
                        {
                            if (slovovisel[i]==bukva) proverka++;
                            if (proverka>=1) bukva2++;
                        }
                        cout<<endl<<"Игрок угадал букву!"<<endl<<endl;

                    }

                    cout<<endl<<endl<<"Буквы, которые уже называли: ";
                    for (int i=0; i<=proverkahoda; i++)
                    {
                        cout<<x[i]<<" ";
                    }
                    cout<<endl<<endl;
                    Sleep(3000);
                    if (schetchik!=0 or y) cout<<"##########################################################################################"<<endl<<endl;
                }
                if (live2!=0) system("cls");

                if (live1==0 and live2==0)
                {
                    system("cls");
                    schetchik=999;
                }

            }
            if (score1>=score2) cout<<"Самое большое количество очков набрал: "<<nik<<" - "<<score1<<endl;
            else cout<<"Самое большое количество очков набрал: "<<nik2<<" - "<<score2<<endl;
            break;


        }
        case 3:
        {
            char botniks[1000]= {"Владимир, Николай, Настя, Клава, Александр, Влад, Тимур, Дмитрий, Егор, Максим, Артур, Олег, Иван, Яна, Мария, Алексей, Вадим, Никита, Ольга, Святослав, Марина, Александра, Андрей"};

            char botnik[25];
            char botnik1[25];
            char botnik2[25];
            int randomnik = rand() %25;
            int randomnik1 = rand() %25;
            int randomnik2 = rand() %25;
            char razdelnik[5]=", ";
            char *pch1=strtok (botniks,razdelnik);
            int schetnik=0;

            while (pch1!=NULL)
            {
                if (schetnik==randomnik) strcpy(botnik,pch1);
                if (schetnik==randomnik1) strcpy(botnik1,pch1);
                if (schetnik==randomnik2) strcpy(botnik2,pch1);
                schetnik++;
                pch1=strtok(NULL,razdelnik);
            }



            cout<<"Вы выбрали игру с ботами. С вами играют: ";
            cout<<endl<<endl<<"Игрок номер 1 - "<< nik<<" - Вы.";
            cout<<endl<<endl<<"Игрок номер 2 - "<< botnik;
            cout<<endl<<endl<<"Игрок номер 3 - "<< botnik1;
            cout<<endl<<endl<<"Игрок номер 4 - "<< botnik2;

            Sleep(1500);

            system("cls");

            int dlinaslova = strlen(slovovisel);
            int schetchik=0;
            char bukva;
            int bukva2=0;
            char vivodslova[30];
            bool y;

            for (int i=0; i<dlinaslova; i++)
            {
                vivodslova[i]='.';
                vivodslova[dlinaslova]=NULL;
            }

            int shag=0, ugadal=1;
            int pobeda = 1;

            int score1=0,score2=0,score3=0,score4=0;
            int live1=10,live2=10,live3=10,live4=10;


            char x[40];
            int proverka=0;
            int proverkahoda=-1;

            while (schetchik!=999)
            {
                y=false;
                cout<<setw(40)<<"Виселица!";
                cout<<endl<<endl;
                shag=0, ugadal=1;
                proverkahoda++;
                while (ugadal>shag and schetchik!=999 and live1!=0)
                {
                    schetchik=0, bukva2=0;
                    ++shag;
                    puts(vivodslova);
                    cout<<endl<<endl;
                    cout<<endl<<"\nБукву говорит "<<nik<<": ";
                    cin>>bukva;
                    for (int i=proverkahoda; i<=proverkahoda; i++)
                    {
                        x[proverkahoda]=bukva;
                    }
                    cout<<endl<<endl<<"Ваш счёт: "<<score1<<endl;

                    for (int i=0; i<dlinaslova; i++)
                    {
                        if (slovovisel[i]==bukva)
                        {
                            y=true;
                            score1+=10;
                            schetchik++;
                            ugadal++;
                            for (int pobeda=0,j=0; j<dlinaslova; j++)
                            {
                                if (slovovisel[j]==bukva and vivodslova[j]=='.') vivodslova[j]=slovovisel[i];
                                if (vivodslova[j]!='.') pobeda++;
                                if (pobeda==dlinaslova)
                                {
                                    schetchik=999;
                                    ugadal--;
                                }
                                while (shag>=0 or ugadal>=1)
                                {
                                    if (shag>=0) shag--;
                                    if (ugadal>=1) ugadal--;
                                }
                            }
                        }
                    }


                    if (schetchik==bukva2)
                    {
                        cout<<endl<<"Игрок не угадал букву. ";
                        cout<<endl<<"Количество ваших жизней: "<<live1--<<endl;
                        if (live1==0) cout<<endl<<"Вы проиграли."<<endl;
                        if (live1==9) cout<<"\n\n\n\n\n__()__";
                        if (live1==8)
                        {
                            cout<<"  ()"<<endl;
                            cout<<"  ()"<<endl;
                            cout<<"  ()"<<endl;
                            cout<<"__()__";
                        }
                        if (live1==7)
                        {
                            cout<<"  >>>>>>>"<<endl;
                            cout<<"  ()"<<endl;
                            cout<<"  ()"<<endl;
                            cout<<"  ()"<<endl;
                            cout<<"__()__";
                        }
                        if (live1==6)
                        {
                            cout<<"  >>>>>>>"<<endl;
                            cout<<"  ()    |"<<endl;
                            cout<<"  ()"<<endl;
                            cout<<"  ()"<<endl;
                            cout<<"__()__";
                        }
                        if (live1==5)
                        {
                            cout<<"  >>>>>>>"<<endl;
                            cout<<"  ()    |"<<endl;
                            cout<<"  ()    o"<<endl;
                            cout<<"  ()"<<endl;
                            cout<<"__()__";
                        }
                        if (live1==4)
                        {
                            cout<<"  >>>>>>>"<<endl;
                            cout<<"  ()    |"<<endl;
                            cout<<"  ()    o"<<endl;
                            cout<<"  ()    |"<<endl;
                            cout<<"__()__";
                        }
                        if (live1==3)
                        {
                            cout<<"  >>>>>>>"<<endl;
                            cout<<"  ()    |"<<endl;
                            cout<<"  ()    o"<<endl;
                            cout<<"  ()   /|"<<endl;
                            cout<<"__()__ ";
                        }
                        if (live1==2)
                        {
                            cout<<"  >>>>>>>"<<endl;
                            cout<<"  ()    |"<<endl;
                            cout<<"  ()    o"<<endl;
                            cout<<"  ()   /|"<<endl;
                            cout<<"__()__ / ";
                        }
                        if (live1==1)
                        {
                            cout<<"  >>>>>>>"<<endl;
                            cout<<"  ()    |"<<endl;
                            cout<<"  ()    o"<<endl;
                            cout<<"  ()   /|"<<endl;
                            cout<<"__()__ / \\";
                        }
                        if (live1==0)
                        {
                            cout<<"  >>>>>>>"<<endl;
                            cout<<"  ()    |"<<endl;
                            cout<<"  ()    o"<<endl;
                            cout<<"  ()   /|\\"<<endl;
                            cout<<"__()__ / \\";
                        }
                    }
                    else
                    {
                        proverka=0;
                        for (int i=0; i<dlinaslova; i++)
                        {
                            if (slovovisel[i]==bukva) proverka++;
                            if (proverka>=1) bukva2++;
                        }
                        cout<<endl<<"Игрок угадал букву!"<<endl<<endl;

                    }

                    cout<<endl<<endl<<"Буквы, которые уже называли: ";
                    for (int i=0; i<=proverkahoda; i++)
                    {
                        cout<<x[i]<<" ";
                    }
                    cout<<endl<<endl;
                    Sleep(3000);
                    if (schetchik!=0 or y) cout<<"##########################################################################################"<<endl<<endl;
                }
                if (live1!=0) system("cls");



                y=false;
                cout<<setw(40)<<"Виселица!";
                cout<<endl<<endl;
                shag=0, ugadal=1;
                proverkahoda++;
                while (ugadal>shag and schetchik!=999 and live2!=0)
                {
                    schetchik=0, bukva2=0;
                    ++shag;
                    puts(vivodslova);
                    cout<<endl<<endl;

                    char bukvirus[200]= {"а, б, в, г, д, е, ё, ж, з, и, й, к, л, м, н, о, п, р, с, т, у, ф, х, ц, ч, ш, щ, ъ, ы, ь, э, ю, я"};
                    int schetchikbot=0;
                    char razdeldliabukv[5]= {", "};
                    char *pch2=strtok (bukvirus, razdeldliabukv);
                    char bukvadliabota[2];
st1:
                    int randombukva = 1 + rand() % 33;

                    while (pch2!=NULL)
                    {
                        if (schetchikbot==randombukva) strcpy(bukvadliabota,pch2);
                        pch2=strtok(NULL,razdeldliabukv);
                        schetchikbot++;
                    }

                    for (int i=0; i<dlinaslova; i++)
                    {
                        if (vivodslova[i]==bukvadliabota[0]) goto st1;
                    }



                    cout<<endl<<"\nБукву говорит "<<botnik<<": "<<bukvadliabota;

                    for (int i=0; i<1; i++)
                    {
                        bukva=bukvadliabota[0];
                    }


                    for (int i=proverkahoda; i<=proverkahoda; i++)
                    {
                        x[proverkahoda]=bukva;
                    }
                    cout<<endl<<endl<<"Ваш счёт: "<<score2<<endl;

                    for (int i=0; i<dlinaslova; i++)
                    {
                        if (slovovisel[i]==bukva)
                        {
                            y=true;
                            score2+=10;
                            schetchik++;
                            ugadal++;
                            for (int pobeda=0,j=0; j<dlinaslova; j++)
                            {
                                if (slovovisel[j]==bukva and vivodslova[j]=='.') vivodslova[j]=slovovisel[i];
                                if (vivodslova[j]!='.') pobeda++;
                                if (pobeda==dlinaslova)
                                {
                                    schetchik=999;
                                    ugadal--;
                                }
                                while (shag>=0 or ugadal>=1)
                                {
                                    if (shag>=0) shag--;
                                    if (ugadal>=1) ugadal--;
                                }
                            }
                        }
                    }

                    if (schetchik==bukva2)
                    {
                        cout<<endl<<"Игрок не угадал букву. ";
                        cout<<endl<<"Количество ваших жизней: "<<live2--<<endl;
                        if (live2==0) cout<<endl<<"Вы проиграли."<<endl;
                        if (live2==9) cout<<"\n\n\n\n\n__()__";
                        if (live2==8)
                        {
                            cout<<"  ()"<<endl;
                            cout<<"  ()"<<endl;
                            cout<<"  ()"<<endl;
                            cout<<"__()__";
                        }
                        if (live2==7)
                        {
                            cout<<"  >>>>>>>"<<endl;
                            cout<<"  ()"<<endl;
                            cout<<"  ()"<<endl;
                            cout<<"  ()"<<endl;
                            cout<<"__()__";
                        }
                        if (live2==6)
                        {
                            cout<<"  >>>>>>>"<<endl;
                            cout<<"  ()    |"<<endl;
                            cout<<"  ()"<<endl;
                            cout<<"  ()"<<endl;
                            cout<<"__()__";
                        }
                        if (live2==5)
                        {
                            cout<<"  >>>>>>>"<<endl;
                            cout<<"  ()    |"<<endl;
                            cout<<"  ()    o"<<endl;
                            cout<<"  ()"<<endl;
                            cout<<"__()__";
                        }
                        if (live2==4)
                        {
                            cout<<"  >>>>>>>"<<endl;
                            cout<<"  ()    |"<<endl;
                            cout<<"  ()    o"<<endl;
                            cout<<"  ()    |"<<endl;
                            cout<<"__()__";
                        }
                        if (live2==3)
                        {
                            cout<<"  >>>>>>>"<<endl;
                            cout<<"  ()    |"<<endl;
                            cout<<"  ()    o"<<endl;
                            cout<<"  ()   /|"<<endl;
                            cout<<"__()__ ";
                        }
                        if (live2==2)
                        {
                            cout<<"  >>>>>>>"<<endl;
                            cout<<"  ()    |"<<endl;
                            cout<<"  ()    o"<<endl;
                            cout<<"  ()   /|"<<endl;
                            cout<<"__()__ / ";
                        }
                        if (live2==1)
                        {
                            cout<<"  >>>>>>>"<<endl;
                            cout<<"  ()    |"<<endl;
                            cout<<"  ()    o"<<endl;
                            cout<<"  ()   /|"<<endl;
                            cout<<"__()__ / \\";
                        }
                        if (live2==0)
                        {
                            cout<<"  >>>>>>>"<<endl;
                            cout<<"  ()    |"<<endl;
                            cout<<"  ()    o"<<endl;
                            cout<<"  ()   /|\\"<<endl;
                            cout<<"__()__ / \\";
                        }
                    }
                    else
                    {
                        proverka=0;
                        for (int i=0; i<dlinaslova; i++)
                        {
                            if (slovovisel[i]==bukva) proverka++;
                            if (proverka>=1) bukva2++;
                        }
                        cout<<endl<<"Игрок угадал букву!"<<endl<<endl;

                    }

                    cout<<endl<<endl<<"Буквы, которые уже называли: ";
                    for (int i=0; i<=proverkahoda; i++)
                    {
                        cout<<x[i]<<" ";
                    }
                    cout<<endl<<endl;
                    Sleep(3000);
                    if (schetchik!=0 or y) cout<<"##########################################################################################"<<endl<<endl;
                }
                if (live2!=0) system("cls");

                y=false;
                cout<<setw(40)<<"Виселица!";
                cout<<endl<<endl;
                shag=0, ugadal=1;
                proverkahoda++;
                while (ugadal>shag and schetchik!=999 and live3!=0)
                {
                    schetchik=0, bukva2=0;
                    ++shag;
                    puts(vivodslova);
                    cout<<endl<<endl;

                    char bukvirus[200]= {"а, б, в, г, д, е, ё, ж, з, и, й, к, л, м, н, о, п, р, с, т, у, ф, х, ц, ч, ш, щ, ъ, ы, ь, э, ю, я"};
                    int schetchikbot=0;
                    char razdeldliabukv[5]= {", "};
                    char *pch2=strtok (bukvirus, razdeldliabukv);
                    char bukvadliabota[2];

st2:
                    int randombukva = 1 + rand() % 33;

                    while (pch2!=NULL)
                    {
                        if (schetchikbot==randombukva) strcpy(bukvadliabota,pch2);
                        pch2=strtok(NULL,razdeldliabukv);
                        schetchikbot++;
                    }

                    for (int i=0; i<dlinaslova; i++)
                    {
                        if (vivodslova[i]==bukvadliabota[0]) goto st2;
                    }

                    cout<<endl<<"\nБукву говорит "<<botnik1<<": "<<bukvadliabota;

                    for (int i=0; i<1; i++)
                    {
                        bukva=bukvadliabota[0];
                    }


                    for (int i=proverkahoda; i<=proverkahoda; i++)
                    {
                        x[proverkahoda]=bukva;
                    }
                    cout<<endl<<endl<<"Ваш счёт: "<<score3<<endl;

                    for (int i=0; i<dlinaslova; i++)
                    {
                        if (slovovisel[i]==bukva)
                        {
                            y=true;
                            score3+=10;
                            schetchik++;
                            ugadal++;
                            for (int pobeda=0,j=0; j<dlinaslova; j++)
                            {
                                if (slovovisel[j]==bukva and vivodslova[j]=='.') vivodslova[j]=slovovisel[i];
                                if (vivodslova[j]!='.') pobeda++;
                                if (pobeda==dlinaslova)
                                {
                                    schetchik=999;
                                    ugadal--;
                                }
                                while (shag>=0 or ugadal>=1)
                                {
                                    if (shag>=0) shag--;
                                    if (ugadal>=1) ugadal--;
                                }
                            }
                        }
                    }

                    if (schetchik==bukva2)
                    {
                        cout<<endl<<"Игрок не угадал букву. ";
                        cout<<endl<<"Количество ваших жизней: "<<live3--<<endl;
                        if (live3==0) cout<<endl<<"Вы проиграли."<<endl;
                        if (live3==9) cout<<"\n\n\n\n\n__()__";
                        if (live3==8)
                        {
                            cout<<"  ()"<<endl;
                            cout<<"  ()"<<endl;
                            cout<<"  ()"<<endl;
                            cout<<"__()__";
                        }
                        if (live3==7)
                        {
                            cout<<"  >>>>>>>"<<endl;
                            cout<<"  ()"<<endl;
                            cout<<"  ()"<<endl;
                            cout<<"  ()"<<endl;
                            cout<<"__()__";
                        }
                        if (live3==6)
                        {
                            cout<<"  >>>>>>>"<<endl;
                            cout<<"  ()    |"<<endl;
                            cout<<"  ()"<<endl;
                            cout<<"  ()"<<endl;
                            cout<<"__()__";
                        }
                        if (live3==5)
                        {
                            cout<<"  >>>>>>>"<<endl;
                            cout<<"  ()    |"<<endl;
                            cout<<"  ()    o"<<endl;
                            cout<<"  ()"<<endl;
                            cout<<"__()__";
                        }
                        if (live3==4)
                        {
                            cout<<"  >>>>>>>"<<endl;
                            cout<<"  ()    |"<<endl;
                            cout<<"  ()    o"<<endl;
                            cout<<"  ()    |"<<endl;
                            cout<<"__()__";
                        }
                        if (live3==3)
                        {
                            cout<<"  >>>>>>>"<<endl;
                            cout<<"  ()    |"<<endl;
                            cout<<"  ()    o"<<endl;
                            cout<<"  ()   /|"<<endl;
                            cout<<"__()__ ";
                        }
                        if (live3==2)
                        {
                            cout<<"  >>>>>>>"<<endl;
                            cout<<"  ()    |"<<endl;
                            cout<<"  ()    o"<<endl;
                            cout<<"  ()   /|"<<endl;
                            cout<<"__()__ / ";
                        }
                        if (live3==1)
                        {
                            cout<<"  >>>>>>>"<<endl;
                            cout<<"  ()    |"<<endl;
                            cout<<"  ()    o"<<endl;
                            cout<<"  ()   /|"<<endl;
                            cout<<"__()__ / \\";
                        }
                        if (live3==0)
                        {
                            cout<<"  >>>>>>>"<<endl;
                            cout<<"  ()    |"<<endl;
                            cout<<"  ()    o"<<endl;
                            cout<<"  ()   /|\\"<<endl;
                            cout<<"__()__ / \\";
                        }
                    }
                    else
                    {
                        proverka=0;
                        for (int i=0; i<dlinaslova; i++)
                        {
                            if (slovovisel[i]==bukva) proverka++;
                            if (proverka>=1) bukva2++;
                        }
                        cout<<endl<<"Игрок угадал букву!"<<endl<<endl;

                    }

                    cout<<endl<<endl<<"Буквы, которые уже называли: ";
                    for (int i=0; i<=proverkahoda; i++)
                    {
                        cout<<x[i]<<" ";
                    }
                    cout<<endl<<endl;
                    Sleep(3000);
                    if (schetchik!=0 or y) cout<<"##########################################################################################"<<endl<<endl;
                }
                if (live3!=0) system("cls");


                y=false;
                cout<<setw(40)<<"Виселица!";
                cout<<endl<<endl;
                shag=0, ugadal=1;
                proverkahoda++;
                while (ugadal>shag and schetchik!=999 and live4!=0)
                {
                    schetchik=0, bukva2=0;
                    ++shag;
                    puts(vivodslova);
                    cout<<endl<<endl;

                    char bukvirus[200]= {"а, б, в, г, д, е, ё, ж, з, и, й, к, л, м, н, о, п, р, с, т, у, ф, х, ц, ч, ш, щ, ъ, ы, ь, э, ю, я"};
                    int schetchikbot=0;
                    char razdeldliabukv[5]= {", "};
                    char *pch2=strtok (bukvirus, razdeldliabukv);
                    char bukvadliabota[2];

st3:
                    int randombukva = 1 + rand() % 33;
                    while (pch2!=NULL)
                    {
                        if (schetchikbot==randombukva) strcpy(bukvadliabota,pch2);
                        pch2=strtok(NULL,razdeldliabukv);
                        schetchikbot++;
                    }

                    for (int i=0; i<dlinaslova; i++)
                    {
                        if (vivodslova[i]==bukvadliabota[0]) goto st3;
                    }

                    cout<<endl<<"\nБукву говорит "<<botnik2<<": "<<bukvadliabota;

                    for (int i=0; i<1; i++)
                    {
                        bukva=bukvadliabota[0];
                    }


                    for (int i=proverkahoda; i<=proverkahoda; i++)
                    {
                        x[proverkahoda]=bukva;
                    }
                    cout<<endl<<endl<<"Ваш счёт: "<<score4<<endl;

                    for (int i=0; i<dlinaslova; i++)
                    {
                        if (slovovisel[i]==bukva)
                        {
                            y=true;
                            score4+=10;
                            schetchik++;
                            ugadal++;
                            for (int pobeda=0,j=0; j<dlinaslova; j++)
                            {
                                if (slovovisel[j]==bukva and vivodslova[j]=='.') vivodslova[j]=slovovisel[i];
                                if (vivodslova[j]!='.') pobeda++;
                                if (pobeda==dlinaslova)
                                {
                                    schetchik=999;
                                    ugadal--;
                                }
                                while (shag>=0 or ugadal>=1)
                                {
                                    if (shag>=0) shag--;
                                    if (ugadal>=1) ugadal--;
                                }
                            }
                        }
                    }

                    if (schetchik==bukva2)
                    {
                        cout<<endl<<"Игрок не угадал букву. ";
                        cout<<endl<<"Количество ваших жизней: "<<live4--<<endl;
                        if (live4==0) cout<<endl<<"Вы проиграли."<<endl;
                        if (live4==9) cout<<"\n\n\n\n\n__()__";
                        if (live4==8)
                        {
                            cout<<"  ()"<<endl;
                            cout<<"  ()"<<endl;
                            cout<<"  ()"<<endl;
                            cout<<"__()__";
                        }
                        if (live4==7)
                        {
                            cout<<"  >>>>>>>"<<endl;
                            cout<<"  ()"<<endl;
                            cout<<"  ()"<<endl;
                            cout<<"  ()"<<endl;
                            cout<<"__()__";
                        }
                        if (live4==6)
                        {
                            cout<<"  >>>>>>>"<<endl;
                            cout<<"  ()    |"<<endl;
                            cout<<"  ()"<<endl;
                            cout<<"  ()"<<endl;
                            cout<<"__()__";
                        }
                        if (live4==5)
                        {
                            cout<<"  >>>>>>>"<<endl;
                            cout<<"  ()    |"<<endl;
                            cout<<"  ()    o"<<endl;
                            cout<<"  ()"<<endl;
                            cout<<"__()__";
                        }
                        if (live4==4)
                        {
                            cout<<"  >>>>>>>"<<endl;
                            cout<<"  ()    |"<<endl;
                            cout<<"  ()    o"<<endl;
                            cout<<"  ()    |"<<endl;
                            cout<<"__()__";
                        }
                        if (live4==3)
                        {
                            cout<<"  >>>>>>>"<<endl;
                            cout<<"  ()    |"<<endl;
                            cout<<"  ()    o"<<endl;
                            cout<<"  ()   /|"<<endl;
                            cout<<"__()__ ";
                        }
                        if (live4==2)
                        {
                            cout<<"  >>>>>>>"<<endl;
                            cout<<"  ()    |"<<endl;
                            cout<<"  ()    o"<<endl;
                            cout<<"  ()   /|"<<endl;
                            cout<<"__()__ / ";
                        }
                        if (live4==1)
                        {
                            cout<<"  >>>>>>>"<<endl;
                            cout<<"  ()    |"<<endl;
                            cout<<"  ()    o"<<endl;
                            cout<<"  ()   /|"<<endl;
                            cout<<"__()__ / \\";
                        }
                        if (live4==0)
                        {
                            cout<<"  >>>>>>>"<<endl;
                            cout<<"  ()    |"<<endl;
                            cout<<"  ()    o"<<endl;
                            cout<<"  ()   /|\\"<<endl;
                            cout<<"__()__ / \\";
                        }
                    }
                    else
                    {
                        proverka=0;
                        for (int i=0; i<dlinaslova; i++)
                        {
                            if (slovovisel[i]==bukva) proverka++;
                            if (proverka>=1) bukva2++;
                        }
                        cout<<endl<<"Игрок угадал букву!"<<endl<<endl;

                    }

                    cout<<endl<<endl<<"Буквы, которые уже называли: ";
                    for (int i=0; i<=proverkahoda; i++)
                    {
                        cout<<x[i]<<" ";
                    }
                    cout<<endl<<endl;
                    Sleep(3000);
                    if (schetchik!=0 or y) cout<<"##########################################################################################"<<endl<<endl;
                }
                if (live4!=0) system("cls");

                if (live1==0 and live2==0 and live3==0 and live4==0)
                {
                    system("cls");
                    schetchik=999;
                }

            }
            if (score1>=score2 and score1>=score3 and score1>=score4) cout<<"Самое большое количество очков набрал: "<<nik<<" - "<<score1<<endl;
            if (score2>=score1 and score2>=score3 and score2>=score4) cout<<"Самое большое количество очков набрал: "<<botnik<<" - "<<score2<<endl;
            if (score3>=score2 and score3>=score1 and score3>=score4) cout<<"Самое большое количество очков набрал: "<<botnik1<<" - "<<score3<<endl;
            if (score4>=score2 and score4>=score3 and score4>=score1) cout<<"Самое большое количество очков набрал: "<<botnik2<<" - "<<score4<<endl;
            break;
        }


        case 4:
        {
            char botniks[1000]= {"Владимир, Николай, Настя, Клава, Александр, Влад, Тимур, Дмитрий, Егор, Максим, Артур, Олег, Иван, Яна, Мария, Алексей, Вадим, Никита, Ольга, Святослав, Марина, Александра, Андрей"};

            char botnik[25];
            int randomnik = rand() %25;
            char razdelnik[5]=", ";
            char *pch1=strtok (botniks,razdelnik);
            int schetnik=0;

            while (pch1!=NULL)
            {
                if (schetnik==randomnik) strcpy(botnik,pch1);
                schetnik++;
                pch1=strtok(NULL,razdelnik);
            }



            cout<<"Вы выбрали игру с ботом. С вами играет бот: ";
            cout<<endl<<endl<<"Игрок номер 1 - "<< nik<<" - Вы.";
            cout<<endl<<endl<<"Игрок номер 2 - "<< botnik;

            Sleep(1500);

            system("cls");

            int dlinaslova = strlen(slovovisel);
            int schetchik=0;
            char bukva;
            int bukva2=0;
            char vivodslova[30];
            bool y;

            for (int i=0; i<dlinaslova; i++)
            {
                vivodslova[i]='.';
                vivodslova[dlinaslova]=NULL;
            }

            int shag=0, ugadal=1;
            int pobeda = 1;

            int score1=0,score2=0;
            int live1=10,live2=10;


            char x[40];
            int proverka=0;
            int proverkahoda=-1;

            while (schetchik!=999)
            {
                y=false;
                cout<<setw(40)<<"Виселица!";
                cout<<endl<<endl;
                shag=0, ugadal=1;
                proverkahoda++;
                while (ugadal>shag and schetchik!=999 and live1!=0)
                {
                    schetchik=0, bukva2=0;
                    ++shag;
                    puts(vivodslova);
                    cout<<endl<<endl;
                    cout<<endl<<"\nБукву говорит "<<nik<<": ";
                    cin>>bukva;
                    for (int i=proverkahoda; i<=proverkahoda; i++)
                    {
                        x[proverkahoda]=bukva;
                    }
                    cout<<endl<<endl<<"Ваш счёт: "<<score1<<endl;

                    for (int i=0; i<dlinaslova; i++)
                    {
                        if (slovovisel[i]==bukva)
                        {
                            y=true;
                            score1+=10;
                            schetchik++;
                            ugadal++;
                            for (int pobeda=0,j=0; j<dlinaslova; j++)
                            {
                                if (slovovisel[j]==bukva and vivodslova[j]=='.') vivodslova[j]=slovovisel[i];
                                if (vivodslova[j]!='.') pobeda++;
                                if (pobeda==dlinaslova)
                                {
                                    schetchik=999;
                                    ugadal--;
                                }
                                while (shag>=0 or ugadal>=1)
                                {
                                    if (shag>=0) shag--;
                                    if (ugadal>=1) ugadal--;
                                }
                            }
                        }
                    }


                    if (schetchik==bukva2)
                    {
                        cout<<endl<<"Игрок не угадал букву. ";
                        cout<<endl<<"Количество ваших жизней: "<<live1--<<endl;
                        if (live1==0) cout<<endl<<"Вы проиграли."<<endl;
                        if (live1==9) cout<<"\n\n\n\n\n__()__";
                        if (live1==8)
                        {
                            cout<<"  ()"<<endl;
                            cout<<"  ()"<<endl;
                            cout<<"  ()"<<endl;
                            cout<<"__()__";
                        }
                        if (live1==7)
                        {
                            cout<<"  >>>>>>>"<<endl;
                            cout<<"  ()"<<endl;
                            cout<<"  ()"<<endl;
                            cout<<"  ()"<<endl;
                            cout<<"__()__";
                        }
                        if (live1==6)
                        {
                            cout<<"  >>>>>>>"<<endl;
                            cout<<"  ()    |"<<endl;
                            cout<<"  ()"<<endl;
                            cout<<"  ()"<<endl;
                            cout<<"__()__";
                        }
                        if (live1==5)
                        {
                            cout<<"  >>>>>>>"<<endl;
                            cout<<"  ()    |"<<endl;
                            cout<<"  ()    o"<<endl;
                            cout<<"  ()"<<endl;
                            cout<<"__()__";
                        }
                        if (live1==4)
                        {
                            cout<<"  >>>>>>>"<<endl;
                            cout<<"  ()    |"<<endl;
                            cout<<"  ()    o"<<endl;
                            cout<<"  ()    |"<<endl;
                            cout<<"__()__";
                        }
                        if (live1==3)
                        {
                            cout<<"  >>>>>>>"<<endl;
                            cout<<"  ()    |"<<endl;
                            cout<<"  ()    o"<<endl;
                            cout<<"  ()   /|"<<endl;
                            cout<<"__()__ ";
                        }
                        if (live1==2)
                        {
                            cout<<"  >>>>>>>"<<endl;
                            cout<<"  ()    |"<<endl;
                            cout<<"  ()    o"<<endl;
                            cout<<"  ()   /|"<<endl;
                            cout<<"__()__ / ";
                        }
                        if (live1==1)
                        {
                            cout<<"  >>>>>>>"<<endl;
                            cout<<"  ()    |"<<endl;
                            cout<<"  ()    o"<<endl;
                            cout<<"  ()   /|"<<endl;
                            cout<<"__()__ / \\";
                        }
                        if (live1==0)
                        {
                            cout<<"  >>>>>>>"<<endl;
                            cout<<"  ()    |"<<endl;
                            cout<<"  ()    o"<<endl;
                            cout<<"  ()   /|\\"<<endl;
                            cout<<"__()__ / \\";
                        }
                    }
                    else
                    {
                        proverka=0;
                        for (int i=0; i<dlinaslova; i++)
                        {
                            if (slovovisel[i]==bukva) proverka++;
                            if (proverka>=1) bukva2++;
                        }
                        cout<<endl<<"Игрок угадал букву!"<<endl<<endl;

                    }

                    cout<<endl<<endl<<"Буквы, которые уже называли: ";
                    for (int i=0; i<=proverkahoda; i++)
                    {
                        cout<<x[i]<<" ";
                    }
                    cout<<endl<<endl;
                    Sleep(3000);
                    if (schetchik!=0 or y) cout<<"##########################################################################################"<<endl<<endl;
                }
                if (live1!=0) system("cls");



                y=false;
                cout<<setw(40)<<"Виселица!";
                cout<<endl<<endl;
                shag=0, ugadal=1;
                proverkahoda++;
                while (ugadal>shag and schetchik!=999 and live2!=0)
                {
                    schetchik=0, bukva2=0;
                    ++shag;
                    puts(vivodslova);
                    cout<<endl<<endl;

                    char bukvirus[200]= {"а, б, в, г, д, е, ё, ж, з, и, й, к, л, м, н, о, п, р, с, т, у, ф, х, ц, ч, ш, щ, ъ, ы, ь, э, ю, я"};
                    int schetchikbot=0;
                    char razdeldliabukv[5]= {", "};
                    char *pch2=strtok (bukvirus, razdeldliabukv);
                    char bukvadliabota[2];

st4:
                    int randombukva = 1 + rand() % 33;

                    while (pch2!=NULL)
                    {
                        if (schetchikbot==randombukva) strcpy(bukvadliabota,pch2);
                        pch2=strtok(NULL,razdeldliabukv);
                        schetchikbot++;
                    }

                    for (int i=0; i<dlinaslova; i++)
                    {
                        if (vivodslova[i]==bukvadliabota[0]) goto st4;
                    }

                    cout<<endl<<"\nБукву говорит "<<botnik<<": "<<bukvadliabota;

                    for (int i=0; i<1; i++)
                    {
                        bukva=bukvadliabota[0];
                    }


                    for (int i=proverkahoda; i<=proverkahoda; i++)
                    {
                        x[proverkahoda]=bukva;
                    }
                    cout<<endl<<endl<<"Ваш счёт: "<<score2<<endl;

                    for (int i=0; i<dlinaslova; i++)
                    {
                        if (slovovisel[i]==bukva)
                        {
                            y=true;
                            score2+=10;
                            schetchik++;
                            ugadal++;
                            for (int pobeda=0,j=0; j<dlinaslova; j++)
                            {
                                if (slovovisel[j]==bukva and vivodslova[j]=='.') vivodslova[j]=slovovisel[i];
                                if (vivodslova[j]!='.') pobeda++;
                                if (pobeda==dlinaslova)
                                {
                                    schetchik=999;
                                    ugadal--;
                                }
                                while (shag>=0 or ugadal>=1)
                                {
                                    if (shag>=0) shag--;
                                    if (ugadal>=1) ugadal--;
                                }
                            }
                        }
                    }

                    if (schetchik==bukva2)
                    {
                        cout<<endl<<"Игрок не угадал букву. ";
                        cout<<endl<<"Количество ваших жизней: "<<live2--<<endl;
                        if (live2==0) cout<<endl<<"Вы проиграли."<<endl;
                        if (live2==9) cout<<"\n\n\n\n\n__()__";
                        if (live2==8)
                        {
                            cout<<"  ()"<<endl;
                            cout<<"  ()"<<endl;
                            cout<<"  ()"<<endl;
                            cout<<"__()__";
                        }
                        if (live2==7)
                        {
                            cout<<"  >>>>>>>"<<endl;
                            cout<<"  ()"<<endl;
                            cout<<"  ()"<<endl;
                            cout<<"  ()"<<endl;
                            cout<<"__()__";
                        }
                        if (live2==6)
                        {
                            cout<<"  >>>>>>>"<<endl;
                            cout<<"  ()    |"<<endl;
                            cout<<"  ()"<<endl;
                            cout<<"  ()"<<endl;
                            cout<<"__()__";
                        }
                        if (live2==5)
                        {
                            cout<<"  >>>>>>>"<<endl;
                            cout<<"  ()    |"<<endl;
                            cout<<"  ()    o"<<endl;
                            cout<<"  ()"<<endl;
                            cout<<"__()__";
                        }
                        if (live2==4)
                        {
                            cout<<"  >>>>>>>"<<endl;
                            cout<<"  ()    |"<<endl;
                            cout<<"  ()    o"<<endl;
                            cout<<"  ()    |"<<endl;
                            cout<<"__()__";
                        }
                        if (live2==3)
                        {
                            cout<<"  >>>>>>>"<<endl;
                            cout<<"  ()    |"<<endl;
                            cout<<"  ()    o"<<endl;
                            cout<<"  ()   /|"<<endl;
                            cout<<"__()__ ";
                        }
                        if (live2==2)
                        {
                            cout<<"  >>>>>>>"<<endl;
                            cout<<"  ()    |"<<endl;
                            cout<<"  ()    o"<<endl;
                            cout<<"  ()   /|"<<endl;
                            cout<<"__()__ / ";
                        }
                        if (live2==1)
                        {
                            cout<<"  >>>>>>>"<<endl;
                            cout<<"  ()    |"<<endl;
                            cout<<"  ()    o"<<endl;
                            cout<<"  ()   /|"<<endl;
                            cout<<"__()__ / \\";
                        }
                        if (live2==0)
                        {
                            cout<<"  >>>>>>>"<<endl;
                            cout<<"  ()    |"<<endl;
                            cout<<"  ()    o"<<endl;
                            cout<<"  ()   /|\\"<<endl;
                            cout<<"__()__ / \\";
                        }
                    }
                    else
                    {
                        proverka=0;
                        for (int i=0; i<dlinaslova; i++)
                        {
                            if (slovovisel[i]==bukva) proverka++;
                            if (proverka>=1) bukva2++;
                        }
                        cout<<endl<<"Игрок угадал букву!"<<endl<<endl;

                    }

                    cout<<endl<<endl<<"Буквы, которые уже называли: ";
                    for (int i=0; i<=proverkahoda; i++)
                    {
                        cout<<x[i]<<" ";
                    }
                    cout<<endl<<endl;
                    Sleep(3000);
                    if (schetchik!=0 or y) cout<<"##########################################################################################"<<endl<<endl;
                }
                if (live2!=0) system("cls");

                if (live1==0 and live2==0)
                {
                    system("cls");
                    schetchik=999;
                }

            }
            if (score1>=score2) cout<<"Самое большое количество очков набрал: "<<nik<<" - "<<score1<<endl;
            else cout<<"Самое большое количество очков набрал: "<<botnik<<" - "<<score2<<endl;
            break;


        }
        }
    }
    case 2:
    {
        char Prizi[250]="Машина, Баклажан, Перец, 100$, Поездка в турцию, Билет в кино, Телевизор, Компьютер, Посуда, 1 лей, Экскурсия по Кишинёву, Место на бюджете в CEITI, Снегоход, День Красоты";
        char Vopros[20000]="Кто был первым в космосе? Цитрусовое дерево с ароматными цветками? Название этого растения произошло от греческого «порождающий чистоту? Эта птица может летать спиной вперед? Бедный, неказистый домишко, избенка?";
        char Otvet[10000]="Гагарин. Бергамот. Баклажан. Колибри. Хибара.";
        char DelVopros[5]="?";
        char DelOtvet[5]=". ";

        char *pchpole1=strtok(Vopros, DelVopros);
        char *pchpole2=strtok(Otvet, DelOtvet);

        int RandomVopros = rand() %4;
        int RandomOtvet = RandomVopros;

        int SchetPole1=0;
        int SchetPole2=0;

        char VoprosIgri[100];
        char OtvetIgri[15];

        while (pchpole1!=NULL)
        {
            if(SchetPole1==RandomVopros) strcpy(VoprosIgri,Vopros);
            pchpole1=strtok(NULL,DelVopros);
            SchetPole1++;
        }

        while (pchpole2!=NULL)
        {
            if(SchetPole2==RandomOtvet) strcpy(OtvetIgri,Otvet);
            pchpole2=strtok(NULL,DelOtvet);
            SchetPole2++;
        }

        int RazmerSlova=strlen(OtvetIgri);
        char SlovoTochki[15];

        system("cls");

        cout<<setw(40)<<"Виселица"<<endl;
        cout<<"1. С друзьями (3 человека)";
        cout<<"\n2. С другом и ботом. (2 человека)";
        cout<<"\n3. C ботами. (1 человек)";

        cout<<"\n\nТы будешь играть: ";

        int PoleVib;

        while (!(cin>>PoleVib))
        {
            cout<<"Ошибка, вы ввели что-то не то. ";
            cin.clear();
            cin.sync();
            cout<<"\nC кем ты будешь играть?: ";
        }
        system("cls");



        switch (PoleVib)
        {
        case 1:
        {
            bool PoleGame=true;
            bool Igrok1=true;
            bool Igrok2=true;
            bool Igrok3=true;

            int SilaVrash;

            int RandomBaraban1=0;
            int RandomBaraban2=0;
            int RandomBaraban3=0;

            int Score1=0;
            int Score2=0;
            int Score3=0;

            //Сектора на барабане
            int SektorPlus;
            char SektorF[6];
            char SektorPriz[6];

            //Для секторов на барабане
            int RandomF;
            int LevPravSektorF;
            char LevSektorFB[6]="Левая";
            char LevSektorFS[6]="левая";
            int DliaStrcmp;
            int Dengi1=0;
            int Dengi2=0;
            int Dengi3=0;
            char Prodoljiti[6]="Буква";
            char VibPriz[5]="Приз";
            int RandomVedushii;
            int RandomVedushiiVib;
            int DengiPriz=0;

            cout<<"В эту игру максимум могут играть только 3 человека.";
            cout<<endl<<nik<<", мы уже знакомы, а как зовут других игроков?";
            cout<<endl<<endl<<"Игрок номер 1 - "<< nik;
            cout<<endl<<endl<<"Игрок номер 2 - ";
            char nik2[20];
            cin>>nik2;
            cout<<endl<<"Игрок номер 3 - ";
            char nik3[20];
            cin>>nik3;

            system("cls");

            for (int i=0; i<RazmerSlova; i++)
            {
                SlovoTochki[i]='.';
                SlovoTochki[RazmerSlova]=NULL;
            }

            while (PoleGame)
            {
                //Первый игрок
                cout<<setw(40)<<"Поле чудес!";
                cout<<endl<<endl;
                while (Igrok1)
                {
                    cout<<endl;
                    puts(SlovoTochki);

                    cout<<endl<<nik<<" ,крутите барабан!"<<endl;

                    cout<<"Введите силу вращения (1-100): ";
                    while (!(cin>>SilaVrash))
                    {
                        cout<<"Ошибка, вы ввели что-то не то. ";
                        cin.clear();
                        cin.sync();
                        cout<<"\nВведите силу вращения (1-10): ";
                    }


                    RandomBaraban1= rand() %40;

                    if (RandomBaraban1==1)
                    {
                        cout<<endl<<"Сектор \"+\" на барабане!"<<endl<<"Вы можете открыть любую букву в слове, введите её номер: ";
                        cin>>SektorPlus;
                        SektorPlus-=1;

                        for (int i=0; i<RazmerSlova; i++)
                        {
                            if (SektorPlus==i) SlovoTochki[i]=OtvetIgri[i];
                        }
                    }
                    if (RandomBaraban1==2)
                    {
                        Score1+=60;
                        cout<<endl<<"На барабане 60 очков!"<<endl;
                    }
                    if (RandomBaraban1==3)
                    {
                        Score1+=20;
                        cout<<endl<<"На барабане 20 очков!"<<endl;
                    }
                    if (RandomBaraban1==4)
                    {
                        cout<<endl<<"Сектор \"Ф\" на барабане!"<<endl<<"Две шкатулки в студию!";
                        RandomF= rand() %2;
                        cout<<endl<<"Выбирайте шкатулку (левая/правая): ";
                        cin>>SektorF;
                        if (strcmp(SektorF, LevSektorFB)==0) LevPravSektorF=1;
                        else if (strcmp(SektorF, LevSektorFS)==0) LevPravSektorF=1;
                        else LevPravSektorF=2;

                        if (LevPravSektorF==RandomF)
                        {
                            cout<<"Поздравляем! Вы выиграли 100 лей!"<<endl;
                            Dengi1+=100;
                        }
                        else
                        {
                            cout<<"Вы не угадали шкатулку"<<endl;
                        }
                    }
                    if (RandomBaraban1==5)
                    {
                        Score1+=150;
                        cout<<endl<<"На барабане 150 очков!"<<endl;
                    }
                    if (RandomBaraban1==6)
                    {
                        Score1+=60;
                        cout<<endl<<"На барабане 60 очков!"<<endl;
                    }
                    if (RandomBaraban1==7)
                    {
                        cout<<endl<<"На барабане 0 очков!"<<endl;
                    }
                    if (RandomBaraban1==8)
                    {
                        Score1+=100;
                        cout<<endl<<"На барабане 100 очков!"<<endl;
                    }
                    if (RandomBaraban1==9)
                    {
                        Score1+=150;
                        cout<<endl<<"На барабане 150 очков!"<<endl;
                    }
                    if (RandomBaraban1==10)
                    {
                        Score1+=20;
                        cout<<endl<<"На барабане 10 очков!"<<endl;
                    }
                    if (RandomBaraban1==12)
                    {
                        Score1+=100;
                        cout<<endl<<"На барабане 100 очков!"<<endl;
                    }
                    if (RandomBaraban1==13)
                    {
                        Score1+=100;
                        cout<<endl<<"На барабане 100 очков!"<<endl;
                    }
                    if (RandomBaraban1==14)
                    {
                        cout<<endl<<"На барабане сектор приз!"<<endl;
                        cout<<"Выбирайте, приз или называете букву, если угадаете, то 500 очков ваши!";
                        cout<<endl<<"Приз или буква: ";
                        gets(SektorPriz);
                        if (stricmp(SektorPriz,Prodoljiti)==0) cout<<"Вы выбрали назвать букву и получить 500 очков";
                        if (stricmp(SektorPriz,VibPriz)==0) cout<<"Чёрный ящик в студию!";

                        RandomVedushii=1;
                        RandomVedushiiVib=2;
                        DengiPriz=0;

                        while (RandomVedushii=!RandomVedushiiVib)
                        {
                            RandomVedushii= rand() %5;
                            RandomVedushiiVib= rand() %5;
                            DengiPriz+=150;
                            cout<<endl<<"Мы предлагаем вам подумать: "<<DengiPriz<<" лей!";
                        }


                    }



                }

            }




        }
        }
    }
    }
    system ("pause");
}
