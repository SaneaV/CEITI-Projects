//Меню:
//1. Сортировка пузырьком.
//2. Усовершенствованный метод пузырька.
//3. Сортировка методом выбора.
//4. Сортировка вставками.

#include <iostream>

using namespace std;

main()
{
    setlocale(LC_ALL,"Rus");

    cout<<"Добро пожаловать!"<<endl<<endl<<"Вы находитесь в меню сортировки данных."<<endl;
    cout<<"1. Сортировка пузырьком."<<endl;
    cout<<"2. Усовершенствованный метод пузырька."<<endl;
    cout<<"3. Сортировка методом выбора."<<endl;
    cout<<"4. Сортировка вставками."<<endl;
    int x;
    cout<<endl<<"Выберите способ сортировки: ";
    cin>>x;

    switch (x)
    {
    case 1:
    {
        cout<<"Введите количество элементов в массиве: ";
        int n;
        cin>>n;

        int x[n];

        for (int i=0; i<n; i++)
            {
                cout<<"Введите число: ";
                cin>>x[i];
            }

        int c=0;

        for (int i=0; i<n-1; i++)
        {
            for (int j=0; j<n; j++)
            {
                if (x[j]>x[j+1])
                {
                    c=x[j];
                    x[j]=x[j+1];
                    x[j+1]=c;
                }
            }
        }

        for (int i=0; i<n; i++)
            cout<<x[i]<<" ";
        break;
    }
    case 2:
    {
        cout<<"Введите количество элементов в массиве: ";
        int n;
        cin>>n;

        int x[n];

        for (int i=0; i<n; i++)
            {
                cout<<"Введите число: ";
                cin>>x[i];
            }

        int c=0;

        bool y=false;

        do
        {
            y=false;
            for (int i=0; i<n; i++)
            {
                if (x[i]>x[i+1])
                {
                    c=x[i];
                    x[i]=x[i+1];
                    x[i+1]=c;
                    y=true;
                }
            }
        }
        while (y);

        for (int i=0; i<n; i++)
            cout<<x[i]<<" ";
        break;
    }
    case 3:
    {
        cout<<"Введите количество элементов в массиве: ";
        int n;
        cin>>n;

        int x[n];

        for (int i=0; i<n; i++)
            {
                cout<<"Введите число: ";
                cin>>x[i];
            }

        int c=0;
        int pmin=0;

        for (int j=0; j<n-1; j++)
        {
            pmin=j;
            for (int i=j+1; i<n; i++)

                if (x[i]<x[pmin])
                    pmin=i;

            c=x[j];
            x[j]=x[pmin];
            x[pmin]=c;

        }



        for (int i=0; i<n; i++)
            cout<<x[i]<<" ";
        break;
    }
    case 4:
    {
        cout<<"Введите количество элементов в массиве: ";
        int n;
        cin>>n;

        int x[n];

        for (int i=0; i<n; i++)
            {
                cout<<"Введите число: ";
                cin>>x[i];
            }

        int c=0;
        int j;


        for (int i=1; i<n; i++)
        {
            j=i;

            while (x[j]<x[j-1] and j>0)
            {
                c=x[j];
                x[j]=x[j-1];
                x[j-1]=c;
                j--;
            }
        }

        for (int i=0; i<n; i++)
            cout<<x[i]<<" ";

        break;
    }
    }
}
