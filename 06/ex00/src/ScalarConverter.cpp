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

void	ScalarConverter::c_convert(std::string str, char type)
{
	char c = 0;
	if (type == 'i')
		c = atoi(str.c_str());
	else if (type == 'c')
		c = str[0];
	else if (type == 'f' || type == 'd')
	{
		std::cout << "impossible";
		return ;
	}
	if (c < 32 || c > 126)
	{
		std::cout << "non printable";
		return ;
	}
	std::cout << c;
}

void	ScalarConverter::i_convert(std::string str, char type)
{
	int n = 0;
	if (type == 'i')
		n = atoi(str.c_str());
	else if (type == 'f' || type == 'd')
	{
		int len = str.find('.');
		n = atol(str.substr(0, len).c_str());
	}
	else if (type == 'c')
		n = str[0];
	std::cout << n;// << std::endl;
}

void	ScalarConverter::df_convert(std::string str, char type, char target)
{
	(void)type;
	unsigned long prec = 0;
	if (target == 'f')
		prec = 7;
	else if (target == 'd')
		prec = 15;

	double	res = 0;
	if (type == 'd' || type == 'f')
	{
		int p = str.find('.');
		std::string snum = str.substr(0, p);
		long num = atol(snum.c_str());

		p++;
		int len = str.length();
		std::string	sdec = str.substr(p, len - p);
		float dec = 0;

		if (p > 0)
			dec = atol(sdec.c_str());
		//std::cout << num << " + " << dec << " = ";
		if (type == 'd')
			res = num + dec / pow(10, sdec.length());
		else if (type == 'f')
			res = num + dec / pow(10, sdec.length() - 1);
		if (sdec.length() > prec)
			std::cout << std::setprecision(prec);
		else
			std::cout << std::setprecision(sdec.length() + 1);
		std::cout << res;// << std::endl;
	}
	else if (type == 'c' || type == 'i')
	{
		if (type == 'c')
			res = str[0];
		if (type == 'i')
			res = atoi(str.c_str());
		std::cout << res;// << std::endl;
		std::cout << ".0";// << std::endl;
	}
	if (target == 'f')
		std::cout << "f";// << std::endl;
	//return (res);
}
/*
void	ScalarConverter::d_convert(std::string str, char type)
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
}*/

char	ScalarConverter::isnum(std::string str)
{
	int i = 0;
	char c = 0;
	
	if (!(str[i] >= '0' && str[i]<= '9'))
		return 0;
	while (str[i] >= '0' && str[i]<= '9')
		i++;
	if (!str[i])
		return ('i');
	else if (str[i] != '.')
		return 0;
	i++;
	if (!(str[i] >= '0' && str[i]<= '9'))
		return 0;
	while (str[i] >= '0' && str[i]<= '9')
		i++;
	if (!str[i])
		return ('d');
	if (str[i] == 'e')
	{
		i++;
		if (str[i] == '+' && str[i] == '-')
			i++;
		if (!(str[i] >= '0' && str[i]<= '9'))
			return 0;
		while (str[i] >= '0' && str[i]<= '9')
			i++;
	}
	if (!str[i])
		return ('d');
	else if (str[i] == 'f' && !str[i + 1])
		return ('f');
	return (c);
}

char	ScalarConverter::ischr(std::string str)
{
	int len = str.length();
	if (len == 1)
		return ('c');
	if (len > 1)
		return ('s');
	return (0);
}

char	ScalarConverter::recognize(std::string str)
{
	char c;
	c = isnum(str);
	if (c)
		return (c);
	c = ischr(str);
	if (c)
		return (c);
	return (0);
}

std::string	ScalarConverter::roundstr(std::string str)
{
	char c = recognize(str);
	int n = str.find('.');
	int i = 0;
	if (c != 'd' && c != 'f')
		return (str);
	for (i = n + 1; str[i] == '0'; i++)
		;
	if (!str[i] || (str[i] == 'f' && !str[i + 1])
		|| (str[i] == 'e'))
		str = str.substr(0, n);
	return (str);
}

void	ScalarConverter::convert(std::string str)
{
	str = roundstr(str);
	char c = recognize(str);
	std::cout << "c is a " << recognize(str) << std::endl;

	std::cout << "char: ";
	c_convert(str, c);
	std::cout << std::endl;

	std::cout << "int: ";
	i_convert(str, c);
	std::cout << std::endl;

	std::cout << "float: ";
	df_convert(str, c, 'f');
	std::cout << std::endl;

	std::cout << "double: ";
	df_convert(str, c, 'd');
	std::cout << std::endl;
}