//Цикл While. Дано n вещественных чисел, найти их среднее арифметическое

#include<iostream>

using namespace std;

main()
{
    setlocale(LC_ALL,"Russian");
    cout<<"Введите n чисел: ";
    int n,i=0,x;
    float S=0;
    cin>>n;
    while (i<n)
    {
        cout<<"Введите число: ";
        cin>>x;
        S+=x;
        i++;
    }
    cout<<S/n*1.0;


}
