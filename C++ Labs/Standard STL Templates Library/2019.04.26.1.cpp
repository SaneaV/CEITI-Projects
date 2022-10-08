#include <iostream>
#include <vector>
#include <ctime>
#include <stdlib.h>
#include <algorithm>

using namespace std;

struct randNumber
{
    int operator()() {return (-100 + rand()%201);}
};

int main()
{
    setlocale(LC_ALL, "RUS");
    srand(time(0));

    int n = 0;
    cout<<"Введите размер вектора: ";
    cin>>n;

    cout<<endl<<endl;

    vector<int> MyVector(n);
    generate (MyVector.begin(), MyVector.end(), randNumber());
    vector<int>::iterator i = MyVector.begin();
    int countNegative = 0;

    for (;i != MyVector.end(); i++)
    {
        cout << *i << " ";
        if(*i<0) countNegative++;
    }

    cout<<endl<<endl;
    cout<<"Количество отрицательных чисел: "<<countNegative;
    cout<<endl<<endl;
    return 0;
}
