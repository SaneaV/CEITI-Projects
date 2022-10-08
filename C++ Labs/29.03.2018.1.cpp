//Написать программу, используя функцию, которая возвращает n! (n>0)

#include <iostream>

using namespace std;

int Factorial (int x)
{
    int m=1;

    for (int i=1; i<=x; i++)
    {
        m*=i;
    }

    return (m);

}

int main()
{
    setlocale(LC_ALL,"RUS");

    int n;
    do
    {
        cout<<"Введите число: ";
        cin>>n;
    }
    while (n<0);

    cout<<"!n = "<<Factorial(n);
}
