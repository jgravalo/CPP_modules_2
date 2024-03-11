#ifndef BTC_HPP
#define BTC_HPP

#include<iostream>
#include<fstream>
#include<map>
#include<cctype>

class BitcoinExchange
{
	private:
		std::map<std::string, float>	btc;
	public:
		BitcoinExchange();
		//BitcoinExchange(file);
		BitcoinExchange(class BitcoinExchange& Copy);
		BitcoinExchange&	operator=(class BitcoinExchange& Copy);
		float	operator[](std::string date);
		~BitcoinExchange();
		std::string		parse_date(std::string date);
		static float			parse_value(std::string value);
		void			create_map();
		static void				error(int n);
		std::string		parse_line(std::string line);
};

#endif
