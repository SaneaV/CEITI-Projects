#include <iostream>
#include <set>
#include <stdlib.h>
#include <ctime>

using namespace std;

template <typename T>
void printSet(const set<T> &S)
{
    cout<<"¬ывод Set на экран: "<<endl;
    for(auto &item:S)
    {
        cout<<item<<" ";
    }
    cout<<endl<<endl;
}

int main()
{
    setlocale(LC_ALL,"RUS");
    srand(time(0));

    /**-----------------------------------------------------------*/
    cout<<"—оздание Set."<<endl<<endl;
    set<int> mySet = {8,9,11};

    /**-----------------------------------------------------------*/
    cout<<"«аполнение Set."<<endl<<endl;
    mySet.insert(5);
    mySet.insert(7);
    mySet.insert(3);
    mySet.insert(4);
    mySet.insert(-2);

    /**-----------------------------------------------------------*/
    cout<<"«аполнение Set случайными числами(только уникальные значени€): "<<endl;
    for(int i=0; i<20; i++)
    {
        mySet.insert(rand()%30);
    }
    cout<<endl;

    /**-----------------------------------------------------------*/
    printSet(mySet);

    /**-----------------------------------------------------------*/
    cout<<"Ѕлок try..cath: "<<endl;
    auto it = mySet.begin();
    int n;
    cout<<"¬ведите элемент дл€ поиска: ";
    cin>>n;

    try
    {
        it = mySet.find(n);
        if(*it==n)
            cout<<"Ёлемент найден"<<endl;
        else
            throw 0;
    }
    catch(int x)
    {
        if(!x)
            cout<<"Ёлемент не найден."<<endl;
    }
    cout<<endl;

    /**-----------------------------------------------------------*/
    cout<<"”даление элемента в Set."<<endl;
    cout<<"¬вeдите элемент дл€ удалени€: ";
    cin>>n;

    try
    {
        if((mySet.erase(n))==true)
        {
            cout<<"Ёлемент удалЄн"<<endl;
            printSet(mySet);
        }
        else
            throw 0;
    }
    catch(int x)
    {
        if(!x)
            cout<<"Ёлемент не найден в Set."<<endl;
    }
    cout<<endl;



    return 0;
}
