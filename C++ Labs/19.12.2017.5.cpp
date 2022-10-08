//Найти площадь трапеции по известным основаниям и высоте.

#include <iostream>

using namespace std;

main()
{
    setlocale(LC_ALL,"Russian");

    cout<<"Введите основание трапеции: ";
    int b,h,a;
    cin>>a;
    cout<<"Введите основание трапеции: ";
    cin>>b;
    cout<<endl<<"Введите высоту трапеции: ";
    cin>>h;
    int S=((a+b)/2)*h;
    cout<<endl<<"Площадь трапеции: "<<S<<endl;
}
