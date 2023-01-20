#include <iostream>
#include <set>
#include <stdlib.h>
#include <ctime>

using namespace std;

template <typename T>
void printSet(const set<T> &S)
{
    cout<<"Вывод Set на экран: "<<endl;
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
    cout<<"Создание Set."<<endl<<endl;
    set<int> mySet = {8,9,11};

    /**-----------------------------------------------------------*/
    cout<<"Заполнение Set."<<endl<<endl;
    mySet.insert(5);
    mySet.insert(7);
    mySet.insert(3);
    mySet.insert(4);
    mySet.insert(-2);

    /**-----------------------------------------------------------*/
    cout<<"Заполнение Set случайными числами(только уникальные значения): "<<endl;
    for(int i=0; i<20; i++)
    {
        mySet.insert(rand()%30);
    }
    cout<<endl;

    /**-----------------------------------------------------------*/
    printSet(mySet);

    /**-----------------------------------------------------------*/
    cout<<"Блок try..cath: "<<endl;
    auto it = mySet.begin();
    int n;
    cout<<"Введите элемент для поиска: ";
    cin>>n;

    try
    {
        it = mySet.find(n);
        if(*it==n)
            cout<<"Элемент найден"<<endl;
        else
            throw 0;
    }
    catch(int x)
    {
        if(!x)
            cout<<"Элемент не найден."<<endl;
    }
    cout<<endl;

    /**-----------------------------------------------------------*/
    cout<<"Удаление элемента в Set."<<endl;
    cout<<"Ввeдите элемент для удаления: ";
    cin>>n;

    try
    {
        if((mySet.erase(n))==true)
        {
            cout<<"Элемент удалён"<<endl;
            printSet(mySet);
        }
        else
            throw 0;
    }
    catch(int x)
    {
        if(!x)
            cout<<"Элемент не найден в Set."<<endl;
    }
    cout<<endl;



    return 0;
}
