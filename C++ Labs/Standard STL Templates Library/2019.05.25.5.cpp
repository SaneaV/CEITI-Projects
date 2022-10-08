///Класс персона - базовый класс
///От него наследуем учителя и ученика
///Всё это записываем в Vector (Vector - тот же самый динамический массив)
///Ну пока что всё. Если что, пишите вопросы, я рядом чат имею.

///Vector - библиотека STL (Могу сделать и с list или deque)
///Чтобы использовать вектор -> #include <vector>
///Ещё одна фигня с ним, что он позволяет добавлять элементы только в конец

///А и ещё rage_based цикл, сейчас покажу

///Ну это вроде всё. Что ещё показать? Что-то из STL? Или шаблоны?

#include <iostream>
#include <windows.h>
#include <vector>
#include <conio.h>

using namespace std;

class Person
{
private:
    string name;
    int age;
public:
    virtual void setData()
    {
        cout<<"Введите имя человека: ";
        cin>>name;
        cout<<"Введите возраст человека: ";
        cin>>age;
    }

    virtual void getData()
    {
        cout<<"Имя: "<<name<<endl;
        cout<<"Возраст: "<<age<<endl;
    }

};

///Класс наследуем от Person
class Teacher : public Person
{
private:
    string nameObject;

public:

    void setData() override
    {
        Person::setData();
        cout<<"Введите название предмета: ";
        cin>>nameObject;
    }

    ///Есть такая вещь в virtual, называется override
    ///Писать её не обязательно, но проф. программисты используют

    void getData() override
    {
        Person::getData();
        cout<<"Предмет: "<<nameObject<<endl;
    }
};


class Student : public Person
{
private:
    int classSchool;

public:

    void setData() override
    {
        Person::setData();
        cout<<"Введите класс ученика: ";
        cin>>classSchool;
    }


    void getData() override
    {
        Person::getData();
        cout<<"Класс: "<<classSchool<<endl;
    }
};

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    ///Русский язык на ввод и вывод

    ///Создание вектора, который содержит в себе наследников Person
    ///Я не нашёл лучшего варианта, как завести переменную n
    ///Дальше объясню зачем

    vector<Person*> pers;
    int n = 0;
    bool Menu = true;
    bool secondMenu = true;

    while(Menu)
    {
        system("cls");
        secondMenu = true;
        cout<<"1. Добавить ученика"<<endl;
        cout<<"2. Добавить учителя"<<endl;
        cout<<"3. Вывести список всех людей"<<endl;
        cout<<"0. Выход из программы"<<endl;

        while(secondMenu)
        {
            if(_kbhit)
            {
                switch(getch())
                {
                case '1':
                {
                    system("cls");
                    pers.push_back(new Student);
                    pers[n++] -> setData();
                    secondMenu = false;
                    break;
                }
                case '2':
                {
                    system("cls");
                    pers.push_back(new Teacher);
                    pers[n++] -> setData();
                    secondMenu = false;
                    break;
                }

                case '3':
                {
                    system("cls");

                    ///auto -> чё-то как template
                    ///int i = 10
                    ///auto i = 10
                    ///Одно и то же
                    ///А количество людей, скрыто где-то в самом цикле range_based цикле

                    /*vector<Person*>::iterator it;

                    for(it=pers.begin(); it!=pers.end();it++)
                    {
                        ///Я хз, мне такой цикл не очень нравится, поэтому я научился
                        ///на range_based
                        *it->getData();
                    }*/

                    ///То же самое, но на нашем.

                    /*for(int i=0; i<n; i++)
                    {
                        pers[i] -> getData();
                    }*/

                    for(auto i : pers)
                    {
                        i -> getData();
                        cout<<endl;
                    }

                    system("PAUSE");
                    secondMenu = false;
                    break;
                }

                case '0':
                {
                    system("cls");
                    secondMenu = false;
                    Menu = false;
                    break;
                }
                }
            }
        }

    }

    return 0;
}
