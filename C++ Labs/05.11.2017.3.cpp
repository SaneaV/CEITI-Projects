//Каждую минуту бактерий становится в два раза больше. Определить, сколько бактерий будет через n минут


#include <iostream>
#include <cmath>

using namespace std;

main()
{
   setlocale(LC_ALL,"Russian");
   cout<<"Введите сколько минут прошло: ";
   int n,S=0,i=1;
   cin>>n;
   do{
    S=pow(2,n);
    i++;
   }while (i<n);
   cout<<S;
   }

