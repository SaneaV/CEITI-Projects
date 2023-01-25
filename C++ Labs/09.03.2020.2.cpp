#include <iostream>
#include <cstring>
#include <fstream>
#include <iomanip>

using namespace std;

int main(){

    int N;
    float Price;
    char Name[255];
    char SecondName[255];
    int Calls;

    int Short = 0;
    int Long = 0;

    ifstream f("Date.in.txt");
    ofstream g("Date.out.txt");

    f>>N>>Price;
    f>>Name>>SecondName;

    for(int i=0;i<N;i++)
    {
        f>>Calls;
        if(Calls<60) Short++;
        if(Calls>=60) Long++;
    }

    f.close();

    g<<Name[0]<<Name[1]<<SecondName[0]<<SecondName[1]<<endl;
    g<<fixed<<setprecision(2)<<Short*Price<<endl;
    g<<fixed<<setprecision(2)<<Long*Price * 2<<endl;
    g<<fixed<<setprecision(2)<<Short*Price + Long*Price * 2<<endl;

    g.close();
    return 0;
}
