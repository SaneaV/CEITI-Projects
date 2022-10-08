//Пользователь вводит размер шага, x и b.
//Пока x<b
//y=5*x*3-2*x+1;

#include <iostream>

using namespace std;

main()
{
    setlocale (LC_ALL,"Russian");
    int x,b,a,y=0,h;
    cout<<"Введите размер шага: ";
    cin>>h;
    cout<<"Ведите x: ";
    cin>>x;
    cout<<"Ведите b: ";
    cin>>b;
    do
    {
        y=5*x*3-2*x+1;
        cout<<"x= "<<x<<" y= "<<y<<"\n";
        x=x+h;
    }while(x<b);

}
