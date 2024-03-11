#include<BitcoinExchange.hpp>

int main(int argc, char **argv)
{
	if (argc != 2)
		BitcoinExchange::error(1);
	(void)argv;
	//BitcoinExchange::parse_date("2010-07-32");
	BitcoinExchange::parse_value("436.34");
	
}