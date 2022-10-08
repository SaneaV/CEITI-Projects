#include <iostream>

using namespace std;

template <class Type> class Calculator
{
private:
    Type a,b;
public:
    Calculator(Type a, Type b): a(0), b(0) {}

    Type input()
    {
        cout<<"Введите число а: ";
        cin>>a;
        cout<<"Введите число b: ";
        cin>>b;
    }

    Type show()
    {
        cout<<"a = "<<a<<"; b = "<<b;
    }

    Type PlusType()
    {
        return a+b;
    }

    Type MinusType()
    {
        return a-b;
    }

    Type UmnojType()
    {
        return a*b;
    }

    Type DelType()
    {
        return a/b;
    }
};



int main()
{
    setlocale(LC_ALL,"RUS");

    int Select;

    cout<<"1. Работать с int"<<endl;
    cout<<"2. Работать с float"<<endl;
    cout<<"3. Работать с char"<<endl;
    cin>>Select;

    if(Select==1)
    {
        Calculator <int> s1(0,0);
        s1.input();
        s1.show();

        cout<<endl;
        cout<<"Операция сложения: "<<s1.PlusType()<<endl;
        cout<<"Операция вычисления: "<<s1.MinusType()<<endl;
        cout<<"Операция умножения: "<<s1.UmnojType()<<endl;
        cout<<"Операция деления: "<<s1.DelType()<<endl;
    }
    else if(Select==2)
    {
        Calculator <float> s1(0,0);
        s1.input();
        s1.show();

        cout<<endl;
        cout<<"Операция сложения: "<<s1.PlusType()<<endl;
        cout<<"Операция вычисления: "<<s1.MinusType()<<endl;
        cout<<"Операция умножения: "<<s1.UmnojType()<<endl;
        cout<<"Операция деления: "<<s1.DelType()<<endl;
    }
    else if(Select==3)
    {
        Calculator <char> s1(0,0);
        s1.input();
        s1.show();

        cout<<endl;
        cout<<"Операция сложения: "<<s1.PlusType()<<endl;
        cout<<"Операция вычисления: "<<s1.MinusType()<<endl;
        cout<<"Операция умножения: "<<s1.UmnojType()<<endl;
        cout<<"Операция деления: "<<s1.DelType()<<endl;
    }

    return 0;
}
