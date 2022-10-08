/*Оплата остатка
Простой пример жадного алгоритма - тот, который используется для решения следующей задачи:
нам нужно дать сдачу клиенту, используя минимальное число монет (банкнот).*/


#include <iostream>

using namespace std;

int Sdacha;
int Kolichestvo[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0};

bool ElementExist()
{
    if(Sdacha!=0)
        return true;
    return false;
}

void SelectElement()
{
    if(Sdacha>=1000)
    {
        Kolichestvo[8]++;
        Sdacha-=1000;
    }
    else if(Sdacha>=500)
    {
        Kolichestvo[7]++;
        Sdacha-=500;
    }
    else if(Sdacha>=200)
    {
        Kolichestvo[6]++;
        Sdacha-=200;
    }
    else if(Sdacha>=100)
    {
        Kolichestvo[5]++;
        Sdacha-=100;
    }
    else if(Sdacha>=50)
    {
        Kolichestvo[4]++;
        Sdacha-=50;
    }
    else if(Sdacha>=20)
    {
        Kolichestvo[3]++;
        Sdacha-=20;
    }
    else if(Sdacha>=10)
    {
        Kolichestvo[2]++;
        Sdacha-=10;
    }
    else if(Sdacha>=5)
    {
        Kolichestvo[1]++;
        Sdacha-=5;
    }
    else
    {
        Kolichestvo[0]++;
        Sdacha-=1;
    }

}

int main()
{
    setlocale(LC_ALL,"RUS");

    cout<<"Введите сумму сдачи: ";
    cin>>Sdacha;

    while(ElementExist())
    {
        SelectElement();
    }

        if(Kolichestvo[0]!=0) cout<<"Купюр номиналом 1 лей: "<<Kolichestvo[0]<<endl;
        if(Kolichestvo[1]!=0) cout<<"Купюр номиналом 5 лей: "<<Kolichestvo[1]<<endl;
        if(Kolichestvo[2]!=0) cout<<"Купюр номиналом 10 лей: "<<Kolichestvo[2]<<endl;
        if(Kolichestvo[3]!=0) cout<<"Купюр номиналом 20 лей: "<<Kolichestvo[3]<<endl;
        if(Kolichestvo[4]!=0) cout<<"Купюр номиналом 50 лей: "<<Kolichestvo[4]<<endl;
        if(Kolichestvo[5]!=0) cout<<"Купюр номиналом 100 лей: "<<Kolichestvo[5]<<endl;
        if(Kolichestvo[6]!=0) cout<<"Купюр номиналом 200 лей: "<<Kolichestvo[6]<<endl;
        if(Kolichestvo[7]!=0) cout<<"Купюр номиналом 500 лей: "<<Kolichestvo[7]<<endl;
        if(Kolichestvo[8]!=0) cout<<"Купюр номиналом 1000 лей: "<<Kolichestvo[8]<<endl;

}
