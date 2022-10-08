#include <iostream>

using namespace std;

class Angle
{
private:
    int Grad;
    float Min;
    char Part;
public:
    void Input();
    //void Output();
};


void Angle::Input()
{
    cout<<"¬ведите количество градусов: ";
    cin>>Grad;
    cout<<"¬ведите количество минут: ";
    cin>>Min;
    cout<<"¬ведите сторону света: ";
    cin>>Part;
}


class Country
{
private:
    Angle dolgota;
    Angle shirota;
    char Name[30];
public:
    void GetData();
    void ShowData();

};

void Coutry::GetData
{
    dolgota.GetData();
}


int main()
{
    setlocale(LC_ALL,"RUS");

    Angle F;

    F.Input();
    F.Output();
}
