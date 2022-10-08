///Тут то же самое, просто я сам немного неправильно дал названия.
///Вроде ничего отличного нет

#include <iostream>

using std::cout;
using std::endl;
using std::cin;
using std::string;

class publication
{
public:

    virtual void SetNumberOfPage()
    {
        cout<<"Введите количество страниц: ";
        cin>>NumberOfPage;
    }

    virtual int getNumberOfPage()
    {
        return NumberOfPage;
    }

private:
    int NumberOfPage;
};

class sales
{
public:

    virtual void SetNumberOfSoldCopies()
    {
        cout<<"Введите количество проданных копий: ";
        cin>>NumberOfCopies;
    }

    virtual int getNumberOfCopies()
    {
        return NumberOfCopies;
    }

private:
    int NumberOfCopies;
};


class book : public publication, public sales
{
private:
    string NameBook;
public:

    void SetBook()
    {
        cout<<"Введите название книги: ";
        cin>>NameBook;
        publication::SetNumberOfPage();
        sales::SetNumberOfSoldCopies();
    }

    void GetBook()
    {
        cout<<"Название книги: "<<NameBook<<endl;
        cout<<"Количество страниц: "<<publication::getNumberOfPage()<<endl;
        cout<<"Количество проданных копий: "<<sales::getNumberOfCopies()<<endl;
    }


};

int main()
{
    setlocale(LC_ALL, "rus");

    book b;

    b.SetBook();

    cout<<endl<<endl;

    b.GetBook();

    return 0;
}
