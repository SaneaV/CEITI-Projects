#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

string GetDatabase()
{
    return "Database was include";
}

string GetImage()
{
    return "Image started work";
}

string GetInfo()
{
    return "Info was sent";
}

void ShowInfo(string (*foo)())
{
    cout<<foo()<<endl;
}

int main()
{
    ShowInfo(GetDatabase);
    ShowInfo(GetImage);
    ShowInfo(GetInfo);

    return 0;
}
