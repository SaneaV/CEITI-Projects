//Считаем среднее арефмитическое чисел из файла.

#include <iostream>
#include <fstream>

using namespace std;

main()
{
    setlocale(LC_ALL,"RUS");

    ifstream f("file1.txt");

    float Sum=0;
    int k=0;
    float x;

    while (!f.eof())
    {
    f>>x;
        if (!f.eof())
        {
            Sum+=x;
            k++;
        }
    }
    cout<<"Среднее арефмитическое: "<<Sum/k;
    f.close();
}
