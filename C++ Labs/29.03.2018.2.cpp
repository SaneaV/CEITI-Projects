//Написать программу с использованием функции для вычисления периметра и площади треугольника по длинам его сторон

#include <iostream>

using namespace std;

void Preamougolnik (int x, int y, int *perimetr, int *ploshadi)
{
    *perimetr=2*x+2*y;
    *ploshadi=x*y;
}

int main()
{
    setlocale(LC_ALL,"RUS");

    int a,b;
    cout<<"Введите сторону а: ";
    cin>>a;
    cout<<"Введите сторону b: ";
    cin>>b;

    int P,S;

    Preamougolnik(a,b,&P,&S);

    cout<<"Периметр треугольника: "<<P<<endl<<"Площадь треугольника: "<<S;

}
