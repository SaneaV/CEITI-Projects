//Возвести число в степень, используя только цикл For

 #include <iostream>

using namespace std;

main()
{
    setlocale(0,"Rus");
    int a,b,S=1;
    cout<<"Введите ваше число: ";
    cin>>a;
    cout<<"Введите степень: ";
    cin>>b;
    for (int i=1;i<=b;i++)
    {
        S*=a;
    }cout<<"Ваше число в степени: "<<S;

    }
