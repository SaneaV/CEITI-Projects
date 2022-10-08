//Даны числа a=1 b=2 c=3 d4
//Выполнить сдвиг вправо.
//Выполнил сдвиг при помощи массива и при помощи создания новой переменной.

#include <iostream>
#include <windows.h>

using namespace std;

int main()
{
    setlocale(LC_ALL,"RUS");

    int Selection;
    cout<<"1. Использовать одномерный массив."<<endl;
    cout<<"2. Использовать только переменные."<<endl;
    do
    {
        cin>>Selection;
    }
    while(Selection>2 or Selection<1);

    system("cls");

    switch(Selection)
    {
    case 1:
    {
        float A[4];//Массив чисел
        float FirstLast;//Временная переменная для последнего элемента
        cout<<"Введите числа \"a\", \"b\", \"c\", \"d\": ";
        cin>>A[0]>>A[1]>>A[2]>>A[3];

        cout<<endl<<endl;

        cout<<"Вы ввели массив: ";
        for(int i=0; i<4; i++)
        {
            cout<<A[i]<<" ";
        }

        for(int i=3; i>=0; i--)
        {
            if(i==3)
                FirstLast=A[i];

            A[i]=A[i-1];

            if(i==0)
                A[i]=FirstLast;
        }

        cout<<endl<<endl;
        cout<<"Конечный вид массива: ";
        for(int i=0; i<4; i++)
        {
            cout<<A[i]<<" ";
        }

        cout<<endl<<endl;

        break;
    }
    case 2:
    {
        float x,y,z,t;
        float c;

        cout<<"Введите числа \"a\", \"b\", \"c\", \"d\": ";
        cin>>x>>y>>z>>t;

        cout<<"Ваши числа: "<<x<<y<<z<<t<<endl<<endl;

        c=t;
        t=z;
        z=y;
        y=x;
        x=c;

        cout<<"Конечный вид: "<<x<<y<<z<<t<<endl<<endl;

        break;
    }
    }

}
