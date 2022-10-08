#include <iostream>
#include <vector>
#include <stdlib.h>
#include <ctime>

using namespace std;

int main()
{
	setlocale(LC_ALL, "RUS");

	vector <int> MyVector = { 10, 5, 7, 8, 9 };
	vector<int>::iterator it;
	it = MyVector.begin();

	cout << "Первый элемент вектора: " << *it << endl;

	cout << endl << "Элементы вектора: ";

	for (;it != MyVector.end();it++)
	{
		cout << *it << " ";
	}

	cout << endl <<  endl;

	////////////////////////////////////////////////////////////////////

	cout << "Ревёрс иттератор: ";
	vector<double> MySecondVector = { 2.1, 56.5, 75,4, 2.3, -1 };
	vector<double>::reverse_iterator ri = MySecondVector.rbegin();

	for (; ri != MySecondVector.rend();ri++)
	{
		cout << *ri << " ";
	}

	cout << endl <<  endl;
	////////////////////////////////////////////////////////////////////

	vector<char> MyThirdVector = { 'a', 'b', 'c', 'd', 'f' };
	vector<char>::iterator CharIterrator = MyThirdVector.begin();

	cout << "Использование функции advance: " << endl;
	cout << "Первый элемент вектора: " << *CharIterrator << endl;
	advance(CharIterrator, 3);
	cout << "advance(*CharIterrator, 3) ------> " << *CharIterrator << endl;
	cout << endl << endl << endl;

	////////////////////////////////////////////////////////////////////
	cout << "Добавление элемнтов в вектор при помощи insert: " << endl;

	vector<int>NewVec(10);
	NewVec = { 10, 5, 634, 5 };

	vector<int>::iterator itv = NewVec.begin();

	NewVec.insert(itv, 1);

	for (itv = NewVec.begin();itv != NewVec.end();itv++)
	{
		cout << *itv << endl;
	}

	cout << endl << endl << endl;

	////////////////////////////////////////////////////////////////////
	cout << "Метод erase: " << endl;

	itv = NewVec.begin();

	NewVec.erase(itv);

	for (itv = NewVec.begin();itv != NewVec.end();itv++)
	{
		cout << *itv << endl;
	}

	return 0;
}