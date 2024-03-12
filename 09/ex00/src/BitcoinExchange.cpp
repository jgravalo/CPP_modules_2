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

std::string		BitcoinExchange::makeDate()
{
	std::string	res = "";
	std::stringstream	ss;

	for (size_t i = 0; i < 3; i++)
	{
		if (i != 0)
			res += "-";
		if (this->time[i] < 10)
			ss << 0;
		ss << this->time[i];
		res += ss.str();
		ss.str("");
	}
	return (res);
}

float	BitcoinExchange::operator[](std::string date)
{
	float res = 0;
	std::string	str[3] = {date.substr(0, 4), date.substr(5, 2), date.substr(8, 2)};
	
	initTime();
	for (size_t i = 0; i < 3; i++)
		this->time[i] = atoi(str[i].c_str());
	for (size_t i = 0; i < 3; i++)
	{
		date = makeDate();
		if (btc[date] != 0)
		{
			res = btc[date];
			break ;
		}
		decreaseTime();
	}
	return (res);
}

BitcoinExchange::~BitcoinExchange()
{
}

void	BitcoinExchange::initTime()
{
	int n[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	for (size_t i = 0; i < 12; i++)
		this->months[i] = n[i];
	for (size_t i = 0; i < 3; i++)
		this->time[i] = 0;
}

void	BitcoinExchange::decreaseTime()
{
	this->time[2]--;
	if (this->time[2] == 0)
	{
		this->time[1]--;
		this->time[2] = this->months[this->time[1]];
	}
}

void		BitcoinExchange::parse_line(std::string line)
{
	std::string		date;
	float			value;
	float			res = 0;

	date = parse_date(line.substr(0, line.find('|') - 1));
	value = parse_value(line.substr(line.find('|') + 2, line.length()));
	if (value < 0)
		this->error(3);
	else if (value > 1000)
		this->error(4);
	res = operator[](date) * value;
	std::cout << date << " => " << value << " = " << res << std::endl;
}

std::string		BitcoinExchange::parse_date(std::string date)
{
	if (date.length() != 10)
		this->error(5);
	std::string	str[3] = {date.substr(0, 4), date.substr(5, 2), date.substr(8, 2)};
	
	for (int i = 0; i < 3; i++)
		for (int j = 0; str[i][j]; j++)
			if (!std::isdigit(str[i][j]))
				this->error(5);
	if (atof(str[0].c_str()) < 2008 || atof(str[0].c_str()) > 2022)
		this->error(5);
	if (atof(str[1].c_str()) < 1 || atof(str[1].c_str()) > 12)
		this->error(5);
	if (atof(str[2].c_str()) < 1 || atof(str[2].c_str()) > 31)
		this->error(5);
	if (date[4] != '-' || date[7] != '-')
		this->error(5);
	return (date);
}

float			BitcoinExchange::parse_value(std::string value)
{
	float	n = 0;
	int		point = 0;

	for (size_t i = 0; value[i]; i++)
		if (!std::isdigit(value[i]))
		{
			if (value[i] == '.' && point == 0)
				point = 1;
			else
				this->error(3);
		}
	n = atof(value.c_str());

	return (n);
}

void	BitcoinExchange::create_map()
{
	std::ifstream	db;
	std::string		line;
	std::string		date;
	float			value;

	db.open("data.csv");
	if (!db.is_open())
		this->error(2);
	std::getline(db, line);
	while (std::getline(db, line))
    {
		date = parse_date(line.substr(0, line.find(',')));
		value = parse_value(line.substr(line.find(',') + 1, line.length()));
		this->btc[date] = value;
    }
}

void	BitcoinExchange::error(int n)
{
	switch (n)
	{
		case 1:
			std::cerr << "Error: could not open file." << std::endl;
			exit(1);
		case 2:
			std::cerr << "Error: could not open database." << std::endl;
			exit(1);
		case 3:
			throw std::out_of_range("Error: not a positive number.");
		case 4:
			throw std::out_of_range("Error: too large a number.");
		case 5:
			std::string err = "Error: bad input => ";
			err += "2001-42-42";
			throw std::out_of_range(err);
	}
}

void	BitcoinExchange::main(char *argv)
{
	std::ifstream	input;

	input.open(argv);
	if (!input.is_open())
		error(1);
	try
	{
		create_map();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::string	buffer;
	std::getline(input, buffer);
	while (std::getline(input, buffer))
	{
		try
		{
			parse_line(buffer);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
}
