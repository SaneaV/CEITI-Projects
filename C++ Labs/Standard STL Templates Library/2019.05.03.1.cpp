п»ї#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <stack>
#include <vector>
#include <list>

using namespace std;

template<typename t>
void fill_Stack(stack<t>& Stack)
{
	cout << "Р—Р°РїРѕР»РЅРµРЅРёРµ СЃС‚РµРєР°." << endl;

	for (int i = 0;i < 10;i++)
		Stack.emplace(rand() % 20);

	cout << endl;
}

template<typename t>
void print_Stack(stack<t> & Stack)
{
	cout << "Р’С‹РІРѕРґ СЃС‚РµРєР° РЅР° СЌРєСЂР°РЅ(РѕРґРЅРѕСЂР°Р·РѕРІС‹Р№ СЃРїРѕСЃРѕР±): " << endl;

	if (!Stack.empty())
		while (!Stack.empty())
		{
			cout << Stack.top() << " ";
			Stack.pop();
		}
	else cout << "РЎС‚РµРє РїСѓСЃС‚" << endl;

	cout << endl;
}

template<typename t>
void print_Stack_Multi(stack<t> & Stack)
{
	cout << "Р’С‹РІРѕРґ СЃС‚РµРєР° РЅР° СЌРєСЂР°РЅ(РјРЅРѕРіРѕСЂР°Р·РѕРІС‹Р№ СЃРїРѕСЃРѕР±): " << endl;

	vector<t> Temp(Stack.size());
	Temp.clear();

	while (!Stack.empty())
	{
		cout << Stack.top() << " ";
		Temp.push_back(Stack.top());
		Stack.pop();
	}

	auto it = Temp.rbegin();

	for (;it != Temp.rend();it++)
		Stack.push(*it);

	Temp.clear();

	cout << endl;
}

template<typename t>
void print_Container(deque<t>& Container)
{
	cout << "Р’С‹РІРѕРґ stack(deque) РЅР° СЌРєСЂР°РЅ: " << endl;

	auto it = Container.rbegin();

	for (;it!=Container.rend();it++)
		cout << *it << " ";
	cout << endl;
}

int main()
{
	setlocale(LC_ALL, "RUS");
	srand(time(0));

	stack<int> st;
	stack<int, list<int>> st2;

	fill_Stack(st);
	print_Stack_Multi(st);
	print_Stack_Multi(st);

	auto a = st._Get_container();
	auto a2 = st2._Get_container();

	print_Container(a);
	print_Stack(st);
	print_Stack(st);



	return 0;
}
