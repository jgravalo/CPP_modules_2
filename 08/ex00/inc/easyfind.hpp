#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include<iostream>
#include<cstdlib>
#include<vector>
#include<list>
#include<deque>

template <typename T>
int	easyfind(T& tmp, int n)
{
	if (std::find(tmp.begin(), tmp.end(), n) == tmp.end())
		return (1);
	return (0);
}

#endif