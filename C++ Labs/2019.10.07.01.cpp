#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL,"RUS");

    int P0 = 0;
    float PM = 0;
    float PN = 0;

    cout<<"Введите количество бактерий: ";
    cin>>P0;

    cout<<"Введите процент рождаемости: ";
    cin>>PN;

    PN/=100;

    cout<<"Введите процент смертности: ";
    cin>>PM;

    PM/=100;

    cout<<endl<<endl;

    for(int i=1;i<=10;i++)
    {
        cout<<"Секунда - "<<i<<" | Рождаемость - "<<PN*100.0<<" | Смертность - "<<PM*100.0<<" | Популяция - "<<P0<<endl;

        if(i==3)
        {
            PN = PM + 0.06;
        }

        if(i==4)
        {
            PN = PM;
        }

        if(i==6)
        {
            PM = PN + 0.02;
        }

        if(P0<=0) cout<<"Все умерли"<<endl;

        P0+=(PN*P0)-(PM*P0);
    }
}

