//Дано четырёхзначное число, поменять его первых два и последних два числа между собой
//1234
//2143

#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL,"RUS");

    int n;

    cout<<"Введите четырёхзначное число: ";
    do
    {
        cin>>n;
    }
    while(n>9999 and n<1000);

    int first, second, third, four;

    for(int i=0;i<4;i++)
    {
        if(i==0) first=n%10;
        //cout<<first<<" ";
        if(i==1) second=n%10;
        //cout<<second<<" ";
        if(i==2) third=n%10;
        //cout<<third<<" ";
        if(i==3) four=n%10;
        //cout<<four<<endl;
        n/=10;
    }

    int Number;

    Number = second + (first*10) + (four*100) + (third*1000);

    cout<<"Ваше число: "<<Number<<endl;
}
