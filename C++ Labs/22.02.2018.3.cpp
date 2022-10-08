//Подсчитать количество строк в файле.

#include <iostream>
#include <fstream>

using namespace std;

main()
{
    ifstream f("Tretia.txt");

    char str[255];

    int k=0;

    while (!f.eof())
    {
      if (f.getline(str,255)) k++;
    }

    cout<<k;
}
