#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL,"RUS");

    float S = 0;
    float D = 0;
    float C = 0;
    int N = 0;

    cout<<"Сумма счёта: ";
    cin>>S;

    cout<<"Процент прибыли: ";
    cin>>D;

    D/=100;

    cout<<"Снимает процент: ";
    cin>>C;

    C/=100;

    cout<<"Количество месяцев: ";
    cin>>N;

    for(int i=0;i<N;i++)
    {
        cout<<"Месяц - "<<i+1;
        cout<<" | Cумма - "<<S;
        cout<<" | Доход - "<<S*D;
        cout<<" | Сняли - "<<S*C;
        S+=((S*D)-(S*C));
        cout<<" | После снятия - "<<S<<endl;
    }
}
