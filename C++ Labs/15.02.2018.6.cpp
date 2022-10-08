//Определить является ли введенный с клавиатуры год високосным.

#include <iostream>

using namespace std;

main()
{
    setlocale(LC_ALL,"RUS");

    cout<<"Введите год: ";
    int year;
    cin>>year;

    cout<<"Год високосный: "<<boolalpha<<((year % 4 == 0) && ((year % 100 != 0) || (year % 400 == 0)));
}
