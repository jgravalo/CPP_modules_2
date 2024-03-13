#include<PmergeMe.hpp>

PmergeMe::PmergeMe()
{
}

PmergeMe::PmergeMe(char **_argv) : argv(_argv)
{
	parse_argv();
}

PmergeMe::~PmergeMe()
{
}

void	PmergeMe::error()
{
	std::cerr << "Error" << std::endl;
	exit(1);
}

void	PmergeMe::ft_split(const std::string &s, char c)
{
	std::string buffer;
	std::istringstream fd(s);

	while (std::getline(fd, buffer, c))
	{
		for (size_t j = 0; buffer[j]; j++)
			if (!std::isdigit(buffer[j]))
				error();
		this->vec.push_back(atoi(buffer.c_str()));
		this->dque.push_back(atoi(buffer.c_str()));
	}
}

void	PmergeMe::parse_argv()
{
	int space;
	int n;

	for (size_t i = 1; argv[i]; i++)
	{
		space = 0;
		for (size_t j = 0; argv[i][j]; j++)
		{
			if (argv[i][j] == ' ')
			{
				space = 1;
				ft_split(argv[i], ' ');
				break ;
			}
			else if (!std::isdigit(argv[i][j]))
				error();
		}
		if (space == 0)
		{
			n = atoi(argv[i]);
			vec.push_back(n);
			dque.push_back(n);
		}
	}
	/* 
	for (size_t i = 0; i < vec.size(); i++)
		std::cout << this->vec[i] << " ";
	std::cout << std::endl;
	for (size_t i = 0; i < dque.size(); i++)
		std::cout << this->dque[i] << " ";
	std::cout << std::endl;
	*/
}
