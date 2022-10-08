/*Непрерывная задача о рюкзаке. Имеются n предметов. Для каждого предмета i (i=1, 2, ..., n)
известен вес gi и прибыль ci, которая получается при транспортировке. Имеется рюкзак, в котором можно переносить один и более предметов,
суммарный вес которых не превышает величины Gmax. Напишите программу, которая определяет, каким образом необходимо загрузить рюкзак с тем,
чтобы суммарная прибыль C была максимальна. При необходимости, переносимые предметы можно разделять на меньшие части.*/

//Код написан очень просто, но конечный вывод на экран понятен.

#include <iostream>
#include <cstring>
#include <windows.h>
#include <fstream>
#include <cmath>

using namespace std;

struct Things
{
    char Name[20];
    float price;
    float weight;
} T[100];

struct Bag
{
    char Name[20];
    float price;
    float weight;
} B[100];

int Sum=0;

int Filling(int n)
{
    ifstream f("Things.txt");

    f>>n;

    for(int i=0; i<n; i++)
    {
        f>>T[i].Name;
        f>>T[i].price;
        f>>T[i].weight;
    }

    return n;

    /*for(int i=0; i<n; i++)
    {
        cout<<"Введите название вещи: ";
        cin>>T[i].Name;
        cout<<"Введите цену вещи: ";
        cin>>T[i].price;
        cout<<"Введите вес вещи: ";
        cin>>T[i].weight;+
        system("cls");
    }*/

}

bool ExistElement(int n, int g)
{
    for(int i=0; i<n; i++)
        if(T[i].price>0)
            return true;
    return false;
}

void SelectElement(int n, int &x)
{
    int imax=0;

    for(int i=0; i<n; i++)
        if(T[i].price/T[i].weight>T[imax].price/T[imax].weight)
            imax=i;

    x=imax;
    B[imax].price=T[imax].price;
    T[imax].price=0;
}

void IncludeElement(int &g,int x)
{
    if(T[x].weight<g)
    {
        strcpy(B[x].Name, T[x].Name);
        B[x].weight=T[x].weight;
        g-=T[x].weight;

    }
    else
    {
        strcpy(B[x].Name, T[x].Name);
        B[x].weight=g/T[x].weight;
        g-=B[x].weight*T[x].weight;

    }
}

void Show(int n)
{
    for(int i=0; i<n; i++)
    {
        cout<<T[i].Name<<" "<<T[i].price<<" "<<T[i].weight<<endl;
    }
}

void ShowBag(int n)
{
    for(int i=0; i<n; i++)
    {
        if(B[i].weight!=0)
        cout<<B[i].Name<<" "<<B[i].price<<" "<<round(B[i].weight*10)/10<<endl;
    }
}

int main()
{
    setlocale(LC_ALL,"RUS");

    int n, g;
    int x;

    /*cout<<"Введите количество вещей: ";
    cin>>n;*/

    cout<<"Введите вес рюкзака: ";
    cin>>g;
    system("cls");

    n = Filling(n);

    while(ExistElement(n,g))
    {
        SelectElement(n,x);
        IncludeElement(g,x);
    }

    system("cls");

    cout<<"Вещи, которые можно взять: "<<endl<<endl;
    Show(n);
    cout<<endl<<endl<<"Вещи, которые поместились в рюкзак: "<<endl<<endl;
    ShowBag(n);

    cout<<endl<<endl<<"Осталось свободного места: "<<g<<endl;
}

