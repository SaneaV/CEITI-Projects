//÷иклический сдвиг массива в право
#include <iostream>
using namespace std;
int main()
{
    setlocale (LC_ALL,"Russian");
    int n, i, x[1000];
    cout<<"¬ведите количество элементов: ";
    cin>>n;
    n++;
    x[0]=0;
    for (i=1; i<n; i++)
    {
        cout<<"¬ведите элемент: ";
        cin>>x[i];
    }
    x[0]=x[i-1];
    n--;
    cout<<"Ёлементы массива после сдвига: "<<endl;
    for (i=0; i<n; i++)
    {
        cout<<x[i]<<" ";
    }
}

