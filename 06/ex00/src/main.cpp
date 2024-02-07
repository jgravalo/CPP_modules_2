#include<ScalarConverter.hpp>

int main(int argc, char **argv)
{

	if (argc != 2)
		return  1;
	std::string	str = argv[1];

	double d = 200000.02;
	std::cout << d << std::endl;
	//std::cout << "atoi = " << atoi(argv[1]) << std::endl;
	//std::cout << "atof = " << atof(argv[1]) << std::endl;
	ScalarConverter::convert(str);

	return 0;
}
