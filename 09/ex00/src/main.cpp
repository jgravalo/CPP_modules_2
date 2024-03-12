#include<BitcoinExchange.hpp>

int main(int argc, char **argv)
{
	if (argc != 2)
		BitcoinExchange::error(1, "");
	//BitcoinExchange btc(argv[1]);
	BitcoinExchange btc;

	(void)argv;
	//BitcoinExchange::parse_date("2010-07-32");
	//BitcoinExchange::parse_value("1f00.00.1");

	btc.main(argv[1]);
}