//Дан текстовый файл F.txt, каждая строка которого содержит три вещественных числа, представляющих собой стороны треугольника. Напишите программу,
//которая запишет в соответствующую строку текстового файла  G.txt тип треугольника (равнобедренный, равносторонний, произвольный).


#include <iostream>
#include <fstream>
#include <windows.h>
#include <iomanip>
#include <cmath>

using namespace std;

main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout<<setw(40)<<"Добро пожаловать!"<<endl;

    cout<<"Выберите способ заполнения файла: "<<endl;
    cout<<"1. Автоматически."<<endl;
    cout<<"2. Вручную."<<endl;

    cout<<"\n\nВы выбираете: ";

    int vib;

    while (!(cin>>vib) or vib>2 or vib<1)//Вводим значение и если это не цифра, начинается цикл (! - not)
    {
        cout<<"Ошибка, вы ввели что-то не то.\n ";
        cin.clear();//Очищает поток
        cin.sync();//Удаляет данные из буффера
        cout<<"\nВы выбираете: ";
    }
    system("cls");

    cout<<"Введите количество треугольников: ";

    int n;

    while (!(cin>>n))//Вводим значение и если это не цифра, начинается цикл (! - not)
    {
        cout<<"Ошибка, вы ввели что-то не то.\n ";
        cin.clear();//Очищает поток
        cin.sync();//Удаляет данные из буффера
        cout<<"\nВведите количество чисел: ";
    }

    system("cls");

    switch(vib)
    {
    case 1://Автоматический ввод
    {

        ofstream f("F.txt");
        int x;
        int k = 0;

        for (int i=0; i<(n*3); i++)
        {
            x = rand() % 20 +1;//Рандомные числа от 1 до 20
            f<<x<<" ";
            k++;
            if (k==3)
            {
                f<<endl;
                k=0;
            }
        }
        f.close();
        break;
    }

    case 2://Ручной ввод
    {
        ofstream f("F.txt");
        int a,b,c;

        for (int i=0; i<n; i++)
        {
            cout<<"Введите 3 числа через пробел: ";
            while (!(cin>>a>>b>>c))//Вводим значение и если это не цифра, начинается цикл (! - not)
            {
                cout<<"Ошибка, вы ввели что-то не то.\n ";
                cin.clear();//Очищает поток
                cin.sync();//Удаляет данные из буффера
                cout<<"\nВведите 3 числа через пробел: ";
            }
            f<<a<<" "<<b<<" "<<c<<endl;
        }
        f.close();
        break;
    }
    }

    ifstream f("F.txt");
    ofstream g("G.txt");

    int a=0,b=0,c=0;

    while (!f.eof())
    {
        f>>a>>b>>c;

        if (!f.eof())
        {
            if (((a+b)>c) and ((a+c)>b) and ((b+c)>a))
            {
                if (a==b and a==c and c==b)
                {
                    g<<a<<" "<<b<<" "<<c<<"    - Треугольник равносторонний"<<endl;
                }
                else if (a==b and a+b>c or a==c and a+c>b or c==b and c+b>a)
                {
                    g<<a<<" "<<b<<" "<<c<<"    - Треугольник равнобедренный"<<endl;
                }
                else if ((a*a+b*b==c*c)or(b*b+c*c==a*a)or(c*c+a*a==b*b))
                {
                    g<<a<<" "<<b<<" "<<c<<"    - Треугольник прямоугольный"<<endl;
                }
                else
                {
                    g<<a<<" "<<b<<" "<<c<<"    - Треугольник произвольный"<<endl;
                }
            }
            else
            {
                g<<a<<" "<<b<<" "<<c<<"   - Такого треугольника не существует"<<endl;
            }
        }
    }


    g.close();
    f.close();
    system("cls");
    cout<<"Программа закончила работу с файлами. "<<endl;

}
