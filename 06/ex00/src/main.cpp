#include<ScalarConverter.hpp>

int main(int argc, char **argv)
{

	if (argc != 2)
		return  1;
	std::string	str = argv[1];

	//char c = 'i';
	//int n = 5;
	//float f = 0.5;
	//double d = 0.5;
	//std::cout << typeid(34.42e3f).name() << std::endl;
	ScalarConverter::convert(str);
/* 	int n = str.find('.');
	int len = str.length();
	std::string snum = str.substr(0, n);
	n++;
	//std::cout << "aqui" << std::endl;
	std::string	sdec = str.substr(n, len - n);
	long num = atol(snum.c_str());
	long dec = atol(sdec.c_str());
	double res = num + dec / pow(10, sdec.length());
	//std::cout << num << " + " << dec << " = ";
	std::cout << std::setprecision(sdec.length() + 1);
	std::cout << res << std::endl; */
	return 0;
}
