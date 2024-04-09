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
		Span(unsigned int N);
		~Span();
		void				addNumber(int n);
		int					shortestSpan();
		int					longestSpan();
		int					getSize();
		int					getStored();
		std::vector<int>	getVec();
		void					print();
};

#endif
