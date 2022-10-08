//В массиве T[1..n] хранится фамилии учащихся. Напишите программу, которая выведет на экран повторяющиеся фамилии. 

#include <iostream>
#include <cstring>
#include <windows.h>

using namespace std;

main()
{
    SetConsoleCP(1251);//Для выводы русского языка
    SetConsoleOutputCP(1251);//Для ввода русского языка
    int n=0;

    cout<<"Программа поддерживает русский язык в консоли. \n"<<endl;
    cout<<"Количество учеников в классе: ";
    while (!(cin>>n))//Вводим значение и если это не цифра, то цикл не начинается(! - not)
    {
        cout<<"Ошибка, вы ввели что-то не то. "<<endl;
        cin.clear();//Очищает поток
        cin.sync();//Удаляет данные из буффера
        cout<<"Количество учеников в классе: ";
    }

    char T[100][25];


    cout<<"Введите фамили учеников (через entet): "<<endl;

    for(int i=0; i<n; i++)
        for (int j=0; j<1; j++)
        {
            cout<<i+1<<". ";
            cin>>T[i];

        }

    cout<<endl<<endl<<"Присутствующие в классе: "<<endl;
    //Вывод фамилий
    for(int i=0; i<n; i++)
    {
        for (int j=0; j<1; j++)
            cout<<i+1<<". "<<T[i]<<endl;
    }


    int z=0;

    cout<<endl<<"Совпадающие фамилии: "<<endl<<endl;
    for (int i=0; i<n; i++)
    {
        for (int k=n; k>i; k--)
        {
            if (strcmp(T[i], T[k])==0)//Проверяем строки на совпадение
            {
                cout<<T[i]<<endl;
                z++;
            }

        }
    }
    if (z==0) cout<<"В этом классе нет однофамильцев."<<endl;
}
