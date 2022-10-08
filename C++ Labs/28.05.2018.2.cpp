//Модульное программирование

#include <iostream>
#include "28.05.2018.1.cpp"
#include <windows.h>
#include <limits.h>

using namespace std;

int n;


main()
{
    setlocale(LC_ALL,"RUS");

    cout<<"Введите размер массива: ";
    cin>>n;

    int *Array = new int [n];

    InputArray(Array, n);
    Sleep(200);
    system("cls");
    SortArray(Array, n);
    ShowArray(Array, n);
    cout<<endl<<"Сумма элементов: "<<Sum(Array,n);
    cout<<endl<<"Количество чисел, больше нуля: "<<MoreZero(Array,n);
    cout<<endl<<"Произведение элементов: "<<Proizvedenie(Array,n);
    cout<<endl<<"Максимальный элемент: "<<Max(Array, n);
    cout<<endl;

    ShowArray(Array, n);

    cout<<endl;

    SortArraySelect(Array, n);
    ShowArray(Array, n);



}

