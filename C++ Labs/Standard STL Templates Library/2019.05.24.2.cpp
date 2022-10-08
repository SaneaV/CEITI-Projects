#include <iostream>

using std::cout;
using std::endl;
using std::exception;

void Foo(int value)
{
    if(value<0)
    {
        throw "Значение меньше нуля";
    }

    if(value==1)
    {
        throw exception("Значение равно единице");
    }

    if(value==0)
    {
        throw 1;
    }
}

int main()
{
    setlocale(LC_ALL,"RUS");

    try
    {
        Foo(-55);
    }
    catch(const char *ex)
    {
        cout<<ex<<endl;
    }
    catch(const exception &ex)
    {
        cout<<ex.what()<<endl;
    }
    catch(...)
    {
        cout<<"Произошла ошибка"<<endl;
    }

    return 0;
}
