#include <iostream>
#include <cstring>

using std::cout;
using std::endl;
using std::cin;

class String
{
private:
    char *str;

public:
    String(): str(nullptr) {};

    String(char *str)
    {
        int lenght=0;
        while(str!='\0')
            lenght++;

        this->str = new char[lenght];

        for(int i=0; i<lenght; i++)
            this->str[i]=str[i];
    }

    void SetStr(char *str)
    {
        int lenght=0;
        while(str[lenght]!='\0')
            lenght++;

        this->str = new char[lenght];

        for(int i=0; i<lenght; i++)
            this->str[i]=str[i];

        this->str[lenght]='\0';
    }

    void PrintStr()
    {
        cout<<str;
    }


    ~String()
    {
        delete [] str;
    }

};

int main()
{
    String a;

    a.SetStr("Orda");
    a.PrintStr();

    return 0;
}
