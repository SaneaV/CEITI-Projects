//Данн массив содержащий N(1<=N<=1000) целых элементов.
//Напишите программу, которая удаляет все отрицательные числа
#include <iostream>
#include <cmath>
using namespace std;
main()
{
    setlocale (0,"");
    cout<<"Введите количество цифр: ";
    int n, x[1000];
    cin>>n;
    if (n<0) n=abs(n);
    for (int i=0; i<n; i++)
    {
        cout<<"Введите число: ";
        cin>>x[i];
    }
    cout<<"Элементы массива до удаления: \n\n";
    for (int i=0; i<n; i++)
    {
        if (x[i]>0 or x[i]==0) cout<<" "<<x[i]<<endl;
        else cout<<x[i]<<endl;
    }
    int i=0;
    //int j=0;
    while (i<n)
    {
        if (x[i]<0)
        {
            for (int j=i; j<n; j++)
            {
                x[j]=x[j+1];
                //cout<<x[j]<<endl;
            }
            n--;
        }
        else i++;
    }


    cout<<"\n\nЭлементы массива после удаления: \n\n";
    for (i=0; i<n; i++)
    {
        cout<<x[i]<<endl;
    }

}
