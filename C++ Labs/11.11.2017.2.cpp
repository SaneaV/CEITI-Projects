//y=3.5a+7x+25x^2, x<5
//y=a+sqrt(5), x>5
//y=acos(x-6/x-5),x=5

#include <iostream>
#include <cmath>

using namespace std;

main()
{
    setlocale(LC_ALL,"Rus");
    float a,x,y=0;
    char *kav="\"";//*kav - будет у нас кавычками
    cout<<"Добро пожаловать\n";
    cout<<"\nВведите значения для "<<kav<<"a"<<kav<<": ";
    while (!(cin>>a))//Вводим значение и если это не цифра, начинается цикл (! - not)
    {
        cout<<"Ошибка, вы ввели что-то не то.";
        cin.clear();//Очищает поток
        cin.sync();//Удаляет данные из буффера
        cout<<" Введите значение для "<<kav<<"a"<<kav<<": ";
    }
    cout<<"\nВведите значения для "<<kav<<"x"<<kav<<": ";
    while (!(cin>>x))//Вводим значение и если это не цифра, начинается цикл (! - not)
    {
        cout<<"Ошибка, вы ввели что-то не то. ";
        cin.clear();//Очищает поток
        cin.sync();//Удаляет данные из буффера
        cout<<" Введите значение для "<<kav<<"x"<<kav<<": ";
    }

    if (x<5)
    {
        cout<<"\n(x<5)\n";
        y=3.5*a+7*x-2.5*pow(x,2);
    }
    else if (x>5)
    {
        cout<<"\n(x>5)\n";
        y=a+sqrt(5);
    }
    else
    {
        cout<<"\n(x=5)\n";
        y=(a*cos((x-6)/(x+5)));
    }
    cout<<"\nОтвет: y = "<<y<<"\n\n";
}
