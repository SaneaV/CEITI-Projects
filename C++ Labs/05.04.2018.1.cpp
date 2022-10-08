//Рекурсия. Число фибоначи.

#include <iostream>

using namespace std;


int Fib (int m)
{
    if (m==1 or m==2) return 1;
    else return Fib(m-2) + Fib(m-1);
}


int main()
{
    setlocale(LC_ALL,"RUS");

    int n;
    cout<<"Введите число: ";
    cin>>n;
    cout<<endl;
    cout<<Fib(n);

}
