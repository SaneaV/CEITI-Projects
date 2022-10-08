//¬озвести число в степень, использу€ только цикл For

 #include <iostream>

using namespace std;

main()
{
    setlocale(0,"Rus");
    int a,b,S=1;
    cout<<"¬ведите ваше число: ";
    cin>>a;
    cout<<"¬ведите степень: ";
    cin>>b;
    for (int i=1;i<=b;i++)
    {
        S*=a;
    }cout<<"¬аше число в степени: "<<S;

    }
