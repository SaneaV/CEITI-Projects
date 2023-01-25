#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctime>

using namespace std;

int NumberOfWorkers;
int NumberOfBrigades;
int NumberOfPeopleInTheBrigades;
ofstream f("Report.txt");

struct Workers
{
    int WorkCode;
    char WorkerName[20];
    int RelationsWithPeople[100];
} W[100];

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

void StartTheProgram()
{
    SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | LightGreen));
    cout<<setw(40)<<"Run the program";
    Sleep(500);
    cout<<".";
    Sleep(500);
    cout<<".";
    Sleep(500);
    cout<<"."<<endl;
    Sleep(1000);

    SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
    cout<<"The program is ready to work"<<endl;

    cout<<"Press ";
    SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | LightGreen));
    cout<<"\"Enter\"";
    SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
    cout<<" to start"<<endl;

    bool CheckIfEnter = false;

    do
    {
        if (_kbhit)
        {
            switch(getch())
            {
            case 13:
            {
                CheckIfEnter = true;
                system("cls");
                break;
            }
            default:
            {
                cout<<endl<<"Press ";
                SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | LightGreen));
                cout<<"'ENTER'";
                SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
                cout<<" to continue";
            }
            }
        }
    }
    while(!CheckIfEnter);
}

void DataInput()
{
    cout<<setw(40)<<"Data Input: "<<endl;

    bool ProtectionAgainstIncorrectInput = false;

    do
    {
        ProtectionAgainstIncorrectInput = false;
        cout<<"Enter the number of workers (1<=n<=100): ";
        while (!(cin>>NumberOfWorkers))
        {
            cout<<"You have entered no number"<<endl;
            cin.clear();
            cin.sync();
            SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | LightRed));
            cout<<"Repeat input."<<endl<<endl;
            SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
            cout<<"Enter the number of workers (1<=n<=100): ";
        }

        if(NumberOfWorkers>100)
        {
            ProtectionAgainstIncorrectInput = true;
            cout<<"The number of workers is more than 100"<<endl;
            SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | LightRed));
            cout<<"Repeat input"<<endl<<endl;
            SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
        }

        if(NumberOfWorkers<1)
        {
            ProtectionAgainstIncorrectInput = true;
            cout<<"The number of workers is less than 1"<<endl;
            SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | LightRed));
            cout<<"Repeat input"<<endl<<endl;
            SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
        }
    }
    while(ProtectionAgainstIncorrectInput);
    f<<"Enter the number of workers: "<<NumberOfWorkers<<endl;

    do
    {
        ProtectionAgainstIncorrectInput = false;
        cout<<"Enter the number of brigades: ";
        while (!(cin>>NumberOfBrigades))
        {
            cout<<"You have entered no number"<<endl;
            cin.clear();
            cin.sync();
            SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | LightRed));
            cout<<"Repeat input."<<endl<<endl;
            SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
            cout<<"Enter the number of brigades: ";
        }

        if(NumberOfWorkers%NumberOfBrigades!=0)
        {
            if(NumberOfBrigades>NumberOfWorkers)
            {
                ProtectionAgainstIncorrectInput = true;
                cout<<"The number of brigades is more than the number of workers"<<endl;
                SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | LightRed));
                cout<<"Repeat input"<<endl<<endl;
                SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
            }
            else
            {
                ProtectionAgainstIncorrectInput = true;
                cout<<"The brigades must be the same size"<<endl;
                SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | LightRed));
                cout<<"Repeat input"<<endl<<endl;
                SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));

                cout<<"Possible options: ";
                for(int i=1; i<NumberOfWorkers; i++)
                {
                    if(NumberOfWorkers%i==0)
                        cout<<i<<" ";
                }
                cout<<endl;
            }
        }

        if(NumberOfBrigades<1)
        {
            ProtectionAgainstIncorrectInput = true;
            cout<<"The number of brigades is less than 1"<<endl;
            SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | LightRed));
            cout<<"Repeat input"<<endl;
            SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
        }
        else if(NumberOfBrigades==NumberOfWorkers)
        {
            ProtectionAgainstIncorrectInput = true;
            cout<<"The team can not consist of 1 member"<<endl;
            SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | LightRed));
            cout<<"Repeat input"<<endl<<endl;
            SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
        }

    }
    while(ProtectionAgainstIncorrectInput);
    f<<"Enter the number of brigades: "<<NumberOfBrigades<<endl;

    NumberOfPeopleInTheBrigades = NumberOfWorkers/NumberOfBrigades;
    cout<<"The number of people in the brigade: "<<NumberOfPeopleInTheBrigades<<endl<<endl;
    f<<"The number of people in the brigade: "<<NumberOfPeopleInTheBrigades<<endl;

    system("PAUSE");
}

void IssuanceOfNames()
{
    int NumberName = 0;
    int k=0;
    char NameTXT[20];
    ifstream g("WorkersName.txt");

    for(int i=0; i<NumberOfWorkers; i++)
    {
        NumberName = rand() % 99 +1;
        f<<"Random Number: "<<NumberName<<" - ";
        k=0;

        for(int j=0; j<=NumberName; j++)
        {
            k++;
            g>>NameTXT;
            if(k==NumberName)
            {
                strcpy(W[i].WorkerName,NameTXT);
                f<<i<<". Worker name: "<<W[i].WorkerName<<endl;
                W[i].WorkCode = i+1;
            }

        }
        g.seekg(0, ios::beg);

    }
    g.close();
    system("cls");
}

void TheRelationshipsBetweenWorkers()
{
    bool Selection = false;
    cout<<"The relationships between workers: "<<endl<<endl;
    cout<<"1. Manual filling."<<endl;
    cout<<"2. Auto filling."<<endl;
    cout<<"Make a choice: ";

    do
    {
        if (_kbhit)
        {
            switch(getch())
            {
            case '1':
            {
                system("cls");
                for(int i=0; i<NumberOfWorkers; i++)
                {
                    for(int j=i+1; j<NumberOfWorkers; j++)
                    {
                        cout<<"Relationships between "<<W[i].WorkerName<<" and "<<W[j].WorkerName<<": ";
                        while (!(cin>>W[i].RelationsWithPeople[j]) or (W[i].RelationsWithPeople[j]>10) or (W[i].RelationsWithPeople[j]<0))
                        {
                            if (W[i].RelationsWithPeople[j]>10)
                            {
                                cout<<"The relationships between workers is more than 10"<<endl;
                                SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | LightRed));
                                cout<<"Repeat input."<<endl<<endl;
                                SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
                            }

                            else if(W[i].RelationsWithPeople[j]<0)
                            {
                                cout<<"The relationships between workers is less than 0"<<endl;
                                SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | LightRed));
                                cout<<"Repeat input."<<endl<<endl;
                                SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
                            }

                            else
                            {
                                cout<<"You have entered no number"<<endl;
                                cin.clear();
                                cin.sync();
                                SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | LightRed));
                                cout<<"Repeat input."<<endl<<endl;
                                SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
                                cout<<"Relationships between "<<W[i].WorkerName<<" and "<<W[j].WorkerName<<": ";
                            }
                        }

                        W[j].RelationsWithPeople[i] = W[i].RelationsWithPeople[j];
                        f<<"Relationships between "<<W[i].WorkerName<<" and "<<W[j].WorkerName<<": "<<W[i].RelationsWithPeople[j]<<endl;

                    }
                    f<<endl;
                }
                Selection = true;
                system("cls");
                break;
            }

            case '2':
            {
                int RandomRelationships = 0;

                system("cls");

                for(int i=0; i<NumberOfWorkers; i++)
                {
                    for(int j=i+1; j<NumberOfWorkers; j++)
                    {
                        RandomRelationships = rand() % 11 +0;
                        W[i].RelationsWithPeople[j] = RandomRelationships;
                        W[j].RelationsWithPeople[i] = W[i].RelationsWithPeople[j];
                        f<<"Relationships between "<<W[i].WorkerName<<" and "<<W[j].WorkerName<<": "<<W[i].RelationsWithPeople[j]<<endl;

                    }
                    f<<endl;
                }
                Selection = true;
                system("cls");
                break;
            }
            default:
            {
                SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | LightRed));
                cout<<"Choose a way to fill relationships"<<endl;
                SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
            }
            }
        }
    }
    while(!Selection);



}

void TheAttitudeOfManToHimself()
{
    for(int i=0; i<NumberOfWorkers; i++)
    {
        for(int j=0; j<NumberOfWorkers; j++)
        {
            if(i==j)
            {
                W[i].RelationsWithPeople[i]=-1;
                f<<W[i].WorkerName<<" - "<<W[i].RelationsWithPeople[j]<<" - "<<W[j].WorkerName<<endl;
            }
        }
    }
}

void ShowTheRelationshipsBetweenWorkers()
{
    for(int i=0; i<NumberOfWorkers; i++)
    {
        for(int j=0; j<NumberOfWorkers; j++)
        {
            f<<W[i].WorkerName<<" - "<<W[i].RelationsWithPeople[j]<<" - "<<W[j].WorkerName<<endl;
        }
        f<<endl;
    }
}

void CombinationAndMax()
{
    if(NumberOfBrigades==1)//Если все работают в одной бригаде
    {
        float Cmax = 0;
        int TemporarySum=0;
        float TemporaryCoefficient = 0;

        for(int p=0; p<NumberOfPeopleInTheBrigades; p++)
        {
            for(int s=p+1; s<NumberOfPeopleInTheBrigades; s++)
            {
                TemporarySum+=W[p].RelationsWithPeople[s]*1.0;
            }
        }

        TemporaryCoefficient = TemporarySum/(NumberOfPeopleInTheBrigades*1.0);
        Cmax = TemporaryCoefficient;
        f<<"Team coefficient: "<<TemporaryCoefficient<<endl;

        f<<endl<<endl<<"The best team coefficient: "<<Cmax<<endl;
        cout<<"The best team coefficient: "<<Cmax<<endl;

        f<<"For team: ";
        cout<<"For team: ";
        for(int i=0; i<NumberOfPeopleInTheBrigades; i++)
        {
            f<<W[i].WorkerName<<" ";
            cout<<W[i].WorkerName<<" ";
        }
        f<<endl;
        cout<<endl;
    }

    else if (NumberOfBrigades!=NumberOfWorkers) //Если количество бригад больше одной и меньше количества человек
    {
        int TemporaryMassiv[NumberOfPeopleInTheBrigades];
        int TheMassivOfTheBestWorkers[NumberOfPeopleInTheBrigades];
        bool Y = false;

        int c = 1;
        int i = 0;
        float TemporarySum = 0;
        float Cmax = 0;

        for(int p=0; p<NumberOfPeopleInTheBrigades; p++)// Заполняем массив от 1 до NumberOfPeopleInTheBrigades
        {
            TemporaryMassiv[p]=c++;
        }
        c--;

        while(!Y)//Пока не дойдём до конца не выйдем из цикла
        {
            for(int q=i+1; q<NumberOfPeopleInTheBrigades; q++)
            {
                if(TemporaryMassiv[q]==NumberOfWorkers)//Проверяем, если последний элемент дошёл до NumberOfWorkers и прибавляем +1 к предыдущему, а последний эдемент получает значение предыдушего +1
                {
                    int Remeber = TemporaryMassiv[q-1];
                    TemporaryMassiv[q-1] += 1 ;
                    TemporaryMassiv[q] = Remeber + 1;
                    c = Remeber+2;
                }
            }

            if (TemporaryMassiv[NumberOfPeopleInTheBrigades-1]>NumberOfWorkers)//Дополнительная проверка, если несколько элементов дошли до NumberOfWorkers
            {
                for(int f=+1; f<NumberOfPeopleInTheBrigades; f++)
                {
                    if(TemporaryMassiv[f]>NumberOfWorkers)
                    {
                        int Remeber = TemporaryMassiv[f-1];
                        TemporaryMassiv[f-1] += 1 ;
                        TemporaryMassiv[f] = Remeber + 1;
                        c = Remeber + 2;
                    }
                }
            }
            if(TemporaryMassiv[0]>NumberOfWorkers)//Если первый элемент больше NumberOfWorkers то выходим из цикла
                Y=true;

            for(int j=TemporaryMassiv[NumberOfPeopleInTheBrigades-1]; j<NumberOfWorkers; j++)
            {
                TemporaryMassiv[NumberOfPeopleInTheBrigades-1]=c++;//Увеличиваем последний элемент на 1

                for(int t=0; t<NumberOfPeopleInTheBrigades; t++)
                {
                    f<<TemporaryMassiv[t]<<" ";
                }
                f<<endl;

                TemporarySum=0;
                float TemporaryCoefficient = 0;

                for(int p=0; p<NumberOfPeopleInTheBrigades; p++)
                {
                    for(int s=p+1; s<NumberOfPeopleInTheBrigades; s++)
                    {
                        TemporarySum+=W[TemporaryMassiv[p]-1].RelationsWithPeople[TemporaryMassiv[s]-1]*1.0;
                    }
                }
                TemporaryCoefficient = TemporarySum/(NumberOfPeopleInTheBrigades*1.0);
                if(TemporaryCoefficient>Cmax)
                {
                    Cmax=TemporaryCoefficient;
                    for(int r=0; r<NumberOfPeopleInTheBrigades; r++)
                    {
                        TheMassivOfTheBestWorkers[r]=TemporaryMassiv[r]-1;
                    }
                }
                f<<"Team coefficient: "<<(TemporaryCoefficient)<<endl;
            }

        }

        f<<endl<<endl<<"The best team coefficient: "<<Cmax<<endl;
        cout<<"The best team coefficient: "<<Cmax<<endl;
        f<<"For team: ";
        cout<<"For team: ";
        for(int i=0; i<NumberOfPeopleInTheBrigades; i++)
        {
            f<<W[TheMassivOfTheBestWorkers[i]].WorkerName<<" ";
            cout<<W[TheMassivOfTheBestWorkers[i]].WorkerName<<" ";
        }
        f<<endl;
        cout<<endl;
    }
}


int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    srand(time(0));

    ///////////////////Запуск программы///////////////////////

    f<<"///////////////////"<<endl;
    f<<"The program has been launched"<<endl<<endl;

    StartTheProgram();

    ///////////////////Ввод данных///////////////////////

    f<<endl<<"///////////////////"<<endl;
    f<<"Data Input: "<<endl<<endl;

    DataInput();

    ///////////////////Разадча имён рабочим///////////////////////

    f<<endl<<"///////////////////"<<endl;
    f<<"Issuance of names: "<<endl<<endl;

    IssuanceOfNames();

    ///////////////////Определение отношений между рабочими///////////////////////

    f<<endl<<"///////////////////"<<endl;
    f<<"The relationships between workers: "<<endl<<endl;

    TheRelationshipsBetweenWorkers();

    ///////////////////Отношение человека к самомум себе будет (-1)///////////////////////

    f<<endl<<"///////////////////"<<endl;
    f<<"The attitude of man to himself (-1)"<<endl<<endl;

    TheAttitudeOfManToHimself();

    ///////////////////Вывод отношений между пользователями(Функция записывается только в отчёт)///////////////////////

    f<<endl<<"///////////////////"<<endl;
    f<<"Show: the relationships between workers: "<<endl<<endl;

    ShowTheRelationshipsBetweenWorkers();

    ///////////////////Комбинации и поиск максимума///////////////////////

    f<<endl<<"///////////////////"<<endl;
    f<<"Combinations and search max: "<<endl<<endl;

    CombinationAndMax();
    f.close();

}
