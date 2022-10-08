#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::cin;
using std::string;

class Human
{
public:
    string name;
    int age;
    float weight;

    void Print()
    {
        cout<<"Name: "<<name<<endl;
        cout<<"Age: "<<age<<endl;
        cout<<"Weight: "<<weight<<endl;
    };
};

int main()
{
    Human FirstHuman;
    Human SecondHuman;

    FirstHuman.age = 18;
    FirstHuman.name = "Alex";
    FirstHuman.weight = 60.5;

    SecondHuman.age = 19;
    SecondHuman.name = "Vlad";
    SecondHuman.weight = 70.5;

    FirstHuman.Print();
    cout<<endl;
    SecondHuman.Print();

    return 0;
}
