//Даны натуральное число n и цифра c. Сколько раз повторяется цифра c при нумерации страниц кнги, в которой n страниц?

#include <iostream>
#include <windows.h>

using namespace std;

int main()
{
    setlocale(LC_ALL,"RUS");

    int c,n;

    cout<<"Введите количество страниц: ";
    cin>>n;

    cout<<"Ввелите число, которое будем искать: ";
    cin>>c;

    system("cls");

    int Select;
    cout<<"Выберите цикл для рещения данной задачи: "<<endl;
    cout<<"1.While"<<endl;
    cout<<"2.Do...While"<<endl;
    cout<<"3.For"<<endl;
    cout<<"Ваш выбор: ";
    cin>>Select;

    int i=1;
    bool checkb = true;
    int k=0;
    int Remember = 0;

    system("cls");

    switch(Select)
    {
    case 1:
    {
        while(Remember<=n)
        {
            checkb = true;
            i = Remember;

            while(checkb)
            {
                if (i%10==c and i!=0)
                    k++;
                if (i==0)
                    checkb = false;
                else
                {
                    i/=10;
                }

            }
            Remember++;

        }
        cout<<"Число "<<c<<" повторяется: "<<k<<" раз"<<endl;
        break;
    }
    case 2:
    {
        do
        {
            checkb = true;
            i = Remember;
            do
            {
                if (i%10==c and i!=0)
                    k++;
                if (i==0)
                    checkb = false;
                else
                {
                    i/=10;
                }

            }
            while(checkb);
            Remember++;

        }
        while(Remember<=n);
        cout<<"Число "<<c<<" повторяется: "<<k<<" раз"<<endl;
        break;
    }
    case 3:
    {
        for(; Remember<=n; Remember++)
        {
            checkb = true;
            i = Remember;
            for(; checkb;)
            {
                if (i%10==c and i!=0)
                    k++;
                if (i==0)
                    checkb = false;
                else
                {
                    i/=10;
                }
            }
        }
        cout<<"Число "<<c<<" повторяется: "<<k<<" раз"<<endl;
        break;
    }
    default: cout<<"Такого варианта нет."<<endl;
    }
}
