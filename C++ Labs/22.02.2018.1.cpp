//Записать n чисел в файл по 4 в строку

#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

main()
{
    setlocale(LC_ALL,"RUS");
    ofstream f("Numbers.txt");

    int n,x;
    cout<<"Введите количество чисел: ";
    cin>>n;
    int k=0;

    for (int i=0;i<n;i++)
    {
        cout<<"Введите число: ";
        cin>>x;
        if (x<200 and x>-200) {f<<x<<"\t";k++;}
        if (k==4) {f<<"\n";k=0;}
    }
}

