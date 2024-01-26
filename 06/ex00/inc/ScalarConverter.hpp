#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include<iostream>
#include<iomanip>

class ScalarConverter
{
	private:
		/* data */
		static char		isnum(std::string str);
		static char		ischr(std::string str);
		static char		recognize(std::string str);
		static void		c_convert(std::string str, char type);
		static void		i_convert(std::string str, char type);
		static void		df_convert(std::string str, char type, char target);
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