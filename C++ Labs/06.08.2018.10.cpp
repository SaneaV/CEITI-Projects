//Дано четырехзначное число. Определить максимальную его цифру.

#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL,"RUS");

    int Number;

    cout<<"Введите число: ";
    cin>>Number;

    int a1,a2,a3,a4;

    a1 = Number/1000;
    a2 = Number/100%10;
    a3 = Number/10%10;
    a4 = Number%10;

    int max=0;

    a1>a2 and a1>a3 and a1>a4? max=a1:0;
    a2>a1 and a2>a3 and a2>a4? max=a2:0;
    a3>a1 and a3>a2 and a3>a4? max=a3:0;
    a4>a1 and a4>a2 and a4>a3? max=a4:0;

    cout<<"Максимальная цифра в числе: "<<max<<endl;
}
