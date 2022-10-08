#include <iostream>
#include <exception>

class myException : public std::exception
{
public:
	myException(const char *msg, int dataState) : std::exception(msg)
	{
		this->dataState = dataState;
	}

	int getDataState()
	{
		return dataState;
	}

private:
	int dataState;

};

void Foo(const int& value)
{
	if (value < 0)
	{
		throw std::exception("The value is less than 0");
	}

	if (value == 1)
	{
		throw myException("The value is 1", value);
	}

	std::cout << "Value = " << value << std::endl;
}

int main()
{

	try
	{
		Foo(1);
	}
	catch (myException & ex)
	{
		std::cout << "I caughted an exception! " << ex.what()<<std::endl;
		std::cout << "The state of data is " << ex.getDataState() << std::endl;
	}

	return 0;
}
