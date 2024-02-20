#include<iter.hpp>
#include<typeinfo>


template <typename T>
void	f(T &i)
{
	static int n = 0;
	std::cout << i << ", n = " << n << std::endl;
	n++;
}

void testInt()
{
	int len = 5;
	int a[] = {2, 4, 1, 6, 9};

	std::cout << "int:" << std::endl;
	for (int i = 0; i < len; i++)
	{
		std::cout << a[i] << std::endl;
	}
	std::cout << "f():" << std::endl;
	::iter(a, len, f);
}

void testChar()
{
	int len = 5;
	char a[] = "Hello";

	std::cout << "char:" << std::endl;
	for (int i = 0; i < len; i++)
	{
		std::cout << a[i] << std::endl;
	}
	std::cout << "f():" << std::endl;
	::iter(a, len, f);
}

void testFloat()
{
	int len = 5;
	float a[] = {2.5, 4.2, 1.3, 6.9, 9.7};

	std::cout << "float:" << std::endl;
	for (int i = 0; i < len; i++)
	{
		std::cout << a[i] << std::endl;
	}
	std::cout << "f():" << std::endl;
	::iter(a, len, f);
}

void testStr()
{
	int len = 5;
	std::string a[] = {"hola", "que tal?", "como estas?", "me entiendes?", "que te den"};

	std::cout << "string:" << std::endl;
	for (int i = 0; i < len; i++)
	{
		std::cout << a[i] << std::endl;
	}
	std::cout << "f():" << std::endl;
	::iter(a, len, f);
}

int main()
{
	testInt();
	testChar();
	testFloat();
	testStr();
	return 0;
}
