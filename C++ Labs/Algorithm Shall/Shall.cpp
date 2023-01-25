#include <iostream>
#include <windows.h>

using namespace std;
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

void FillArray(int* &Array, int &NumberOf)
{
    NumberOf = 0;
    int Number;
    cout<<"Print the numbers: ";

    while(cin>>Number and Number!='x')
        Array[NumberOf++] = Number;
}

void ShowArray(int* const Array, int const NumberOf)
{
    cout<<"Your array: ";
    for(int i=0; i<NumberOf; i++)
        cout<<Array[i]<<" ";
    cout<<endl;
}

void ShowArrayInTimeOfSorting(int* const Array, int const NumberOf, int const First, int const Second)
{
    for(int i=0; i<NumberOf; i++)
    {
        if(i==First or i==Second)
        {
            SetConsoleTextAttribute(hConsole, (WORD) ((0 << 4) | 10));
            cout<<Array[i]<<" ";
            SetConsoleTextAttribute(hConsole, (WORD) ((0 << 4) | 15));
        }
        else
            cout<<Array[i]<<" ";
    }
    cout<<endl;
}

void Sort(int* &Array, int NumberOf)
{
    int step, i, j, tmp;
    int k = 0;

    for (step = NumberOf / 2; step > 0;)
    {
        if(k>0 and step!=2 and step!=1)
        {
            step = (step/2) + 1;

        }
        else if (step==2 and k>0)
        {
            step = 1;
        }

        k++;


        cout<<endl<<endl<<"Step is: "<<step<<endl<<endl;
        for (i = step; i < NumberOf; i++)
        {
            for (j = i - step; j >= 0 and Array[j] > Array[j + step]; j -= step)
            {
                tmp = Array[j];
                Array[j] = Array[j + step];
                Array[j + step] = tmp;
                ShowArrayInTimeOfSorting(Array, NumberOf,j, j+step);
            }
        }

        if(k>0 and step == 1)
            step = 0;
    }
}

int main()
{
    setlocale(LC_ALL,"RUS");

    int *Array = new int[100];
    int NumberOf = 0;

    FillArray(Array, NumberOf);
    ShowArray(Array, NumberOf);

    Sort(Array, NumberOf);

    cout<<endl<<endl;

    ShowArray(Array, NumberOf);


    return 0;
}
