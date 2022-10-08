//Дано натуральное число n. Вычислить сумму: (2.0*n-1)*(2.0*n+1)+S(n-1);

#include <iostream>

using namespace std;

float S (int n)
{
    if (n<=0)
        return 0;
    else
        while (n>=0)
            return (2.0*n-1)*(2.0*n+1)+S(n-1);
}

int main()
{
    setlocale(LC_ALL,"RUS");
    int x;
    cout<<"Введите \"n\": ";
    cin>>x;

    cout<< S(x);
}
