#include <iostream>
#include <stdio.h>

using namespace std;

main()
{
    FILE *f;
    f=fopen("Zadacha3.txt","r");

    struct figur
    {
        int Nomer;
        char Nazvanie[20];
        int perimetr;
        int ploshadi;
    } x[30];

    cout<<"Vvedite nomer figuri: ";
    int n;
    cin>>n;

    int i=0,j=0;


    while (!feof(f))
    {
        fread(&x[i],sizeof(figur),1,f);

        if (!feof(f))
        {
            if (n!=x[i].Nomer)
            {

                fclose(f);
                f=fopen("Zadacha3.txt","wa");
                    cout<<"Vvedite nomer: ";
                    cin>>x[i].Nomer;
                    cout<<"Vvedite Nazvanie: ";
                    cin>>x[i].Nazvanie;
                    cout<<"Vvedite perimet: ";
                    cin>>x[i].perimetr;
                    cout<<"Vvedte ploshadi: ";
                    cin>>x[i].ploshadi;
                    fwrite(&x[i],sizeof(figur),1,f);
                    fclose(f);
                    f=fopen("Zadacha3.txt","r");
            }
            else
            {


            }
        }
    }



    fclose(f);

    f=fopen("Zadacha3.txt","r");

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
