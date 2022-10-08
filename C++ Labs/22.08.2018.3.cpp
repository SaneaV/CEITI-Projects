/*"Багаж пассажира характеризуется  ФИО пассажира, количеством вещей и общим весом вещей. Задать массив записей, содержащий сведения о багаже всех пассажиров. Подсчитать и вывести на экран:
• найдите число пассажиров, у которых количество вещей превосходит среднее число вещей.
• найдите всех пассажиров, у которых багаж состоит из 1 вещи весом менее 100 кг, но более 10 кг.*/

#include <iostream>
#include <windows.h>

using namespace std;

int main()
{
    setlocale(LC_ALL,"RUS");

    cout<<"Введите количество пассажиров: ";
    int n;
    cin>>n;

    system("cls");

    struct BAG
    {
        char Name[20];
        char Surname[20];
        char MiddleName[20];
        int k;
        int m;
    } B[n];

    for(int i=0; i<n; i++)
    {
        cout<<"Введите имя человека: ";
        cin>>B[i].Name;

        cout<<"Введите фамилию человеку: ";
        cin>>B[i].Surname;

        cout<<"Введите отчество человека: ";
        cin>>B[i].MiddleName;

        cout<<"Введите количество вещей: ";
        cin>>B[i].k;

        cout<<"Введите массу вещей: ";
        cin>>B[i].m;

        system("cls");
    }

    int Selection;
    int Reselection;
    bool FinishProgram = false;

    while(!FinishProgram)
    {
        cout<<"1. Число пассажиров, у которых количество вещей превосходит среднее число вещей."<<endl;
        cout<<"2. Пассажиры, у которых багаж состоит из 1 вещи весом менее 100 кг, но более 10 кг."<<endl;
        cout<<"Ваш выбор: ";
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
            int S = 0;
            int k = 0;
            int M = 0;
            for(int i=0; i<n; i++)
            {
                S += B[i].k;
            }

            M = S/n;

            for(int i=0; i<n; i++)
            {
                if(B[i].k>M)
                    k++;
            }

            cout<<"Число пассажиров, у которых количество багажа выше среднего: "<<k<<endl;

            cout<<endl<<endl;
            cout<<"1.Вернуться в меню."<<endl;
            cout<<"2.Выйти из программы."<<endl;
            do
            {
                cin>>Reselection;
            }
            while(Reselection>2 or Reselection<1);

            if (Reselection==1)
                system("cls");
            if(Reselection==2)
                FinishProgram=true;
            break;
        }
        case 2:
        {
            for(int i=0; i<n; i++)
            {
                if(B[i].k==1)
                    if(B[i].m>10 and B[i].m<100)
                        cout<<"Пассажир - "<<B[i].Name<<" "<<B[i].Surname<<" "<<B[i].MiddleName<<" - перевозит с собой 1 вещь, весом в - "<<B[i].m<<" кг."<<endl;
            }

            cout<<endl<<endl;
            cout<<"1.Вернуться в меню."<<endl;
            cout<<"2.Выйти из программы."<<endl;
            do
            {
                cin>>Reselection;
            }
            while(Reselection>2 or Reselection<1);

            if (Reselection==1)
                system("cls");
            if(Reselection==2)
                FinishProgram=true;
            break;
        }

        }



    }
}
