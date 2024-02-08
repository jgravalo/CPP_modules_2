#ifndef ARRAY_HPP
#define ARRAY_HPP

#include<iostream>

template <class T>
class Array
{
	private:
		T				*arr;
		unsigned int	_size;
	public:
		Array();
		Array(unsigned int n);
		Array(class Array& Copy);
		Array&	operator=(class Array& Copy);
		~Array();
		T*	clone();
		T&	operator[](int n);
		int	size();

};

#endif
