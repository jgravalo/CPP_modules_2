#include<ScalarConverter.hpp>

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(class ScalarConverter& Copy)
{
	(void)Copy;
}

ScalarConverter&	ScalarConverter::operator=(class ScalarConverter& Copy)
{
	(void)Copy;
	return(*this);
}

ScalarConverter::~ScalarConverter()
{
}

void	ScalarConverter::c_convert(std::string str)
{
	char n = atoi(str.c_str());
	std::cout << n;// << std::endl;
}

void	ScalarConverter::i_convert(std::string str)
{
	int n = atoi(str.c_str());
	std::cout << n;// << std::endl;
}

void	ScalarConverter::f_convert(std::string str)
{
	int n = str.find('.');
	//	std::cout << n << " ";
	std::string snum = str.substr(0, n);
	long num = atol(snum.c_str());
	n++;
	int len = str.length();
	std::string	sdec = str.substr(n, len - n);
	float dec = 0;
	if (n > 0)
		dec = atol(sdec.c_str());		
	std::cout << num << " + " << dec << " = ";
	float res = num + dec / pow(10, sdec.length());
	if (sdec.length() > 7)
		std::cout << std::setprecision(7);
	else
		std::cout << std::setprecision(sdec.length() + 1);
	std::cout << res;// << std::endl;
	//std::cout << ".0";// << std::endl;
	//std::cout << "f";// << std::endl;
	//return (res);
}

void	ScalarConverter::d_convert(std::string str)
{
	int n = str.find('.');
	std::string snum = str.substr(0, n);
	long num = atol(snum.c_str());
	n++;
	int len = str.length();
	std::string	sdec = str.substr(n, len - n);

	double dec = 0;
	if (n > 0)
		dec = atol(sdec.c_str());
	std::cout << num << " + " << dec << " = ";
	double res = num + dec / pow(10, sdec.length());
	if (sdec.length() > 15)
		std::cout << std::setprecision(15);
	else
		std::cout << std::setprecision(sdec.length() + 1);
	std::cout << res;// << std::endl;
	//std::cout << ".0";// << std::endl;
	//return (res);
}

char	ScalarConverter::recognize(std::string str)
{
	char c = 0;
	for (size_t i = 0; i < str.length() ; i++)
	{
		if (str[i] >= '0' && str[i]<= '9')
		{
			for (size_t i = 0; str[i] >= '0' && str[i]<= '9'; i++)
			{
				/* code */
			}
		}
		else
		{
			
		}
	}
	return (c);
}

void	ScalarConverter::convert(std::string str)
{
	std::cout << str << std::endl;

	/*std::cout << "char: " << "<";
	c_convert(str);
	std::cout << ">" << std::endl;
	
	std::cout << "int: " << "<";
	i_convert(str);
	std::cout << ">" << std::endl;

	std::cout << "float: " << "<";
	f_convert(str);
	std::cout << ">" << std::endl;

	std::cout << "double: " << "<";
	d_convert(str);
	std::cout << ">" << std::endl; */
}
/* 
char	ScalarConverter::c_convert(std::string str)
{
	char c = atoi(str.c_str());
	if (n < 32 || n >= 127)
	{
		std::cout << "non printable";
		return (0);
	}
	std::cout << c << std::endl;
	return (c);
}

int		ScalarConverter::i_convert(int n)
{
	int n;
	return (n);
} */