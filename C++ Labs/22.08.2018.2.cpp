/*"Опишите, используя тип данных запись, базу данных библиотеки, если известно:
-общее количество книг;
-название каждой книги;
-фамилия, имя автора каждой книги;
-количество страниц каждой книги;
-тематика каждой книги (роман, учебник, поэзия и т.д.);
-язык, на котором написана книга;
-издательство, выпустившее книгу;
-страна, в которой издана книга;
-год издания каждой книги.
Напишите программу, которая выводит на экран:
• Список книг заданного автора;
• Список книг изданных на румынском языке за рубежом;
• Список книг изданных по заданной тематике, начиная с 2000 года.*/

#include <iostream>
#include <windows.h>
#include <cstring>

using namespace std;

int main()
{
    setlocale(LC_ALL,"RUS");

    cout<<"Введите количество книг: ";
    int AmountOfBooks;
    cin>>AmountOfBooks;

    system("cls");

    struct Books
    {
        char NameBook[20];
        char AuthorName[20];
        char AuthorSurname[20];
        int AmountOfPage;
        char KindOfBook[20];
        char BookLanguage[20];
        char PublishName[20];
        char Country[20];
        int YearOfPublish;
    } B[AmountOfBooks];

    for(int i=0; i<AmountOfBooks; i++)
    {
        cout<<"Введите название книги(слитно): ";
        cin>>B[i].NameBook;

        cout<<"Введите имя автора: ";
        cin>>B[i].AuthorName;

        cout<<"Введите фамилию автора: ";
        cin>>B[i].AuthorSurname;

        cout<<"Введите количество страниц: ";
        cin>>B[i].AmountOfPage;

        cout<<"Введите жанр книги: ";
        cin>>B[i].KindOfBook;

        cout<<"Введите язык книги: ";
        cin>>B[i].BookLanguage;

        cout<<"Введите название издательства: ";
        cin>>B[i].PublishName;

        cout<<"Введите страну написания книги: ";
        cin>>B[i].Country;

        cout<<"Введите год написания книги: ";
        cin>>B[i].YearOfPublish;

        system("cls");
    }

    int Selection;
    int Reselection;
    bool FinishProgram = false;

    while(!FinishProgram)
    {
        cout<<"1. Список румынских книг изданных за рубежом."<<endl;
        cout<<"2. Список книг заданного автора."<<endl;
        cout<<"3. Список книг изданных по заданной тематике, начиная с 2000 года."<<endl;
        cout<<"Ваш выбор: ";
        do
        {
            cin>>Selection;
        }
        while(Selection>3 or Selection<1);

        system("cls");

        switch(Selection)
        {
        case 1:
        {

            for(int i=0; i<AmountOfBooks; i++)
            {
                if(strcmp(B[i].BookLanguage,"Rom")==0)
                    if(strcmp("Romania",B[i].Country)!=0)
                    {
                        cout<<"Книга - "<<B[i].NameBook<<endl;
                        cout<<"Автор - "<<B[i].AuthorName<<" "<<B[i].AuthorSurname<<endl;
                        cout<<"Количество страниц - "<<B[i].AmountOfPage<<endl;
                        cout<<"Жанр книги - "<<B[i].KindOfBook<<endl;
                        cout<<"Язык написания - "<<B[i].BookLanguage<<endl;
                        cout<<"Название издательства - "<<B[i].PublishName<<endl;
                        cout<<"Страна написания - "<<B[i].Country<<endl;
                        cout<<"Год написания книги - "<<B[i].YearOfPublish<<endl;
                        cout<<endl<<endl;
                    }
            }

            cout<<endl<<endl;
            cout<<"1.Вернуться в меню."<<endl;
            cout<<"2.Выйти из программы."<<endl;
            do
            {
                cin>>Reselection;
            }
            while(Reselection>2 or Reselection<1);

            if (Reselection==1)
                system("cls");
            if(Reselection==2)
                FinishProgram=true;
            break;
        }
        case 2:
        {
            char Name[20];
            char Surname[20];

            cout<<"Введите фамилию автора: ";
            cin>>Surname;
            cout<<"Введите имя автора: ";
            cin>>Name;

            system("cls");

            for(int i=0; i<AmountOfBooks; i++)
            {
                if(strcmp(B[i].AuthorSurname,Surname)==0)
                    if(strcmp(B[i].AuthorName,Name)==0)
                    {
                        cout<<"Книга - "<<B[i].NameBook<<endl;
                        cout<<"Автор - "<<B[i].AuthorName<<" "<<B[i].AuthorSurname<<endl;
                        cout<<"Количество страниц - "<<B[i].AmountOfPage<<endl;
                        cout<<"Жанр книги - "<<B[i].KindOfBook<<endl;
                        cout<<"Язык написания - "<<B[i].BookLanguage<<endl;
                        cout<<"Название издательства - "<<B[i].PublishName<<endl;
                        cout<<"Страна написания - "<<B[i].Country<<endl;
                        cout<<"Год написания книги - "<<B[i].YearOfPublish<<endl;
                        cout<<endl<<endl;
                    }
            }

            cout<<endl<<endl;
            cout<<"1.Вернуться в меню."<<endl;
            cout<<"2.Выйти из программы."<<endl;
            do
            {
                cin>>Reselection;
            }
            while(Reselection>2 or Reselection<1);

            if (Reselection==1)
                system("cls");
            if(Reselection==2)
                FinishProgram=true;
            break;
        }
        case 3:
        {
            char Kind[20];
            cout<<"Введите жанр книги: ";
            cin>>Kind;

            system("cls");

            for(int i=0; i<AmountOfBooks; i++)
            {
                if(strcmp(Kind,B[i].KindOfBook)==0)
                    if(B[i].YearOfPublish>=2000)
                    {
                        cout<<"Книга - "<<B[i].NameBook<<endl;
                        cout<<"Автор - "<<B[i].AuthorName<<" "<<B[i].AuthorSurname<<endl;
                        cout<<"Количество страниц - "<<B[i].AmountOfPage<<endl;
                        cout<<"Жанр книги - "<<B[i].KindOfBook<<endl;
                        cout<<"Язык написания - "<<B[i].BookLanguage<<endl;
                        cout<<"Название издательства - "<<B[i].PublishName<<endl;
                        cout<<"Страна написания - "<<B[i].Country<<endl;
                        cout<<"Год написания книги - "<<B[i].YearOfPublish<<endl;
                        cout<<endl<<endl;
                    }
            }

            cout<<endl<<endl;
            cout<<"1.Вернуться в меню."<<endl;
            cout<<"2.Выйти из программы."<<endl;
            do
            {
                cin>>Reselection;
            }
            while(Reselection>2 or Reselection<1);

            if (Reselection==1)
                system("cls");
            if(Reselection==2)
                FinishProgram=true;
            break;

        }
        }
    }
}


