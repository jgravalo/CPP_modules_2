#include<RPN.hpp>

RPN::RPN()
{
}

RPN::RPN(std::string argv)
{
	loop(argv);
}

RPN::~RPN()
{
}

std::list<std::string>	RPN::ft_split(const std::string &s, char c)
{
	std::list<std::string> tokens;
	std::string buffer;
	std::istringstream fd(s);

	while (std::getline(fd, buffer, c))
		tokens.push_back(buffer);
	return tokens;
}

void	RPN::error()
{
	std::cerr << "Error" << std::endl;
	exit(1);
}

void	RPN::operar()
{
	int res = 0;

	switch (op)
	{
		case '+':
			res = n1 + n2;
			break;
		case '-':
			res = n1 - n2;
			break;
		case '*':
			res = n1 * n2;
			break;
		case '/':
			res = n1 / n2;
			break;
	}
	numbers.push_back(res);
}

int		RPN::loop(std::string argv)
{
	if (argv == "")
		this->error();
	lst = ft_split(argv, ' ');
	std::list<std::string>::iterator it;
	std::string tmp;
	unsigned long i = 0;

    for (it = lst.begin(); it != lst.end(); ++it)
	{
		tmp = *it;
		if (tmp == "+" || tmp == "-" ||
			tmp == "*" || tmp == "/")
		{
			if (this->numbers.size() < 2)
				error();
			this->n2 = numbers.back();
			this->numbers.pop_back();
			this->n1 = numbers.back();
			this->numbers.pop_back();
			this->op = tmp[0];
			this->operar();
		}
		else
		{
			if (i /* + 1 */ == this->lst.size())
					this->error();
			for (size_t j = 0; j < tmp.length(); j++)
				if (!std::isdigit(tmp[j]))
					this->error();
			this->numbers.push_back(atoi(tmp.c_str()));
		}
		i++;
	}
	if (this->numbers.size() != 1)
		this->error();
	std::cout << numbers.back() << std::endl;
	return (0);
}