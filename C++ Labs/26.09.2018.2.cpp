//Двое детей получили по n яблок. Разработайте программу, которыая выведет на экран, сколько яблок у каждого
//если первый ребёнок съел одно яблоко и одно отдал второму ребёнкую
//Пример: n=10
//Ответ: у первого ребёнка 8 яблок, а у второго 11

#include <iostream>

using namespace std;

int main()
{
    int n;
    cout<<"Skolko iablok poluchat deti: ";
    cin>>n;

    cout<<"Iablok u pervogo rebenka: "<<n-2<<endl;
    cout<<"Iablok u vtorogo rebenka: "<<n+1;
}
