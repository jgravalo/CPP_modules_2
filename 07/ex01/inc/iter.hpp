#ifndef ITER_HPP
#define ITER_HPP

#include<iostream>

template <typename T>
void	iter(T *a, int len, void (*f)(T&))
{
	if (a == NULL)
		return;
	for (int i = 0; i < len; i++)
	{
		f(a[i]);
	}
	return ;
}

#endif