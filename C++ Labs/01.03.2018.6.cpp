//Выводим на экран содержимое файлов с чётными и нечётными числами.

#include <iostream>
#include <fstream>

using namespace std;

main()
{
    setlocale (LC_ALL,"RUS");
    int x;

    ifstream f("Cet.out.txt");
    ifstream g("Necet.out.txt");

    cout<<"Содержание первой папки: ";

    while (!f.eof())
    {
        f>>x;
        cout<<x<<" ";
    }

    cout<<"\n\nСодержание второй папки: ";

    while (!g.eof())
    {
        g>>x;
        cout<<x<<" ";
    }

    f.close();
    g.close();
}

