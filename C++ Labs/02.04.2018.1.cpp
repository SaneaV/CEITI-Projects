//Работа с файлами. Из файла считывается количество нулей и они вводятся в другой файл.

#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

int main()
{
    setlocale(LC_ALL,"russian");

    ifstream f("F.in.txt");
    ofstream g("F.out.txt");

    char str[256];
    int k=0;
    int x=0;
    int n;

    while(f.getline(str,256))
    {
        n=strlen(str);
        for(int i=0;i<n;i++)
            if (str[i]=='0') k++;

        for (int j=0;j<k;j++)
        g<<x<<" ";
        g<<endl;
        k=0;
    }

    f.close();
    g.close();

}
