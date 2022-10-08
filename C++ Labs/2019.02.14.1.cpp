#include <iostream>
#include <windows.h>
#include <iomanip>
#include <stdio.h>
#include <conio.h>
#include <cstring>

using namespace std;

class Cars
{
public:
    char Marka[30];
    int price;

    void AddCar();

    Cars(char *, int);
    Cars() {}
};


Cars::Cars(char *Marka, int price)
{
    this->Marka[30]=Marka[30];
    this->price=price;
}

void Cars::AddCar()
{
    system("cls");
    cout<<setw(40)<<"Добавление машины"<<endl;
    cout<<"Введите название машины: ";
    cin.sync();
    gets(Marka);
    cout<<"Введите цену машины: ";
    cin>>price;

}

int main()
{
    setlocale(LC_ALL,"RUS");
    bool Stop = false;
    int n=-1;

    Cars CarsArr[500];

    while(!Stop)
    {
        cout<<setw(40)<<"Добро пожаловать!"<<endl;
        cout<<"1. Менеджер: Добавить машину."<<endl;
        cout<<"2. Дилер: Заказать машину."<<endl;
        cout<<"3. Выйти из программы."<<endl;
        cout<<"Выберите вариант: ";

        if(_kbhit)
        {
            switch(getch())
            {
            case '1':
            {
                ++n;
                cout<<n;
                CarsArr[n].AddCar();

                break;
            }
            case '2':
            {
                char SelectMarka[30];
                int k=0;

                system("cls");
                cout<<setw(40)<<"Поиск машины."<<endl;
                cout<<"Введите марку машины: ";
                cin.sync();
                gets(SelectMarka);

                cout<<"Начинается поиск: ";
                for(int i=0; i<=n; i++)
                    if(strcmp(SelectMarka,CarsArr[i].Marka)==0)
                    {
                        cout<<endl<<endl;
                        cout<<"Данная марка была найдена, её стоимость: "<<CarsArr[i].price<<endl;
                        k++;
                    }
                if(k!=0)
                    getch();

                try
                {
                    if(k==0)
                        throw 1;
                }
                catch(int i)
                {
                    cout<<"К сожалению, данной машины сейчас нет в списке."<<endl;
                }

                break;
            }
            case '3':
            {
                /*for(int i=0; i<=n; i++)
                {
                    cout<<CarsArr[i].Marka;
                    cout<<CarsArr[i].price;
                    cout<<endl;
                }*/

                system("cls");
                Stop=true;
                break;
            }

            }
            system("cls");
        }
    }
}
