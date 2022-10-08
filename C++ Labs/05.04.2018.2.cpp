//Рекурсия. Вычисление по формуле: P(n-1)*(3*n-2);

#include <iostream>

using namespace std;

int P(int n)
{
    if (n==1) return 1;
    else return P(n-1)*(3*n-2);
}

int main()
{
    setlocale(LC_ALL,"RUS");

    cout<<"Введите число: ";
    int m;
    cin>>m;

    cout<<P(m);
}
