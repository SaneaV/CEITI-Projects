//Дано натуральное число n, где n>1, и действительное число x. Вычислить значения многочленов Эрмита Ci(x), i=1,2..n, |x|<=1
//C0(x)=1, C1(x)=x, Ci(x)=2iCi-1(x)-Ci-2(x), где i=2,3...n

#include <iostream>

using namespace std;

float C(int n, float x)
{
    if (n==0) return 1;
    if (n==1) return 2*x;

    return 2*x*C(n-1,x)-C(n-2,x);

}

main()
{
    setlocale(LC_ALL,"RUS");

    int n = 0;
    float x = 0;

    cout<<"Введите значение \"n\": ";
    cin>>n;
    cout<<"Введите значение \"x\": ";
    cin>>x;

    cout<<C(n,x);
}
