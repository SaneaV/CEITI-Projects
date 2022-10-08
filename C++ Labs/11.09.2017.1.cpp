//Математические дейсвтия над двумя числами

#include <iostream>

using namespace std;

int main()
{
    int x,y,c,z,r,b;
    setlocale(LC_ALL,"Russian");

    cout<< "Введите целое число: ";
    cin>> x;
    cout<< "Вы ввели: "<< x<< endl;

    cout<< "Введите целое число: ";
    cin>>y;
    cout<<"Вы ввели: "<< y<< endl;

    c=x+y;
    cout<< "Сумма двух чисел: "<< c<< endl;

    z=x*x;
    cout<<"Первое число во второй степени: "<< z<< endl;

    r=y*y;
    cout<<"Второе число во второй степени: "<< r <<endl;

    b=y-x;
    cout<<"Разность ваших чисел: "<< b<< endl;

    return 0;
}
