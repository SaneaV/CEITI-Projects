//Получаем по отдельности цифры трёхзначного числа

#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    int n1, n2, n3, n;
    cout<< "Введите число: ";
    cin>> n;

    n1= n/ 100;
    n2= n/10%10;
    n3= n%10;

    cout<< n1<< endl;
    cout<< n2<< endl;
    cout<< n3<< endl;

}
