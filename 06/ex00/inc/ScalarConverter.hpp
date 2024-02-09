#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include<iostream>
#include<iomanip>
#include<cstdlib>

class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(class ScalarConverter& Copy);
		ScalarConverter&	operator=(class ScalarConverter& Copy);
		virtual ~ScalarConverter();
		static std::string	roundstr(std::string str);
		static char			isnum(std::string str);
		static char			ischr(std::string str);
		static char			isnon(std::string str);
		static int			isdec(std::string str, char type);
		static char			recognize(std::string str);
		static void			c_convert(double i, double dec, std::string str);
		static void			i_convert(double d, double dec, std::string str);
		static void			f_convert(double d, double dec, std::string str);
		static void			d_convert(double d, double dec, std::string str);
	public:
		static int		convert(std::string str);
		virtual void	f() = 0;
};

#endif