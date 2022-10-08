//Под словом понимается любая непустая последовательность из букв латинского алфавита.
//Напишите программу, которая формирует список слов, встречающихся в текстовом файле, и считает, сколько раз появляется каждое слово.
//Рассмотрите следующие случаи:
//a) слова вставляются в список в порядке их первого появления в тексте;
//б) слова вставляются в список в алфавитном порядке.
//Прописные и строчные буквы считаются идентичными.

#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

using namespace std;

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

struct Text
{
    char Words[50];
    int Repeats;
    Text *next;
}*bg;


//Создаём новый файл

void CreateFile()
{
    ofstream g("Words.txt");

    char ch[50];
    char SaveWord[50];

    SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | LightRed));
    cout<<"If you want to stop typing, enter \"STOP\"."<<endl;
    SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
    SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | LightGreen));
    cout<<"To enter the word, press Enter."<<endl;
    SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));

    while(strcmp(ch,"stop")!=0)
    {
        cout<<"Input word: ";
        cin>>ch;

        strcpy(SaveWord,ch);

        for(int i=0; i<strlen(ch); i++)
        {
            ch[i]=tolower(ch[i]);
        }

        if(strcmp(ch,"stop")!=0)
            g<<SaveWord<<endl;
    }
    g.close();

}


Text* FirstFoundFirsAdd()
{
    char TXTWord[50];
    char SaveWord[50];
    int n;

    Text *cr,*prv,*r;

    ifstream f("Words.txt");

    while(!f.eof())
    {
        f>>TXTWord;

        n=strlen(TXTWord);

        for(int i=0; i<n; i++)
        {
            //Избавляемся от цифр в слове
            if(isdigit(TXTWord[i]))
            {
                for(int j=i; j<n; j++)
                {
                    TXTWord[j]=TXTWord[j+1];
                }
                n--;
                i--;
            }

            //Избавляемся от знаков припенания
            if(ispunct(TXTWord[i]))
            {
                for(int j=i; j<n; j++)
                {
                    TXTWord[j]=TXTWord[j+1];
                }
                n--;
                i--;
            }

            //Переводим все слова в нижний регистр
            TXTWord[i]=tolower(TXTWord[i]);
        }

        if(strlen(TXTWord)!=0)
        {
            r = new Text;
            bool exist = false;
            strcpy(r->Words,TXTWord);
            r->Repeats=1;


            if(bg==NULL or strcmp(bg->Words,r->Words)==0)
            {
                if(bg==NULL)
                {
                    bg=r;
                    bg->next=NULL;
                    cr=bg;
                    prv=cr;
                }
                else if(bg!=NULL and strcmp(bg->Words,r->Words)==0)
                {

                    bg->Repeats+=1;
                    delete r;
                }
            }
            else
            {
                cr=bg;
                while(cr!=NULL)
                {
                    if(strcmp(r->Words,cr->Words)==0)
                    {
                        cr->Repeats+=1;
                        exist=true;
                        delete r;
                    }
                    cr=cr->next;
                }
                if(!exist)
                {
                    prv->next=r;
                    cr=r;
                    prv=cr;
                }

            }
        }
    }
    f.close();
    return bg;
}

void Show(Text *bg)
{
    Text *cr;

    cr=bg;

    if(cr==NULL)
    {
        cout<<"The list is empty"<<endl;
    }
    else
        while(cr!=NULL)
        {
            cout<<cr->Words<<" - ";
            cout<<cr->Repeats<<endl;
            cr=cr->next;
        }
}

Text* Sort(Text *bg)
{
    Text *cr, *nxt, *prv;

    char Text[50];
    int Repeat=0;
    int k=0;

    cr=bg;
    int c=0;
    while(cr!=NULL)
    {
        c++;
        cr=cr->next;
    }

    cr=bg;
    for(int i=0; i<c-1; i++)
    {
        k=0;
        cr=bg;
        prv=cr;
        cr=prv->next;
        while(cr!=NULL)
        {
            if(strcmp(prv->Words,cr->Words)>0)
            {
                strcpy(Text,cr->Words);
                Repeat=cr->Repeats;

                strcpy(cr->Words,prv->Words);
                cr->Repeats=prv->Repeats;

                strcpy(prv->Words,Text);
                prv->Repeats=Repeat;

                prv->next=prv;
                prv->next=cr;
            }
            prv=cr;
            cr=cr->next;
        }
    }
    Show(bg);
}





int main()
{
    setlocale(LC_ALL,"RUS");

    bg=NULL; //Изначально список пуст

    //Инструкция для пользователя

    SetConsoleTextAttribute(hConsole, (WORD) ((Red << 4) | White));
    cout<<setw(32)<<"WARNING            "<<endl;
    SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | LightGreen));
    cout<<"1. The program works only with the Latin alphabet."<<endl;
    cout<<"2. For the full operation of the program, open it in full screen."<<endl;
    cout<<"3. The choice is made by pressing the keys."<<endl;
    cout<<"4. All numbers and punctuation marks in a word will be deleted."<<endl;
    cout<<"Press ";
    SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | LightRed));
    cout<<"'ENTER'";
    SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | LightGreen));
    cout<<" key to continue";

    bool CheckIfEnter = false;

    do
    {
        if (_kbhit)
        {
            switch(getch())
            {
            case 13:
            {
                cout<<".";
                Sleep(250);
                cout<<".";
                Sleep(250);
                cout<<".";
                Sleep(250);
                SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
                cout<<"START";
                Sleep(1000);
                CheckIfEnter = true;
                system("cls");
                break;
            }

            default:
            {
                cout<<endl<<"Press ";
                SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | LightRed));
                cout<<"'ENTER'";
                SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | LightGreen));
                cout<<" key to continue";
            }
            }
        }
    }
    while(!CheckIfEnter);

    //Запрашиваем у пользователя: создать новый файл или использовать существующий

    cout<<"1. I created txt file with text ";
    SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | LightRed));
    cout<<"(it is in the program folder and his name \"Words.txt\")."<<endl;
    SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
    cout<<"2. I want to create new txt file."<<endl;
    cout<<"What do you choice: ";

    bool CheckIftxtCreate = false;

    do
    {
        if(_kbhit)
        {
            switch(getch())
            {
            case '1':
            {
                system("cls");
                CheckIftxtCreate=true;
                break;
            }
            case '2':
            {
                system("cls");
                CreateFile();

                system("cls");
                SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | LightRed));
                cout<<endl<<endl<<"Go to the file and delete the last transition to a new line."<<endl;
                SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
                CheckIftxtCreate=true;
                cout<<endl<<endl;
                system("PAUSE");
                system("cls");
                break;
            }
            default:
            {
                cout<<endl<<"What do you choice: ";
            }
            }
        }

    }
    while(!CheckIftxtCreate);



    bool WorkWithList = false;
    bool SecondChoise = false;

    do
    {
        cout<<"What will we do next?"<<endl;
        cout<<"1. Words are inserted into the list in the order of their first appearance in the text."<<endl;
        cout<<"2. Words are inserted into the list in alphabetical order."<<endl;
        cout<<endl<<"What do you choice: ";
        if(_kbhit)
        {
            switch(getch())
            {
            case '1':
            {
                bg=NULL; //Изначально список пуст. Необходимо каждый раз обнулять список, чтобы значения повторов не удваивались при повторном выборе.
                system("cls");
                bg=FirstFoundFirsAdd();
                SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | LightGreen));
                cout<<"Words and repeats: "<<endl;
                SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
                Show(bg);


                cout<<endl<<endl<<"What's next?"<<endl;
                cout<<"1. Back to the menu"<<endl;
                cout<<"2. Exit the program"<<endl;
                cout<<"Your choice: ";
                do
                {
                    if(_kbhit)
                    {
                        switch(getch())
                        {
                        case '1':
                        {
                            system("cls");
                            SecondChoise=true;
                            break;
                        }
                        case '2':
                        {
                            system("cls");
                            SecondChoise=true;
                            WorkWithList=true;
                            break;
                        }
                        default:
                        {
                            cout<<endl<<"Your choice: ";
                            SecondChoise=false;
                        }
                        }
                    }
                }
                while(!SecondChoise);
                break;
            }
            case '2':
            {
                bg=NULL; //Изначально список пуст. Необходимо каждый раз обнулять начало списка, чтобы значения повторов не удваивались при новом подсчёте.
                system("cls");
                SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | LightGreen));
                cout<<"Words and repeats: "<<endl;
                SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
                bg=FirstFoundFirsAdd();
                bg=Sort(bg);

                cout<<endl<<endl<<"What's next?"<<endl;
                cout<<"1. Back to the menu"<<endl;
                cout<<"2. Exit the program"<<endl;
                cout<<"Your choice: ";
                do
                {
                    if(_kbhit)
                    {
                        switch(getch())
                        {
                        case '1':
                        {
                            system("cls");
                            SecondChoise=true;
                            break;
                        }
                        case '2':
                        {
                            system("cls");
                            SecondChoise=true;
                            WorkWithList=true;
                            break;
                        }
                        default:
                        {
                            cout<<endl<<"Your choice: ";
                            SecondChoise=false;
                        }
                        }
                    }
                }
                while(!SecondChoise);
                break;
            }
            default:
            {
                cout<<endl<<"What do you choice: "<<endl;
            }
            }
        }

    }
    while(!WorkWithList);



    SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | LightGreen));
    cout<<"The program has successfully completed its work."<<endl;
    SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));

    return 0;
}

