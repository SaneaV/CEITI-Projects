//Даны три вещественных числа.
//Вывести на экран те из них, которые принадлежат интервалу (-6,7;11,2).
//Если таких чисел нет, то вывести сообщение «ТАКИХ ЧИСЕЛ НЕТ»

#include <iostream>
using namespace std;
main()
{
    setlocale(LC_ALL,"Russian");
    cout<<"Пропишите первое число: ";
    float p;
    cin>>p;
    cout<<"Пропишите второе число: ";
    float o;
    cin>>o;
    cout<<"Пропишите третье число: ";
    float i;
    cin>>i;

    if (p>-6.7 and p<11.2 or o>-6.7 and o<11.2 or i>-6.7 and i<11.2 )
    {
        if (p>-6.7 and p<11.2) cout<<p<<endl;
        if (o>-6.7 and o<11.2) cout<<o<<endl;
        if (i>-6.7 and i<11.2) cout<<i<<endl;

    }
    else cout<<"Таких чисел нет!";
}


