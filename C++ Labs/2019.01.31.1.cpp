#include <iostream>
#include <windows.h>
#include <conio.h>

using namespace std;

class TollBooth
{
private:
    unsigned int NumberOfCars;
    double Money;

    float LightCar;
    float HardCar;
    float Passenger;
public:
    float PayingCar();
    int NoPayCar();
    void Display();

    TollBooth();
};

TollBooth::TollBooth()
{
    Money = 0;
    NumberOfCars = 0;

    LightCar=0;
    HardCar=0;
    Passenger=0;
}

float TollBooth::PayingCar()
{
    NumberOfCars++;

    cout<<"1. Легковая машина. Тариф = 0.5"<<endl;
    cout<<"2. Грузовая машина. Тариф = 1.5 "<<endl;
    cout<<"3. Пассажирская машина. Тариф = 1"<<endl;

    bool TypeCar = false;

    while(!TypeCar)
    {
        if(_kbhit)
        {
            switch(getch())
            {
            case '1':
            {
                LightCar++;
                Money+=0.5;
                TypeCar=true;
                break;
            }
            case '2':
            {
                HardCar++;
                Money+=1.5;
                TypeCar=true;
                break;
            }
            case '3':
            {
                Passenger++;
                Money+=1.0;
                TypeCar=true;
                break;
            }
            }
        }
    }
}

int TollBooth::NoPayCar()
{
    NumberOfCars++;
}

void TollBooth::Display()
{
    cout<<"Количество проехавших машин: "<<NumberOfCars<<endl;
    cout<<"Общее количество денег: "<<Money<<endl<<endl;

    cout<<"Количество лёгковых машин: "<<LightCar<<endl;
    cout<<"Полученно денег: "<<LightCar*0.5<<endl<<endl;

    cout<<"Количество грузовых машин: "<<HardCar<<endl;
    cout<<"Полученно денег: "<<HardCar*1.5<<endl<<endl;

    cout<<"Количество пассажирских машин: "<<Passenger<<endl;
    cout<<"Полученно денег: "<<Passenger<<endl<<endl;
    system("PAUSE");
}

int main()
{
    setlocale(LC_ALL,"RUS");

    bool Work = true;
    TollBooth Car;

    while(Work)
    {
        cout<<"Нажмите 1, если машина проехала и заплатила."<<endl;
        cout<<"Нажмите 2, если машина проехала и не заплатила."<<endl;
        cout<<"Нажмите 3, если хотите увидеть статистику."<<endl;
        cout<<"Нажмите 0, если хотите выйти из программы."<<endl;
        if(_kbhit)
        {
            switch(getch())
            {
            case '1':
            {
                cout<<"Машина проехала и заплатила"<<endl;
                Car.PayingCar();
                break;
            }
            case '2':
            {
                cout<<"Машина проехала и не заплатила"<<endl;
                Car.NoPayCar();
                break;
            }
            case '3':
            {
                system("cls");
                Car.Display();
                break;
            }
            case '0':
            {
                Work=false;
            }
            }
        }
        system("cls");
    }



}
