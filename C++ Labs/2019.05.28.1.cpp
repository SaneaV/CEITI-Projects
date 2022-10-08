#include <iostream>
#include <windows.h>
#include <conio.h>
#include <cstring>

using namespace std;

class product
{
private:
    string postavshik;
    int price;
    int kolOf;
public:
    virtual void getdata()
    {
        cout<<"Введите имя поставщика: ";
        cin>>postavshik;
        cout<<"Введите цену: ";
        cin>>price;
        cout<<"Введите количество продукта: ";
        cin>>kolOf;
    }

    virtual void putdata()
    {
        cout<<"имя поставщика: "<<postavshik<<endl;
        cout<<"цена: "<<price<<endl;
        cout<<"количество продукта: "<<kolOf<<endl;
    }

    int Getprice()
    {
        return price;
    }

    virtual bool isDeficiency() = 0;
    virtual int Summa() = 0;
};

class delivery
{
private:
    float Massive[3];
public:
    void getdata()
    {
        cout<<"Введите сумму продаж за первый месяц: ";
        cin>>Massive[0];
        cout<<"Введите сумму продаж за второй месяц: ";
        cin>>Massive[1];
        cout<<"Введите сумму продаж за третий месяц: ";
        cin>>Massive[2];
    }
    void putdata()
    {
        cout<<"Сумма продаж за первый месяц: "<<Massive[0]<<endl;
        cout<<"Сумма продаж за второй месяц: "<<Massive[1]<<endl;
        cout<<"Сумма продаж за третий месяц: "<<Massive[2]<<endl;
    }

    int ObshSum()
    {
        return Massive[0]+Massive[1]+Massive[2];
    }

};


class crupa : public product, public delivery
{
    char nameCrupa[255];
    int weight;

public:

    void getdata()
    {
        product::getdata();
        delivery::getdata();
        cout<<"Введите название крупы: ";
        cin>>nameCrupa;
        cout<<"Введите вес: ";
        cin>>weight;
    }
    void putdata()
    {
        product::putdata();
        delivery::putdata();
        cout<<"Название крупы: "<<*nameCrupa<<endl;
        cout<<"Вес: "<<weight<<endl;
    }

    int Summa()
    {
        return ObshSum()*Getprice();
    }

    bool isDeficiency()
    {
        return (weight <=5) ? true : false;
    }
};


class sok : public product, public delivery
{
private:
    char nameSok[255];
    int litr;
    char sostav[255];
public:
    void getdata()
    {
        product::getdata();
        delivery::getdata();
        cout<<"Введите название сока: ";
        cin>>nameSok;
        cout<<"Введите лираж: ";
        cin>>litr;
        cout<<"Введите состав: ";
        cin>>sostav;
    }
    void putdata()
    {
        product::putdata();
        delivery::putdata();
        cout<<"Название сока: "<<*nameSok<<endl;
        cout<<"Литраж: "<<litr<<endl;
        cout<<"Состав: "<<*sostav<<endl;
    }
    bool isDeficiency()
    {
        return (litr >= 10) ? true : false;
    }

    int Summa()
    {
        return ObshSum()*Getprice();
    }


};


int main()
{
    setlocale(LC_ALL,"RUS");

    product *prod[100];
    int n=0;
    bool Menu = true;
    int Select;

    do
    {
        cout<<"Добавить крупу(1) "<<endl;
        cout<<"Добавить сок(2)"<<endl;
        cout<<"Вывести на экран(3)"<<endl;
        cout<<"Вывести общую сумму(4)"<<endl;
        cout<<"Вывести отдельную сумму(5)"<<endl;
        cout<<"Выйти из программы (0)"<<endl;
        cout<<"Ваш выбор: ";
        cin>>Select;


        switch(Select)
        {
        case 1:
        {
            cout<<endl;
            prod[n] = new crupa;
            prod[n++]->getdata();
            break;
        }
        case 2:
        {
            cout<<endl;
            prod[n] = new sok;
            prod[n++]->getdata();
            break;
        }
        case 3:
        {
            for(int i=0; i<n; i++)
            {
                prod[i]->putdata();
                if(prod[i]->isDeficiency())
                    cout<<endl<<"Нужен заказ!!!"<<endl;
                cout<<endl;
            }
            system("Pause");
            break;
        }
        case 4:
        {
            int Sum = 0;
            for(int i=0; i<n; i++)
            {
                Sum += prod[i]->Summa();
            }
            cout<<"Общая сумма: "<<Sum<<endl;
            system("PAUSE");
            break;
        }
        case 5:
        {
            int y = 0;
            int Sum = 0;
            cout<<"Введите номер объекта: ";

            cin>>y;
            Sum += prod[y]->Summa();
            cout<<"Общая сумма: "<<Sum<<endl;
            system("PAUSE");
            break;
        }
        case 0:
        {
            Menu = false;
            break;
        }
        }

        system("cls");

    }
    while(Menu);

    system("cls");


}

