#include<Span.hpp>

Span::Span(unsigned int N)
{
	size = N;
	stored = 0;
}
/* 
Span::Span()s
{
	size = 0;
}

Span::Span(class Span& Copy)
{
	//vec = Copy.vec;
	size = Copy.getSize();
}

Span&	Span::operator=(class Span& Copy)
{
	//vec = Copy.vec;
	size = Copy.getSize();
	return (*this);
}
*/
Span::~Span()
{
}

void	Span::addNumber(int n)
{
	if (stored >= size)
		throw std::out_of_range("the span is full");
	vec.push_back(n);
	this->stored++;
}

int		Span::getSize()
{
	return (size);
}

int		Span::longestSpan()
{
	if (stored == 0)
		throw std::out_of_range("the span is empty");
	int min = vec[0];
	int max = vec[0];

	for (size_t i = 0; vec[i]; i++)
	{
		if (vec[i] < min)
			min = vec[i];
		if (vec[i] > max)
			max = vec[i];
	}
	return (max - min);
}

int		Span::shortestSpan()
{
	int min = longestSpan();

	for (size_t i = 0; vec[i]; i++)
	{
		for (size_t j = 0; vec[j]; j++)
		{
			if (i != j && abs(vec[i] - vec[j]) < min)
				min = abs(vec[i] - vec[j]);
		}
	}
	return (min);
}