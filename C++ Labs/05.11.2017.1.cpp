//Возвести число в степень в цикле do..while

#include <iostream>

using namespace std;

main()
{
   setlocale(LC_ALL,"Russian");
   cout<<"Введите число: ";
   int a=0,b,i=0,S=1;
   cin>>a;
   cout<<"Введите степень: ";
   cin>>b;
   do{
    S*=a;
    i++;
   }while (i<b);
   cout<<S;
}
