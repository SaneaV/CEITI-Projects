//Дано число. С помощью целочисленного деления mod и div определить является ли оно трехзначным.

#include <iostream>
#include <cmath>
using namespace std;
main()
{
    setlocale (LC_ALL,"Rus");
    cout<<"n: ";
    int n,div,f=0;
    cin>>n;
    div = n/1000;//целая часть от деления
    f= fmod (n,100);//остаток от деления
    ((div==0)and(fmod (n,100)!=n))? cout<<"Число трёхзначное":cout<<"Число не трёхзначное";
}
