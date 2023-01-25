#include <iostream>
#include <string>
#include <fstream>

using namespace std;

bool isValid(string str)
{
    if(str.length()<8) return false;
    int k=0;
    for(int i=0;i<str.length();i++)
        if(str[i]>='A' and str[i]<='Z') k++;
    if(k==0) return false;
    return true;
}

int main(){
    ifstream f("Pr.in.txt");
    int n;
    string str;

    f>>n;

    ofstream g("Pr.out.txt");

    for(int i=0;i<n;i++)
    {
        f>>str;
        if(isValid(str))
            g<<str<<" "<<"Parola nevalida"<<endl;
        else
            g<<str<<" "<<"Parola valida"<<endl;
    }

    f.close();
    g.close();
}
