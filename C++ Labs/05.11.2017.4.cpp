//Каждый день пловец проплывал по 300 метров. Определить, в какой день он проплывёт 5100 метров, 30000 метров.

#include<iostream>
using namespace std;
main()
{
    setlocale (LC_ALL,"Russian");
    int Proplil=3000, deni=1;
    do
    {
        cout<<"В "<<deni<<" день проплыл: "<<Proplil<<" метров\n";
        Proplil+=300;
        deni++;
        if (Proplil==5100) (cout<<"\nВ "<<deni<<" день проплыл: 5000 метров\nЕГО НОВЫЙ РЕКОР");
        if (Proplil==30000) (cout<<"В "<<deni<<" день проплыл: 30000 метров\nЕГО РЕКОРД ДОСТИГНУТ");

    }while (Proplil<=30000);
}
