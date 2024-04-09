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
		void		print();
		void		Ford_Johnson();
		/* void		Push_Swap();
		template <typename A, typename B>
			void		push(A& a, B& b);
		template <typename T>
			void		rotate(T& t);
		template <typename T>
			void		rrotate(T& t); */
		void		ft_split(const std::string &s, char c);
		static void	error();
		template <typename T>
			void		sort(T &tmp);

};

#endif
