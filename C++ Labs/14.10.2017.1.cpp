//Определить, сколько часов, минут и секунд в N сутках

#include <iostream>

using namespace std;

int main()
{
int n;
setlocale(LC_ALL, "Russian");

cout<< "Введите число: ";
cin>> n;

int h,m,s;

h=24*n;
m=60*n;
s=60*n;

cout<< "В "<< n<< " сутках "<< h<< " часов "<< m<< " минут " <<s<< " секунд ";
}
