//Проверить, является ли введённый символ гласной буквой: а) английского б) русского языка

#include <iostream>
#include <windows.h>

using namespace std;

main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout<<"Введите символ: ";
    char ch;
    cin>>ch;


    bool y;
    y= ch=='o' or ch=='e' or ch=='y' or ch=='u' or ch=='i' or ch=='a';
    cout<<"Ваш символ является гласной буквой англисйкого алфавита: "<< boolalpha<< (y);

    bool t;
    t= ch=='й' or ch=='у' or ch=='е' or ch=='а' or ch=='ы' or ch=='о' or ch=='э' or ch=='я' or ch=='и' or ch=='ю';
    cout<<"\nВаш символ является гласной буквой русского алфавита: "<<boolalpha<< (t);
}
