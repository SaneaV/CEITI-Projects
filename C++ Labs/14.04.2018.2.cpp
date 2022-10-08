//В одномерном массиве, вводимом с клавиатуры и состоящем из N вещественных элементов,
//вычислить количество четных элементов на четных позициях (использовать рекурсивную функцию для вычисления).

#include <iostream>

using namespace std;

void InputArray(float *x, int n)
{
    if(n==1)
    {
        cout<<"Введите элемент: ";
        cin>>x[0];
    }
    else
    {
        InputArray(x,n-1);
        cout<<"Введите элемент: ";
        cin>>x[n-1];
    }
}


void ShowArray (float *x, int n)
{
    if (n==1)
        cout<<x[0]<<" ";
    else
    {
        ShowArray(x,n-1);
        cout<<x[n-1]<<" ";
    }
}

int Even(float *x, int n)
{
    //В С++ нельзя проверить чётность вещественного числа
    //Воспользуемся: A=B/1
    int A = x[n-1]/1;
    if(n==0) return 0;
    else if (A%2==0 and n%2==0) return Even(x,n-1)+1;
    else return Even(x,n-1);
}


int main()
{
    setlocale(LC_ALL,"RUS");

    int m;
    cout<<"Введите количество элементов массива: ";
    while (!(cin>>m) or m<=0)//Вводим значение и если это не цифра, начинается цикл (! - not)
    {
        cout<<"Ошибка, вы ввели что-то не то.\n ";
        cin.clear();//Очищает поток
        cin.sync();//Удаляет данные из буффера
        cout<<"\nПовторите ввод: ";
    }
    float *Array = new float [m];


    cout<<endl;
    InputArray(Array,m);
    cout<<endl;
    ShowArray(Array,m);
    cout<<endl<<"Количество чётных элементов на чётных позициях: "<<Even(Array,m);
}
