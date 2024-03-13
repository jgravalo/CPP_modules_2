#ifndef PMERGME_HPP
#define PMERGME_HPP

#include<iostream>
#include<sstream>
#include<vector>
#include<deque>

class PmergeMe
{
	private:
		char				**argv;
		std::deque<int>		dque;
		std::vector<int>	vec;
	public:
		PmergeMe();
		PmergeMe(char **argv);
		~PmergeMe();
		void		parse_argv();
		void		ft_split(const std::string &s, char c);
		static void	error();
};

#endif
