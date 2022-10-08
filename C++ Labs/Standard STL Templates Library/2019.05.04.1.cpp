#include <iostream>
#include <queue>
#include <stdlib.h>
#include <ctime>
#include <vector>

using namespace std;

template <typename t>
void fill_Queue (queue<t> &Q)
{
    cout<<"Заполнение очереди: "<<endl;

    for(int i = 0; i < 10; i++)
    {
        Q.emplace(rand()%20);
    }

    cout<<endl;
}

template <typename t>
void print_Queue(queue<t> &Q)
{
    cout<<"Вывод очереди на экран: "<<endl;\

    vector<t> Temp(Q.size());
    Temp.clear();

    while(!Q.empty())
    {
        cout<<Q.front()<<" ";
        Temp.push_back(Q.front());
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

    queue<int> myQueue;

    fill_Queue(myQueue);
    print_Queue(myQueue);
    print_Queue(myQueue);

    return 0;
}
