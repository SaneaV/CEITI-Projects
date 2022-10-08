//—умма элементов матрицы по модулю

#include <iostream>
#include <cmath>

using namespace std;

main()
{
    setlocale (LC_ALL,"Russian");
    cout<<"¬ведите количество строк: ";
    int n,m,mat[20][20];
    cin>>n;
    cout<<"¬ведите количество столбцов: ";
    cin>>m;

    int S=0;
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
        {
            cout<<"¬ведите число матрицы дл€ "<<i<<" строчки "<<j<<" столбца: ";
            cin>>mat[i][j];
            mat[i][j]=abs(mat[i][j]);
            S+=mat[i][j];
        }

    }
    cout<<"\n\n";
    cout<<"—умма элементов матрицы: "<<S;

}
