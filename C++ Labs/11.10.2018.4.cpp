//Дано число n (1<=n<=255).
//Составить программуЮ которая найдёт сумму: 3^n+4^n+7^n


#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL,"rus");
    int n;

    cout<<"Введите \"n\": ";
    cin>>n;

    int a,b;


    switch(n%4)
    {
    case 0:
    {
        a=1;
        cout<<"Последняя цифра 1"<<endl;
        break;
    }
    case 1:
    {
        a=3;
        cout<<"Последняя цифра 9"<<endl;
        break;
    }
    case 2:
    {
        a=9;
        cout<<"Последняя цифра 7"<<endl;
        break;
    }
    case 3:
    {
        a=7;
        cout<<"Последняя цифра 3"<<endl;
        break;
    }
    }

    switch (n%2)
    {
    case 0:
    {
        b=6;
        cout<<"Последняя цифра 1"<<endl;
        break;
    }
    case 1:
    {
        b=4;
        cout<<"Последняя цифра 9"<<endl;
        break;
    }
    }

    cout<<"S= "<<(a+b+5)%10;
}

