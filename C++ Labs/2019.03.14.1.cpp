#include <iostream>
#include <windows.h>
#include <conio.h>

using namespace std;

class Product
{
private:
    string Name;
    int Price;
    int Weight;
    char Units;
public:
    virtual void Get_Data()
    {
        cout<<"Введите название товара: ";
        cin>>Name;
        cout<<"Введите цену: ";
        cin>>Price;
        cout<<"Введите единицу измерения(l - литры, w - штуки, k - килограммы) : ";
        cin>>Units;

        if(Units=='l')
        {
            cout<<"Введите объём: ";
            cin>>Weight;
        }
        else if (Units=='w')
        {
            cout<<"Введите количество штук: ";
            cin>>Weight;
        }
        else if (Units=='k')
        {
            cout<<"Введите вес: ";
            cin>>Weight;
        }
    }

    virtual void Set_Data()
    {
        cout<<"Название товара: "<<Name<<endl;
        cout<<"Цена товара: "<<Price<<endl;
        if(Units=='l')
        {
            cout<<"Объём: "<<Weight<<" литров"<<endl;
        }
        else if (Units=='w')
        {
            cout<<"Количество: "<<Weight<<" штук"<<endl;
        }
        else if (Units=='k')
        {
            cout<<"Вес: "<<Weight<<" килограмм"<<endl;
        }

    }
};

class Buy : public Product
{
private:
    int dd, mm, yyyy;
public:
    void Get_Data()
    {
        Product::Get_Data();
        char l;
        cout<<"Введите дату покупки (dd.mm.yyyy): ";
        cin>>dd>>l>>mm>>l>>yyyy;
    }

    void Set_Data()
    {
        Product::Set_Data();
        cout<<"Дата покупки товара: "<<dd<<"."<<mm<<"."<<yyyy<<endl;
    }

};

class Check : public Buy
{
public:
    void Set_Data()
    {
        Buy::Set_Data();
    }

};



int main()
{
    setlocale (LC_ALL,"RUS");

    Product *Prod[100];
    int n=0;
    bool Menu = true;

    while(Menu)
    {
        cout<<"1. Создать продукт. "<<endl;
        cout<<"2. Вывести информацию о товаре и продажах. "<<endl;
        cout<<"3. Выйти из программы."<<endl;

        if(_kbhit)
        {
            switch(getch())
            {
            case '1':
            {
                cout<<endl;
                Prod[n] = new Buy;

                Prod[n++]->Get_Data();

                break;
            }
            case '2':
            {
                cout<<endl;
                for(int i=0; i<n; i++)
                {
                    Prod[i]->Set_Data();
                    cout<<endl;
                }

                getch();

                break;
            }
            case '3':
            {
                Menu = false;
                break;
            }
            }

            system("cls");
        }

    }
}
