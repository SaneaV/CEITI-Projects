#include <iostream>
#include <deque>

using namespace std;

int main()
{
    setlocale(LC_ALL,"RUS");

    deque<int> dq = {1,9, 44};

    /**======================================================*/
    cout<<"Добавление элемента."<<endl;
    dq.push_front(10);
    dq.push_back(2);
    cout<<endl;

    /**======================================================*/
    cout<<"Создание итератора. "<<endl;
    deque<int>::iterator it = dq.begin();
    cout<<endl;

    /**======================================================*/
    cout<<"Вывод deque на экран при помощи range based: "<<endl;
    for(it:dq)
    {
        cout<<it<<" ";
    }
    cout<<endl<<endl;

    /**======================================================*/
    cout<<"Поиск max и min: "<<endl;
    int minE = dq[0];
    int maxE = dq[0];
    for(it:dq)
    {
        maxE = max(it,maxE);
        minE = min(it,minE);
    }
    cout<<"Максимальный элемент: "<<maxE<<endl;
    cout<<"Минимальный элемент: "<<minE<<endl;


    return 0;
}
