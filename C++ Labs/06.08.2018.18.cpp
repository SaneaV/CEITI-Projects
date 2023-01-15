//Даны координаты точки (х,у). Определить по координатам, какой четверти принадлежит точка.

#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL,"RUS");

    int x,y;

    cout<<"Введите координату \"x\": ";
    cin>>x;
    cout<<"Введите координату \"y\": ";
    cin>>y;

    x==0 and y==0? cout<<"Точка находится на позиции (0;0)"<<endl:cout<<"";
    x>0 and y>0? cout<<"Точка принадлежит первой четверти"<<endl:cout<<"";
    x<0 and y>0? cout<<"Точка принадлежит второй четверти"<<endl:cout<<"";
    x<0 and y<0? cout<<"Точка принадлежит третей четверти"<<endl:cout<<"";
    x>0 and y<0? cout<<"Точка принадлежит четвёртой четверти"<<endl:cout<<"";
}
