//Вводится промежуток от а до b. Вывести все числа с тройкой в конце.

#include <iostream>

using namespace std;

main()
{
    setlocale(LC_ALL,"rus");
    cout<<"Добро пожаловать!\n";
    int a,b;
     cin>>a;
     cin>>b;

    while (a<=b)
        {

            int c=0;
            c=a;
            int x=0;
            x=c%10;
            if (x==3){cout<<"В данном числе 3 в конце: "<<a;}
            a++;
        }
}
