//Создаём два файла. В один записываем чётные числа, в другой нечётные.

#include <iostream>
#include <fstream>

using namespace std;

main()
{
    setlocale (LC_ALL,"RUS");
    ofstream f("Cet.out.txt");
    ofstream g("Necet.out.txt");

    int x;
    int n;

    cout<<"Введите количество символов: ";
    cin>>n;

    for (int i=0;i<n;i++)
    {
        cout<<"Введите число: ";
        cin>>x;

        if (x%2==0) {f<<x;}
        else {g<<x;}
    }

    f.close();
    g.close();
}
