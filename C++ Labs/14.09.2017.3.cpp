//Получаем последнее натуральное число

#include <iostream>

using namespace std;

int main()

{
    setlocale (LC_ALL, "Russian");
    int x,y,a;
    cout<< "Введите число: ";
    cin>> x;


    a=x%10;

    cout<< "Ваше последнее натуральное число: "<< a<< endl;
}
