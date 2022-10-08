//—реднее арефмитическое матрицы

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


    for (int i=0; i<n; i++)
    {
        for (int j=0; j<m; j++)
        {
            cout<<"¬ведите число матрицы дл€ "<<i<<" строчки "<<j<<" столбца: ";
            cin>>mat[i][j];
        }
    }
    int S=0;
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<m; j++)
        {
            S+=mat[i][j];
        }
    }
      S/=(n*m);
    cout<<"—реднее арефмитическое матрицы: "<<S;


}
