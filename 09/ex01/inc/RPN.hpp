#ifndef RPN_HPP
#define RPN_HPP

#include<iostream>
#include<sstream>
#include<vector>

class RPN
{
	private:
		std::vector<int>			numbers;
		std::vector<std::string>	vec;
		int							n1;
		int							n2;
		char						op;
	public:
		RPN();
		RPN(std::string argv);
		~RPN();
		static void					error();
		void						isnum();
		void						isop();
		void						operar();
		std::vector<std::string>	ft_split(const std::string &s, char c);
		int							loop(std::string argv);
};

#endif
