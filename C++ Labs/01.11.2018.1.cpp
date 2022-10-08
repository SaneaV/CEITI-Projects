//Двоичный поиск. Рассмотрим множество A={a1, a2, ..., an}, элементами которого являются упорядоченные в порядке возрастания целые числа.
//Напишите программу, которая определяет,
//содержит ли множество A заданное число p. Оцените временную сложность написанной программы.

#include<iostream>

using namespace std;

float A[100],x;
int n, p;


bool Find(int i, int j)
{
    int m;
    if(i!=j)
    {
        m=(i+j)/2;
        if(A[m]==p)
            return true;
        else if (p<A[m])
            return Find(i, m-1);
        else
            return Find (m+1, j);
    }
    else if (A[i]==p)
        return true;
    else
        return false;
}

int main()
{
    setlocale(LC_ALL,"RUS");
    cout<<"Введите размер массива: ";
    cin>>n;

    cout<<"Введите число поиска: ";
    cin>>p;

    for(int i=0; i<n; i++)
    {
        A[i]=i+1;
    }

    if(Find(0, n-1))
        cout<<"Yes";
    else cout<<"No";


}
