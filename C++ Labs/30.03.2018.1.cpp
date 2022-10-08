//Дан текстовый файл F.txt. Переписать строки файла F.txt  в файл G.txt, заменяя все маленькие буквы на большие. Порядок строк сохранить.

#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

int main()
{
    setlocale(LC_ALL,"RUS");

    ifstream f("F.txt");
    ofstream g("G.txt");

    int n;

    char str[256];
    while(f.getline(str,256))
    {
        n=strlen(str);
        for(int i=0;i<n;i++)
            if (islower(str[i])) str[i]=toupper(str[i]);
        g<<str<<endl;
    }


    g.close();
    f.close();

}
