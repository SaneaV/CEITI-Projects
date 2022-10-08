//Дана целочисленная квадратная матрица.  
//Найти сумму элементов в тех столбцах, которые содержат хотя бы один отрицательный элемент.
#include <iostream>

using namespace std;

main()
{
    setlocale(LC_ALL,"Russian");

    cout<<"Введите размер массива: ";
    int n;
    cin>>n;

    int m=n;

    int a[20][20];

    for (int i=0; i<n; i++)
    {
        for (int j=0; j<m; j++)
        {
            cout<<"Введите число: ";
            cin>>a[i][j];
        }

    }

    int S=0;
    for (int i=0; i<n; i++)
    {
        S=0;
        for (int j=0; j<m; j++)
        {
            if (a[i][j]<0)
            {
                for (int i=0; i<m; i++)
                {
                    S+=a[i][j];
                }
                i++;
                cout<<endl<<"Сумма этого столбца: "<<S<<endl;
            }
        }
    }

    for (int i=0;i<n;i++)
    {
        for (int j=0;j<m;j++)

            cout<<a[i][j]<<"\t";
            cout<<endl;

    }
}
