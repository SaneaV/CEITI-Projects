#include <iostream>
#include <vector>
#include <typeinfo>
#include <windows.h>
#include <conio.h>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;


class Person
{
private:
    int age;
    string name;

public:

    int getAge()
    {
        return age;
    }

    string getName()
    {
        return name;
    }

    void setName(string name)
    {
        this->name = name;
    }

    void setAge(int age)
    {
        this->age = age;
    }

    virtual void getData()
    {
        cout<<"Name - "<<name<<endl;
        cout<<"Age - "<<age<<endl;
    }

    virtual void setData()
    {
        cout<<"Name - ";
        cin>>name;
        cout<<"Age - ";
        cin>>age;
    }
};

class Teacher:public Person
{
private:
    string subject;

public:
    string getSubject()
    {
        return subject;
    }

    void setSubject(string subject)
    {
        this->subject = subject;
    }

    void getData()
    {
        Person::getData();
        cout<<"Subject - "<<subject<<endl;
    }

    void setData()
    {
        Person::setData();
        cout<<"Subject - ";
        cin>>subject;
    }
};

class Student:public Person
{
private:
    int classStud;

public:

    int getClassStud()
    {
        return classStud;
    }

    void setClassStud(int classStud)
    {
        this->classStud = classStud;
    }

    void getData()
    {
        Person::getData();
        cout<<"Class stud - "<<classStud<<endl;
    }

    void setData()
    {
        Person::setData();
        cout<<"Class stud - ";
        cin>>classStud;
    }
};

template <class T>
string showType(T *a)
{
    return typeid(*a).name();
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    vector<Person*> pers;
    int n=0;
    bool Menu = true;
    bool Selecting = true;

    while(Menu)
    {
        system("cls");
        Selecting = true;
        cout<<"1. Add a teacher."<<endl;
        cout<<"2. Add a student."<<endl;
        cout<<"3. List of students."<<endl;
        cout<<"4. List of teachers."<<endl;
        cout<<"5. List of all persons."<<endl;
        cout<<"6. Exit the program."<<endl;
        cout<<"Choose the action: ";

        while(Selecting)
        {
            if(_kbhit)
            {
                switch(getch())
                {
                case '1':
                {
                    system("cls");
                    pers.push_back(new Teacher);
                    Selecting = false;
                    pers[n++] -> setData();
                    break;
                }
                case '2':
                {
                    system("cls");
                    pers.push_back(new Student);
                    Selecting = false;
                    pers[n++] -> setData();
                    break;
                }
                case '3':
                {
                    system("cls");
                    for(auto i : pers)
                    {
                        if(showType(i)=="7Student")
                            i -> getData();

                    }
                    Selecting = false;
                    cout<<endl;
                    system("pause");
                    break;
                }
                case '4':
                {
                    system("cls");
                    for(auto i : pers)
                    {
                        if(showType(i)=="7Teacher")
                            i -> getData();

                    }
                    Selecting = false;
                    cout<<endl;
                    system("pause");
                    break;
                }
                case '5':
                {
                    system("cls");
                    for(auto i : pers)
                    {
                            i -> getData();

                    }
                    Selecting = false;
                    cout<<endl;
                    system("pause");
                    break;
                }
                case '6':
                    {
                        Selecting = false;
                        Menu = false;
                        break;
                    }

                }
            }
        }
    }


    return 0;
}
