//Даны три целых числа. Вывести среднее значение числа
//(средним числом назовем то, которое меньше наибольшего, но больше наименьшего числа).


#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL,"RUS");

    int a,b,c;

    cout<<"Введите число: ";
    cin>>a;
    cout<<"Введите число: ";
    cin>>b;
    cout<<"Введите число: ";
    cin>>c;

    int Medium=0;

    a>b and a<c or a>c and a<b? Medium=a:0;
    b>a and b<c or b>c and b<a? Medium=b:0;
    c>b and c<a or c>a and c<b? Medium=c:0;

    cout<<"Среднее число: "<<Medium<<endl;
}
