//Программа, для подсчёта среднего балла ученика

#include<iostream>
#include <stdlib.h>
#include <iomanip>
#include <windows.h>

using namespace std;

main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    cout<<"Добрый день!"<<endl;
    cout<<"Давайте подсчитаем ваш средний балл."<<endl;
    cout<<"Для выхода из программы просто напишите \"8888\""<<endl;
    float y=1,S=0,x;


    do
    {
        cout<<"\nВведите вашу оценку: \n"<<y<<".";
        while (!(cin>>x))//Вводим значение и если это не цифра, начинается цикл (! - not)
        {
            cout<<"Ошибка, вы ввели что-то не то. "<<endl;
            cin.clear();//Очищает поток
            cin.sync();//Удаляет данные из буффера
            cout<<"\nВведите вашу оценку: \n"<<y<<".";
        }
        if (x>0 and x<11)
        {
            S+=x;
            ++y;
        }
        else if (x!=8888) (cout<<"Вы ввели большую цифру, не переживай, продолжай вводить оценки\n");

    }
    while (x!=8888);
    cout<<"Ваш средний балл: "<<setprecision(3)<<S/(--y)<<"\n\n\n";
    system("PAUSE");
}
