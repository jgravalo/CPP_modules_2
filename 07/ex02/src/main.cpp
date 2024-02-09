#include<Array.hpp>
#include<Array.tpp>
#include<iostream>

void testCopy()
{
	int			tmp[6] = {4, INT_MIN, 1, INT_MAX, 9};
	Array<int>	arr(6);

	std::cout << "\nCopy constructor:" << std::endl;
	Array<int>	arr2(arr);
	for (size_t i = 0; i < 6; i++)
		std::cout << arr[i] << " - " << arr2[i] << std::endl;

	std::cout << "\nChanges:" << std::endl;
	for (size_t i = 0; i < 6; i++)
		arr[i] = tmp[i];
	for (size_t i = 0; i < 6; i++)
		std::cout << arr[i] << " - " << arr2[i] << std::endl;

	std::cout << "\nCopy assigment operator:" << std::endl;
	arr2 = arr;
	for (size_t i = 0; i < 6; i++)
		std::cout << arr[i] << " - " << arr2[i] << std::endl;
}

void testNulls()
{
	Array<int>	i;
	Array<char>	c;

	std::cout << std::endl;
	std::cout << "Int:" << std::endl;
	std::cout << i[0] << std::endl;
		std::cout << "aqui" << std::endl;
	std::cout << "Char:" << std::endl;
	std::cout << c[0] << std::endl;
}

void testInvalid()
{
	try
	{
		int			tmp[6] = {4, INT_MIN, 1, INT_MAX, 9};
		Array<int>	arr(6);

		std::cout << "\nInt:" << std::endl;
		for (size_t i = 0; i < 6; i++)
			arr[i] = tmp[i];
		std::cout << arr[0] << std::endl;
		std::cout << arr[5] << std::endl;
		std::cout << arr[6] << std::endl;
		std::cout << arr[7] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

void testInt()
{
	int			tmp[6] = {4, INT_MIN, 1, INT_MAX, 9};
	Array<int>	arr(6);

	std::cout << "\nInt:" << std::endl;
	for (size_t i = 0; i < 6; i++)
		arr[i] = tmp[i];
	for (size_t i = 0; i < 6; i++)
		std::cout << arr[i] << std::endl;
}

void testChar()
{
	char		tmp[6] = "he\ny0";
	Array<char>	arr(6);

	std::cout << "\nChar:" << std::endl;
	for (size_t i = 0; i < 6; i++)
		arr[i] = tmp[i];
	for (size_t i = 0; i < 6; i++)
		std::cout << arr[i] << std::endl;
}

void testFloat()
{
	float			tmp[6] = {4.32, INT_MIN, 1, INT_MAX, 9.5};
	Array<float>	arr(6);

	std::cout << "\nFloat:" << std::endl;
	for (size_t i = 0; i < 6; i++)
		arr[i] = tmp[i];
	for (size_t i = 0; i < 6; i++)
		std::cout << arr[i] << std::endl;
}
/*
void testString()
{
	std::string			tmp[6] = {"hola", "que tal", "a ver si va", "INT_MAX", "9.5"};
	Array<std::string>	arr(6);

	std::cout << "\nString:" << std::endl;
	for (size_t i = 0; i < 6; i++)
		arr[i] = tmp[i];
	for (size_t i = 0; i < 6; i++)
		std::cout << arr[i] << std::endl;
}
*/

int main()
{
	int * a = new int();
	std::cout << *a << std::endl;
	testCopy();
	testNulls();
	testInvalid();
	testInt();
	testChar();
	testFloat();
	//testString();
	return 0;
}