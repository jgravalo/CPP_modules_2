#include<BitcoinExchange.hpp>

int main(int argc, char **argv)
{
	if (argc != 2)
		BitcoinExchange::error(1, "");
	BitcoinExchange btc;

	(void)argv;

	btc.main(argv[1]);
}