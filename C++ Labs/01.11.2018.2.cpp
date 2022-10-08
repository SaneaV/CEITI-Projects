//Поиск элемента способоб "Разделяй и властвуй"

#include<iostream>

using namespace std;

float a[100], p;
bool x;
int n;


bool DirectSolution(int i, int j)
{
    if (j-i<1)
        return true;
    else
        return false;
}

void Processing(int i, bool &x)
{
    cout<<a[i]<<endl;
    if(a[i]==p)
        x=true;
    else
        x=false;
}

void Merge(bool x1, bool x2, bool &x)
{
    x = x1 or x2;
}

void DevideEtImpera(int i, int j, bool &x)
{
    int m;
    bool x1,x2;
    if (DirectSolution(i, j))
    {
        Processing(i, x);
        //cout<<"4"<<endl;
    }
    else
    {
        m=(j-i) / 2;
        //cout<<"0"<<endl;
        DevideEtImpera(i, i+m, x1);
        //cout<<"1"<<endl;
        DevideEtImpera(i+m+1, j, x2);
        //cout<<"2"<<endl;
        Merge(x1, x2, x);
        //cout<<"3"<<endl;
    }

}
int main()
{
    setlocale(LC_ALL,"RUS");
    cout<<"Введите размер массива: ";
    cin>>n;

    cout<<"Введите элемент поиска: ";
    cin>>p;

    for(int i=0; i<n; i++)
    {
        cout<<"Введите элемент: ";
        cin>>a[i];
    }
    DevideEtImpera(0, n-1, x);

    if(x)
        cout<<"Yes";
    else
        cout<<"No";

}
