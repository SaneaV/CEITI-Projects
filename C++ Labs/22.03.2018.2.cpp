//Описать процедуру MinMax(X,Y), записывающую в переменнную X минимальное значение из значений X и Y, и в Y - максимальное значение из этих переменных
//Используя четыре вызова этой процедуры, найти минимальное и максимальное из данных чисел A,B,C,D

#include <iostream>

using namespace std;

float MinMax (float &x, float &y)
{
    if (x>y)
    {
        float c=x;
        x=y;
        y=c;
    }
}

int main()
{
    setlocale(LC_ALL,"RUS");
    float A,B,C,D;
    cout<<"Введите A: ";
    cin>>A;
    cout<<"Введите B: ";
    cin>>B;
    cout<<"Введите C: ";
    cin>>C;
    cout<<"Введите D: ";
    cin>>D;

    MinMax(A,B);
    MinMax(C,D);
    MinMax(A,C);
    MinMax(B,D);
    MinMax(B,C);

    cout<<"Минимальное число: "<<A<<endl;
    cout<<"Второе число: "<<B<<endl;
    cout<<"Третье число: "<<C<<endl;
    cout<<"Максимальное число: "<<D<<endl;
}
