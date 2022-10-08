/*Разложения натурального числа
Напишите программу, которая выводит на экран все способы разложения натурального числа n в виде суммы k взаимно различных натуральных чисел.
Например, для n=9 и k=3 решениями являются суммы 1+2+6, 2+3+4 и 1+3+5.
*/

#include <iostream>

using namespace std;

int k,n;
int Numbers[100][100];
bool flag;
int x[50];

void Filling()
{
    int t;

    for(int i=0; i<k; i++)
    {
        t=1;
        for(int j=0; j<n; j++)
        {
            Numbers[i][j]=t++;
        }
    }
}

int FirstElement(int p)
{
    return 0;
}
bool Continue(int p)
{
    int sum=0;
    for(int i=0; i<p; i++)
        sum+=Numbers[i][x[i]];
    if (((p<k) and (sum<n)) or ((p==k) and (sum==n)))
        return true;
    else
        return false;

}

bool ExistSuccessor(int p)
{
    return (x[p]<k);
}

int Successor(int p)
{
    return x[p]+1;
}

void ProcessingSolution()
{
    cout<<"Решение:";
    for(int i=0; i<n; i++)
        if(Numbers[i][x[i]!=0])
        cout<<Numbers[i][x[i]]<<" ";
    cout<<endl;
    flag=true;

}

void Backtracking(int p)
{
    if(p<=k)
    {
        x[p]=FirstElement(p);
        if(Continue(p))Backtracking(p+1);
        while (ExistSuccessor(p))
        {
            x[p]=Successor(p);
            if(Continue(p)) Backtracking(p+1);
        }
    }
    else ProcessingSolution();

}

int main()
{
    setlocale(0,"Rus");

    cout<<"Введите число: ";
    cin>>n;

    cout<<"Введите количество цифр суммы числа "<<n<<": ";
    cin>>k;

    Filling();
    flag=false;
    Backtracking(0);
    if(!flag) cout<<"Решения нет";



}
