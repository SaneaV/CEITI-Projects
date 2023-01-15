//Дана квадратная матрица целых чисел размером N*N (N – вводим с клавиатуры). Удалить все строки матрицы, которые содержат минимальный элемент.

#include <iostream>
#include <cstdlib>
#include <stdlib.h>

using namespace std;

main()
{
    setlocale (LC_ALL, "Russian");

    int n=0,m=0;

    cout<<"Ваша матрица будет (N*N), ведите значение для \"N\": ";

    while (!(cin>>n))//Вводим значение и если это не цифра, то цикл не начинается(! - not)
    {
        cout<<"Ошибка, вы ввели что-то не то. "<<endl;
        cin.clear();//Очищает поток
        cin.sync();//Удаляет данные из буффера
        cout<<"Ведите значение для \"N\": \n";
    }

    m=n;//Присваиваем значение n для m. Необходимо для правильного использования (к пр. n--)


    int mat[n][m];//Создаём матрицу размерами N*N

    cout<<endl;

    cout<<"Вы можете ввести свои элементы или воспользоваться рандомом: \n"<<endl;
    cout<<"Ввести самому - 1 "<<endl;
    cout<<"Воспользоваться рандомом - 2 "<<endl;
    cout<<"\nВыберите вариант заполнения матрицы: ";

    int vib;

    while (!(cin>>vib) or vib>2 or vib<1)//Вводим значение и если это не цифра, то цикл не начинается(! - not)
    {
        cout<<"Ошибка, вы ввели что-то не то. "<<endl;
        cin.clear();//Очищает поток
        cin.sync();//Удаляет данные из буффера
        cout<<"Выберите вариант заполнения матрицы: ";
    }

    switch(vib)
    {
    case 1:
    {
        //Ввод элементов матрицы полизователем
        for (int i = 0 ; i < n ; i++ )
        {
            for (int j = 0 ; j < m ; j++ )
            {
                cout<<"Введите число: ";
                cin>>mat[i][j];
            }
        }break;
    }

    case 2:
    {
        //Ввод элементов матрицы рандомом
        for (int i = 0 ; i < n ; i++ )
        {
            for (int j = 0 ; j < m ; j++ )
            {
                mat[i][j] = (rand() % 100)-10;; // Каждый элемент случайному числу от -10 до 89

            }
        }break;
    }
    }

    cout << "\nВывод начальной матрицы:\n\n";
        //Вывод матрицы
    for (int i = 0 ; i < n ; i++ )
    {
        for (int j = 0 ; j < m ; j++ )
            cout<<mat[i][j]<<"\t";
        cout<<endl;
    }
    cout << "\n\n";


        //Поиск минимального элемента
    int min = mat[0][0];

    for (int i = 0 ; i < n ; i++ )
    {
        for (int j = 0 ; j < m ; j++ )
        {
            if (mat[i][j] < min)
            {
                min = mat[i][j];
            }
        }

    }

        //Удаление строк с минимальным элементом
    for (int i = 0 ; i < n ; i++ )
    {
        for (int j = 0 ; j < m ; j++ )
        {
            if (mat[i][j]==min)//проверяем условие
            {
                for(int k=i; k<n-1; k++) //если в строке есть минимальное число, заменяем её на нижнюю
                    for (int g=0; g<m; g++)
                    {
                        mat[k][g]=mat[k+1][g];
                    }
                n--;
                i--;
            }
        }
    }

        //Вывод матрицы
    cout << "Вывод конечной матрицы\n\n";
    for (int i = 0 ; i < n ; i++ )
    {
        for (int j = 0 ; j < m ; j++ )
            cout<<mat[i][j]<<"\t";
        cout<<endl;
    }
    system ("pause");
    }

