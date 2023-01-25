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


    if(PN==PM)
        cout<<"Количество популяции не изменяется!"<<endl;
    if(PN==1 and PM==0)
        cout<<"Количество популяции за одну секунду увеличится в 2 раза."<<endl;

    int x = P0;
    bool Popx2 = false;
    int time = 0;

    int PMtemp;
    int PNtemp;

    while(!Popx2)
    {
        time++;

        PMtemp = PM*P0;
        PNtemp = PN*P0;

        cout<<"Бактерий - "<<P0<<" | Родилось - "<<PNtemp<<" | Умерло - "<<PMtemp<<endl;

        if(P0/x>=2)
        {
            Popx2 = true;
            cout<<"Популяция увеличилась в 2 раза спустя: "<<time<<" секунд"<<endl;
        }

        if(P0 <= 0)
        {
            Popx2 = true;
            cout<<"Все умерли"<<endl;
        }

        if(PMtemp == 0 and PNtemp == 0 )
        {
            cout<<"Дальше ничего не меняется"<<endl;
            Popx2 = true;
        }

         if(PMtemp == PNtemp)
        {
            cout<<"Дальше ничего не меняется"<<endl;
            Popx2 = true;
        }


        P0+=(PN*P0)-(PM*P0);

    }

}
