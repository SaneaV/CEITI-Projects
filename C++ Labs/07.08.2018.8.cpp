//Если x<=4, y = sqrt(4-x)+a*x^3
//Есди 4<x<=10, y = a + (100/x)+1.4
//Если x>10, y = a*x-10*x+2

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    setlocale(LC_ALL,"RUS");

    float a,x,y;

    cout<<"Введите значение \"х\": ";
    cin>>x;
    cout<<"Введите значение \"a\": ";
    cin>>a;

    x<=4? y = sqrt(4-x)+a*pow(x,3): 4<x and x<=10? y = a+(100/x)+1.4: x>10? y = a*x-10*x+2:0;

    cout<<"y = "<<y<<endl;
}
