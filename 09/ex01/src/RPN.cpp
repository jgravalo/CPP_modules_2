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

std::vector<std::string>	RPN::ft_split(const std::string &s, char c)
{
	std::vector<std::string> tokens;
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
	vec = ft_split(argv, ' ');
	for (size_t i = 0; i < vec.size(); i++)
	{
		if (vec[i] == "+" || vec[i] == "-" ||
			vec[i] == "*" || vec[i] == "/")
		{
			if (numbers.size() < 2)
				error();
			n2 = numbers.back();
			numbers.pop_back();
			n1 = numbers.back();
			numbers.pop_back();
			op = vec[i][0];
			operar();
		}
		else
		{
			for (size_t j = 0; j < vec[i].length(); j++)
				if (!std::isdigit(vec[i][j]))
					error();
			numbers.push_back(atoi(vec[i].c_str()));
		}
	}
	std::cout << numbers.back() << std::endl;
	return (0);
}