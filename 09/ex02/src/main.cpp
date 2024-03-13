#include<PmergeMe.hpp>

int main(int argc, char **argv)
{
	if (argc < 2)
		PmergeMe::error();
	PmergeMe	p(argv);
	return (0);
}