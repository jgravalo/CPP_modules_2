#ifndef BTC_HPP
#define BTC_HPP

#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<cctype>
#include<map>

class BitcoinExchange
{
	private:
		std::map<std::string, float>	btc;
		int								time[3];
		int								months[12];// = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	public:
		BitcoinExchange();
		BitcoinExchange(std::string file);
		BitcoinExchange(class BitcoinExchange& Copy);
		BitcoinExchange&	operator=(class BitcoinExchange& Copy);
		float				operator[](std::string date);
		~BitcoinExchange();
		std::string			parse_date(std::string date);
		std::string			makeDate();
		int					isDate(int year, int month, int day);
		float				parse_value(std::string value);
		void				main(char *argv);
		void				create_map();
		void				parse_line(std::string line);
		static void			error(int n, std::string date);
		void				decreaseTime();
		void				initTime();
};

#endif
