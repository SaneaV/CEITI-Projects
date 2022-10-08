//Расписание уроков

#include <iostream>

using namespace std;

main()
{
    setlocale (LC_ALL, "Russian");
    cout<<"Введите день недели: ";
    int x;
    cin>>x;

    cout<<"\nВ данный день недели у вас: \n\n";

    switch(x)
    {
    case 1:{cout<<"Математика\nРусский\nГеография\n\n";break;}
    case 2:{cout<<"Немецкий\nФизра\nМатематика\n\n";break;}
    case 3:{cout<<"Французский\nИнформатика\nНауки\n\n";break;}
    case 4:{cout<<"История\nСамооборона\nБиология\n\n";break;}
    case 5:{cout<<"Освобождение от уроков\n\n";break;}
    case 6:{cout<<"У вас выходной\n\n";break;}
    case 7:{cout<<"У вас выходной\n\n";break;}
    default:cout<<"Такого дня недели нет\n\n";
    }
}
