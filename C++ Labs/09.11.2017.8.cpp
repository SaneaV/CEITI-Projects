//Дан символ. Определить, является ли знаком препинания. (Тернарный оператор)

#include <iostream>

using namespace std;

main()
{
    setlocale(0,"Rus");
    char sim;
    cout<<"Введите символ: ";
    cin>>sim;
    sim=='.' or sim==',' or sim=='?' or sim=='!'? cout<<"Вы ввели знак препинания!":cout<<"Ваш символ не знак препинания!";
}
