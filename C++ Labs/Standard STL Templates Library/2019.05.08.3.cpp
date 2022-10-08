#include <iostream>
//#define DEBUG
#define DEBUG2 1

using namespace std;

int main()
{
    setlocale(LC_ALL,"RUS");

#ifdef DEBUG
    cout<<"Начало цикла: "<<endl;

    #else
    cout<<"Дебаг не определён"<<endl;
#endif // DEBUG

    for(int i=0; i<5; i++)
        cout<<i<<"\t";

#ifdef DEBUG
            cout<<endl<<"Конец цикла: "<<endl;
#endif // DEBUG


#ifndef DEBUG
cout<<endl<<"Дебаг не определён"<<endl;
#endif // DEBUG


#if DEBUG2 == 2
cout<<endl<<"Дебаг определён"<<endl;
#elif DEBUG2 == 1
cout<<"Дебаг определён, но значение другое."<<endl;
#endif // DEBUG2

    return 0;
}
