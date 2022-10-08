//Создаём файл с числами

#include <iostream>
#include <fstream>

using namespace std;

main()
{
    setlocale(LC_ALL,"RUS");
    ofstream f("file1.txt");

    int n;
    cout<<"Введите количество чисел: ";
    cin>>n;

    float x;

    for (int i=0;i<n;i++)
    {
        cout<<"Введите вещественное число: ";
        cin>>x;
        f<<x<<" ";
    }
    f.close();

}
