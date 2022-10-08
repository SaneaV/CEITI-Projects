//»з значени€ из таблицы ASCII получаем маленькую и большую букву латинского алфавита соответсвенно
#include <iostream>

using namespace std;

int main()

{
 setlocale(LC_ALL,"Russian");
 int x;
 cout<<"¬едите число: "<< endl;
 cin>> x;

 cout<<char(x+64)<<char(x+96);


}
