//Создать файл, записать в него числа и перезаписать во второй файл.

#include <iostream>
#include <stdio.h>

using namespace std;

main()
{
    setlocale(LC_ALL,"RUS");

    FILE *f;
    FILE *f1;

    f=fopen("F1.txt","w");

    int n;
    cout<<"Введите количество чисел: ";
    cin>>n;


    int x;
    for (int i=0; i<n; i++)
    {
        cout<<"Введите число: ";
        cin>>x;
        fwrite(&x,sizeof(int),1,f);
    }
    fclose(f);


    cout<<"\n\nРабота с первым файлом окончена!";
    cout<<"\n\nРабота с вторым файлом: "<<endl<<endl;

    f=fopen("F1.txt","r");
    f1=fopen("F2.txt","w");


    for (int i=0; i<n; i++)
    {
        fread(&x,sizeof(int),1,f);
        cout<<"Число "<<x<<" перезаписано!"<<endl;
        fwrite(&x,sizeof(int),1,f1);
    }


    fclose(f1);
    fclose(f);
    f1=fopen("F2.txt","r");

    cout<<"\n\nСодержимое второго файла: ";

    for (int i=0; i<n; i++)
    {
        fread(&x,sizeof(int),1,f1);
        cout<<x<<" ";
    }
    cout<<"\n\n";

    fclose(f1);
}
