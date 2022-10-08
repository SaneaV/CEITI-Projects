#include <iostream>
#include <windows.h>
#include <conio.h>

using namespace std;

class publication
{
private:
    string BookName;
    float price;
public:
    virtual void getdata()
    {
        cout<<"Введите название публикации: ";
        cin>>BookName;
        cout<<"Введите стоимость публикации: ";
        cin>>price;
    }

    virtual void putdata()
    {
        cout<<"Название книги: "<<BookName<<" - стоимость - "<<price<<endl;
    }

    virtual bool isOveersize() = 0;
};

class sales
{
private:
    float Massive[2];
public:
    void getdata()
    {
        cout<<"Введите сумму продаж за первый месяц: ";
        cin>>Massive[0];
        cout<<"Введите сумму продаж за второй месяц: ";
        cin>>Massive[1];
        cout<<"Введите сумму продаж за третий месяц: ";
        cin>>Massive[2];
    }
    void putdata()
    {
        cout<<"Сумма продаж за первый месяц: "<<Massive[0]<<endl;
        cout<<"Сумма продаж за второй месяц: "<<Massive[1]<<endl;
        cout<<"Сумма продаж за третий месяц: "<<Massive[2]<<endl;
    }
};



class book : public publication, public sales
{
public:
    int NumberOfPages=0;
    void getdata()
    {
        publication::getdata();
        cout<<"Введите количество страниц: ";
        cin>>NumberOfPages;
        sales::getdata();
    }
    void putdata()
    {
        publication::putdata();
        cout<<"Количество страниц в вашей книги: "<<NumberOfPages<<endl;
        sales::putdata();
    }
    bool isOveersize()
    {
        return (NumberOfPages >= 800) ? true : false;
    }
};

class tape : public publication, public sales
{
private:
    int AudioDuration=0;
    void getdata()
    {
        publication::getdata();
        cout<<"Введите продолжительность аудио-записи книги: ";
        cin>>AudioDuration;
        sales::getdata();
    }
    void putdata()
    {
        publication::putdata();
        cout<<"Продолжительность аудио-записи книги: "<<AudioDuration<<endl;
        sales::putdata();
    }

    bool isOveersize()
    {
        return (AudioDuration >= 90) ? true : false;
    }

};

class disk : public publication, public sales
{
private:
    char Type;
    float Size=0;
public:
    void getdata()
    {
        publication::getdata();
        cout<<"Введите название носителя CD(c) или DVD(d): ";
        cin>>Type;
        cout<<"Введите размер носителя(GB): ";
        cin>>Size;
        sales::getdata();
    }
    void putdata()
    {
        publication::putdata();
        cout<<"Физический носитель: ";
        if(Type=='c')
            cout<<"CD";
        else
            cout<<"DVD";
        sales::putdata();
    }
    bool isOveersize()
    {
        return (Size >= 5) ? true : false;
    }


};


int main()
{
    setlocale(LC_ALL,"RUS");

    publication *pubarr[100];
    int n=0;
    bool Menu = true;
    char Select;

    do
    {
        cout<<"Создать книгу(b) "<<endl;
        cout<<"Создать аудио-запись(a)"<<endl;
        cout<<"Запись на диск(d)"<<endl;
        cout<<"Выйти из программы (x)"<<endl;
        cout<<"Ваш выбор: ";
        cin>>Select;


        switch(Select)
        {
        case 'b':
        {
                cout<<endl;
                pubarr[n] = new book;
                break;
        }
        case 'a':
        {
            cout<<endl;
            pubarr[n] = new tape;
            break;
        }
        case 'd':
        {
            cout<<endl;
            pubarr[n] = new disk;
            break;
        }
        case 'x':
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
            pubarr[n++]->getdata();
        }

        system("cls");

    }
    while(Menu);

    system("cls");

    for(int i=0; i<n; i++)
    {
        pubarr[i]->putdata();
        if(pubarr[i]->isOveersize())
            cout<<endl<<"Превышение размера!"<<endl;
        cout<<endl;
    }
}
