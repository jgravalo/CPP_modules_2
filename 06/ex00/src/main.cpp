#include<ScalarConverter.hpp>
//#include<iostream>

int main(int argc, char **argv)
{

	if (argc != 2)
		return  1;
	std::string	str = argv[1];

	//char c = 'i';
	//int n = 5;
	//float f = 3.40282349e+38F;
	//double f = 1.79769313486231571e+308;
	//double f = 2.2507385850720138e+308;
	//std::cout << typeid(f).name() << std::endl;
	//std::cout << std::setprecision(15);
	//std::cout << f << std::endl;
	std::cout << str.find('+') << std::endl;
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
