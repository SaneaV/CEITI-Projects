//Дано четырехзначное число. Кратно ли произведение его цифр числу а?

#include <iostream>

using namespace std;

main()
{
    setlocale(LC_ALL,"RUS");

    cout<<"Введите число трёхзначное: ";
    int n;
    cin>>n;

    cout<<"Введите число \"а\": ";
    int a;
    cin>>a;

    int n1,n2,n3;

    n1=n/100;
    n2=n/10%10;
    n3=n%10;

    cout<<"Произведение цифр вашего трёхзначного числа кратно \"а\": "<<boolalpha<<((n1*n2*n3)%a==0);
}
