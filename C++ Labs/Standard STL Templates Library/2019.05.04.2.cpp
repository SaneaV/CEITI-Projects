#include <iostream>
#include <queue>
#include <stdlib.h>
#include <ctime>

using namespace std;

template <typename t>
void fill_Queue (priority_queue<t> &Q)
{
    cout<<"Заполнение очереди: "<<endl;

    for(int i = 0; i < 10; i++)
    {
        Q.emplace(rand()%20);
    }

    cout<<endl;
}

template <typename t>
void print_Queue(priority_queue<t> &Q)
{
    cout<<"Вывод очереди на экран(многоразовый способ): "<<endl;\

    vector<t> Temp(Q.size());
    Temp.clear();

    while(!Q.empty())
    {
        cout<<Q.top()<<" ";
        Temp.push_back(Q.top());
        Q.pop();
    }

    auto it = Temp.begin();

    for(;it!=Temp.end();it++)
    {
        Q.emplace(*it);
    }

    cout<<endl;
}


int main()
{
    setlocale(LC_ALL,"RUS");
    srand(time(0));

    priority_queue<float> myPriorityQueue;

    fill_Queue(myPriorityQueue);
    print_Queue(myPriorityQueue);
    print_Queue(myPriorityQueue);



    return 0;
}
