//Ввод матрицы
//Сумма матрицы
//Количество нулей
//Количество положительных в каждой строке
//Одномерный массив,  котором записаны максимальные элементы матрицы
//Матрица, состоящая из -1,0,1 (в зависимости от больше, меньше либо равно нулю.
//Матрица, состоящая из сумм двух вводимых пользователем матриц
//Дана матрица А, поменять местами столбцы по элементам (p,q)

#include <iostream>
#include <cmath>

using namespace std;

main()
{
    setlocale (LC_ALL,"Russian");
    cout<<"Введите количество строк: ";
    int n,m,mat[20][20];
    cin>>n;
    cout<<"Введите количество столбцов: ";
    cin>>m;

    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
        {
            cout<<"Введите число матрицы для "<<i<<" строчки "<<j<<" столбца: ";
            cin>>mat[i][j];
        }

    }
    cout<<"\n\n";
    int S=0,k=0,kstr,min, x[20],pol=0;

    for (int i=0; i<n; i++)
    {
        kstr=0;
        for (int j=0; j<m; j++)
        {
            S+=mat[i][j];//Сумма матрицы
            if (mat[i][j]==0) k++;//Количество нулей
            if (mat[i][j]>0) kstr++;//Количество положительных в каждой строке

        }
        cout<<"Количество положительных элементов в "<<i<<" строке: "<<kstr<<endl;

    }
    cout<<"\n\n\n";
    cout<<"Сумма матрицы: "<<S<<endl;
    cout<<"Нулевых элементов в вашей матрице: "<<k<<endl;

    for (int i=0; i<n; i++)
    {
        int min=mat[i][0];
        pol++;
        for (int j=0; j<m; j++)
        {
            if (mat[i][j]>min)
            {
                min=mat[i][j];      //Одномерный массив, в который записываем максимальные элементы строк матрицы
                x[i]=mat[i][j];
            }
        }
    }


    cout<<"\nОдномерный массив из максимальных элементов матрицы: "<<endl;
    for (int i=0; i<pol; i++)
    {
        cout<<x[i]<<" ";
    }

    int matz[20][20];
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<m; j++)
            matz[i][j]=mat[i][j];

    }

    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
        {
            if (mat[i][j]>0)
            {
                mat[i][j]=1;
            }
            else if (mat[i][j]<0)
            {
                mat[i][j]=-1;
            }
            else
            {
                mat[i][j]=0;
            }
        }
    }

    cout<<"\n\nМатрица, состоящая из -1,0,1 (в зависимости от больше, меньше либо равно нулю."<<endl;
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<m; j++)
            cout<<mat[i][j]<<"\t";
        cout<<endl;
    }

    cout<<"\n\nСоздадим новую матрицу(c теми же размерами): "<<endl;
    int b[20][20];
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<m; j++)
        {
            cout<<"Введите число матрицы для "<<i<<" строчки "<<j<<" столбца: ";
            cin>>b[i][j];
        }
    }

    int c[20][20];
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<m; j++)
        {
            c[i][j]=matz[i][j]+b[i][j];
        }
    }

    cout<<"\n\nСумма исходной матрицы и новой: "<<endl;

    for (int i=0; i<n; i++)
    {
        for (int j=0; j<m; j++)

            cout<<c[i][j]<<"\t";
        cout<<endl;

    }

    cout<<"\n\nТеперь поменяем местами строки: "<<endl;
    cout<<"Введите номер строки, которую мы заменим: ";
    int q=0,p=0,t;
    cin>>p;
    cout<<"Ввидети номер строки, на которую мы заменим: ";
    cin>>q;


    for (int i=0; i<n; i++)
    {
        for (int j=0; j<m; j++)

        {
            t=matz[q][j];
            matz[q][j]=matz[p][j];
            matz[p][j]=t;
        }
    }

    for (int i=0; i<n; i++)
    {
        for (int j=0; j<m; j++)
            cout<<matz[i][j]<<"\t";
        cout<<endl;
    }

}
