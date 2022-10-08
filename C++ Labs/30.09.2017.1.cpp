//Дан символ, определить, является ли он цифрой

#include <iostream>

using namespace std;

int main ()
{
setlocale (LC_ALL, "Russian");

cout<<"Введите символ, букву, число: ";
char c;
cin>> c;

bool y;
y = isdigit(c);


cout<<"Вы ввели цифру: "<< boolalpha<<(y);
}
