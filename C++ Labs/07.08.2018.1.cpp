//Дано четырехзначное число. Определить минимальную его цифру.

#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL,"RUS");

    int n;

    cout<<"Введите число: ";
    cin>>n;

    int a1,a2,a3,a4;

    a1 = n/1000;
    a2 = n/100%10;
    a3 = n/10%10;
    a4 = n%10;

    int min;

    a1<a2 and a1<a3 and a1<a4? min=a1:0;
    a2<a1 and a2<a3 and a2<a4? min=a2:0;
    a3<a1 and a3<a2 and a3<a4? min=a3:0;
    a4<a1 and a4<a2 and a4<a3? min=a4:0;

    cout<<"Минимальная цифра числа: "<<min<<endl;
}
