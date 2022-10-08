//Найти среднееарефмитическое N чисел

#include <iostream>

using namespace std;

main()
{
    setlocale (0,"Rus");
    cout<<"Введите n: ";
    float n,S=0,i;
    cin>>n;
    for (i=0; i<n;i++)
    {
        int x;
        cin>>x;
        S+=x;

    }cout<<S/i;
}
