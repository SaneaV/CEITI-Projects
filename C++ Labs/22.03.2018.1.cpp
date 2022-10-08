//Создать процедуру, для вычисления периметра и площади прямоугольника по его сторонам.

#include <iostream>

using namespace std;

void DlinaShirina (int x, int y, int &s, int &p)
{
    p=2*(x+y);
    s=x*y;
}

int main()
{
    setlocale(LC_ALL,"RUS");
    cout<<"Введите сторону a: ";
    int a,b;
    cin>>a;
    cout<<"Введите сторону b: ";
    cin>>b;
    int ploshadi, perimetr;

    DlinaShirina(a,b,perimetr,ploshadi);
    cout<<"Периметр: "<<perimetr<<endl<<"Площади: "<<ploshadi;



}
