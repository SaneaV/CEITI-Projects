#include <iostream>
#include <fstream>
#include <windows.h>

using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    fstream fs;
    fs.open("MyFile.txt", fstream::in | fstream::out | fstream::app);

    if(!fs.is_open())
    {
        cout<<"File was not open"<<endl;
    }
    else
    {
        int value;
        string msg;

        cout<<"1. Записать фразу в файл"<<endl;
        cout<<"2. Прочитать информацию из файла"<<endl;
        cin>>value;

        switch(value)
        {
        case 1:
        {
            cin>>msg;
            fs<<msg<<endl;
            break;
        }
        case 2:
            {
                while(!fs.eof())
                {
                    msg = "";
                    getline(fs, msg);
                    cout<<msg;
                }
            }
        }
    }

    fs.close();

    return 0;
}
