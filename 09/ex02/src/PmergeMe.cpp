#include<PmergeMe.hpp>

PmergeMe::PmergeMe()
{
}

PmergeMe::PmergeMe(char **_argv) : argv(_argv)
{
	parse_argv();
/* 	print();
	rotate(vec);
	rotate(dque);
	print();
	rrotate(vec);
	rrotate(dque);
	print();
	push(vec, dque);
	print(); */
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
	for (size_t i = 0; i < dque.size(); i++)
		std::cout << this->dque[i] << " ";
	std::cout << std::endl;
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
template <typename T>
void	PmergeMe::sort(T &tmp)
{
	std::vector<int>	left;
	std::vector<int>	right;
	unsigned long		i = 0;
	//int					size = tmp.size();

	std::cout << "size = " << tmp.size() << std::endl;
	//std::cout << "medium size = " << tmp.size() / 2 << std::endl;
	for (; i < (tmp.size() / 2); i++)
	{
		//std::cout << tmp[i] << " ";
		left.push_back(tmp[i]);
	}
	//std::cout << " // ";
	for (; i < tmp.size(); i++)
	{
		//std::cout << tmp[i] << " ";
		right.push_back(tmp[i]);
	}
	//std::cout << "\n";

	if (left.size() > 1)
		this->sort(left);
	if (right.size() > 1)
		this->sort(right);

	for (i = 0; i < left.size(); i++)
		std::cout << left[i] << " ";
	std::cout << " // ";
	for (i = 0; i < right.size(); i++)
		std::cout << right[i] << " ";
	std::cout << std::endl;

	std::vector<int>	res;
	i = 0;
	unsigned long j = 0;
	while (res.size() < left.size() + right.size())
	{
		std::cout << "(" << left[i] << "," << right[j] << ")";
		if ((left[i] <= right[j] && i < left.size()) || j >= right.size())
		{
			std::cout << left[i] << " ";
			res.push_back(left[i]);
			i++;
		}
		else// if (left[i] > right[j] && j < right.size())
		{
			std::cout << right[i] << " ";
			res.push_back(right[j]);
			j++;
		}
	}
	std::cout << std::endl;
	for (i = 0; i < res.size(); i++)
		std::cout << res[i] << " ";
	std::cout << std::endl;
	tmp = res;
}

void	PmergeMe::Ford_Johnson()
{
	//std::clock_t		vecTime[ 2 ];
	//std::clock_t		dqueTime[ 2 ];
	this->sort(this->vec);
}

	/* 
	std::deque<int> q1(q.begin(), q.begin() + q.size() / 2);
	std::deque<int> q2(q.begin() + q.size() / 2, q.end());

		for (size_t i = 0; i < q1.size(); i++)
		std::cout << q1[i] << " ";
	std::cout << std::endl;
	for (size_t i = 0; i < q2.size(); i++)
		std::cout << q2[i] << " ";
	std::cout << std::endl; */
