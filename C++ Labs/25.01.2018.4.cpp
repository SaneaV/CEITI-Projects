//Сортировка подсчёта №3

#include <iostream>
#include <windows.h>

using namespace std;

main()
{
    SetConsoleCP(1251);
    int a[999],b[999],c[999];
    int  n;

    cout<<"n=";
    cin>>n;
    cout<<"введите "<<n<<" элементов массива"<<endl;
    for(int i=0; i<n; i++) cin>>a[i];
    cout<<"массив до сортировки:"<<endl;
    for(int i=0; i<n; i++) cout<<a[i]<<" ";

    //определение номеров мест:/
     for(int i=0; i<n; i++) b[i] = 0;
    for(int i=n-1; i>0; i--)
        for(int j=i-1; j>=0; j--)
            if (a[i] < a[j])  b[j] = b[j]+1;
            else b[i]= b[i]+1;
    //расстановка элементов массива:
    for(int i=0; i<n; i++) c[ b[i] ] = a[i];

    cout<<endl<<"Отсортированный массив: "<<endl;
    for(int i=0; i<n; i++) cout<<c[i]<<" ";
}

