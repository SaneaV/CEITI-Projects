#include <iostream>
#include <windows.h>
#include <iomanip>
#include <conio.h>
#include <stdlib.h>

using namespace std;

bool Working = true;
bool SecondWorking = true;
int First, Second;
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
    White = 15,
};

class Mnogochlen
{
private:
    int n;
    float ArrOfKoef[100];
public:
    void Filling();
    void Show();

    bool CheckN();
    bool CheckElem();

    void InitForSumRaz();
    void InitForUmnoj();

    Mnogochlen operator =(Mnogochlen mng1);
    Mnogochlen operator +(Mnogochlen mng1);
    Mnogochlen operator -(Mnogochlen mng1);
    Mnogochlen operator *(Mnogochlen mng1);

    Mnogochlen();
    ~Mnogochlen();
};

Mnogochlen M[30];


void Mnogochlen::Filling()
{
    cout<<"Введите количество степеней (нулевая степень добавляется автоматически): ";
    while (!(cin>>n))
    {
        cout<<"Ошибка, вы ввели что-то не то."<<endl;
        cin.clear();
        cin.sync();
        cout<<"Повторите ввод: ";
    }

    try
    {
        if(n==0)
            throw 1;
        if(n<0)
            throw 0;
        else
        {
            for(int i=0; i<=n; i++)
            {
                cout<<"Введите коэффицент (заполнение слева на право): ";
                while (!(cin>>ArrOfKoef[i]))
                {
                    cout<<"Ошибка, вы ввели что-то не то."<<endl;
                    cin.clear();
                    cin.sync();
                    cout<<"Повторите ввод: ";
                }
            }
        }
    }
    catch(int i)
    {
        SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | LightRed));
        if(i==1)
            cout<<"Программа не может работать с количеством степеней равных нулю.";
        if(i==0)
            cout<<"Программа не может работать с количеством степеней меньше 1.";
        SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
    }

}

void Mnogochlen::InitForSumRaz()
{
    if(M[First-1].n>M[Second-1].n or
            M[First-1].n==M[Second-1].n)
        n = M[First-1].n;
    else if(M[First-1].n<M[Second-1].n)
        n = M[Second-1].n;
}

void Mnogochlen::InitForUmnoj()
{
    n = M[First-1].n + M[Second-1].n;
}

bool Mnogochlen::CheckN()
{
    if(n<=0)
        return false;
    else
        return true;
}

bool Mnogochlen::CheckElem()
{
    for(int i=0; i<=n; i++)
    {
        if(ArrOfKoef[i]!=0)
            return true;
    }
    return false;
}

void Mnogochlen::Show()
{
    cout<<"P(x) = ";


    for(int i=0, j=n ; i<=n; i++, j--)
    {
        if (j==n and ArrOfKoef[0]==-1)
        {
            cout<<"-";
        }

        if(ArrOfKoef[i]!=0)
        {
            if(ArrOfKoef[i]!=1 and ArrOfKoef[i]!=-1 or (j==0 and ArrOfKoef[i]==1) or (j==0 and ArrOfKoef[i]==-1))
                cout<<ArrOfKoef[i];

            if(j!=0)
                cout<<"x";

            if(j!=1 and j!=0)
                cout<<"^"<<j;

            if(ArrOfKoef[i+1]>=0 and j!=0)
            {
                if(ArrOfKoef[i+1]!=0 and j!=0)
                {
                    cout<<"+";
                }


            }

            if(ArrOfKoef[i+1]<0)
            {
                if(ArrOfKoef[i+1]==-1 and j!=1)
                {
                    cout<<"-";
                }
            }
        }
    }
}


Mnogochlen Mnogochlen::operator =(Mnogochlen mng1)
{
    for(int i=0; i<=n; i++)
        ArrOfKoef[i] = mng1.ArrOfKoef[i];

    return *this;
}

Mnogochlen Mnogochlen::operator +(Mnogochlen mng1)
{
    Mnogochlen m;
    float *tmp1 = new float [50];
    float *tmp2 = new float [50];
    int N;

    if(M[First-1].n>M[Second-1].n)
        N = M[First-1].n;
    else if(M[First-1].n<M[Second-1].n)
        N = M[Second-1].n;
    else
        N = M[First-1].n; //Когда размеры одинаковы


    if(M[First-1].n>M[Second-1].n)
    {
        int Raz = M[First-1].n-M[Second-1].n;
        int j=0;

        for(int i=0; i<=M[First-1].n; i++)
        {
            tmp1[i]=0;
        }

        for(int i=0; i<=M[First-1].n; i++)
        {
            if(Raz<=i)
            {
                tmp1[i]=mng1.ArrOfKoef[j];
                j++;
            }
            tmp2[i] = ArrOfKoef[i];

        }
    }
    else if (M[First-1].n<M[Second-1].n)
    {
        int Raz = M[Second-1].n-M[First-1].n;
        int j=0;

        for(int i=0; i<=M[Second-1].n; i++)
        {
            tmp1[i]=0;
        }

        for(int i=0; i<=M[Second-1].n; i++)
        {
            if(Raz<=i)
            {
                tmp1[i]=ArrOfKoef[j];
                j++;
            }
            tmp2[i] = mng1.ArrOfKoef[i];

        }

    }
    else if(M[First-1].n==M[Second-1].n)
    {
        for(int i=0; i<=N; i++)
        {
            tmp1[i] = ArrOfKoef[i];
            tmp2[i] = mng1.ArrOfKoef[i];
        }
    }

    for(int i=0; i<=N; i++)
    {
        m.ArrOfKoef[i] = tmp1[i]+tmp2[i];
    }

    delete tmp1;
    delete tmp2;
    return m;
}


Mnogochlen Mnogochlen::operator -(Mnogochlen mng1)
{
    Mnogochlen m;
    float *tmp1 = new float [50];
    float *tmp2 = new float [50];
    int N;

    if(M[First-1].n>M[Second-1].n)
        N = M[First-1].n;
    else if(M[First-1].n<M[Second-1].n)
        N = M[Second-1].n;
    else
        N = M[First-1].n; //Когда размеры одинаковы


    if(M[First-1].n>M[Second-1].n)
    {
        int Raz = M[First-1].n-M[Second-1].n;
        int j=0;

        for(int i=0; i<=M[First-1].n; i++)
        {
            tmp1[i]=0;
        }

        for(int i=0; i<=M[First-1].n; i++)
        {
            if(Raz<=i)
            {
                tmp1[i]=mng1.ArrOfKoef[j];
                j++;
            }
            tmp2[i] = ArrOfKoef[i];

        }
    }
    else if (M[First-1].n<M[Second-1].n)
    {
        int Raz = M[Second-1].n-M[First-1].n;
        int j=0;

        for(int i=0; i<=M[Second-1].n; i++)
        {
            tmp1[i]=0;
        }

        for(int i=0; i<=M[Second-1].n; i++)
        {
            if(Raz<=i)
            {
                tmp1[i]=ArrOfKoef[j];
                j++;
            }
            tmp2[i] = mng1.ArrOfKoef[i];

        }

    }
    else if(M[First-1].n==M[Second-1].n)
    {
        for(int i=0; i<=N; i++)
        {
            tmp1[i] = ArrOfKoef[i];
            tmp2[i] = mng1.ArrOfKoef[i];
        }
    }

    for(int i=0; i<=N; i++)
    {
        if(M[First-1].n<M[Second-1].n or M[First-1].n==M[Second-1].n)
            m.ArrOfKoef[i] = tmp1[i]-tmp2[i];
        else
            m.ArrOfKoef[i] = tmp2[i]-tmp1[i];
    }

    delete tmp1;
    delete tmp2;
    return m;
}

Mnogochlen Mnogochlen::operator *(Mnogochlen mng1)
{
    Mnogochlen m;

    int N1=M[First-1].n;
    int N2=M[Second-1].n;

    for(int i=0; i<=N1+N2; i++)
        m.ArrOfKoef[i]=0;

    for(int i=0; i<=N1; i++)
    {
        for(int j=0; j<=N2; j++)
        {
            m.ArrOfKoef[i+j] += ArrOfKoef[i] * mng1.ArrOfKoef[j];
        }
    }

    return m;
}


Mnogochlen::Mnogochlen()
{
    this->n=n;
    this->ArrOfKoef[100]=ArrOfKoef[100];
}

Mnogochlen::~Mnogochlen()
{
}


void exit()
{
    cout<<endl<<endl;
    cout<<"1. Вернуться в меню."<<endl;
    cout<<"2. Выйти их программы."<<endl;
    cout<<"Ваш выбор: ";

    while(SecondWorking)
    {
        if(_kbhit)
        {
            switch(getch())
            {
            case '1':
            {
                SecondWorking = false;
                system("cls");
                break;
            }
            case '2':
            {
                SecondWorking = false;
                Working = false;
                system("cls");
                break;
            }
            }
        }
    }

}

void MenuFill()
{
    cout<<"||";
    for(int i=0; i<40; i++)
        cout<<"=";
    cout<<"||"<<endl<<"||";
}

void Loading()
{
    ////////////////////////////////////////////////////////
    int KolOf = 7;
    char Word[2][7];
    bool Stop = false;

////////////////////////////////////////////////////////
    Word[0][0] = 'L';
    Word[0][1] = 'o';
    Word[0][2] = 'a';
    Word[0][3] = 'd';
    Word[0][4] = 'i';
    Word[0][5] = 'n';
    Word[0][6] = 'g';

    for(int i=0; i<KolOf; i++)
    {
        Word[1][i] = ' ';
    }
////////////////////////////////////////////////////////
    SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | LightGreen));
    while(!Stop)
    {
        for(int i=0; i<2; i++)
        {
            for(int j=0; j<KolOf; j++)
            {
                if (i==0)
                {
                    Word[i+1][j] = Word[i][j];
                    Word[i][j] = ' ';
                }
                else if (i==1)
                {
                    Word[i-1][j] = Word[i][j];
                    Word[i][j] = ' ';
                }

                for(int p=0; p<2; p++)
                {
                    for(int q=0; q<KolOf; q++)
                    {
                        if (q==0)
                            cout<<setw(25)<<Word[p][q];
                        else
                            cout<<Word[p][q];
                    }
                    cout<<endl;
                }
                Sleep(250);
                system("cls");
            }
        }
        Stop = true;
    }
    SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
}


int main()
{
    setlocale(LC_ALL,"RUS");

    int NumberOfMnogoch = -1;
    Loading();

    while(Working)
    {
        SecondWorking = true;
        MenuFill();
        SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | LightGreen));
        cout<<setw(30)<<"Добро пожаловать!";
        SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
        cout<<setw(12)<<"||"<<endl;
        MenuFill();
        cout<<"1. Создание и заполнение многочлена."<<setw(6)<<"||"<<endl;
        MenuFill();
        cout<<"2. Вывод многочлена на экран."<<setw(13)<<"||"<<endl;
        MenuFill();
        cout<<"3. Сложение многочленов."<<setw(18)<<"||"<<endl;
        MenuFill();
        cout<<"4. Вычитание многочленов."<<setw(17)<<"||"<<endl;
        MenuFill();
        cout<<"5. Умножение многочленов."<<setw(17)<<"||"<<endl;
        MenuFill();
        SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | LightRed));
        cout<<"6. Выйти из программы";
        SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
        cout<<setw(21)<<"||"<<endl;
        cout<<"||";
        for(int i=0; i<40; i++)
            cout<<"=";
        cout<<"||"<<endl;


        if(_kbhit)
        {
            switch(getch())
            {
            case '1':
            {
                system("cls");
                NumberOfMnogoch++;
                M[NumberOfMnogoch].Filling();

                if(!M[NumberOfMnogoch].CheckN())
                    NumberOfMnogoch--;
                if(!M[NumberOfMnogoch].CheckElem() and M[NumberOfMnogoch].CheckN())
                {
                    NumberOfMnogoch--;
                    SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | LightRed));
                    cout<<"Многочлен не создан. Все элементы многочлена равны нулю."<<endl;
                    SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
                }

                exit();
                break;

            }
            case '2':
            {
                system("cls");
                if(NumberOfMnogoch!=-1)
                    for(int i=0; i<=NumberOfMnogoch; i++)
                    {
                        cout<<i+1<<". ";
                        M[i].Show();
                        cout<<endl;
                    }
                else
                {
                    SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | LightRed));
                    cout<<"Не введенно ни одного многочлена"<<endl;
                    SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
                }

                exit();
                break;
            }
            case '3':
            {
                system("cls");

                try
                {
                    if(NumberOfMnogoch==-1)
                        throw 1;
                    if (NumberOfMnogoch==0)
                        throw 2;
                    else
                    {
                        for(int i=0; i<=NumberOfMnogoch; i++)
                        {
                            cout<<i+1<<". ";
                            M[i].Show();
                            cout<<endl;
                        }

                        bool Check;

                        cout<<"Номер многочлена первого слагаемого: ";
                        do
                        {
                            while (!(cin>>First))
                            {
                                cout<<"Ошибка, вы ввели что-то не то."<<endl;
                                cin.clear();
                                cin.sync();
                                cout<<"Повторите ввод: ";
                            }
                            if(First>NumberOfMnogoch+1 or First<=0)
                            {
                                Check=false;
                                SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | LightRed));
                                cout<<"Вы допустили ошибку в выборе слагаемого"<<endl;
                                SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
                            }
                            else
                                Check=true;
                        }
                        while(!Check);

                        cout<<"Номер многочлена второго слагаемого: ";
                        do
                        {
                            while (!(cin>>Second))
                            {
                                cout<<"Ошибка, вы ввели что-то не то."<<endl;
                                cin.clear();
                                cin.sync();
                                cout<<"Повторите ввод: ";
                            }
                            if(Second>NumberOfMnogoch+1 or Second<=0 or Second==First)
                            {
                                Check=false;
                                SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | LightRed));
                                cout<<"Вы допустили ошибку в выборе слагаемого"<<endl;
                                SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
                            }
                            else
                                Check=true;

                        }
                        while(!Check);

                        NumberOfMnogoch++;
                        M[NumberOfMnogoch].InitForSumRaz();
                        M[NumberOfMnogoch]=M[First-1]+M[Second-1];

                        if(!M[NumberOfMnogoch].CheckElem())
                        {
                            NumberOfMnogoch--;
                            SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | LightRed));
                            cout<<"После совершения данного действия, многочлен стал равен нулю и не был добавлен в список."<<endl;
                            SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
                        }
                    }
                }
                catch(int i)
                {
                    SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | LightRed));
                    if (i==1)
                        cout<<"Не введенно ни одного многочлена"<<endl;
                    if (i==2)
                        cout<<"Введён только один многочлен. Для сложения необходимо - два"<<endl;
                    SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
                }

                exit();
                break;

            }
            case '4':
            {
                system("cls");

                try
                {
                    if(NumberOfMnogoch==-1)
                        throw 1;
                    if (NumberOfMnogoch==0)
                        throw 2;
                    else
                    {
                        for(int i=0; i<=NumberOfMnogoch; i++)
                        {
                            cout<<i+1<<". ";
                            M[i].Show();
                            cout<<endl;
                        }

                        bool Check;

                        cout<<"Номер уменьшаемого многочлена: ";
                        do
                        {
                            while (!(cin>>First))
                            {
                                cout<<"Ошибка, вы ввели что-то не то."<<endl;
                                cin.clear();
                                cin.sync();
                                cout<<"Повторите ввод: ";
                            }
                            if(First>NumberOfMnogoch+1 or First<=0)
                            {
                                Check=false;
                                SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | LightRed));
                                cout<<"Вы допустили ошибку в выборе уменьшаемого"<<endl;
                                SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
                            }
                            else
                                Check=true;
                        }
                        while(!Check);

                        cout<<"Номер вычитаемого многочлена: ";
                        do
                        {
                            while (!(cin>>Second))
                            {
                                cout<<"Ошибка, вы ввели что-то не то."<<endl;
                                cin.clear();
                                cin.sync();
                                cout<<"Повторите ввод: ";
                            }
                            if(Second>NumberOfMnogoch+1 or Second<=0 or Second==First)
                            {
                                Check=false;
                                SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | LightRed));
                                cout<<"Вы допустили ошибку в выборе вычитаемого"<<endl;
                                SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
                            }
                            else
                                Check=true;

                        }
                        while(!Check);

                        NumberOfMnogoch++;
                        M[NumberOfMnogoch].InitForSumRaz();
                        M[NumberOfMnogoch]=M[First-1]-M[Second-1];

                        if(!M[NumberOfMnogoch].CheckElem())
                        {
                            NumberOfMnogoch--;
                            SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | LightRed));
                            cout<<"После совершения данного действия, многочлен стал равен нулю и не был добавлен в список."<<endl;
                            SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
                        }
                    }
                }
                catch(int i)
                {
                    SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | LightRed));
                    if (i==1)
                        cout<<"Не введенно ни одного многочлена"<<endl;
                    if (i==2)
                        cout<<"Введён только один многочлен. Для сложения необходимо - два"<<endl;
                    SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
                }

                exit();
                break;
            }
            case '5':
            {
                system("cls");

                try
                {
                    if(NumberOfMnogoch==-1)
                        throw 1;
                    if (NumberOfMnogoch==0)
                        throw 2;
                    else
                    {
                        for(int i=0; i<=NumberOfMnogoch; i++)
                        {
                            cout<<i+1<<". ";
                            M[i].Show();
                            cout<<endl;
                        }

                        bool Check;

                        cout<<"Номер множителя многочлена: ";
                        do
                        {
                            while (!(cin>>First))
                            {
                                cout<<"Ошибка, вы ввели что-то не то."<<endl;
                                cin.clear();
                                cin.sync();
                                cout<<"Повторите ввод: ";
                            }
                            if(First>NumberOfMnogoch+1 or First<=0)
                            {
                                Check=false;
                                SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | LightRed));
                                cout<<"Вы допустили ошибку в выборе множителя"<<endl;
                                SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
                            }
                            else
                                Check=true;
                        }
                        while(!Check);

                        cout<<"Номер множителя многочлена: ";
                        do
                        {
                            while (!(cin>>Second))
                            {
                                cout<<"Ошибка, вы ввели что-то не то."<<endl;
                                cin.clear();
                                cin.sync();
                                cout<<"Повторите ввод: ";
                            }
                            if(Second>NumberOfMnogoch+1 or Second<=0 or Second==First)
                            {
                                Check=false;
                                SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | LightRed));
                                cout<<"Вы допустили ошибку в выборе множителя"<<endl;
                                SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
                            }
                            else
                                Check=true;

                        }
                        while(!Check);

                        NumberOfMnogoch++;
                        M[NumberOfMnogoch].InitForUmnoj();
                        M[NumberOfMnogoch]=M[First-1]*M[Second-1];

                        if(!M[NumberOfMnogoch].CheckElem())
                        {
                            NumberOfMnogoch--;
                            SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | LightRed));
                            cout<<"После совершения данного действия, многочлен стал равен нулю и не был добавлен в список."<<endl;
                            SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
                        }
                    }
                }
                catch(int i)
                {
                    SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | LightRed));
                    if (i==1)
                        cout<<"Не введенно ни одного многочлена"<<endl;
                    if (i==2)
                        cout<<"Введён только один многочлен. Для сложения необходимо - два"<<endl;
                    SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
                }

                exit();

                break;
            }
            case '6':
            {
                system("cls");
                Working=false;
                break;
            }
            default:
            {
                system("cls");
                SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | LightRed));
                cout<<endl<<"Вы ошиблись клавишей"<<endl;
                SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
                cout<<endl;

            }
            }
        }
    }

    SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | LightGreen));
    cout<<"Программа закончила свою работу"<<endl;
    SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));

}
