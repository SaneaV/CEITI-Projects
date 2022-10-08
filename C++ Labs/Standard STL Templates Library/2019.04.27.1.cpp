#include <iostream>
#include <list>
#include <algorithm>
#include <ctime>
#include <stdlib.h>

using namespace std;

template <typename T>
void printList(const list<T>& lst)
{
	for (auto i = lst.begin();i != lst.end();++i)
	{
		cout << *i << " ";
	}

	cout << endl << endl;
}

struct randNumber
{
	int operator () () { return (rand() % 100); }
};

int main()
{
	setlocale(LC_ALL, "RUS");
	srand(time(0));

	list<int> myList = { 99 , 10, 9 , 55 , 99 , 7 , 8 , 99 , 99 , 99};

	myList.push_back(10);
	myList.push_front(5);

	auto listIter = myList.begin();

	cout << "Вывод листа на экран: " << endl;
	printList(myList);

	cout << "Вывод сортированного по возрастанию листа: " << endl;
	myList.sort();
	printList(myList);

	cout << "Удаление первого и последнего элемента: " << endl;
	myList.pop_back();
	myList.pop_front();
	printList(myList);

	cout << "Количество элементов в списке: ";
	cout << myList.size() << endl << endl;

	cout << "Удаление дубликатов в списке (подряд): " << endl;
	myList.push_front(99);
	printList(myList);
	myList.unique();
	printList(myList);

	cout << "Очистка листа: " << endl;
	myList.clear();
	cout << "Количество элементов в списке: ";
	cout << myList.size() << endl;
	cout << "Заполнение листа случайными числами." << endl << endl;;
	myList.resize(10);
	generate(myList.begin(), myList.end(), randNumber());
	cout << "Лист заполнен: " << endl;
	printList(myList);

	cout << "Ревёрс списка: " << endl;
	myList.reverse();
	printList(myList);

	cout << "Добавление и удаление элемента через Insert и Erase: " << endl;
	listIter = myList.begin();
	advance(listIter, 5);
	myList.insert(listIter, 1000);
	printList(myList);
	listIter--;
	myList.erase(listIter);
	printList(myList);

	cout << "Удаление конкретного числа (remove): " << endl;
	listIter = myList.begin();
	advance(listIter, 5);
	myList.insert(listIter, 7);
	listIter++;
	myList.insert(listIter, 7);
	printList(myList);
	myList.remove(7);
	printList(myList);


	cout << "Заполнение списка при помощи assign() только одним элементом: " << endl;
	myList.assign(10, (rand() % 100));
	printList(myList);

	cout << "Перезапись одного списка в другой: " << endl;
	cout << "Первый список: ";
	printList(myList);
	cout << "Второй список: ";
	list<int> myList2 = { 1,2,3,4,5 };
	printList(myList2);
	cout << "Копирование." << endl << endl;
	cout << "Первый список: " << endl;
	myList.assign(myList2.begin(), myList2.end());
	printList(myList);


	return 0;
}