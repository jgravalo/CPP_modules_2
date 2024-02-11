#ifndef SPAN_HPP
#define SPAN_HPP

#include<iostream>
#include<vector>

class Span
{
	private:
		std::vector<int>	vec;
		int					stored;
		int					size;
	public:
		//Span();
		Span(unsigned int N);
		//Span(class Span& Copy);
		//Span&	operator=(class Span& Copy);
		~Span();
		void	addNumber(int n);
		int		shortestSpan();
		int		longestSpan();
		int		getSize();
};

#endif
