#include <iostream>

using std::cout;
using std::cin;
using std::endl;

class myClass
{
private:
    int size;
    int *data;

public:

    void Print()
    {
        for(int i=0;i<size;i++)
            cout<<data[i]<<" ";
        cout<<endl;
    }

    myClass(int size)
    {
        this->size = size;
        this->data = new int [size];

        for(int i=0;i<size;i++)
        {
            data[i] = i;
        }

        cout<<"The constructor was called - "<<this<<endl;
    }

    ~myClass()
    {
        delete [] data;
        cout<<"The destructor was called - "<<this<<endl;
    }

    myClass(const myClass &other)
    {
        this->size = other.size;
        this -> data = new int [other.size];

        for(int i=0;i<other.size;i++)
        {
            this->data[i] = other.data[i];
        }
         cout<<"The copy-constructor was called - "<<this<<endl;
    }

    myClass & operator = (const myClass &other)
    {
        cout<<"The operator = was called - "<<this<<endl;
        delete [] this->data;
        this->data = new int[other.size];
        this->size = other.size;

        for(int i=0;i<size;i++)
        {
            this->data[i] = other.data[i];
        }

        return *this;
    }

};

void Foo(myClass value)
{
     cout<<"The function was called"<<endl;
}

myClass Foo_2()
{
    cout<<"The second function was called"<<endl;
    myClass temp(1);

    return temp;
}

int main()
{
    myClass firstClass(10);
    myClass secondClass(firstClass);
    myClass thirdClass(1);
    thirdClass = firstClass = secondClass;
    //Foo(firstClass);
    //Foo_2();

    firstClass.Print();
    secondClass.Print();
    thirdClass.Print();


    return 0;
}
