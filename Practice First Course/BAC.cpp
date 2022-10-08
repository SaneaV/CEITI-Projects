#include <iostream>
#include <windows.h>
#include <fstream>
#include <iomanip>
#include <stdlib.h>
#include <cstring>
#include <mmsystem.h>
#include "BAC.h"

using namespace std;

int KolichestvoStud;
int KolichestvoAppeal;
int KolichestvoSchool;
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);


void NICEWORK()
{
    PlaySound(TEXT("nice-work.wav"), NULL, SND_SYNC);
}

void TROUBLE()
{
    PlaySound(TEXT("im-in-touble.wav"), NULL, SND_SYNC);
}

void HELLO()
{
    PlaySound(TEXT("hello-1.wav"), NULL, SND_SYNC);
}


struct Student
{
    int CodC;
    char NumeC[20];
    char PrenE[20];
    char DenInst[40];
    char Profil[20];
    char D1[20];
    char D2[20];
    char D3[20];
    char D4[20];
    int Note1;
    int Note2;
    int Note3;
    int Note4;
} S[30];


struct Appel
{
    int CodC;
    char D1[20];
    char D2[20];
    char D3[20];
    char D4[20];
    int Note1;
    int Note2;
    int Note3;
    int Note4;

} S2[20];

void READTXT1()
{
    int i=0;
    ifstream f("BAC.txt");

    while(!f.eof())
    {
        f>>S[i].CodC>>S[i].NumeC>>S[i].PrenE>>S[i].DenInst>>S[i].Profil>>S[i].D1>>S[i].D2>>S[i].D3>>S[i].D4>>S[i].Note1>>S[i].Note2>>S[i].Note3>>S[i].Note4;
        if (!f.eof())
            i++;
    }
    KolichestvoStud = i;
    f.close();
}

void READTXT2()
{

    int i=0;
    ifstream g("Contest.txt");

    while(!g.eof())
    {
        g>>S2[i].CodC>>S2[i].D1>>S2[i].D2>>S2[i].D3>>S2[i].D4>>S2[i].Note1>>S2[i].Note2>>S2[i].Note3>>S2[i].Note4;
        if (!g.eof())
            i++;
    }

    KolichestvoAppeal = i;
    g.close();
}

void READTXT3()
{
    int i=0;
    ifstream f("CandInst.txt");

    while(!f.eof())
    {
        f>>S[i].CodC>>S[i].NumeC>>S[i].PrenE>>S[i].DenInst>>S[i].Profil>>S[i].D1>>S[i].D2>>S[i].D3>>S[i].D4>>S[i].Note1>>S[i].Note2>>S[i].Note3>>S[i].Note4;
        if (!f.eof())
            i++;
    }
    KolichestvoSchool=i;
    f.close();
}



void ShowInfoStudent()
{
    if (S[0].CodC!=NULL)
    {
        for (int j=0; j<=128; j++)
        {
            if (j==0 or j==128)
                cout<<"|";
            else
                cout<<"=";
        }
        cout<<endl;

        cout<<left<<setw(6)<<"| №";
        cout<<"|";
        SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | Yellow));
        cout<<left<<setw(11)<<"Фамилия";
        SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
        cout<<"|";
        SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | Yellow));
        cout<<left<<setw(11)<<"Имя";
        SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
        cout<<"|";
        SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | LightRed));
        cout<<left<<setw(17)<<"Уч.заведение";
        SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
        cout<<"|";
        SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | LightGreen));
        cout<<left<<setw(13)<<"Профиль";
        SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
        cout<<"|";
        SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | Magenta));
        cout<<left<<setw(12)<<"Предмет№1";
        SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
        cout<<"|";
        SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | Cyan));
        cout<<left<<setw(11)<<"Предмет№2";
        SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
        cout<<"|";
        SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | Blue));
        cout<<left<<setw(10)<<"Предмет№3";
        SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
        cout<<"|";
        SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | DarkGray));
        cout<<left<<setw(12)<<"Предмет№4";
        SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
        cout<<"|";
        SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | Magenta));
        cout<<right<<setw(3)<<"#1";
        SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
        cout<<"|";
        SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | Cyan));
        cout<<right<<setw(3)<<"#2";
        SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
        cout<<"|";
        SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | Blue));
        cout<<right<<setw(4)<<"#3";
        SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
        cout<<"|";
        SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | DarkGray));
        cout<<right<<setw(3)<<"#4";
        SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
        cout<<"|"<<endl;

        for (int j=0; j<=128; j++)
        {
            if (j==0 or j==128)
                cout<<"|";
            else
                cout<<"=";
        }
        cout<<endl;

        for (int i=0; i<KolichestvoStud; i++)
        {
            cout<<"|"<<left<<S[i].CodC<<" ";
            cout<<"|"<<left<<setw(11)<<S[i].NumeC;
            cout<<"|"<<left<<setw(11)<<S[i].PrenE;
            cout<<"|"<<left<<setw(17)<<S[i].DenInst;
            cout<<"|"<<left<<setw(13)<<S[i].Profil<<"|";
            SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | LightMagenta));
            cout<<left<<setw(12)<<S[i].D1;
            SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
            cout<<"|";
            SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | LightCyan));
            cout<<left<<setw(11)<<S[i].D2;
            SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
            cout<<"|";
            SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | LightBlue));
            cout<<left<<setw(10)<<S[i].D3;
            SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
            cout<<"|";
            SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | LightGray));
            cout<<left<<setw(12)<<S[i].D4;
            SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
            cout<<"|";
            SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | LightMagenta));
            cout<<right<<setw(3)<<S[i].Note1;
            SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
            cout<<"|";
            SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | LightCyan));
            cout<<right<<setw(3)<<S[i].Note2;
            SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
            cout<<"|";
            SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | LightBlue));
            cout<<right<<setw(4)<<S[i].Note3;
            SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
            cout<<"|";
            SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | LightGray));
            cout<<right<<setw(3)<<S[i].Note4;
            SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
            cout<<"|"<<endl;

            for (int j=0; j<=128; j++)
            {
                if (j==0 or j==128)
                    cout<<"|";
                else
                    cout<<"_";
            }
            cout<<endl;
        }
        cout<<endl<<endl;
    }
    else
    {
        TROUBLE();
        system("cls");
        SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | LightRed));
        cout<<"||===================================================||"<<endl<<"||";
        cout<<setw(29)<<"Файл пуст";
        cout<<setw(24)<<"||"<<endl<<"||===================================================||";
        SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));

        cout<<endl<<endl;
    }
}

void ShowInfoAppeal()
{
    if (S2[0].CodC!=NULL)
    {
        for (int j=0; j<=79; j++)
        {
            if (j==0 or j==79)
                cout<<"|";
            else
                cout<<"=";
        }

        cout<<endl;
        cout<<left<<setw(6)<<"| №";
        SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
        cout<<"|";
        SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | Magenta));
        cout<<left<<setw(13)<<"Предмет№1";
        SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
        cout<<"|";
        SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | Cyan));
        cout<<left<<setw(12)<<"Предмет№2";
        SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
        cout<<"|";
        SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | Blue));
        cout<<left<<setw(11)<<"Предмет№3";
        SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
        cout<<"|";
        SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | DarkGray));
        cout<<left<<setw(13)<<"Предмет№4";
        SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
        cout<<"|";
        SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | Magenta));
        cout<<right<<setw(4)<<"#1";
        SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
        cout<<"|";
        SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | Cyan));
        cout<<right<<setw(4)<<"#2";
        SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
        cout<<"|";
        SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | Blue));
        cout<<right<<setw(4)<<"#3";
        SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
        cout<<"|";
        SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | DarkGray));
        cout<<right<<setw(4)<<"#4";
        SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
        cout<<"|"<<endl;

        for (int j=0; j<=79; j++)
        {
            if (j==0 or j==79)
                cout<<"|";
            else
                cout<<"=";
        }
        cout<<endl;

        for (int i=0; i<KolichestvoAppeal; i++)
        {
            cout<<left<<"|"<<S2[i].CodC<<" ";
            SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
            cout<<"|";
            SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | LightMagenta));
            cout<<left<<setw(13)<<S2[i].D1;
            SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
            cout<<"|";
            SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | LightCyan));
            cout<<left<<setw(12)<<S2[i].D2;
            SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
            cout<<"|";
            SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | LightBlue));
            cout<<left<<setw(11)<<S2[i].D3;
            SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
            cout<<"|";
            SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | LightGray));
            cout<<left<<setw(13)<<S2[i].D4;
            SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
            cout<<"|";
            SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | LightMagenta));
            cout<<right<<setw(4)<<S2[i].Note1;
            SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
            cout<<"|";
            SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | LightCyan));
            cout<<right<<setw(4)<<S2[i].Note2;
            SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
            cout<<"|";
            SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | LightBlue));
            cout<<right<<setw(4)<<S2[i].Note3;
            SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
            cout<<"|";
            SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | LightGray));
            cout<<right<<setw(4)<<S2[i].Note4;
            SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
            cout<<"|"<<endl;
            for (int j=0; j<=79; j++)
            {
                if (j==0 or j==79)
                    cout<<"|";
                else
                    cout<<"_";
            }
            cout<<endl;
        }
    }
    else
    {
        TROUBLE();
        SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | LightRed));
        cout<<"||===================================================||"<<endl<<"||";
        cout<<setw(29)<<"Файл пуст";
        cout<<setw(24)<<"||"<<endl<<"||===================================================||";
        SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
    }

    cout<<endl<<endl;
}

void ShowInfoSchool()
{
    if (S[0].CodC!=NULL)
    {
        for (int j=0; j<=128; j++)
        {
            if (j==0 or j==128)
                cout<<"|";
            else
                cout<<"=";
        }
        cout<<endl;

        cout<<left<<setw(6)<<"| №";
        SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
        cout<<"|";
        SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | Yellow));
        cout<<left<<setw(11)<<"Фамилия";
        SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
        cout<<"|";
        SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | Yellow));
        cout<<left<<setw(11)<<"Имя";
        SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
        cout<<"|";
        SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | LightRed));
        cout<<left<<setw(17)<<"Уч.заведение";
        SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
        cout<<"|";
        SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | LightGreen));
        cout<<left<<setw(13)<<"Профиль";
        SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
        cout<<"|";
        SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | Magenta));
        cout<<left<<setw(12)<<"Предмет№1";
        SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
        cout<<"|";
        SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | Cyan));
        cout<<left<<setw(11)<<"Предмет№2";
        SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
        cout<<"|";
        SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | Blue));
        cout<<left<<setw(10)<<"Предмет№3";
        SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
        cout<<"|";
        SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | DarkGray));
        cout<<left<<setw(12)<<"Предмет№4";
        SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
        cout<<"|";
        SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | Magenta));
        cout<<right<<setw(3)<<"#1";
        SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
        cout<<"|";
        SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | Cyan));
        cout<<right<<setw(3)<<"#2";
        SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
        cout<<"|";
        SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | Blue));
        cout<<right<<setw(4)<<"#3";
        SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
        cout<<"|";
        SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | DarkGray));
        cout<<right<<setw(3)<<"#4";
        SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
        cout<<"|"<<endl;

        for (int j=0; j<=128; j++)
        {
            if (j==0 or j==128)
                cout<<"|";
            else
                cout<<"=";
        }
        cout<<endl;

        for (int i=0; i<KolichestvoSchool; i++)
        {
            cout<<"|"<<left<<S[i].CodC<<" ";
            cout<<"|"<<left<<setw(11)<<S[i].NumeC;
            cout<<"|"<<left<<setw(11)<<S[i].PrenE;
            cout<<"|"<<left<<setw(17)<<S[i].DenInst;
            cout<<"|"<<left<<setw(13)<<S[i].Profil<<"|";
            SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | LightMagenta));
            cout<<left<<setw(12)<<S[i].D1;
            SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
            cout<<"|";
            SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | LightCyan));
            cout<<left<<setw(11)<<S[i].D2;
            SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
            cout<<"|";
            SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | LightBlue));
            cout<<left<<setw(10)<<S[i].D3;
            SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
            cout<<"|";
            SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | LightGray));
            cout<<left<<setw(12)<<S[i].D4;
            SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
            cout<<"|";
            SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | LightMagenta));
            cout<<right<<setw(3)<<S[i].Note1;
            SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
            cout<<"|";
            SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | LightCyan));
            cout<<right<<setw(3)<<S[i].Note2;
            SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
            cout<<"|";
            SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | LightBlue));
            cout<<right<<setw(4)<<S[i].Note3;
            SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
            cout<<"|";
            SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | LightGray));
            cout<<right<<setw(3)<<S[i].Note4;
            SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
            cout<<"|"<<endl;

            for (int j=0; j<=128; j++)
            {
                if (j==0 or j==128)
                    cout<<"|";
                else
                    cout<<"_";
            }
            cout<<endl;
        }
    }
    else
    {
        TROUBLE();
        SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | LightRed));
        cout<<"||===================================================||"<<endl<<"||";
        cout<<setw(29)<<"Файл пуст";
        cout<<setw(24)<<"||"<<endl<<"||===================================================||";
        SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
    }
    cout<<endl<<endl;
}

void Rewrite1()
{
    ofstream f("BAC.txt");

    for (int i=0; i<KolichestvoStud; i++)
    {
        f<<S[i].CodC<<" "<<S[i].NumeC<<" "<<S[i].PrenE<<" "<<S[i].DenInst<<" "<<S[i].Profil<<" "<<S[i].D1<<" "<<S[i].D2<<" "<<S[i].D3<<" "<<S[i].D4<<" "<<S[i].Note1<<" "<<S[i].Note2<<" "<<S[i].Note3<<" "<<S[i].Note4<<endl;
    }
    f.close();
}

void Rewrite2()
{
    ofstream f("Contest.txt");

    for (int i=0; i<KolichestvoAppeal; i++)
    {
        f<<S2[i].CodC<<" "<<S2[i].D1<<" "<<S2[i].D2<<" "<<S2[i].D3<<" "<<S2[i].D4<<" "<<S2[i].Note1<<" "<<S2[i].Note2<<" "<<S2[i].Note3<<" "<<S2[i].Note4<<endl;
    }
    f.close();
}

void AddStudent()
{
    Student x;
    int poz;
    int Proverka=0;

    cout<<"Введите номер человека: ";
    while (!(cin>>x.CodC) or x.CodC<1000 or x.CodC>9999)
    {
        TROUBLE();
        SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | LightRed));
        cout<<"Вы допустили ошибку!(Код должен состоять из 4 цифр)"<<endl;
        SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
        cin.clear();
        cin.sync();
        cout<<"Введите номер человека: ";
    }
    cin.ignore();
    do
    {
        cout<<"Введите фамилию человека: ";
        gets(x.NumeC);
        Proverka = strlen (x.NumeC);
    }
    while (Proverka<3);
    do
    {
        cout<<"Введите имя человека: ";
        gets(x.PrenE);
        Proverka = strlen (x.PrenE);
    }
    while(Proverka<3);
    do
    {
        cout<<"Введите название учебного заведения: ";
        gets(x.DenInst);
        Proverka = strlen (x.DenInst);
    }
    while(Proverka<3);
    do
    {
        cout<<"Введите профиль, на котором учится человек: ";
        gets(x.Profil);
        Proverka = strlen (x.Profil);
    }
    while(Proverka<4);
    do
    {
        cout<<"Введите первый предмет: ";
        gets(x.D1);
        Proverka = strlen (x.D1);
    }
    while (Proverka<4);
    do
    {
        cout<<"Введите второй предмет: ";
        gets(x.D2);
        Proverka = strlen (x.D2);
    }
    while (Proverka<4);
    do
    {
        cout<<"Введите третий предмет: ";
        gets(x.D3);
        Proverka = strlen (x.D3);
    }
    while(Proverka<4);
    do
    {
        cout<<"Введите четвётый предмет: ";
        gets(x.D4);
        Proverka = strlen (x.D4);
    }
    while (Proverka<4);
    cout<<"Введите оценку за первый предмет: ";
    while (!(cin>>x.Note1) or x.Note1>10 or x.Note1<1)
    {
        TROUBLE();
        SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | LightRed));
        cout<<"Вы допустили ошибку!"<<endl;
        SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
        cin.clear();
        cin.sync();
        cout<<"Введите оценку: ";
    }
    cout<<"Введите оценку за второй предмет: ";
    while (!(cin>>x.Note2) or x.Note2>10 or x.Note2<1)
    {
        TROUBLE();
        SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | LightRed));
        cout<<"Вы допустили ошибку!"<<endl;
        SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
        cin.clear();
        cin.sync();
        cout<<"Введите оценку: ";
    }
    cout<<"Введите оценку за третий предмет: ";
    while (!(cin>>x.Note3) or x.Note3>10 or x.Note3<1)
    {
        TROUBLE();
        SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | LightRed));
        cout<<"Вы допустили ошибку!"<<endl;
        SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
        cin.clear();
        cin.sync();
        cout<<"Введите оценку: ";
    }
    cout<<"Введите оценку за четвётый предмет: ";
    while (!(cin>>x.Note4) or x.Note4>10 or x.Note4<1)
    {
        TROUBLE();
        SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | LightRed));
        cout<<"Вы допустили ошибку!"<<endl;
        SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
        cin.clear();
        cin.sync();
        cout<<"Введите оценку: ";
    }

    cout<<endl<<endl;
    cout<<"Здесь находятся " <<KolichestvoStud<<" студентов."<<endl<<endl;

    cout<<"Введите позицию: ";

    while (!(cin>>poz) or poz-1>KolichestvoStud or poz<0)
    {
        TROUBLE();
        SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | LightRed));
        cout<<"Вы ошиблись в вводе."<<endl;
        SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
        cin.clear();
        cin.sync();
        cout<<"Введите позицию: ";
    }
    poz--;

    KolichestvoStud++;
    if (poz>=0 and poz<KolichestvoStud)
    {
        for(int i=KolichestvoStud-1; i>=poz; i--)
            S[i]=S[i-1];
        S[poz]=x;
    }
    else if (KolichestvoStud==poz)
        S[poz]=x;

    Rewrite1();

}

void AddAppel()
{
    Appel x;
    int poz;
    int Proverka=0;

    cout<<"Введите номер человека: ";
    while (!(cin>>x.CodC) or x.CodC>9999 or x.CodC<1000)
    {
        TROUBLE();
        SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | LightRed));
        cout<<"Вы допустили ошибку!(Код должен состоять из 4 цифр)"<<endl;
        SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
        cin.clear();
        cin.sync();
        cout<<"Введите номер человека: ";
    }
    cin.ignore();
    do
    {
        cout<<"Введите первый предмет: ";
        gets(x.D1);
        Proverka = strlen (x.D1);
    }
    while (Proverka<4);
    do
    {
        cout<<"Введите второй предмет: ";
        gets(x.D2);
        Proverka = strlen (x.D2);
    }
    while (Proverka<4);
    do
    {
        cout<<"Введите третий предмет: ";
        gets(x.D3);
        Proverka = strlen (x.D3);
    }
    while(Proverka<4);
    do
    {
        cout<<"Введите четвётый предмет: ";
        gets(x.D4);
        Proverka = strlen (x.D4);
    }
    while (Proverka<4);
    cout<<"Введите оценку за первый предмет: ";
    while (!(cin>>x.Note1) or x.Note1>10 or x.Note1<1)
    {
        TROUBLE();
        SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | LightRed));
        cout<<"Вы допустили ошибку!"<<endl;
        SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
        cin.clear();
        cin.sync();
        cout<<"Введите оценку: ";
    }
    cout<<"Введите оценку за второй предмет: ";
    while (!(cin>>x.Note2) or x.Note2>10 or x.Note2<1)
    {
        TROUBLE();
        SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | LightRed));
        cout<<"Вы допустили ошибку!"<<endl;
        SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
        cin.clear();
        cin.sync();
        cout<<"Введите оценку: ";
    }
    cout<<"Введите оценку за третий предмет: ";
    while (!(cin>>x.Note3) or x.Note3>10 or x.Note3<1)
    {
        TROUBLE();
        SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | LightRed));
        cout<<"Вы допустили ошибку!"<<endl;
        SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
        cin.clear();
        cin.sync();
        cout<<"Введите оценку: ";
    }
    cout<<"Введите оценку за четвётый предмет: ";
    while (!(cin>>x.Note4) or x.Note4>10 or x.Note4<1)
    {
        TROUBLE();
        SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | LightRed));
        cout<<"Вы допустили ошибку!"<<endl;
        SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
        cin.clear();
        cin.sync();
        cout<<"Введите оценку: ";
    }

    cout<<endl<<endl;

    cout<<"Здесь находятся " <<KolichestvoAppeal<<" студентов, подавших на аппеляцию"<<endl<<endl;

    cout<<"Введите позицию: ";

    while (!(cin>>poz) or poz-1>KolichestvoAppeal or poz<0)
    {
        TROUBLE();
        SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | LightRed));
        cout<<"Здесь находятся " <<KolichestvoAppeal<<" студентов, подавших на аппеляцию"<<endl;
        SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
        cin.clear();
        cin.sync();
        cout<<"Введите позицию: ";
    }
    poz--;

    KolichestvoAppeal++;
    if (poz>=0 and poz<KolichestvoAppeal)
    {
        for(int i=KolichestvoAppeal-1; i>=poz; i--)
            S2[i]=S2[i-1];
        S2[poz]=x;
    }
    else if (KolichestvoAppeal==poz)
        S2[poz]=x;

    Rewrite2();

}


void DelStudent()
{
    bool Y = true;

    char Name[30];
    char Surname[30];

    cout<<"Введите фамилию человека: ";
    cin>>Surname;
    cout<<"Введите имя человека: ";
    cin>>Name;

    for (int j=0; j<KolichestvoStud; j++)
    {
        if(strcmp(Surname,S[j].NumeC)==0 and strcmp(Name,S[j].PrenE)==0)
        {
            for(int i=j; i<KolichestvoStud; i++)
            {
                S[i]=S[i+1];
                Y = false;
            }
            for (int t=0; t<KolichestvoAppeal; t++)
            {
                if(S[j].CodC==S2[t].CodC)
                {
                    if (t==0)
                        for (int k=0; k<KolichestvoAppeal; k++)
                            S2[k]=S2[k+1];

                    else
                        for (int k=t-1; k<KolichestvoAppeal; k++)
                            S2[k]=S2[k+1];

                    KolichestvoAppeal--;
                    Rewrite2();
                }
            }
            if (j!=0)
                j--;
            KolichestvoStud--;
            Rewrite1();
        }
    }

    if (Y)
    {
        TROUBLE();
        cout<<"||====================================================||"<<endl<<"||";
        cout<<setw(40)<<"Данный человек не найден.";
        cout<<setw(14)<<"||"<<endl<<"||====================================================||"<<endl<<endl;
    }
    else
    {
        cout<<"||====================================================||"<<endl<<"||";
        SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | LightGreen));
        cout<<setw(35)<<"Студент удалён!";
        SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
        cout<<setw(19)<<"||"<<endl<<"||====================================================||"<<endl<<endl;
    }
}


void DelAppel()
{
    bool Y = true;
    int Number;

    cout<<"Введите номер человека: ";
    while (!(cin>>Number) or Number>9999 or Number<1000)
    {
        TROUBLE();
        SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | LightRed));
        cout<<"Вы допустили ошибку!(Код должен состоять из 4 цифр)"<<endl;
        SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
        cin.clear();
        cin.sync();
        cout<<"Введите номер человека: ";
    }

    for (int j=0; j<KolichestvoAppeal; j++)
    {
        if(Number==S2[j].CodC)
        {
            for(int i=j; i<KolichestvoAppeal; i++)
            {
                S2[i]=S2[i+1];
                Y = false;
            }
            if (j!=0)
                j--;

            KolichestvoAppeal--;
            Rewrite2();
        }

    }

    if (Y)
    {
        TROUBLE();
        cout<<"||====================================================||"<<endl<<"||";
        cout<<setw(40)<<"Данный человек не найден.";
        cout<<setw(14)<<"||"<<endl<<"||====================================================||"<<endl<<endl;
    }

    else
    {
        cout<<"||====================================================||"<<endl<<"||";
        SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | LightGreen));
        cout<<setw(35)<<"Студент удалён!";
        SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
        cout<<setw(19)<<"||"<<endl<<"||====================================================||"<<endl<<endl;
    }
}


void SortStudent()
{
    for (int i=0; i<KolichestvoStud-1; i++)
    {
        for (int j=0; j<KolichestvoStud-1-i; j++)
        {
            if (strcmp(S[j].NumeC,S[j+1].NumeC)>0)
            {
                int temp = S[j].CodC;
                char Name[20];
                strcpy(Name,S[j].NumeC);
                char Surname[20];
                strcpy(Surname,S[j].PrenE);
                char Napravlenie[20];
                strcpy(Napravlenie,S[j].Profil);
                char DenInst1[30];
                strcpy(DenInst1,S[j].DenInst);
                char predmet1[20];
                strcpy(predmet1,S[j].D1);
                char predmet2[20];
                strcpy(predmet2,S[j].D2);
                char predmet3[20];
                strcpy(predmet3,S[j].D3);
                char predmet4[20];
                strcpy(predmet4,S[j].D4);
                int o1=S[j].Note1;
                int o2=S[j].Note2;
                int o3=S[j].Note3;
                int o4=S[j].Note4;

                S[j]=S[j+1];

                S[j+1].CodC=temp;
                strcpy (S[j+1].NumeC,Name);
                strcpy (S[j+1].PrenE,Surname);
                strcpy (S[j+1].DenInst,DenInst1);
                strcpy (S[j+1].Profil,Napravlenie);
                strcpy (S[j+1].D1, predmet1);
                strcpy (S[j+1].D2, predmet2);
                strcpy (S[j+1].D3, predmet3);
                strcpy (S[j+1].D4, predmet4);
                S[j+1].Note1 = o1;
                S[j+1].Note2 = o2;
                S[j+1].Note3 = o3;
                S[j+1].Note4 = o4;
            }
            else if (strcmp(S[j].NumeC,S[j+1].NumeC)==0)
            {
                if(strcmp(S[j].PrenE,S[j+1].PrenE)>0)
                {
                    int temp = S[j].CodC;
                    char Name[20];
                    strcpy(Name,S[j].NumeC);
                    char Surname[20];
                    strcpy(Surname,S[j].PrenE);
                    char Napravlenie[20];
                    strcpy(Napravlenie,S[j].Profil);
                    char DenInst1[30];
                    strcpy(DenInst1,S[j].DenInst);
                    char predmet1[20];
                    strcpy(predmet1,S[j].D1);
                    char predmet2[20];
                    strcpy(predmet2,S[j].D2);
                    char predmet3[20];
                    strcpy(predmet3,S[j].D3);
                    char predmet4[20];
                    strcpy(predmet4,S[j].D4);
                    int o1=S[j].Note1;
                    int o2=S[j].Note2;
                    int o3=S[j].Note3;
                    int o4=S[j].Note4;

                    S[j]=S[j+1];

                    S[j+1].CodC=temp;
                    strcpy (S[j+1].NumeC,Name);
                    strcpy (S[j+1].PrenE,Surname);
                    strcpy (S[j+1].DenInst,DenInst1);
                    strcpy (S[j+1].Profil,Napravlenie);
                    strcpy (S[j+1].D1, predmet1);
                    strcpy (S[j+1].D2, predmet2);
                    strcpy (S[j+1].D3, predmet3);
                    strcpy (S[j+1].D4, predmet4);
                    S[j+1].Note1 = o1;
                    S[j+1].Note2 = o2;
                    S[j+1].Note3 = o3;
                    S[j+1].Note4 = o4;
                }
            }
        }
    }
}

void OutputR()
{
    for (int j=0; j<=128; j++)
    {
        if (j==0 or j==128)
            cout<<"|";
        else
            cout<<"=";
    }
    cout<<endl;

    cout<<left<<setw(6)<<"| №"<<"|";
    SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | Yellow));
    cout<<left<<setw(11)<<"Фамилия";
    SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
    cout<<"|";
    SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | Yellow));
    cout<<left<<setw(11)<<"Имя";
    SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
    cout<<"|";
    SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | LightRed));
    cout<<left<<setw(17)<<"Уч.заведение";
    SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
    cout<<"|";
    SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | LightGreen));
    cout<<left<<setw(13)<<"Профиль";
    SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
    cout<<"|";
    SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | Magenta));
    cout<<left<<setw(12)<<"Предмет№1";
    SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
    cout<<"|";
    SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | Cyan));
    cout<<left<<setw(11)<<"Предмет№2";
    SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
    cout<<"|";
    SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | Blue));
    cout<<left<<setw(10)<<"Предмет№3";
    SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
    cout<<"|";
    SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | DarkGray));
    cout<<left<<setw(12)<<"Предмет№4";
    SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
    cout<<"|";
    SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | Magenta));
    cout<<right<<setw(3)<<"#1";
    SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
    cout<<"|";
    SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | Cyan));
    cout<<right<<setw(3)<<"#2";
    SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
    cout<<"|";
    SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | Blue));
    cout<<right<<setw(4)<<"#3";
    SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
    cout<<"|";
    SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | DarkGray));
    cout<<right<<setw(3)<<"#4";
    SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
    cout<<"|"<<endl;

    for (int j=0; j<=128; j++)
    {
        if (j==0 or j==128)
            cout<<"|";
        else
            cout<<"=";
    }
    cout<<endl;

    for (int i=0; i<KolichestvoStud; i++)
    {
        if(strcmp(S[i].Profil,"Реальный")==0)
        {
            cout<<"|"<<left<<S[i].CodC<<" ";
            cout<<"|"<<left<<setw(11)<<S[i].NumeC;
            cout<<"|"<<left<<setw(11)<<S[i].PrenE;
            cout<<"|"<<left<<setw(17)<<S[i].DenInst;
            cout<<"|"<<left<<setw(13)<<S[i].Profil<<"|";
            SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | LightMagenta));
            cout<<left<<setw(12)<<S[i].D1;
            SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
            cout<<"|";
            SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | LightCyan));
            cout<<left<<setw(11)<<S[i].D2;
            SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
            cout<<"|";
            SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | LightBlue));
            cout<<left<<setw(10)<<S[i].D3;
            SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
            cout<<"|";
            SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | LightGray));
            cout<<left<<setw(12)<<S[i].D4;
            SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
            cout<<"|";
            SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | LightMagenta));
            cout<<right<<setw(3)<<S[i].Note1;
            SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
            cout<<"|";
            SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | LightCyan));
            cout<<right<<setw(3)<<S[i].Note2;
            SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
            cout<<"|";
            SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | LightBlue));
            cout<<right<<setw(4)<<S[i].Note3;
            SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
            cout<<"|";
            SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | LightGray));
            cout<<right<<setw(3)<<S[i].Note4;
            SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
            cout<<"|"<<endl;

            for (int j=0; j<=128; j++)
            {
                if (j==0 or j==128)
                    cout<<"|";
                else
                    cout<<"_";
            }
            cout<<endl;
        }
    }
    cout<<endl<<endl;
}


void OutputG()
{
    for (int j=0; j<=128; j++)
    {
        if (j==0 or j==128)
            cout<<"|";
        else
            cout<<"=";
    }
    cout<<endl;

    cout<<left<<setw(6)<<"| №";
    SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
    cout<<"|";
    SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | Yellow));
    cout<<left<<setw(11)<<"Фамилия";
    SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
    cout<<"|";
    SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | Yellow));
    cout<<left<<setw(11)<<"Имя";
    SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
    cout<<"|";
    SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | LightRed));
    cout<<left<<setw(17)<<"Уч.заведение";
    SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
    cout<<"|";
    SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | LightGreen));
    cout<<left<<setw(13)<<"Профиль";
    SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
    cout<<"|";
    SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | Magenta));
    cout<<left<<setw(12)<<"Предмет№1";
    SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
    cout<<"|";
    SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | Cyan));
    cout<<left<<setw(11)<<"Предмет№2";
    SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
    cout<<"|";
    SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | Blue));
    cout<<left<<setw(10)<<"Предмет№3";
    SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
    cout<<"|";
    SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | DarkGray));
    cout<<left<<setw(12)<<"Предмет№4";
    SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
    cout<<"|";
    SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | Magenta));
    cout<<right<<setw(3)<<"#1";
    SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
    cout<<"|";
    SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | Cyan));
    cout<<right<<setw(3)<<"#2";
    SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
    cout<<"|";
    SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | Blue));
    cout<<right<<setw(4)<<"#3";
    SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
    cout<<"|";
    SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | DarkGray));
    cout<<right<<setw(3)<<"#4";
    SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
    cout<<"|"<<endl;

    for (int j=0; j<=128; j++)
    {
        if (j==0 or j==128)
            cout<<"|";
        else
            cout<<"=";
    }
    cout<<endl;

    for (int i=0; i<KolichestvoStud; i++)
    {
        if(strcmp(S[i].Profil,"Гуманитарий")==0)
        {
            cout<<"|"<<left<<S[i].CodC<<" ";
            cout<<"|"<<left<<setw(11)<<S[i].NumeC;
            cout<<"|"<<left<<setw(11)<<S[i].PrenE;
            cout<<"|"<<left<<setw(17)<<S[i].DenInst;
            cout<<"|"<<left<<setw(13)<<S[i].Profil<<"|";
            SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | LightMagenta));
            cout<<left<<setw(12)<<S[i].D1;
            SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
            cout<<"|";
            SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | LightCyan));
            cout<<left<<setw(11)<<S[i].D2;
            SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
            cout<<"|";
            SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | LightBlue));
            cout<<left<<setw(10)<<S[i].D3;
            SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
            cout<<"|";
            SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | LightGray));
            cout<<left<<setw(12)<<S[i].D4;
            SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
            cout<<"|";
            SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | LightMagenta));
            cout<<right<<setw(3)<<S[i].Note1;
            SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
            cout<<"|";
            SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | LightCyan));
            cout<<right<<setw(3)<<S[i].Note2;
            SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
            cout<<"|";
            SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | LightBlue));
            cout<<right<<setw(4)<<S[i].Note3;
            SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
            cout<<"|";
            SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | LightGray));
            cout<<right<<setw(3)<<S[i].Note4;
            SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
            cout<<"|"<<endl;

            for (int j=0; j<=128; j++)
            {
                if (j==0 or j==128)
                    cout<<"|";
                else
                    cout<<"_";
            }
            cout<<endl;
        }
    }
    cout<<endl<<endl;
}

void CorrectionNotes()
{
    for (int i=0; i<KolichestvoStud; i++)
    {
        for (int j=0; j<KolichestvoAppeal; j++)
        {
            if(S[i].CodC==S2[j].CodC)
            {
                S[i].Note1 = S2[j].Note1;
                S[i].Note2 = S2[j].Note2;
                S[i].Note3 = S2[j].Note3;
                S[i].Note4 = S2[j].Note4;
            }
        }
    }
    Rewrite1();
}

void SchoolFile()
{
    ofstream f("CandInst.txt");
    bool Y = true;
    int Proverka=0;
    char School[20];

    do
    {
        cout<<"Введите название школьнокого учереждения: ";
        cin>>School;
        Proverka = strlen (School);
    }
    while(Proverka<3);

    for (int i=0; i<KolichestvoStud; i++)
    {
        if (strcmp(School,S[i].DenInst)==0)
        {
            Y = false;
            f<<S[i].CodC<<" "<<S[i].NumeC<<" "<<S[i].PrenE<<" "<<S[i].DenInst<<" "<<S[i].Profil<<" "<<S[i].D1<<" "<<S[i].D2<<" "<<S[i].D3<<" "<<S[i].D4<<" "<<S[i].Note1<<" "<<S[i].Note2<<" "<<S[i].Note3<<" "<<S[i].Note4<<endl;
        }
    }
    f.close();

    if(Y)
    {
        TROUBLE();
        cout<<"||===================================================||"<<endl<<"||";
        SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | LightRed));
        cout<<"Такой школы не найдено! Все данные из файла удалены";
        SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
        cout<<setw(2)<<"||"<<endl<<"||===================================================||"<<endl;
    }
    else
    {
        cout<<"||===================================================||"<<endl<<"||";
        SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | LightGreen));
        cout<<setw(45)<<"Данные в файл были удачно загруженны.";
        SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
        cout<<setw(8)<<"||"<<endl<<"||===================================================||"<<endl;
    }
}

void BadNote1()
{
    int k=0;//Количество учеников с отрицательным баллом
    int k1=0;//Количество отрицательных баллов
    int t;//Ученик с самым большим количеством отрицательных баллов
    int pmax=0;//Позиция максимального элемента
    int max=0;
    for (int j=0; j<=128; j++)
    {
        if (j==0 or j==128)
            cout<<"|";
        else
            cout<<"=";
    }
    cout<<endl;

    cout<<left<<setw(6)<<"| №";
    SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
    cout<<"|";
    SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | Yellow));
    cout<<left<<setw(11)<<"Фамилия";
    SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
    cout<<"|";
    SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | Yellow));
    cout<<left<<setw(11)<<"Имя";
    SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
    cout<<"|";
    SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | LightRed));
    cout<<left<<setw(17)<<"Уч.заведение";
    SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
    cout<<"|";
    SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | LightGreen));
    cout<<left<<setw(13)<<"Профиль";
    SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
    cout<<"|"<<left<<setw(12)<<"Предмет№1";
    cout<<"|"<<left<<setw(11)<<"Предмет№2";
    cout<<"|"<<left<<setw(10)<<"Предмет№3";
    cout<<"|"<<left<<setw(12)<<"Предмет№4";
    cout<<"|"<<right<<setw(3)<<"#1";
    cout<<"|"<<right<<setw(3)<<"#2";
    cout<<"|"<<right<<setw(4)<<"#3";
    cout<<"|"<<right<<setw(3)<<"#4";
    cout<<"|"<<endl;

    for (int j=0; j<=128; j++)
    {
        if (j==0 or j==128)
            cout<<"|";
        else
            cout<<"=";
    }
    cout<<endl;

    for (int j=0; j<KolichestvoStud; j++)
    {
        t=0;
        if(S[j].Note1<5 or S[j].Note2<5 or S[j].Note3<5 or S[j].Note4<5)
        {
            k++;
            if (S[j].Note1<5)
            {
                k1++;
                t++;
            }
            if (S[j].Note2<5)
            {
                k1++;
                t++;
            }
            if (S[j].Note3<5)
            {
                k1++;
                t++;
            }
            if (S[j].Note4<5)
            {
                k1++;
                t++;
            }

            for (int i=0; i<k; i++)
            {
                if(t>max)
                {
                    pmax=j;
                    max=t;
                }
            }

            SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
            cout<<"|"<<left<<S[j].CodC<<" ";
            cout<<"|"<<left<<setw(11)<<S[j].NumeC;
            cout<<"|"<<left<<setw(11)<<S[j].PrenE;
            cout<<"|"<<left<<setw(17)<<S[j].DenInst;
            cout<<"|"<<left<<setw(13)<<S[j].Profil<<"|";
            if (S[j].Note1<5)
                SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | LightRed));
            else
                SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
            cout<<left<<setw(12)<<S[j].D1;
            SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
            cout<<"|";
            if (S[j].Note2<5)
                SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | LightRed));
            else
                SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
            cout<<left<<setw(11)<<S[j].D2;
            SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
            cout<<"|";
            if (S[j].Note3<5)
                SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | LightRed));
            else
                SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
            cout<<left<<setw(10)<<S[j].D3;
            SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
            cout<<"|";
            if (S[j].Note4<5)
                SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | LightRed));
            else
                SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
            cout<<left<<setw(12)<<S[j].D4;
            SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
            cout<<"|";
            if (S[j].Note1<5)
                SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | LightRed));
            else
                SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
            cout<<right<<setw(3)<<S[j].Note1;
            SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
            cout<<"|";
            if (S[j].Note2<5)
                SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | LightRed));
            else
                SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
            cout<<right<<setw(3)<<S[j].Note2;
            SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
            cout<<"|";
            if (S[j].Note3<5)
                SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | LightRed));
            else
                SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
            cout<<right<<setw(4)<<S[j].Note3;
            SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
            cout<<"|";
            if (S[j].Note4<5)
                SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | LightRed));
            else
                SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
            cout<<right<<setw(3)<<S[j].Note4;
            SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
            cout<<"|"<<endl;
            for (int j=0; j<=128; j++)
            {
                if (j==0 or j==128)
                    cout<<"|";
                else
                    cout<<"_";
            }
            cout<<endl;
        }
    }

    SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | LightGreen));
    cout<<endl<<endl<<"Общее количество учеников с отрицательным баллом: ";
    SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | LightRed));
    cout<<k;
    SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | LightGreen));
    cout<<endl<<endl<<"Общее количество отрицательных баллов: ";
    SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | LightRed));
    cout<<k1;
    SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | LightGreen));
    cout<<endl<<endl<<"Самое большое количество отрицательных баллов у: ";
    SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | Yellow));
    if (k==0)
        cout<<"Не обнаруженно";
    else
        cout<<S[pmax].NumeC<<" "<<S[pmax].PrenE;
    SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
    cout<<endl<<endl;
}


void BadNote2()
{
    int k=0;//Количество учеников с отрицательным баллом
    int k1=0;//Количество отрицательных баллов
    int t;//Ученик с самым большим количеством отрицательных баллов
    int pmax=0;//Позиция максимального элемента
    int max=0;
    for (int j=0; j<=72; j++)
    {
        if (j==0 or j==72)
            cout<<"|";
        else
            cout<<"=";
    }
    cout<<endl;

    cout<<left<<setw(6)<<"| №";
    cout<<"|"<<left<<setw(12)<<"Предмет№1";
    cout<<"|"<<left<<setw(11)<<"Предмет№2";
    cout<<"|"<<left<<setw(10)<<"Предмет№3";
    cout<<"|"<<left<<setw(12)<<"Предмет№4";
    cout<<"|"<<right<<setw(3)<<"#1";
    cout<<"|"<<right<<setw(3)<<"#2";
    cout<<"|"<<right<<setw(4)<<"#3";
    cout<<"|"<<right<<setw(3)<<"#4";
    cout<<"|"<<endl;

    for (int j=0; j<=72; j++)
    {
        if (j==0 or j==72)
            cout<<"|";
        else
            cout<<"=";
    }
    cout<<endl;

    for (int j=0; j<KolichestvoAppeal; j++)
    {
        t=0;
        if(S2[j].Note1<5 or S2[j].Note2<5 or S2[j].Note3<5 or S2[j].Note4<5)
        {
            k++;
            if (S2[j].Note1<5)
            {
                k1++;
                t++;
            }
            if (S2[j].Note2<5)
            {
                k1++;
                t++;
            }
            if (S2[j].Note3<5)
            {
                k1++;
                t++;
            }
            if (S2[j].Note4<5)
            {
                k1++;
                t++;
            }

            for (int i=0; i<k; i++)
            {
                if(t>max)
                {
                    pmax=j;
                    max=t;
                }
            }

            cout<<"|"<<left<<S2[j].CodC<<" |";
            if (S2[j].Note1<5)
                SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | LightRed));
            else
                SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
            cout<<left<<setw(12)<<S2[j].D1;
            SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
            cout<<"|";
            if (S2[j].Note2<5)
                SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | LightRed));
            else
                SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
            cout<<left<<setw(11)<<S2[j].D2;
            SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
            cout<<"|";
            if (S2[j].Note3<5)
                SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | LightRed));
            else
                SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
            cout<<left<<setw(10)<<S2[j].D3;
            SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
            cout<<"|";
            if (S2[j].Note4<5)
                SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | LightRed));
            else
                SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
            cout<<left<<setw(12)<<S2[j].D4;
            SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
            cout<<"|";
            if (S2[j].Note1<5)
                SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | LightRed));
            else
                SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
            cout<<right<<setw(3)<<S2[j].Note1;
            SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
            cout<<"|";
            if (S2[j].Note2<5)
                SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | LightRed));
            else
                SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
            cout<<right<<setw(3)<<S2[j].Note2;
            SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
            cout<<"|";
            if (S2[j].Note3<5)
                SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | LightRed));
            else
                SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
            cout<<right<<setw(4)<<S2[j].Note3;
            SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
            cout<<"|";
            if (S2[j].Note4<5)
                SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | LightRed));
            else
                SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
            cout<<right<<setw(3)<<S2[j].Note4;
            SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
            cout<<"|"<<endl;
            for (int j=0; j<=72; j++)
            {
                if (j==0 or j==72)
                    cout<<"|";
                else
                    cout<<"_";
            }
            cout<<endl;
        }
    }

    SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | LightGreen));
    cout<<endl<<endl<<"Общее количество учеников с отрицательным баллом: ";
    SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | LightRed));
    cout<<k;
    SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | LightGreen));
    cout<<endl<<endl<<"Общее количество отрицательных баллов: ";
    SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | LightRed));
    cout<<k1;
    SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | LightGreen));
    cout<<endl<<endl<<"Самое большое количество отрицательных баллов у: ";
    SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | Yellow));
    if (k==0)
        cout<<"Не обнаруженно";
    else
        cout<<S2[pmax].CodC;
    SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
    cout<<endl<<endl;
}

void MediumNote1()
{
    char School[20];
    int Proverka = 0;

    do
    {
        cout<<"Введите название учебного заведения: ";
        cin>>School;
        Proverka = strlen (School);
    }
    while(Proverka<3);

    float Sum=0;
    int k=0;

    for (int i=0; i<KolichestvoStud; i++)
    {
        if(strcmp(School,S[i].DenInst)==0)
        {
            k+=4;
            Sum += (S[i].Note1 + S[i].Note2 + S[i].Note3 + S[i].Note4)*1.0;
        }
    }

    cout<<endl<<endl;

    if (k!=0)
    {
        cout<<"||====================================================||"<<endl<<"||";
        SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | LightGreen));
        cout<<"Средний балл за все экзамены: ";
        SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | Yellow));
        cout<<setprecision(3)<<(Sum/k)*1.0;
        SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
        cout<<setw(20)<<"||"<<endl<<"||====================================================||";
        cout<<endl<<endl;
    }
    else
    {
        TROUBLE();
        cout<<"||====================================================||"<<endl<<"||";
        cout<<setw(45)<<"Данное учебное заведение не найдено.";
        cout<<setw(9)<<"||"<<endl<<"||====================================================||"<<endl<<endl;
    }
}

void StupAppeal()
{

    for (int j=0; j<=128; j++)
    {
        if (j==0 or j==128)
            cout<<"|";
        else
            cout<<"=";
    }
    cout<<endl;

    cout<<left<<setw(6)<<"| №";
    SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
    cout<<"|";
    SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | Yellow));
    cout<<left<<setw(11)<<"Фамилия";
    SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
    cout<<"|";
    SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | Yellow));
    cout<<left<<setw(11)<<"Имя";
    SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
    cout<<"|";
    SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | LightRed));
    cout<<left<<setw(17)<<"Уч.заведение";
    SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
    cout<<"|";
    SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | LightGreen));
    cout<<left<<setw(13)<<"Профиль";
    SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
    cout<<"|";
    SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | Magenta));
    cout<<left<<setw(12)<<"Предмет№1";
    SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
    cout<<"|";
    SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | Cyan));
    cout<<left<<setw(11)<<"Предмет№2";
    SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
    cout<<"|";
    SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | Blue));
    cout<<left<<setw(10)<<"Предмет№3";
    SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
    cout<<"|";
    SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | DarkGray));
    cout<<left<<setw(12)<<"Предмет№4";
    SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
    cout<<"|";
    SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | Magenta));
    cout<<right<<setw(3)<<"#1";
    SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
    cout<<"|";
    SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | Cyan));
    cout<<right<<setw(3)<<"#2";
    SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
    cout<<"|";
    SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | Blue));
    cout<<right<<setw(4)<<"#3";
    SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
    cout<<"|";
    SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | DarkGray));
    cout<<right<<setw(3)<<"#4";
    SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
    cout<<"|"<<endl;

    for (int j=0; j<=128; j++)
    {
        if (j==0 or j==128)
            cout<<"|";
        else
            cout<<"=";
    }
    cout<<endl;

    for (int j=0; j<KolichestvoAppeal; j++)
        for (int i=0; i<KolichestvoStud; i++)
        {
            if(S[i].CodC==S2[j].CodC)
            {
                cout<<"|"<<left<<S[i].CodC<<" ";
                cout<<"|"<<left<<setw(11)<<S[i].NumeC;
                cout<<"|"<<left<<setw(11)<<S[i].PrenE;
                cout<<"|"<<left<<setw(17)<<S[i].DenInst;
                cout<<"|"<<left<<setw(13)<<S[i].Profil<<"|";
                SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | LightMagenta));
                cout<<left<<setw(12)<<S[i].D1;
                SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
                cout<<"|";
                SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | LightCyan));
                cout<<left<<setw(11)<<S[i].D2;
                SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
                cout<<"|";
                SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | LightBlue));
                cout<<left<<setw(10)<<S[i].D3;
                SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
                cout<<"|";
                SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | LightGray));
                cout<<left<<setw(12)<<S[i].D4;
                SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
                cout<<"|";
                SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | LightMagenta));
                cout<<right<<setw(3)<<S[i].Note1;
                SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
                cout<<"|";
                SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | LightCyan));
                cout<<right<<setw(3)<<S[i].Note2;
                SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
                cout<<"|";
                SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | LightBlue));
                cout<<right<<setw(4)<<S[i].Note3;
                SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
                cout<<"|";
                SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | LightGray));
                cout<<right<<setw(3)<<S[i].Note4;
                SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
                cout<<"|"<<endl;

                for (int j=0; j<=128; j++)
                {
                    if (j==0 or j==128)
                        cout<<"|";
                    else
                        cout<<"_";
                }
                cout<<endl;
            }
        }
    cout<<endl<<endl;
}
