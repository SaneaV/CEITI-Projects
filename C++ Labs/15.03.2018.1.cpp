//Функции. Найти среднее арефмитическое 4 чисел.

#include <iostream>

using namespace std;

float Medium (float a, float b, float c, float z)
{
    return (a+b+c+z)/4.0;
}

int main()
{
    setlocale(LC_ALL,"Rus");

    cout<<"Введите число: ";
    float x1,x2,x3,x4;
    cin>>x1;
    cout<<"Введите число: ";
    cin>>x2;
    cout<<"Введите число: ";
    cin>>x3;
    cout<<"Введите число: ";
    cin>>x4;

    cout<<"Среднее арефмитическое: "<<Medium(x1,x2,x3,x4);
}
