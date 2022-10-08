//Задача о лабиринте

#include <iostream>
#include <fstream>
#include <cmath>
#include <windows.h>

using namespace std;

int Labyrint[10][10];
int n, m;
int StartI, StartJ;
int EndI, EndJ;
int CurrentI, CurrentJ;
ofstream g("HrubeOut.txt");

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
enum ConsoleColor
{
    Black = 0,
    Blue = 1,
    Green = 2,
    Cyan = 3,
    Red = 4,
    Magenta = 5,
    Brown = 6,
    LightGray = 7,
    DarkGray = 8,
    LightBlue = 9,
    LightGreen = 10,
    LightCyan = 11,
    LightRed = 12,
    LightMagenta = 13,
    Yellow = 14,
    White = 15
};

void CreateLabyrint ()
{
    ifstream f("HrubeIn.txt");

    f>>n>>m;

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            f>>Labyrint[i][j];
        }
    }

    f.close();
}

bool ExistElement()
{
    if(Labyrint[CurrentI+1][CurrentJ]==0 and CurrentI<n-1 or Labyrint[CurrentI+1][CurrentJ]==3)
        return true;

    else if(Labyrint[CurrentI-1][CurrentJ]==0 and CurrentI>0 or Labyrint[CurrentI-1][CurrentJ]==3)
        return true;

    else if(Labyrint[CurrentI][CurrentJ+1]==0 and CurrentJ<m-1 or Labyrint[CurrentI][CurrentJ+1]==3)
        return true;

    else if(Labyrint[CurrentI][CurrentJ-1]==0 and CurrentJ>0 or Labyrint[CurrentI][CurrentJ-1]==3)
        return true;
    return false;
}


void StartEndPoz()
{
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
        {
            if(Labyrint[i][j]==2)
            {
                StartI=i;
                StartJ=j;
            }
            if(Labyrint[i][j]==3)
            {
                EndI=i;
                EndJ=j;
            }
        }
}


void SelectElement()
{

    if(Labyrint[CurrentI+1][CurrentJ]==0 and abs(EndI-CurrentI-1)<abs(EndI-CurrentI) and CurrentI<n-1 or Labyrint[CurrentI+1][CurrentJ]==3)
    {
        cout<<"Робот совершает ход на позицию: "<<CurrentI+1<<" "<<CurrentJ<<endl;
        g<<"Вниз"<<endl;
        Labyrint[CurrentI][CurrentJ]=5;
        CurrentI++;
    }
    else if(Labyrint[CurrentI-1][CurrentJ]==0 and abs(EndI-CurrentI+1)<abs(EndI-CurrentI) and CurrentI>0 or Labyrint[CurrentI-1][CurrentJ]==3)
    {
        cout<<"Робот совершает ход на позицию: "<<CurrentI-1<<" "<<CurrentJ<<endl;
        g<<"Вверх"<<endl;
        Labyrint[CurrentI][CurrentJ]=5;
        CurrentI--;
    }
    else if(Labyrint[CurrentI][CurrentJ+1]==0 and abs(EndJ-CurrentJ-1)<abs(EndJ-CurrentJ) and CurrentJ<m-1 or Labyrint[CurrentI][CurrentJ+1]==3)
    {
        cout<<"Робот совершает ход на позицию: "<<CurrentI<<" "<<CurrentJ+1<<endl;
        g<<"Направо"<<endl;
        Labyrint[CurrentI][CurrentJ]=5;
        CurrentJ++;
    }
    else if(Labyrint[CurrentI][CurrentJ-1]==0 and abs(EndJ-CurrentJ+1)<abs(EndJ-CurrentJ) and CurrentJ>0 or Labyrint[CurrentI][CurrentJ-1]==3)
    {
        cout<<"Робот совершает ход на позицию: "<<CurrentI<<" "<<CurrentJ-1<<endl;
        g<<"Налево"<<endl;
        Labyrint[CurrentI][CurrentJ]=5;
        CurrentJ--;
    }
    else if(Labyrint[CurrentI+1][CurrentJ]==0 and CurrentI<n-1 or Labyrint[CurrentI+1][CurrentJ]==3)
    {
        cout<<"Робот совершает ход на позицию: "<<CurrentI+1<<" "<<CurrentJ<<endl;
        g<<"Вниз"<<endl;
        Labyrint[CurrentI][CurrentJ]=5;
        CurrentI++;
    }
    else if(Labyrint[CurrentI-1][CurrentJ]==0 and CurrentI>0 or Labyrint[CurrentI-1][CurrentJ]==3)
    {
        cout<<"Робот совершает ход на позицию: "<<CurrentI-1<<" "<<CurrentJ<<endl;
        g<<"Вверх"<<endl;
        Labyrint[CurrentI][CurrentJ]=5;
        CurrentI--;
    }
    else if(Labyrint[CurrentI][CurrentJ+1]==0 and CurrentJ<m-1 or Labyrint[CurrentI][CurrentJ+1]==3)
    {
        cout<<"Робот совершает ход на позицию: "<<CurrentI<<" "<<CurrentJ+1<<endl;
        g<<"Направо"<<endl;
        Labyrint[CurrentI][CurrentJ]=5;
        CurrentJ++;
    }
    else if(Labyrint[CurrentI][CurrentJ-1]==0 and CurrentJ>0 or Labyrint[CurrentI][CurrentJ-1]==3)
    {
        cout<<"Робот совершает ход на позицию: "<<CurrentI<<" "<<CurrentJ-1<<endl;
        g<<"Налево"<<endl;
        Labyrint[CurrentI][CurrentJ]=5;
        CurrentJ--;
    }

    if(Labyrint[CurrentI+1][CurrentJ]==1 and Labyrint[CurrentI-1][CurrentJ]==1 and Labyrint[CurrentI][CurrentJ+1]==1 and Labyrint[CurrentI][CurrentJ-1]==1)
    {
        g<<"Робот попал в тупик"<<endl;
    }

}

void Show()
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(Labyrint[i][j]==0) SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | LightGreen));
            if(Labyrint[i][j]==1) SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | LightBlue));
            if(Labyrint[i][j]==5) SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | LightRed));
            //if(Labyrint[i][j]==2) SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | LightCyan));
            if(Labyrint[i][j]==3) SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | LightMagenta));
            cout<<Labyrint[i][j]<<" ";
            SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
        }
        cout<<endl;
    }
}


int main()
{
    setlocale(LC_ALL,"RUS");

    CreateLabyrint();
    StartEndPoz();

    CurrentI = StartI;
    CurrentJ = StartJ;

    while(ExistElement())
    {
        SelectElement();
    }
    g.close();

    cout<<endl<<endl;
    Show();


}
