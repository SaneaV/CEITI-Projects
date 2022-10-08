///Давай сделаю перегрузку операторов и на сегодня всё, ок?

#include <iostream>
#include <vector>
#include <ctime>
#include <stdlib.h>
#include <typeinfo>

template <typename T> ///<-Cоздание, за место template можно написать class, штука из C(язык)
void FillVector(std::vector<T> &Vec)
{

    ///Эта функция сможет принять любой(один) вектор на заполнение (хотя со string и char* хз)
    for(int i=0; i<10; i++)
    {
        if(typeid(Vec[0]) == typeid(float))
        {
            Vec.push_back((rand()%10)*0.6);
        }

        else
            Vec.push_back(rand()%10);
    }
}

template<class T>
void showVector(const std::vector<T> &Vec)
///сonst - значит, что я его не буду менять
///& - взятие по адресу, так просто быстрей
{
    for(auto i : Vec)
    {
        std::cout<<i<<" ";
    }
    std::cout<<std::endl;
}

int main()
{
    srand(time(NULL)); ///Случайная генерация чисел

    std::vector<float> firstVector(10);
    std::vector<double> secondVector;

    firstVector.clear();

    ///Ещё пару приколов с вектор
    ///Если сразу дать размер, то он заполнит 0 на n ячеек
    ///Чтобы очистить НазваниеВектора.clear()
    ///Но есть ещё прикол
    ///НазваниеВектора(n, любое число)

    FillVector(firstVector);
    FillVector(secondVector);

    showVector(firstVector);
    std::cout<<std::endl;
    showVector(secondVector);

    return 0;
}
