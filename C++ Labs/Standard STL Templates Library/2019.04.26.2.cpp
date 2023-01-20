п»ї#include <iostream>
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

	cout << "РџРµСЂРІС‹Р№ СЌР»РµРјРµРЅС‚ РІРµРєС‚РѕСЂР°: " << *it << endl;

	cout << endl << "Р­Р»РµРјРµРЅС‚С‹ РІРµРєС‚РѕСЂР°: ";

	for (;it != MyVector.end();it++)
	{
		cout << *it << " ";
	}

	cout << endl <<  endl;

	////////////////////////////////////////////////////////////////////

	cout << "Р РµРІС‘СЂСЃ РёС‚С‚РµСЂР°С‚РѕСЂ: ";
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

	cout << "Р