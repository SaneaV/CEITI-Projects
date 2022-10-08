//Создать программу, которая создаст файл, записав в него данные о фигуре (порядковый номер, название,
//периметр, площадь). Кол-во вводится с клавиатуры.

#include <iostream>
#include <stdio.h>

using namespace std;

main()
{
    cout<<"Programma rabotaet na translite."<<endl<<endl;

    cout<<"Vvedite kolichestvo figur: ";
    int n;
    cin>>n;

    struct figur
    {
        int Nomer;
        char Nazvanie[20];
        int perimetr;
        int ploshadi;
    } x[30];

    FILE *f;

    f=fopen("Zadacha3.txt","w");

    for (int i=0; i<n; i++)
    {
        cout<<"Vvedite nomer: ";
        cin>>x[i].Nomer;
        cout<<"Vvedite Nazvanie: ";
        cin>>x[i].Nazvanie;
        cout<<"Vvedite perimet: ";
        cin>>x[i].perimetr;
        cout<<"Vvedte ploshadi: ";
        cin>>x[i].ploshadi;
        fwrite(&x[i],sizeof(figur),1,f);

        cout<<endl;
    }
    fclose(f);

    f=fopen("Zadacha3.txt","r");
    int j=0;

    while (!feof(f))
    {
        fread(&x[j],sizeof(figur),1,f);

        if (!feof(f))
        {
            cout<<x[j].Nomer<<"\t"<<x[j].Nazvanie<<"\t"<<x[j].perimetr<<"\t"<<x[j].ploshadi<<endl;
        }
    }

    fclose(f);
}
