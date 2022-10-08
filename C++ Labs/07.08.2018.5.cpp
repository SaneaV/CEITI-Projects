//Если x<5, y = 3.5*a+7*x-2.5*x^2
//Есди x=5, y = a + sqrt(5)
//Если x>5, y = a * cos (x-6/x+5)

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    setlocale(LC_ALL,"RUS");

    float x,a,y;

    cout<<"Введите значение \"х\": ";
    cin>>x;
    cout<<"Введите значение \"a\": ";
    cin>>a;

    x<5? y = 3.5*a+7*x-2.*pow(x,2): x==5? y= a + sqrt(5): x>5? y = a*cos((x-6)/(x+5)):0;

    cout<<"y = "<<y<<endl;
}
