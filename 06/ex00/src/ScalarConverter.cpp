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

char	ScalarConverter::isnum(std::string str)
{
	int i = 0;

	if (str[i] == '+' || str[i] == '-')
			i++;
	if (!(str[i] >= '0' && str[i]<= '9'))
		return 0;
	while (str[i] >= '0' && str[i]<= '9')
		i++;
	if (!str[i])
		return ('i');
	else if (str[i] == 'f')
		return (0);
	else if (str[i] == '.')
	{
		i++;
		if (!(str[i] >= '0' && str[i]<= '9'))
			return 0;
		while (str[i] >= '0' && str[i]<= '9')
			i++;
	}
	if (str[i] == 'e')
	{
		i++;
		if (str[i] == '+' || str[i] == '-')
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
	return (0);
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

char	ScalarConverter::isnon(std::string str)
{
	if (str == "nan" || str == "nanf")
		return ('n');
	if (str == "+inf" || str == "+inff")
		return ('+');
	if (str == "-inf" || str == "-inff")
		return ('-');
	return (0);
}

int		ScalarConverter::isdec(std::string str, char type)
{
	double	d = 0;
	if (type == 'c')
		d = (double)str[0];
	else
		d = atof(str.c_str());
	double	i = roundf(d);
	double dec = d - i;
	dec -= roundf(dec);
	if (dec != 0)
		return (1);
	return (0);
}

char	ScalarConverter::recognize(std::string str)
{
	char c;
	c = isnon(str);
	if (c)
		return (c);
	c = isnum(str);
	if (c)
		return (c);
	c = ischr(str);
	if (c)
		return (c);
	return (0);
}

void	ScalarConverter::c_convert(double i, double dec, std::string str)
{
	if (dec != 0 || isnon(str))
		std::cout << "impossible";
	else
	{
		char c = static_cast<char>(i);
		if (c < 32 || c > 126)
			std::cout << "Non displayable";
		else
			std::cout << "\'" << c << "\'";
	}
}

void	ScalarConverter::i_convert(double d, double dec, std::string str)
{
	if (dec != 0 || isnon(str))
		std::cout << "impossible";
	else if (d < -2147483648)
		std::cout << "-inf";
	else if (d > 2147483647)
		std::cout << "inf";
	else
	{
		int	n = static_cast<int>(d);
		std::cout << n;
	}
}

void	ScalarConverter::f_convert(double d, double dec, std::string str)
{
	if (dec != 0 && str.length() > 6 && abs(d) < 1000000)
		std::cout << std::setprecision(str.length());
	std::cout << d;
	if (dec == 0 && abs(d) < 1000000)
		std::cout << ".0";
	std::cout << "f";
}

void	ScalarConverter::d_convert(double d, double dec, std::string str)
{
	if (dec != 0 && str.length() > 6 && abs(d) < 1000000)
		std::cout << std::setprecision(str.length());
	std::cout << d;
	if (dec == 0 && abs(d) < 1000000)
		std::cout << ".0";
}

int		ScalarConverter::convert(std::string str)
{
	char c = recognize(str);
	if (c == 's' && !isnon(str))
	{
		std::cerr << "invalid argument" << std::endl;
		return (1);
	}
	double	d = 0;
	if (c == 'c')
		d = static_cast<double>(str[0]);
	else
		d = atof(str.c_str());
	double	i = roundf(d);
	double dec = d - i;
	dec -= roundf(dec);

	std::cout << "char: ";
	c_convert(i, dec, str);
	std::cout << std::endl;

	std::cout << "int: ";
	i_convert(d, dec, str);
	std::cout << std::endl;

	std::cout << "float: ";
	f_convert(d, dec, str);
	std::cout << std::endl;

	std::cout << "double: ";
	d_convert(d, dec, str);
	std::cout << std::endl;
	return (0);
}