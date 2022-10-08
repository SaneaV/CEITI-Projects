//Получаем значение маленькой латинской буквы из таблицы ASCII

#include <iostream>
#include <cctype>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    char x;
    cout<< "Введите букву латинского алфавита: ";
    cin>> x;

    x= tolower (x);


    cout<<int (x) -96 << endl;
}
