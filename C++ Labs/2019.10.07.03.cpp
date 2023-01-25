#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL,"RUS");

    float Mere = 20.0;
    float summa = 0;

    bool Stop1 = true;
    bool Stop2 = true;

    cout<<"Год - "<<1990<<" | "<<" яблоки - "<<Mere<<endl;

    for(int an = 1992 ; Mere>5 or summa<=90 ; an+=2)
    {
        summa+=Mere;
        Mere*=0.8;

        cout<<"Год - "<<an<<" | "<<" яблоки - "<<Mere<<endl;

        if(Mere<5 and Stop1)
        {
            cout<<"Урожай составил меньше 5 тонн"<<endl;
            Stop1 = false;
        }

        if(summa >= 90 and Stop2)
        {
            cout<<"Общая сумма урожая 90 тонн"<<endl;
            Stop2 = false;
        }

    }
}
