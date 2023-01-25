#include <iostream>
#include <string>
#include <fstream>

using namespace std;

string ReadFromFile(string fileName)
{
    ifstream file;
    file.open(fileName.c_str());
    string line;
    string allLines = "";

    while(getline(file,line))
    {
        allLines+=line;
    }
    file.close();

    return allLines;
}

int checker(string code, string target)
{
    int occurrences = 0;
    std::string::size_type pos = 0;
    while ((pos = code.find(target, pos )) != std::string::npos)
    {
        ++ occurrences;
        pos += target.length();
    }

    return occurrences;
}

int main()
{
    string allCode = ReadFromFile("2021.02.26.txt");
    string functions[] = {"create_list", "insert", "delete", "display"};
    cout<<"Number of \"create list\": "<<checker(allCode, functions[0])<<endl;
    cout<<"Number of \"insert\": "<<checker(allCode, functions[1])<<endl;
    cout<<"Number of \"delete\": "<<checker(allCode, functions[2])<<endl;
    cout<<"Number of \"display\": "<<checker(allCode, functions[3])<<endl;

    return 0;
}

