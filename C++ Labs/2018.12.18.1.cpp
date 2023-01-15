#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL,"RUS");

    int Months[13];

    for(int i=0;i<12;i++)
    {
        cout<<"Введите температуру для "<<i+1<<" месяца: ";
        cin>>Months[i];
    }

    float MedPoz=0;
    float MedNeg=0;
    int KPoz=0;
    int KNeg=0;

    for(int i=0;i<12;i++)
    {
        if(Months[i]>0)
        {
            MedPoz+=Months[i];
            KPoz++;
        }
        else
        {
            MedNeg+=Months[i];
            KNeg++;
        }
    }

    ///Округление чисел
    float Poz = int((MedPoz/(KPoz*1.0))*100 + 0.5)/100.0;
    float Neg = int((MedNeg/(KNeg*1.0))*100 + 0.5)/100.0;



    cout<<endl<<endl;
    if(KPoz!=0) cout<<"Средняя положительная температура в году: +"<<Poz<<endl;
    else cout<<"Положительных температур в этом году не было"<<endl;
    if(KNeg!=0)cout<<"Средеяя отрицательная темапература в году: "<<Neg<<endl;
    else cout<<"Отрицательных температур в этом году не было"<<endl;
}
