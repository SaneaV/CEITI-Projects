/*Непрерывная задача о рюкзаке. Имеются n предметов. Для каждого предмета i (i=1, 2, ..., n)
известен вес gi и прибыль ci, которая получается при транспортировке. Имеется рюкзак, в котором можно переносить один и более предметов,
суммарный вес которых не превышает величины Gmax. Напишите программу, которая определяет, каким образом необходимо загрузить рюкзак с тем,
чтобы суммарная прибыль C была максимальна. При необходимости, переносимые предметы можно разделять на меньшие части.*/

//Код написан очень просто и конечный вывод непонятен.

#include <iostream>

using namespace std;

float c[1000], g[1000], Gmax, k[1000];
int n;

bool ExistElement()
{
    for(int i=0; i<n; i++)
        if(c[i]>0)
            return true;
    return false;
}

void SelecElement(int &x)
{
    int imax=0;
    for(int i=0; i<n; i++)
        if(c[i]/g[i]>c[imax]/g[imax])
            imax=i;
    x=imax;
    c[imax]=0;

}

void IncludeElement(int x)
{
    if(g[x]<Gmax)
    {
        k[x]=1;
        Gmax-=g[x];
    }
    else
    {
        k[x]=Gmax/g[x];
        Gmax-=k[x]*g[x];
    }
}

int main()
{
    setlocale(LC_ALL,"RUS");
    int x;

    cout<<"Введите количество вещей: ";
    cin>>n;

    for(int i=0; i<n; i++)
    {
        cout<<"Введите цену вещи: ";
        cin>>c[i];
        cout<<"Введите вес вещи: ";
        cin>>g[i];

        k[i]=0;
    }

    cout<<"Введите вместимость рюкзака: ";
    cin>>Gmax;

    while(ExistElement())
    {
        SelecElement(x);
        IncludeElement(x);
    }

    for(int i=0;i<n;i++)
        cout<<k[i]<<" ";

}
