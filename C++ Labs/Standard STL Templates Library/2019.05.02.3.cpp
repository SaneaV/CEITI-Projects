#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <windows.h>

using namespace std;

bool is_Exist()
{
    fstream r("Marfa.txt");

    if(r)
    {
        return 1;
        r.close();
    }
    else
        return 0;
}

void create_File()
{
    ofstream w("Marfa.txt");
    w.close();
}

bool is_Empty()
{
    fstream r("Marfa.txt");

    r.seekg (0, r.end);
    int length = r.tellg();
    if(length != 0 )
        return 1;
    else
        return 0;

    r.close();
}

void put_Marfa()
{
    ofstream w("Marfa.txt");

    int n;
    string str;

    cout<<"¬ведите количество товара: ";
    cin>>n;
    system("cls");

    for(int i=0; i<n; i++)
    {
        cout<<i+1<<". ¬ведите название товара: ";
        cin>>str;

        w<<i+1<<" "<<str<<endl;
    }
    w.close();
}

template<typename f, typename s>
void fill_Marfa(map<f,s> &M)
{
    ifstream r("Marfa.txt");

    int number;
    string str;

    while(!r.eof())
    {
        r>>number>>str;

        M.emplace(number,str);
    }
    r.close();
}

template<typename f, typename s>
void output_Marfa(const map<f,s> &M)
{
    for(auto i:M)
        cout<<i.first<<". "<<i.second<<endl;
    cout<<endl;
}



int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    map<int, string> Marfa;

    if(!is_Exist())
    {
        create_File();
    }

    if(!is_Empty())
    {
        put_Marfa();
        fill_Marfa(Marfa);
        system("cls");
    }
    else
    {
        fill_Marfa(Marfa);
    }

    output_Marfa(Marfa);



    return 0;
}
