#include <iostream>
#include <set>
#include <stdlib.h>
#include <ctime>
#include <algorithm>

using namespace std;

template <typename T>
void printMultiset (const multiset<T> &M)
{
    cout<<"Вывод Multiset на экран: "<<endl;
    for(auto &item: M)
    {
        cout<<item<<" ";
    }
    cout<<endl<<endl;
}

int main()
{
    setlocale(LC_ALL,"RUS");
    srand(time(0));

    multiset<int> myMultiset;

    /**-----------------------------------------------------------*/
    cout<<"Заполнение Set случайными числами(с повторами). "<<endl;
    for(int i=0; i<20; i++)
    {
        myMultiset.insert(rand()%30);
    }
    cout<<endl;

    printMultiset(myMultiset);

    /**-----------------------------------------------------------*/
    cout<<"Возврат первого найденного элемента: ";
    auto it = myMultiset.lower_bound(1);
    cout<<*it<<endl;
    cout<<"Возврат элемента идущего после последнего найденного: ";
    auto it2 = myMultiset.upper_bound(1);
    cout<<*it2<<endl;

    cout<<endl;

    /**-----------------------------------------------------------*/
    cout<<"Возврат значений от lower_bound до upper_bound: "<<endl;
    auto it4 = myMultiset.equal_range(3);

    cout << "\nThe lower bound of 3 is " << *it4.first;
    cout << "\nThe upper bound of 3 is " << *it4.second;

    cout<<endl;

    return 0;
}
