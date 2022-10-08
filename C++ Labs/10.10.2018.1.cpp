/*В копилке находится N монет различных достоинств общим весом G граммов. Вес каждой монеты определенной стоимости дан в таблице, приведенной ниже.

Стоимость монеты, лей	Вес монеты, грамм
1	1
5	2
10	3
25	4
50	5
Напишите программу, которая определит минимальную сумму S, которая может находиться в копилке. */

#include <iostream>
#include <windows.h>

using namespace std;

int Smin(int G, int N)
{
    int Smin=0;
    int *Money = new int [N];
    bool Y=true;
    int G2=0;

    //Заполняем массив единицами
    for(int i=0; i<N; i++)
        Money[i]=1;

    //Делаем первую проверку (Суммируем все монеты номиналом 1 бан)
    for(int i=0; i<N; i++)
        G2+=Money[i];

    if(G2==G)
    {
        cout<<"Все монеты номиналом 1 бан."<<endl;
        return G;
    }
    else if(G2>G)
    {
        cout<<"Такое сочетание невозможно."<<endl;
        return 0;
    }

    int k=0; //Проверка, если все элементы одинаковые

    Money[0]=2;

    while(Y)
    {
        G2=0;
        k=1;

        for(int i=0; i<N; i++)
            G2+=Money[i];

        if(G2==G)
            Y=false;
        else
        {
            for(int i=1; i<N; i++)
            {
                if(Money[0]==Money[i])
                    k++;
            }
            if(k==N)
                Money[0]+=1;
            else if(k<N)
                Money[k]+=1;
        }

        for(int i=0; i<N; i++)
        {
            if(Money[i]>5)
            {
                cout<<"Такое сочетание невозможно."<<endl;
                return 0;
            }
        }
    }

    for(int i=0; i<N; i++)
    {
        if(Money[i]==1)
        {
            cout<<i+1<<". Монета номиналом 1 бан"<<endl;
            Smin+=1;
        }
        if(Money[i]==2)
        {
            cout<<i+1<<". Монета номиналом 5 бан"<<endl;
            Smin+=5;
        }
        if(Money[i]==3)
        {
            cout<<i+1<<". Монета номиналом 10 бан"<<endl;
            Smin+=10;
        }
        if(Money[i]==4)
        {
            cout<<i+1<<". Монета номиналом 25 бан"<<endl;
            Smin+=25;
        }
        if(Money[i]==5)
        {
            cout<<i+1<<". Монета номиналом 50 бан"<<endl;
            Smin+=50;
        }
    }

    cout<<endl<<endl;
    return Smin;
}

int main()
{
    setlocale(LC_ALL,"RUS");

    cout<<"Введите вес монет: ";
    int G;
    cin>>G;

    cout<<"Введите количество монет: ";
    int N;
    cin>>N;

    cout<<endl<<endl<<endl;

    int S = Smin(G,N);

    if(S!=0)
        cout<<"Минимальная сумма "<<N<<" монет, весом "<<G<<" грамм"<<", составляет: "<<S<<" бан."<<endl;
}
