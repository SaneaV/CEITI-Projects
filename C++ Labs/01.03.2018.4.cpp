//Считаем количество гласных букв в файле

#include <iostream>
#include <fstream>

using namespace std;

main()
{
    setlocale(LC_ALL,"RUS");

    ifstream f("file2.txt");

    char x;
    int k=0;

    while (!f.eof())
    {
    f>>x;
        if (!f.eof())
        {
            if (x=='e' or x=='y' or x=='u' or x=='i' or x=='o' or x=='a')
                k++;
        }
    }
    cout<<"Количество гласных: "<<k;
    f.close();
}

