//Найти среднее арефмитическое N отрицательных и положительных чисел.
#include <iostream>

using namespace std;

int main()
{
    setlocale (LC_ALL,"Russian");
    cout<<"Введите количество чисел: ";
    float n,S=0,x,i=0, S1=0,O=0,O1=0;
    cin>>n;
    do
    {
        cout<<"Введите число: ";
        cin>>x;
        if (x>0) {S+=x; O++;}
        else if (x<0) {S1+=x;O1++;}
        i++;
    }while (i!=n);
    cout<<"Среднее арефмитичекое положительных чисел: "<<S/O<<endl;
    cout<<"Среднее арефмитичекое отрицательных чисел: "<<S1/O1<<endl;
}
