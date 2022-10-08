//Вводится N чисел. Подсчитать количество отрицательных.

#include <iostream>

using namespace std;

int main()
{
    setlocale (LC_ALL,"Russian");
    float x,S=0;
   do
   {
       cout<<"Введите число: ";
       cin>>x;
       if (x<0) S++;
   }while(x!=0);
   cout<<S;
}
