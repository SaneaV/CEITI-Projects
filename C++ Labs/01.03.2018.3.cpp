//Создаём файл с символами

#include <iostream>
#include <fstream>

using namespace std;

main()
{
    setlocale(LC_ALL,"RUS");
    ofstream f("file2.txt");

    int n;
    cout<<"Введите количество символов: ";
    cin>>n;

    char x;

    for (int i=0;i<n;i++)
    {
        cout<<"Введите символ: ";
        cin>>x;
        f<<x<<" ";
    }
    f.close();

}

