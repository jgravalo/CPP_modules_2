#ifndef ARRAY_HPP
#define ARRAY_HPP

#include<iostream>

template <typename T>
class Array
{
	private:
		T	*T;
	public:
		Array();
		Array(unsigned int n);
		Array(class Array& Copy);
		Array&	operator=(class Array& Copy);
		~Array();
		Array&	operator[](int n);
};

#endif

Array::Array()
{
}

Array::Array(unsigned int n)
{
	T = n;
}

Array::Array(class Array& Copy)
{
	(void)Copy;
}

Array&	Array::operator=(class Array& Copy)
{
	(void)Copy;
	return (*this);
}

Array::~Array()
{
}

Array&	Array::operator[](int n)
{
	return (T);
}

