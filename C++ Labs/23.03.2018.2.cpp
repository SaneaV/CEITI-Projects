//Дан текстовый файл F.txt, каждая строка которого содержит два целых числа и три вещественных.
//Напишите программу, которая выводит на экран сумму целых чисел и сумму вещественных в каждой строке. 


#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    setlocale (LC_ALL,"RUS");

    ofstream f("F.txt");

    cout<<"Количесво строк с числами = ";
    int n;
    cin>>n;

    int x;
    float z;

    for (int i=0; i<n; i++)
    {
        cout<<"Введите целое число: ";
        cin>>x;
        f<<x<<" ";
        cout<<"Введите целое число: ";
        cin>>x;
        f<<x<<" ";
        cout<<"Введите вещественное число: ";
        cin>>z;
        f<<z<<" ";
        cout<<"Введите вещественное число: ";
        cin>>z;
        f<<z<<" ";
        cout<<"Введите вещественное число: ";
        cin>>z;
        f<<z<<" "<<endl;

    }
    f.close();


    ifstream g("F.txt");

    int a,b;
    float c,d,e;
    int Sum1=0;
    float Sum2=0;
    int j=0;

    for (int i=0; i<n; i++)
    {
        Sum1=0;
        Sum2=0;

        g>>a>>b>>c>>d>>e;
        Sum1=a+b;
        Sum2=c+d+e;
        cout<<"В строке "<<++j<<", сумма целых чисел: "<<Sum1<<", сумма вещественных чисел: "<<Sum2<<endl;

    }
    g.close();
}

