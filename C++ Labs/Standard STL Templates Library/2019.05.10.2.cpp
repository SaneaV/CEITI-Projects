#include <iostream>

using namespace std;

class Car
{
private:
    string color;
    int numberOfDoors;
    char region[2];

};

union KM_MILIES
{
    int KM;
    double MILIES;
};

int main()
{
    Car FirstCar;
    KM_MILIES A;

    A.KM = 10;
    cout<<sizeof(A)<<endl;
    A.MILIES = 10;
    cout<<sizeof(A)<<endl;


    cout<<sizeof(FirstCar);
}
