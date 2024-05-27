#ifndef PMERGME_HPP
#define PMERGME_HPP

#include<iostream>
#include<sstream>
#include<vector>
#include<deque>
#include<ctime>

class PmergeMe
{
	private:
		char				**argv;
		std::deque<int>		dque;
		std::vector<int>	vec;
		std::clock_t		vecTime[ 2 ];
		std::clock_t		dqueTime[ 2 ];
		double				vec_secs;
		double				dque_secs;
		int					vecSize;
		int					dqueSize;
	public:
		PmergeMe();
		PmergeMe(char **argv);
		~PmergeMe();
		void		parse_argv();
		void		print();
		void		printTime();
		void		Ford_Johnson();
		void		ft_split(const std::string &s, char c);
		static void	error();
		void		isuint(std::string str);
		template <typename T>
			void		Sort_Merge(T &tmp);

		/* void		Push_Swap();
		template <typename A, typename B>
			void		push(A& a, B& b);
		template <typename T>
			void		rotate(T& t);
		template <typename T>
			void		rrotate(T& t); */
};

#endif
