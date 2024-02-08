#include<Array.hpp>
#include<Array.tpp>
#include<iostream>

void testInt()
{
	int			tmp[6] = {4, INT_MIN, 1, INT_MAX, 9};
	Array<int>	arr(6);

	std::cout << "\nChar:" << std::endl;
	for (size_t i = 0; i < 6; i++)
		arr[i] = tmp[i];
	for (size_t i = 0; i < 6; i++)
		std::cout << arr[i] << std::endl;
}

void testChar()
{
	char		tmp[6] = "he\ny0";
	Array<char>	arr(6);

	std::cout << "\nInt:" << std::endl;
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
	testInt();
	testChar();
	testFloat();
	//testString();
	return 0;
}