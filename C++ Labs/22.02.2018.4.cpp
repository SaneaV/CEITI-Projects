//Самую длинную строку из файла переписать во второй файл.

#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

main()
{
    ifstream f("Tretia.txt");
    ofstream g("Chetvertai.txt");

    int max=0;
    char str[255];


    while (!f.eof())
    {
        f.getline(str,255);
        if (strlen(str)>max) max=strlen(str);
    }
    f.seekg(0,ios_base::beg);

    while (!f.eof())
    {
        f.getline(str,255);
        if(max==strlen(str)) g<<str<<endl;
    }

    f.close();
    g.close();
}
