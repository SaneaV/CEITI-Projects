//РЎРѕСЂС‚РёСЂРѕРІРєР° РїРѕРґСЃС‡С‘С‚Р° в„–1
//РџСЂРµРґРїРѕР»РѕР¶РёРј, С‡С‚Рѕ РІСЃРµ СЌР»РµРјРµРЅС‚С‹ РјР°СЃСЃРёРІР° РјРµРЅСЊС€Рµ С‡РµРј 100, РЅРѕ РЅРµ РѕС‚СЂРёС†Р°С‚РµР»СЊРЅС‹Рµ


#include <iostream>

using namespace std;

main()
{
    int n;
    cout<<"Vvedite kolichestov chisel: ";
    cin>>n;
    int b[100];
    int a[100];

    for (int i=0;i<n;i++)
    {
        cout<<"Vvvedite chislo: ";
        cin>>a[i];
    }

    for (int i=0;i<100;i++)
    {
        b[i]=0;
    }

    for (int i=0;i<n;i++)
    {
        b[a[i]]++;
    }

    int k=0;

    for (int i=0;i<100;i++)
    {
        for (int j=0;j<b[i];j++)
        {
            a[k]=i;
            k++;
        }
    }

    for (int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
}
