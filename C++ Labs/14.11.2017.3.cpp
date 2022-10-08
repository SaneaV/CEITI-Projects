//Вывести на экран:
//*****
//****
//***
//**
//*

#include <iostream>

using namespace std;

main()
{
    setlocale(0,"Rus");
    int n=1;

for (int i=5;i>=n;i--){
    for (int j=1;j<=i;j++)
        cout<<"*";
        cout<<endl;}
}
