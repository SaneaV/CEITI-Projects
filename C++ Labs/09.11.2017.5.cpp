 //Вывести на экран:
 //12345
 //2468
 //369
 //48
 //5

 #include <iostream>

using namespace std;

main()
{
int n=5;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n-i+1;j++)
        cout<<i*j;
        cout<<endl;}
    }
