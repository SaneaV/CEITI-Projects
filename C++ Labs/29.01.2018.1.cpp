#include <iostream>

using namespace std;

main()
{
    setlocale(LC_ALL,"Russian");
    int mat[100][100];

    int n,m;

    cout<<"Введите количетсво строк: ";
    while (!(cin>>n))//Вводим значение и если это не цифра, начинается цикл (! - not)
        {
            cout<<"Ошибка, вы ввели что-то не то. "<<endl;
            cin.clear();//Очищает поток
            cin.sync();//Удаляет данные из буффера
            cout<<"\nВведите количетсво строк: ";
        }


        cout<<"Введите количетсво столбцов: ";
    while (!(cin>>m))//Вводим значение и если это не цифра, начинается цикл (! - not)
        {
            cout<<"Ошибка, вы ввели что-то не то. "<<endl;
            cin.clear();//Очищает поток
            cin.sync();//Удаляет данные из буффера
            cout<<"\nВведите количетсво столбцов: ";
        }


    cout<<endl<<endl;

    //Заполняем матрицу
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<m; j++)
        {
            cout<<"Введите число: ";
            cin>>mat[i][j];
        }

    }

    cout<<endl<<endl<<"Исходная матрица: "<<endl;

    for (int i=0; i<n; i++)
    {
        for (int j=0; j<m; j++)
            cout<<mat[i][j]<<" ";
        cout<<endl;
    }

    cout<<endl<<endl;


    int t=0;

    //Пузырьковая сортировка

    for (int i=0; i<m; i++)
    {
        for (int j=0; j<m-1-i; j++)
        {
            if (mat[0][j] > mat[0][j+1])//Проверяем первую строку матрицы
            {
                for (int q=0; q<n; q++) //Переставляем столбцы в возрастающем порядке
                {
                    t = mat[q][j];
                    mat[q][j]=mat[q][j+1];
                    mat[q][j+1]=t;
                }
            }
        }
    }



    cout<<"Изменённая матрица: "<<endl;
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<m; j++)
            cout<<mat[i][j]<<" ";
        cout<<endl;
    }

}

