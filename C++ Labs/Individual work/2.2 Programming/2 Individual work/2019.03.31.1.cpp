#include <iostream>
#include <windows.h>
#include <conio.h>
#include <string.h>

using namespace std;
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

enum ConsoleColor
{
    Black = 0,
    Blue = 1,
    Green = 2,
    Cyan = 3,
    Red = 4,
    Magenta = 5,
    Brown = 6,
    LightGray = 7,
    DarkGray = 8,
    LightBlue = 9,
    LightGreen = 10,
    LightCyan = 11,
    LightRed = 12,
    LightMagenta = 13,
    Yellow = 14,
    White = 15,
};

////////////////////////////////////////////////////////////////////////////////

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
        this->Name = Name;
    }
    void setSecondName(string SecondName)
    {
        this->SecondName = SecondName;
    }
    void setAge(int Age)
    {
        this->Age = Age;
    }
    void setGender(char Gender)
    {
        this->Gender = Gender;
    }
    void setWorkExpirience(int WorkExpirience)
    {
        this->WorkExpirience = WorkExpirience;
    }
    void setEducation(string Education)
    {
        this->Education = Education;
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
        do
        {
            SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
            cout << "Введите имя человека: ";
            SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | LightGreen));
            cin >> Name;
        }
        while(Name.size()<3);

        do
        {
            SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
            cout << "Введите фамилию человека: ";
            SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | LightGreen));
            cin >> SecondName;
        }
        while(SecondName.size()<3);

        SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
        cout << "Введите возраст человека: ";
        SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | LightGreen));
        while (!(cin>>Age) or Age<16)
        {
            SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | LightRed));
            cout<<"По трудовому кодексу, человек может начинать работу с 16 лет!"<<endl;
            cin.clear();
            cin.sync();
            cout<<"Повторите ввод: ";
            SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
        }

        SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
        cout << "Введите пол человека(одним символом): ";
        SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | LightGreen));
        cin>>Gender;

        do
        {
            SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
            cout << "Введите образование: ";
            SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | LightGreen));
            cin >> Education;
        }
        while(Education.size()<3);

        SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
        cout << "Введите стаж работы: ";
        SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | LightGreen));
        while (!(cin>>WorkExpirience) or WorkExpirience<0 or (Age-WorkExpirience)<16)
        {
            if((Age-WorkExpirience)<16)
            {
                SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | LightRed));
                cout<<"Человеку - "<<Age<<" лет"<<endl;
                cout<<"Его стаж работы - "<<WorkExpirience<<endl;
                cout<<"Получается, работать он начал в "<<Age-WorkExpirience<<" лет"<<endl;
                cout<<"По трудовому кодексу, человек может начинать работу с 16 лет!"<<endl;
                cin.clear();
                cin.sync();
                cout<<"Повторите ввод: ";
                SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
            }
            else if(WorkExpirience<0)
            {
                SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | LightRed));
                cout<<"Ладно, если вообще не работал, но вот так..."<<endl;
                cin.clear();
                cin.sync();
                cout<<"Повторите ввод: ";
                SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
            }
            else
            {
                SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | LightRed));
                cout<<"Я понимаю только в цифрах((("<<endl;
                cin.clear();
                cin.sync();
                cout<<"Повторите ввод: ";
                SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
            }

        }
        SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
    }

    virtual void PutData()
    {
        cout << "Имя: ";
        SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | LightGreen));
        cout<< Name << endl;
        SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
        cout << "Фамилия: ";
        SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | LightGreen));
        cout<< SecondName << endl;
        SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
        cout << "Возраст: ";
        SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | LightGreen));
        cout<< Age << endl;
        SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
        cout << "Пол: ";
        SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | LightGreen));
        cout << Gender << endl;
        SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
        cout << "Образование: ";
        SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | LightGreen));
        cout << Education << endl;
        SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
        cout << "Стаж работы: ";
        SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | LightGreen));
        cout << WorkExpirience << endl;
        SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
    }

};


////////////////////////////////////////////////////////////////////////////////
class Employee : public Person
{
private:
    string NameWork;
public:
    void setNameWork()
    {
        this->NameWork = NameWork;
    }
    string getNameWork()
    {
        return NameWork;
    }

    void GetData()
    {
        Person::GetData();
        do
        {
            cout << "Введите место работы служащего(инженер, бухгалтер, секретарь и т.д.): ";
            SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | LightGreen));
            cin >> NameWork;
            SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
        }
        while(NameWork.size()<3);

    };

    void PutData()
    {
        Person::PutData();

        cout << "Место работы: ";
        SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | LightGreen));
        cout<< NameWork << endl;
        SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));

        SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | LightRed));
        cout<<"======================================================="<<endl<<endl;
        SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
    }

};

////////////////////////////////////////////////////////////////////////////////

class ForeMan : public Person
{
private:
    string Object;
public:
    void getObject()
    {
        this->Object = Object;
    }
    string setObject()
    {
        return Object;
    }

    void GetData()
    {
        Person::GetData();
        do
        {
            cout << "Введите объект на котором сейчас происходит работа: ";
            SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | LightGreen));
            cin>>Object;
            SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
        }
        while(Object.size()<3);

    }

    void PutData()
    {
        Person::PutData();
        cout << "Сейчас работа выполняется на объекте: ";
        SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | LightGreen));
        cout<< Object << endl;
        SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));

        SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | LightRed));
        cout<<"======================================================="<<endl<<endl;
        SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
    }
};

////////////////////////////////////////////////////////////////////////////////

class Builder : public Person
{
private:
    string Specialization;
    int Discharge;
public:
    void getSpecialization()
    {
        this->Specialization = Specialization;
    }
    void getDischarge()
    {
        this->Discharge = Discharge;
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
        Person::GetData();
        do
        {
            cout << "Введите специализацию строителя: ";
            SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | LightGreen));
            cin >> Specialization;
            SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
        }
        while(Specialization.size()<3);

        do
        {
            cout << "Введите разряд строителя(если предусматривается, в противном случае - 0): ";
            SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | LightGreen));
            cin>> Discharge;
            SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
        }
        while(Discharge<0);
    }

    void PutData()
    {
        Person::PutData();

        cout << "Специализация: ";
        SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | LightGreen));
        cout<< Specialization << endl;
        SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
        cout << "Разряд: ";
        SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | LightGreen));
        cout<< Discharge << endl;
        SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));


        SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | LightRed));
        cout<<"======================================================="<<endl<<endl;
        SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
    }
};

////////////////////////////////////////////////////////////////////////////////

template <typename T>
class Node
{
private:
    T *info;
    Node *next;

public:
    void setInfo(T *info)
    {
        this->info = info;
    }
    void setNext(Node *next)
    {
        this->next = next;
    }
    T*  getInfo()
    {
        return info;
    }
    Node* getNext()
    {
        return next;
    }

};

template <typename T>
class List
{
private:
    Node<T> *bg;
    Node<T> *prv;
public:
    List()
    {
        bg=NULL;
        prv = NULL;
    }
    Node<T>* getBegin()
    {
        return bg;
    }

    void addData()
    {
        Node<T> *cr = new Node<T>;

        T *info;

        bool Select = true;

        do
        {
            cout<<"1. Добавить служащего."<<endl;
            cout<<"2. Добавить прораба."<<endl;
            cout<<"3. Добавить строителя."<<endl;
            cout<<"Ваш выбор: ";

            if(_kbhit)
            {
                switch(getch())
                {
                case '1':
                {
                    system("cls");
                    info = new Employee;
                    Select=false;
                    break;
                }
                case '2':
                {
                    system("cls");
                    info = new ForeMan;
                    Select=false;
                    break;
                }
                case '3':
                {
                    system("cls");
                    info = new Builder;
                    Select=false;
                    break;
                }
                default:
                {
                    system("cls");
                }
                }
            }
        }
        while(Select);

        info->GetData();
        cr->setInfo(info);
        cr->setNext(NULL);
        if (bg==NULL)
            bg=cr;
        else
            prv->setNext(cr);
        prv=cr;

    }


    void DeleteData()
    {
        if (bg==NULL)
        {
            SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | LightRed));
            cout<<"Список пуст!"<<endl<<endl;
            SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
            system("PAUSE");
        }
        else
        {
            Node<T> *cr, *prv;
            cr=bg;
            prv=cr;

            bool Select = true;

            do
            {
                cout<<"1. Удалить по позиции."<<endl;
                cout<<"2. Удалить по имени и фамилии."<<endl;
                cout<<"Ваш выбор: ";

                if(_kbhit)
                {
                    switch(getch())
                    {
                    case '1':
                    {
                        system("cls");
                        Select = false;
                        int SelectNum=1;
                        int k=0;
                        bool Find = false;

                        cout<<"Введите позицию для удаления: "<<endl;
                        do
                        {
                            cin>>SelectNum;
                            if(SelectNum<=0)
                                cout<<"Позиция не должна быть меньше либо равна нулю"<<endl;
                        }
                        while(SelectNum<=0);

                        system("cls");

                        SelectNum--;
                        if(SelectNum == 0)
                        {
                            bg = bg->getNext();
                            delete cr;
                            Find = true;

                        }
                        else
                        {
                            while(cr!=NULL)
                            {
                                if(k==SelectNum)
                                {
                                    prv->setNext(cr->getNext());
                                    delete cr;
                                    Find = true;
                                    break;
                                }

                                prv=cr;
                                cr=cr->getNext();
                                k++;
                            }
                        }

                        if(!Find)
                        {
                            SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | LightRed));
                            cout<<"Человека на такой большой позиции нет!"<<endl<<endl;
                            SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
                            system("PAUSE");
                        }
                        break;
                    }
                    case '2':
                    {
                        system("cls");
                        Select = false;
                        bool Find = false;
                        string NamePers;
                        string SecondNamePers;

                        cout<<"Введите имя человека: ";
                        cin>>NamePers;
                        cout<<"Введите фамилию человека: ";
                        cin>>SecondNamePers;


                        if(bg->getInfo()->getName()==NamePers &&
                                bg->getInfo()->getSecondName()==SecondNamePers)
                        {
                            bg = bg->getNext();
                            delete cr;
                            Find = true;
                        }

                        while(cr!=NULL)
                        {
                            if(cr->getInfo()->getName()==NamePers &&
                                    cr->getInfo()->getSecondName()==SecondNamePers)
                            {
                                prv->setNext(cr->getNext());
                                delete cr;
                                Find = true;
                                break;
                            }

                            prv=cr;
                            cr=cr->getNext();
                        }
                        if(!Find)
                        {
                            SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | LightRed));
                            cout<<"Человек не найден!"<<endl<<endl;
                            SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
                            system("PAUSE");
                        }
                        break;

                    }
                    default:
                    {
                        system("cls");
                    }
                    }
                }

            }
            while(Select);
        }
    }

    void  showData()
    {
        if (bg==NULL)
        {
            SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | LightRed));
            cout<<"Список пуст!"<<endl<<endl;
            SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
        }
        else
        {
            Node<T> *cr;
            cr=bg;
            while(cr!=NULL)
            {
                cr->getInfo()->PutData();
                cr=cr->getNext();
            }
        }
    }

};


////////////////////////////////////////////////////////////////////////////////


int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | LightRed));
    cout<<"Программа работает и с русским языком!"<<endl<<endl;
    SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
    system("PAUSE");
    system("cls");

    bool Menu = true;
    bool Selection = true;

    List <Person> pers;

    while(Menu)
    {
        Selection = true;

        system("cls");
        cout<<"1. Добавить человека."<<endl;
        cout<<"2. Удалить человека."<<endl;
        cout<<"3. Вывести список людей."<<endl;
        SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | LightRed));
        cout<<"0. Окончить ввод."<<endl;
        SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
        cout<<"Ваш выбор: ";

        if(_kbhit)
        {
            switch(getch())
            {
            case '1':
            {

                while(Selection)
                {
                    system("cls");
                    pers.addData();

                    cout<<endl<<endl;
                    cout<<"1. Повторить ввод."<<endl;
                    SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | LightRed));
                    cout<<"2. Закончить ввод."<<endl;
                    SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
                    cout<<"Ваш выбор: ";

                    if(_kbhit)
                    {
                        switch(getch())
                        {
                        case '1':
                        {
                            system("cls");
                            break;
                        }
                        case '2':
                        {
                            Selection = false;
                            break;
                        }
                        }
                    }
                }
                break;
            }

            case '2':
            {
                system("cls");
                pers.DeleteData();
                break;
            }

            case '3':
            {
                system("cls");
                pers.showData();
                system("PAUSE");
                break;
            }
            case '0':
            {
                system("cls");
                Menu = false;
                break;
            }
            default:
            {
                system("cls");
            }
            }
        }
    }
}




