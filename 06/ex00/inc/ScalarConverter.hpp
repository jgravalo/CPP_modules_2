#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include<iostream>
#include<iomanip>

class ScalarConverter
{
	private:
		/* data */
		static char		recognize(std::string str);
		static void		c_convert(std::string str);
		static void		i_convert(std::string str);
		static void		f_convert(std::string str);
		static void		d_convert(std::string str);
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