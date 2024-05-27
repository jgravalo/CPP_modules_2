#ifndef RPN_HPP
#define RPN_HPP

#include<iostream>
#include<sstream>
#include<list>

class RPN
{
	private:
		std::list<int>			numbers;
		std::list<std::string>	lst;
		int						n1;
		int						n2;
		char					op;
	public:
		RPN();
		RPN(std::string argv);
		~RPN();
		static void				error();
		void					isnum();
		void					isop();
		void					operar();
		std::list<std::string>	ft_split(const std::string &s, char c);
		int						loop(std::string argv);
		void					isuint(std::string str);
};

#endif
