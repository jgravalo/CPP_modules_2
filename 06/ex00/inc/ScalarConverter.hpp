#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include<iostream>
#include<iomanip>
#include<cstdlib>

class ScalarConverter
{
	private:
		/* data */
		static std::string	roundstr(std::string str);
		static char			isnum(std::string str);
		static char			ischr(std::string str);
		static int			isdec(std::string str, char type);
		static char			recognize(std::string str);
/* 		static void			c_convert(std::string str, char type);
		static void			i_convert(std::string str, char type);
		static void			df_convert(std::string str, char type, char target); */
		static void			c_convert(double i, double dec);
		static void			i_convert(double d, double dec);
		static void			f_convert(double d, double dec);
		static void			d_convert(double d, double dec);
		//static double	atod(std::string str);
	public:
		ScalarConverter();
		ScalarConverter(class ScalarConverter& Copy);
		ScalarConverter&	operator=(class ScalarConverter& Copy);
		~ScalarConverter();
		static void		convert(std::string str);
		virtual void	f() = 0;
};

#endif