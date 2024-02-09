#include<easyfind.hpp>

int main()
{
	int	n[] = {5, 7, 8, 1, INT_MAX};
	//std::cout << easyfind(n, 8) << std::endl;

	std::vector< int >	vec;
	std::list< int >	lst;
	std::deque< int >	que;

	for (size_t i = 0; n[i]; i++)
	{
		vec.push_back(n[i]);
		lst.push_back(n[i]);
		que.push_back(n[i]);
	}
	std::cout << easyfind(vec, 8) << std::endl;
	std::cout << easyfind(lst, 8) << std::endl;
	std::cout << easyfind(que, 8) << std::endl;
	return (0);
}