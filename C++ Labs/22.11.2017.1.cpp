//Дан массив x, вывести на экран элемент массива и его сумму с соседним элементом

#include <iostream>
using namespace std;
int main()
{
    setlocale (LC_ALL,"Russian");
    int n, i, x[1000], s=0, j;
    cout<<"Введите количество элементов: ";//задаём количество элементов
    cin>>n;
    for (i=0; i<n; i++)
    {
        cout<<"Введите элемент: ";//задаём значения элементов массива
        cin>>x[i];
    }
    i=0;
    int y[1000];
    cout<<"Результат: ";//выполняем и выводим результат
    while (i<n)
    {
        if (x[i+1]!=x[n])
        {
        cout<<x[i]<<" ";//выводим элемент массива
        y[i]=x[i]+x[++i];//выводим сумму этого элемента и соседнего
        cout<<y[i]<<" ";
        }
        if (x[i+1]==x[n])
        {
            cout<<x[i]<<" ";
            i++;
        }
    }
}
