//РЎРѕСЂС‚РёСЂРѕРІРєР° РїРѕРґСЃС‡С‘С‚Р° в„–3

#include <iostream>
#include <windows.h>

using namespace std;

main()
{
    SetConsoleCP(1251);
    int a[999],b[999],c[999];
    int  n;

    cout<<"n=";
    cin>>n;
    cout<<"РІРІРµРґРёС‚Рµ "<<n<<" СЌР»РµРјРµРЅС‚РѕРІ РјР°СЃСЃРёРІР°"<<endl;
    for(int i=0; i<n; i++) cin>>a[i];
    cout<<"РјР°СЃСЃРёРІ РґРѕ СЃРѕСЂС‚РёСЂРѕРІРєРё:"<<endl;
    for(int i=0; i<n; i++) cout<<a[i]<<" ";

    //РѕРїСЂРµРґРµР»РµРЅРёРµ РЅРѕРјРµСЂРѕРІ РјРµСЃС‚:/
     for(int i=0; i<n; i++) b[i] = 0;
    for(int i=n-1; i>0; i--)
        for(int j=i-1; j>=0; j--)
            if (a[i] < a[j])  b[j] = b[j]+1;
            else b[i]= b[i]+1;
    //СЂР°СЃСЃС‚Р°РЅРѕРІРєР° СЌР»РµРјРµРЅС‚РѕРІ РјР°СЃСЃРёРІР°:
    for(int i=0; i<n; i++) c[ b[i] ] = a[i];

    cout<<endl<<"РћС‚СЃРѕСЂС‚РёСЂРѕРІР°РЅРЅС‹Р№ РјР°СЃСЃРёРІ: "<<endl;
    for(int i=0; i<n; i++) cout<<c[i]<<" ";
}

