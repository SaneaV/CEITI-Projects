/*Хранение файлов на магнитных лентах. Рассмотрим n файлов f1, f2, ..., fn ,
которые должны быть записаны на магнитную ленту. Напишите программу, определяющую такой порядок размещения файлов на ленте,
чтобы среднее время доступа к ним было минимальным. Предполагается, что частота обращения ко всем файлам (для чтения) одинакова,
а на чтение файла fi (i=1, 2, ..., n) затрачивается ti секунд.*/

#include <iostream>
#include <windows.h>
#include <limits.h>

using namespace std;

struct Files
{
    int Number;
    int Time;
} T[1000];

struct Lenta
{
    int Number;
    int Time;
} L[1000];

int n=0,m=0;
int k=0;

bool ExistElement()
{
    for(int i=0; i<n; i++)
        if(T[i].Time!=0)
            return true;
    return false;
}

void SelecElement(int &x)
{
    int mini;

    for(int i=0; i<n; i++)
        if(T[i].Time!=0)
        {
            mini=i;
            i=n;
        }

    for(int i=0; i<n; i++)
        if(T[i].Time<T[mini].Time and T[i].Time!=0)
            mini=i;

    x=mini;
    L[m].Time=T[x].Time;
    T[mini].Time=0;

    /*int c=T[mini].Time;
    T[mini].Time=T[n-1].Time;
    T[n-1].Time=c;
    n--;*/
}

void IncludeElement(int x)
{
    L[m].Number=T[x].Number;
    m++;
}

void Show()
{
    for(int i=0; i<k; i++)
    {
        cout<<"Number - "<<T[i].Number<<" Time - "<<T[i].Time<<endl;

    }
}

void ShowLenta()
{
    for(int i=0; i<n; i++)
    {
        cout<<"Number - "<<L[i].Number<<" Time - "<<L[i].Time<<endl;

    }
}


int main()
{
    setlocale(LC_ALL,"RUS");
    int x;

    cout<<"Введите количество лент: ";
    cin>>n;
    k=n;

    for(int i=0; i<n; i++)
    {
        cout<<"Введите количество времени, которое уходит на чтение: ";
        cin>>T[i].Time;
        T[i].Number=i+1;

    }
    system("cls");

    Show();
    cout<<endl<<endl;

    while(ExistElement())
    {
        SelecElement(x);
        IncludeElement(x);
    }

    ShowLenta();

}
