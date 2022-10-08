#include <iostream>

class Human
{
private:
    std::string name;

public:

    std::string GetName()
    {
        return name;
    }

    void SetName(std::string name)
    {
        this->name = name;
    }

};

class Student : public Human
{
public:
    std::string group;

    void Learn()
    {
        std::cout<<"I learn!"<<std::endl;
    }

};

class ExtramuralStudent : public Student
{
public:
    void Learn()
    {
        std::cout<<"I learn, but I am an extramural student"<<std::endl;
    }
};

class Teacher : public Human
{
public:
    std::string subject;
};

int main()
{
    Student St;
    Teacher Th;
    ExtramuralStudent ExSt;

    St.SetName("Andry");
    std::cout<<St.GetName()<<std::endl;
    St.group;
    St.Learn();

    ExSt.SetName("Diana");
    std::cout<<ExSt.GetName()<<std::endl;
    ExSt.group;
    ExSt.Learn();

    Th.SetName("Victor");
    std::cout<<Th.GetName()<<std::endl;
    Th.subject;

    return 0;
}
