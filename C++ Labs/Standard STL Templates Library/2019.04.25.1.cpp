#include <iostream>
#include <vector>

using namespace std;

int main()
{
    setlocale(LC_ALL,"RUS");

    ///Создание вектора MyVector
    vector<int> MyVector(30, 2);

    ///Определения емкости векстора вручную
    MyVector.reserve(100);

    cout<<"Количество элментов в векторе: "<<MyVector.size()<<endl;
    MyVector.resize(15);
    cout<<"Количество элментов в векторе: "<<MyVector.size()<<endl;

    ///Емкость вектора
    cout<<"Емкость вектора: "<<MyVector.capacity()<<endl;


    ///Добавление в конец трёх элементов 2,77,44
    MyVector.push_back(2);
    MyVector.push_back(77);
    MyVector.push_back(44);

    ///Вывод второго элемента через at
    cout<<"Элемент под номером 2: "<<MyVector.at(2)<<endl;


    ///Блок try...catch, который проверяет не вышла ли ошбика за границы
    cout<<"\n";
    try
    {
        cout<<"Элемент под номером 10: "<<MyVector.at(10)<<endl;
    }
    catch(out_of_range & ex)
    {
        cout<<ex.what()<<endl<<endl;
    }

    ///Вывод элементов вектора на экран
    cout<<"Элементы вектора: ";
    for(int i=0; i<MyVector.size(); i++)
    {
        cout<<MyVector.at(i)<<" ";
    }

    ///Удаление последнего элемента
    cout<<endl<<endl<<"Удаление последнего элемента: ";
    MyVector.pop_back();
    cout<<endl;

    cout<<"Элементы вектора: ";
    for(int i=0; i<MyVector.size(); i++)
    {
        cout<<MyVector.at(i)<<" ";
    }

    ///Проверка вектора на наличие элементов
    cout<<endl<<endl<<"Вектор имеет элементы: "<<boolalpha<<MyVector.empty()<<endl;


    ///Очистка вектора
    cout<<endl<<endl<<"Количество элементов в векторе: "<<MyVector.size()<<endl;
    MyVector.clear();
    cout<<"Количество элементов в векторе: "<<MyVector.size()<<endl;

    ///Проверка вектора на наличие элементов
    cout<<endl<<"Вектор имеет элементы: "<<boolalpha<<MyVector.empty()<<endl;

    return 0;
}
