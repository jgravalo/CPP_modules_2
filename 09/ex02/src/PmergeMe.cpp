#include<PmergeMe.hpp>

PmergeMe::PmergeMe()
{
}

PmergeMe::PmergeMe(char **_argv) : argv(_argv)
{
	parse_argv();
	Ford_Johnson();
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

void	PmergeMe::print()
{
	for (size_t i = 0; i < vec.size(); i++)
		std::cout << this->vec[i] << " ";
	std::cout << std::endl;
}
void	PmergeMe::printTime()
{
	std::cout << "Time to process a range of " << this->vecSize << " elements with std::vector : " << this->vec_secs << " us" << std::endl;
	std::cout << "Time to process a range of " << this->dqueSize << " elements with std::deque : " << this->dque_secs << " us" << std::endl;
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
	this->dqueSize = dque.size();
	this->vecSize = vec.size();
}

template <typename T>
void	PmergeMe::Sort_Merge(T &tmp)
{
	T					res;
	std::vector<int>	left;
	std::vector<int>	right;
	unsigned long		i = 0;
	unsigned long		j = 0;

	for (; i < (tmp.size() / 2); i++)
		left.push_back(tmp[i]);
	for (; i < tmp.size(); i++)
		right.push_back(tmp[i]);

	if (left.size() > 1)
		this->Sort_Merge(left);
	if (right.size() > 1)
		this->Sort_Merge(right);
	i = 0;
	while (res.size() < left.size() + right.size())
	{
		if ((left[i] <= right[j] && i < left.size()) || j >= right.size())
		{
			res.push_back(left[i]);
			i++;
		}
		else
		{
			res.push_back(right[j]);
			j++;
		}
	}
	tmp = res;
}

void	PmergeMe::Ford_Johnson()
{
	std::cout << "Before: ";
	print();
	this->vecTime[0] = clock();
	this->Sort_Merge(this->vec);
	this->vecTime[1] = clock();
	this->vec_secs = double(this->vecTime[1] - this->vecTime[0]);

	this->dqueTime[0] = clock();
	this->Sort_Merge(this->dque);
	this->dqueTime[1] = clock();
	this->dque_secs = double(this->dqueTime[1] - this->dqueTime[0]);
	std::cout << "After: ";
	print();
	printTime();
}



/* 
template <typename A, typename B>
void	PmergeMe::push(A& a, B& b)
{
	b.insert(b.begin(), a[0]);
	a.erase(a.begin());
}

template <typename T>
void	PmergeMe::rotate(T& t)
{
	int tmp = t[0];
	t.erase(t.begin());
	t.push_back(tmp);
}

template <typename T>
void	PmergeMe::rrotate(T& t)
{
	int tmp = t.back();
	t.pop_back();
	t.insert(t.begin(), tmp);
}

void	PmergeMe::Push_Swap()
{
 	std::vector<int>	vec2;
	int					in = 100;
	int					i = 0;

	while (!vec.empty())
	{
		if (vec[1] > i)
		rotate(vec);
	} 
}
*/
