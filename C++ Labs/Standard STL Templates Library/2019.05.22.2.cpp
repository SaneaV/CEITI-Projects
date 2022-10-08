#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ofstream fout;
    fout.open("MyFile.txt", ofstream::app);

    if(!fout.is_open())
    {
        cout<<"File was not open"<<endl;
    }
    else
    {
        fout<<"It is our data"<<endl;
    }
    fout.close();

    ifstream fin;
    fin.open("MyFile.txt");
    if(!fin.is_open())
    {
        cout<<"File was not open"<<endl;
    }
    else
    {
        string str;
        while(!fin.eof())
        {
            getline(fin, str);
            cout<<str;
            cout<<endl;
        }
    }
    fin.close();

    return 0;
}
