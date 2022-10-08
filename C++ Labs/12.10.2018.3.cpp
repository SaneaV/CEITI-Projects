//Даны два числа
//Проверить, какое из чисел самое большое не используя операторы сравнения.

#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL,"RUS");

    int a,b;

    cout<<"Введите число \"a\": ";
    cin>>a;
    cout<<"Введите число \"b\": ";
    cin>>b;


    bool SecondCheck=true;
    bool FirstCheck=true;

    int Ra;
    int Rb;

    Ra=a;
    Rb=b;

    while(SecondCheck and FirstCheck)
    {
        SecondCheck=false;
        FirstCheck=false;

        if(a-=1)
            FirstCheck=true;
        if(b-=1)
            SecondCheck=true;
    }

    if(FirstCheck) cout<<"Число "<<Ra<<" больше"<<endl;
    if(SecondCheck) cout<<"Число "<<Rb<<" больше"<<endl;
}
