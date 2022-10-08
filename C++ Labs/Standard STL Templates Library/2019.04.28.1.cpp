#include <iostream>
#include <forward_list>

using namespace std;

int main()
{
	setlocale(LC_ALL, "RUS");

	forward_list<int> fl = { 5,7,8,9 };

	fl.push_front(1);
	fl.push_front(5);

	for (const auto &itfl : fl)
	{
		cout << itfl << " ";
	}

	cout << endl << endl;

	/////////////////////////////////////////////////////////////////////////
	forward_list<int> fl2 = { 1,2,3,4,5,6 };
	forward_list<int>::iterator itfl2 = fl2.before_begin();

	fl2.insert_after(itfl2, 10);

	for (const auto& i : fl2)
	{
		cout << i << " ";
	}


	return 0;
}