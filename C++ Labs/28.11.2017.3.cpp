//Найти среднее арефмитическое произведений элементов каждой строки матрицы

#include <iostream>

using namespace std;

main()
{
    setlocale (LC_ALL,"Rus");
    int n,m,x[20][20];
    cout<<"Введите количество строк: ";
    cin>>n;
    cout<<"Введите количество столбцов: ";
    cin>>m;
    for (int i=0;i<n;i++)
        for (int j=0;j<m;j++)
    {
        cout<<"Введите число: ";
        cin>>x[i][j];
    }
    int S=1;
    for (int i=0;i<n;i++)
    {
        S=1;
        for (int j=0;j<m;j++)
            {
                S*=x[i][j];
            }
            S/=m;
            cout<<"Среднее арефметическое произведний "<<i<<": "<<S<<endl;
    }

}
