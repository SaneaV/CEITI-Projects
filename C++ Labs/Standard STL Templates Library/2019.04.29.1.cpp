#include <iostream>
#include <array>

using namespace std;

int main()
{
	setlocale(LC_ALL, "RUS");
	
	array<int, 4> arr = { 5,7,8,9 };

	///////////////////////////////////////////////////////////////////
	cout << "Обращение к элементу через at: ";
	cout << arr.at(0) << endl;
	cout << endl << endl;

	///////////////////////////////////////////////////////////////////
	cout << "Поиск ошибки через exception: " << endl;
	try
	{
		cout << arr.at(5) << endl;
	}
	catch(const exception &ex)
	{
		cout << ex.what() << endl;
	}

	cout << endl;

	///////////////////////////////////////////////////////////////////
	cout << "Заполнение array: " << endl;

	for (int i = 0; i < arr.size() ;i++)
	{
		cout << "Введите число: ";
		cin >> arr[i];
	}
	cout << endl;

	///////////////////////////////////////////////////////////////////
	cout << "Range based цикл: " << endl;
	for (auto i : arr)
	{
		cout << i << " ";
	}
	cout << endl << endl;

	///////////////////////////////////////////////////////////////////
	cout << "Доступ к первому элементу: " << arr.front() << endl;
	cout << "Доступ к последнему элементу: " << arr.back() << endl;

	return 0;
}