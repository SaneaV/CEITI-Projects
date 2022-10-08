#include <iostream>

using namespace std;

int strlen(const char *str)
{
    int i=0;

    while(str[i]!='\0')
        i++;

    return i;

}

int main()
{
    char *str = "Hello, here are 26 symbols";
    cout<<strlen(str);

    return 0;
}
