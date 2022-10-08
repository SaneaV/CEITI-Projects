//Найти в каждой строке матрицы максимальные и минимальные элементы и поместить их на место первого и последнего элемента строки соотвественно

#include <iostream>
#include <windows.h>
#include <stdlib.h>

using namespace std;

main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int n,m;

    cout<<"Введите количество строк: ";
    cin>>n;
    cout<<"Введите количество столбцов: ";
    cin>>m;

    int x[n][m];

    //Ввод матрицы
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<m;j++)
        {
            cout<<"Введите число: ";
            cin>>x[i][j];
        }
    }
    //Проверка на минимальность и максимальность
    for (int i=0;i<n;i++)
    {
    int max=x[i][0];
    int min=x[i][0];
    int p=0, q=0, t=0;
    int p1=0, q1=0, t1=0;
        for (int j=0;j<m;j++)
        {
        if (x[i][j] <= min) {min = x[i][j] ; q = i; p = j; }
        if (x[i][j] >= max) {max = x[i][j] ; q1 = i; p1 = j; }
        }
        //Устанавливаем на 0 позицию строки минимальный элемент
        t = x[i][0];
        x[i][0] = x[q][p];
        x[q][p] = t;

        //Устанавливаем на m-1 позицию максимальный элемент строки
        t1 = x[i][m-1];
        x[i][m-1] = x[q1][p1];
        x[q1][p1] = t1;
    }

    cout<<endl;
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<m;j++)
            cout<<x[i][j]<<"\t";
        cout<<endl;
    }

    system ("Pause");
}
