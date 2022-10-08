#include <iostream>
#include <map>

using namespace std;

template<typename f, typename s>
void print_Map(const map<f,s> &M)
{
    cout<<endl<<"Вывод элементов на экран: "<<endl;
    for(auto i:M)
        cout<<i.first<<". "<<i.second<<endl;
    cout<<endl;
}

int main()
{
    setlocale(LC_ALL,"RUS");

    map<int, string> myMap;

    myMap.insert(pair<int, string> (1, "Ноутбук"));
    myMap.insert(make_pair(2,"Монитор"));
    myMap.emplace(3,"Телефон");

    /**------------------------------------------------------------------*/
    try
    {
        int n;
        cout<<"Введите элемент для поиска: ";
        cin>>n;

        auto it = myMap.find(n);

        if(it==myMap.end())
            throw 0;
        else
        {
            cout<<it->first<<" ";
            cout<<it->second<<endl;
        }

    }
    catch(int i)
    {
        if(i==0)
            cout<<"Элемент не найден"<<endl;
    }

    /**------------------------------------------------------------------*/
    print_Map(myMap);

    /**------------------------------------------------------------------*/
    cout<<"Обращение к ключу элемента через квадратные скобочки: "<<endl;

    int n;
    cout<<"Введите элемент для поиска: ";
    cin>>n;

    cout<<myMap[n]<<endl;
    cout<<endl;

    /**------------------------------------------------------------------*/
    cout<<"Изменение значений через квадратные скобочки(или добавление нового): "<<endl;

    cout<<"Введите элемент для поиска: ";
    cin>>n;

    myMap[n] = "Модем";

    cout<<myMap[n]<<endl;

    /**------------------------------------------------------------------*/
    print_Map(myMap);

    /**------------------------------------------------------------------*/
    cout<<"Блок try...catch: ";

    try
    {
        myMap.at(5)= "Компьютер";
    }
    catch(const exception &x)
    {
        cout<<x.what()<<endl;
    }

    /**------------------------------------------------------------------*/
    cout<<endl<<"Удаление элемента: "<<endl;

    myMap.erase(4);

    /**------------------------------------------------------------------*/
    print_Map(myMap);


    return 0;
}
