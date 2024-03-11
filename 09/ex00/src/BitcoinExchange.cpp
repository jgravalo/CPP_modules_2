#include<BitcoinExchange.hpp>

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(class BitcoinExchange& Copy)
{
	(void)Copy;
}

BitcoinExchange&	BitcoinExchange::operator=(class BitcoinExchange& Copy)
{
	(void)Copy;
	return (*this);
}

BitcoinExchange::~BitcoinExchange()
{
}

void	BitcoinExchange::error(int n)
{
	switch (n)
	{
		case 1:
			std::cerr << "Error: could not open file." << std::endl;
			break;
		case 2:
			std::cerr << "Error: could not open database." << std::endl;
			break;
		case 3:
			std::cerr << "Error: not a positive number." << std::endl;
			break;
		case 4:
			std::cerr << "Error: too large a number." << std::endl;
			break;
		case 5:
			std::cerr << "Error: bad input => " << "2001-42-42" << std::endl;
			break;
		
		default:
			break;
	}
	exit(1);
}

std::string		BitcoinExchange::parse_line(std::string line)
{
	std::string		date;
	float			value;
	date = parse_date(line.substr(0, line.find(',')));
	value = parse_value(line.substr(line.find(',') + 1, line.length()));

}

std::string		BitcoinExchange::parse_date(std::string date)
{
	if (date.length() != 10)
		/* this-> */error(5);
	std::string	str[3] = {date.substr(0, 4), date.substr(5, 2), date.substr(8, 2)};
	
	for (int i = 0; i < 3; i++)
		std::cout << str[i] << std::endl;
	for (int i = 0; i < 3; i++)
		for (int j = 0; str[i][j]; j++)
			if (!std::isdigit(str[i][j]))
				/* this-> */error(5);
	if (atof(str[0].c_str()) < 2008 || atof(str[0].c_str()) > 2022)
		/* this-> */error(5);
	if (atof(str[1].c_str()) < 1 || atof(str[1].c_str()) > 12)
		/* this-> */error(5);
	if (atof(str[2].c_str()) < 1 || atof(str[2].c_str()) > 31)
		/* this-> */error(5);
	if (date[4] != '-' || date[7] != '-')
		/* this-> */error(5);
	return (date);
}

float			BitcoinExchange::parse_value(std::string value)
{
	float	n = 0;
	int		point = 0;
	for (size_t i = 0; value[i]; i++)
		if (!std::isdigit(value[i]) || value[i] == '')
			this->error(3);
	n = atof(value.c_str());
	if (n < 0)
		this->error(3);
	else if (n > 1000)
		this->error(4);
	return (n);
}

void	BitcoinExchange::create_map()
{
	std::ifstream	db;
	std::string		line;
	std::string		date;
	float			value;

	db.open("data.csv");
	if (db.is_open())
		this->error(2);
	while (std::getline(db, line))
    {
		date = parse_date(line.substr(0, line.find(',')));
		value = parse_value(line.substr(line.find(',') + 1, line.length()));
		std::cout << date << ", " << value << std::endl;
		this->btc[date] = value;
    }
}