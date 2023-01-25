#include <iostream>
#include <fstream>

using namespace std;
char timp[30];

int PS(int decade)
{
    int k = 0;
    decade--;
    for(int i=decade; i<decade+10; i++)
        if(timp[i]=='S')
            k++;

    return k;

}

int main()
{
    int i = 0;
    ifstream f("vreme.in.txt");
    while(f>>timp[i])
        i++;
    f.close();

    int First = PS(1), Second= PS(11), Last= PS(21);
    int max = First, p = 1;
    if(max<Second)
    {
        max = Second;
        p=11;
    }
    if(max<Last)
    {
        max = Last;
        p = 21;
    }

    ofstream g("vreme.out.txt");
    g<<p<<"-"<<p+9<<endl<<max;
    g.close();
}
