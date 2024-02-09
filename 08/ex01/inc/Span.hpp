#ifndef SPAN_HPP
#define SPAN_HPP

#include<iostream>

class Span
{
private:
	/* data */
public:
	Span();

	Span(class Span& Copy);
	Span	operator=(class Span& Copy);
	~Span();
	void	shortestSpan();
	void	longestSpan();
};

#endif

Span::Span()
{
}

Span::~Span()
{
}
