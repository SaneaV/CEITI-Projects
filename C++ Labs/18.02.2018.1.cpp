//Записать n чисел в файл. Найти их среднее арефметическое. Бинарный файл.

#include <iostream>
#include <stdio.h>

using namespace std;

main()
{
    setlocale (LC_ALL,"RUS");
    FILE *f;

    f=fopen("test1.txt","w");

    cout<<"Введите количество чисел: ";
    int n;
    cin>>n;

    float x;

    for (int i=0; i<n; i++)
    {
        cout<<"Введите число: ";
        cin>>x;
        fwrite(&x,sizeof(float),1,f);
    }

    fclose(f);
    cout<<"\n\nПроцесс записи окончен!";

    cout<<"\n\n\nПроцесс чтения файла!";

    f=fopen("test1.txt","r");

    float S=0,k=0;

    while (!feof(f))
    {
        if (!feof(f))
        {
            fread(&x,sizeof(float),1,f);

            if (x>0)
            {
                S+=x;
                k++;
            }
        }

    }

    cout<<endl<<endl<<"Среднее арефмитическое положительных чисел: "<<S/k<<endl;

    fclose(f);

}
