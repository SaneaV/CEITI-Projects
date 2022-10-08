//Создать динамическую матрицу и записать её в файл количество элементов в строке равняется n.

#include <iostream>
#include <fstream>

using namespace std;

main()
{
    setlocale (LC_ALL,"RUS");

    ofstream f("file1.txt");

    int n;
    cout<<"Введите размер матрицы: ";
    cin>>n;

    int **A=new int *[n];
    for (int i=0; i<n; i++)
        A[i]=new int [n];
    int k=0;

    for (int j=0; j<n; j++)
    {
        for (int i=0; i<n; i++)
        {
            cin>>A[i][j];
            f<<A[i][j]<<" ";
            k++;
            if (k==n) {f<<endl; k=0;}

        }
    }
}
