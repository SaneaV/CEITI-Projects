//Дан символ. Определить, является ли он арифметической операцией.

#include<iostream>

using namespace std;

main()
{
    setlocale(LC_ALL,"RUS");

    cout<<"Введите символ: ";
    char ch;
    cin>>ch;

    cout<<"Ваш символ является арефмитической операцией: "<<boolalpha<<(ch=='-' or ch=='+' or ch=='*' or ch=='/');
}
