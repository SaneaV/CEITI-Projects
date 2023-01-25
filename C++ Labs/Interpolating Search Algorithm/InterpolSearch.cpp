#include <iostream>
#include <windows.h>
#include <conio.h>

using namespace std;

void Sort(int* &Array, int NumberOf)
{
    int step, i, j, tmp;

    for (step = NumberOf / 2; step > 0; step /= 2)

        for (i = step; i < NumberOf; i++)

            for (j = i - step; j >= 0 && Array[j] > Array[j + step]; j -= step)
            {
                tmp = Array[j];
                Array[j] = Array[j + step];
                Array[j + step] = tmp;
            }
}


int main()
{
    setlocale(LC_ALL,"RUS");

    bool End = false;
    int *Array = new int[100];
    int Number = 0;

    cout<<"Введите величину массива: ";
    cin>>Number;

    for(int i=0; i<Number; i++)
    {
        cout<<"Введите число: ";
        cin>>Array[i];
    }

    Sort(Array, Number);

    bool Exit = false;

    while(!Exit)
    {
        cout<<"Ваш массив: ";
        for(int i=0; i<Number; i++)
        {
            cout<<Array[i]<<" ";
        }
        cout<<endl;

        int x;
        cout<<"Введите число для поиска: ";
        cin>>x;

        int s = 0;
        int d = Number-1;
        int m;
        int m2=-1;
        bool Find = false;

        while((x>=Array[s] or x<=Array[d]) and !Find)
        {
            m = s + (x-Array[s])*(d-s)/(Array[d]-Array[s]);

            if(x>Array[m])
                s = m+1;
            else
                d = m-1;

            if(m2!=m)
                m2=m;
            else
                Find =true;

            if(Array[m]==x or s>=d or Array[s]==Array[d])
                Find = true;
        }


        if(Array[m]==x)
            cout << x << " - найден на позиции - " << m+1 << endl;
        else
            cout << "Элемент не найден" << endl;

        cout<<"Нажмите \"x\", чтобы выйти"<<endl<<endl;
        if(_kbhit)
            switch(getch())
            {
            case 'x':
            {
                Exit = true;
                break;
            }
            default:
                (system("cls"));
            }
    }

}

