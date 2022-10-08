#include <iostream>
#include <windows.h>
#include <conio.h>

using namespace std;

class Person
{
private:
    string Name;
    string SecondName;
    int Age;
    char Gender;
    int WorkExpirience;
    string Education;
public:

    void setName(string Name)
    {
        this->Name=Name;
    }
    void setSecondName(string SecondName)
    {
        this->SecondName=SecondName;
    }
    void setAge(int Age)
    {
        this->Age=Age;
    }
    void setGender(char Gender)
    {
        this->Gender=Gender;
    }
    void setWorkExpirience(int WorkExpirience)
    {
        this->WorkExpirience=WorkExpirience;
    }
    void setEducation(string Education)
    {
        this->Education=Education;
    }

    string getName()
    {
        return Name;
    }
    string getSecondName()
    {
        return SecondName;
    }
    int getAge()
    {
        return Age;
    }
    char getGender()
    {
        return Gender;
    }
    int getWorkExpirience()
    {
        return WorkExpirience;
    }
    string getEducation()
    {
        return Education;
    }

    virtual void GetData()
    {
        cout<<"Введите имя человека: ";
        cin>>Name;
        cout<<"Введите фамилию человека: ";
        cin>>SecondName;
        cout<<"Введите возраст человека: ";
        cin>>Age;
        cout<<"Введите пол человека(F/M): ";
        cin>>Gender;
        cout<<"Введите образование: ";
        cin>>Education;
        cout<<"Введите стаж работы: ";
        cin>>WorkExpirience;
    }

    virtual void PutData()
    {
        cout<<"Имя: "<<Name<<endl;
        cout<<"Фамилия: "<<SecondName<<endl;
        cout<<"Возраст: "<<Age<<endl;
        cout<<"Пол: "<<Gender<<endl;
        cout<<"Образование: "<<Education<<endl;
        cout<<"Стаж работы: "<<WorkExpirience<<endl;
    }

};


////////////////////////////////////////////////////////////////////////////////
class Employee: public Person
{
private:
    string NameWork;
public:
    void setNameWork()
    {
        this->NameWork=NameWork;
    }
    string getNameWork()
    {
        return NameWork;
    }

    void GetData()
    {
        Person::GetData();
        cout<<"Введите место работы служащего(инженер, бухгалтер, секретарь и т.д.): ";
        cin>>NameWork;
    };

    void PutData()
    {
        Person::PutData();
        cout<<"Место работы: "<<NameWork<<endl;
    }

};

////////////////////////////////////////////////////////////////////////////////

class ForeMan: public Person
{
private:
    string Object;
public:
    void getObject()
    {
        this->Object=Object;
    }
    string setObject()
    {
        return Object;
    }

    void GetData()
    {
        Person::GetData();
        cout<<"Введите объект на котором сейчас происходит работа: ";
    }

    void PutData()
    {
        Person::PutData();
        cout<<"Сейчас работа выполняется на объекте: "<<Object<<endl;
    }
};

////////////////////////////////////////////////////////////////////////////////

class Builder: public ForeMan
{
private:
    string Specialization;
    int Discharge;
public:
    void getSpecialization()
    {
        this->Specialization=Specialization;
    }
    void getDischarge()
    {
        this->Discharge=Discharge;
    }
    string setSpecialization()
    {
        return Specialization;
    }
    int setDischarge()
    {
        return Discharge;
    }

    void GetData()
    {
        ForeMan::GetData();
        cout<<"Введите специализацию строителя: ";
        cin>>Specialization;
        cout<<"Введите разряд строителя(если предусматривается, в противном случае - 0): ";
        cin>>Discharge;
    }

    void PutData()
    {
        ForeMan::PutData();
        cout<<"Специализация: "<<Specialization<<endl;
        cout<<"Разряд: "<<Discharge<<endl;
    }
};

////////////////////////////////////////////////////////////////////////////////

class List
{
private:
    Person *info;
    List *next;
    static List *bg;
public:
    void setInfo(Person *info){this->info = info;}
    void setNext(List *next){this->next = next;}
    Person*  getInfo(){return info;}
    List* getNext(){return next;}
    void addData();
    void showData();
};
  List *List::bg=NULL;



void List::addData()
{
   List *cr =new List;
   List *prv;
   Person *info = new Person;
   info->InputData();
   cr->setInfo(info);
   cr->setNext(NULL);
   if (bg==NULL) bg=cr;
      else prv->setNext(cr);
   prv=cr;
}

void List:: showData()
{
    if (bg==NULL)cout<<"empty";
    else
    {
        List *cr;
        cr=bg;
        while(cr!=NULL)
        {
            cr->getInfo()->showData();
            cr=cr->getNext();
        }
    }
}


////////////////////////////////////////////////////////////////////////////////

int main()
{
    setlocale(LC_ALL,"RUS");

    List pers;
    int n=0;
    bool Menu = true;

    do
    {
        cout<<"1. Ввести данные служащего. "<<endl;
        cout<<"2. Ввести данные прораба."<<endl;
        cout<<"3. Ввести данные строителя."<<endl;
        cout<<"0. Выйти из программы."<<endl;
        cout<<"Ваш выбор: ";

        if(_kbhit())
        {
            switch(getch())
            {
            case '1':
            {
                cout<<endl;
                pers.GetData();
                break;
            }
            case '2':
            {
                cout<<endl;
                pers[n] = new ForeMan;
                break;
            }
            case '3':
            {
                cout<<endl;
                pers[n] = new Builder;
                break;
            }
            case '0':
            {
                Menu = false;
                break;
            }
            default:
            {
                cout<<"Повторите ввод."<<endl;
            }
            }

            if(Menu)
            {
                pers[n++]->GetData();
            }

            system("cls");

        }
    }
    while(Menu);

    system("cls");

    for(int i=0; i<n; i++)
    {
        pers[i]->PutData();
        cout<<endl;
    }
}


