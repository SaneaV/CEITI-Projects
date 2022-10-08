//Найти среднее арифметическое одномерного массива.

#include <iostream>
#include <cstring>

using namespace std;


int Medium(int x[30], int m)
{
    int S=0;
    for (int i=0;i<m;i++)
    {
        S+=x[i];
    }
    int rez=S/m;
    return S/m;
}

main()
{
    setlocale(LC_ALL,"RUS");

    cout<<"Введите количество чисел: ";
    int n;
    cin>>n;
    int x1[30];

    for (int i=0;i<n;i++)
    {
        cout<<"Введите число: ";
        cin>>x1[i];
    }

    cout<<"Среднее арефмитическое: "<<Medium(x1,n);

}
