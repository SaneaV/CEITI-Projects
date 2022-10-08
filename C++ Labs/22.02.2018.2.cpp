//—оздать файл, в котором будут записаны числа от 1 до 9 и буквы от a до j по 10 в строку.

#include <iostream>
#include <fstream>

using namespace std;

main()
{
    setlocale(LC_ALL,"RUS");

    ofstream f("Vtoraia.txt");

    int n=0;
    int x=0;
    char ch='a';

    while (ch!='k')
    {
        while (n!=11)
        {
            f<<x<<" ";
            n++;
        }
        x++;
        f<<"\n";
        n=0;
        while (n!=11)
        {
            f<<ch<<" ";
            n++;
        }
        ch++;
        f<<"\n";
        n=0;
    }
}
