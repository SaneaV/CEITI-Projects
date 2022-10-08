//Если x<2, y = b * ((2*x^2+7.3)/3)
//Есди 2<=x<=3, y = b - abs(x^2-5*x+6)
//Если x>3, y = b*x+sin(x)

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    setlocale(LC_ALL,"RUS");

    float b,x,y;

    cout<<"Введите значение \"х\": ";
    cin>>x;
    cout<<"Введите значение \"b\": ";
    cin>>b;

    x<2? y = b*((2*pow(x,2)+7.3)/3): 2<=x and x<=3? y = b-abs(pow(x,2)-5*x+6): x>3? y = b*x+ sin(x):0;

    cout<<"y = "<<y<<endl;
}
