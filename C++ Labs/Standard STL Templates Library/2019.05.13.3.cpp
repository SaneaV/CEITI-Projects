#include <iostream>
#include <windows.h>

int main(int argc, char* argv[])
{
    SetConsoleOutputCP(1251);

    for(int i=0; i<argc; i++)
        std::cout<<argv[i]<<std::endl;

    system("PAUSE");
    return 0;
}
