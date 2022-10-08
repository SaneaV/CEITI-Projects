#include <iostream>
#include <windows.h>
#include <conio.h>

using namespace std;

class CVehicle
{
private:
    char Latitude;
    char Longitude;

    int GradLat;
    int MinLat;
    int SecLat;

    int GradLon;
    int MinLon;
    int SecLon;

    int Price;
    int Speed;
    int YearOfProduction;
public:
    virtual void Get_Data()
    {
        cout<<"Южная или Северная широта? (ю или с): ";
        cin>>Latitude;
        cout<<"Введите (градусы минуты секунды) ";
        cin>>GradLat>>MinLat>>SecLat;

        cout<<"Западная или Восточная долгота? (з или в): ";
        cin>>Longitude;
        cout<<"Введите (градусы минуты секунды) ";
        cin>>GradLon>>MinLon>>SecLon;

        cout<<"Введите цену средства передвижения: ";
        cin>>Price;

        cout<<"Введите скорость средства передвижения: ";
        cin>>Speed;

        cout<<"Введите год выпуска средства передвижения: ";
        cin>>YearOfProduction;
    }

    virtual void Set_Data()
    {
        cout<<"Координаты: "<<endl;
        cout<<GradLat<<"°"<<MinLat<<"\'"<<SecLat<<"\" "<<Latitude<<".ш."<<endl;
        cout<<GradLat<<"°"<<MinLat<<"\'"<<SecLat<<"\" "<<Longitude<<".д."<<endl;
        cout<<"Стоимость: "<<Price<<endl;
        cout<<"Скорость: "<<Speed<<endl;
        cout<<"Год выпуска: "<<YearOfProduction<<endl;
    }

    CVehicle() {};
    CVehicle(int GLt, int MLt, int SLt, int GLn, int MLn, int SLn) : GradLat(GLt), MinLat(MLt), SecLat(SLt), GradLon(GLn), MinLon(MLn), SecLon(SLn)
    {}

};

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    CVehicle C;
    C.Get_Data();
    system("cls");
    C.Set_Data();

}
