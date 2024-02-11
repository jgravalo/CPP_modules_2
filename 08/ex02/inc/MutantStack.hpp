#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include<iostream>
#include<stack>

template <typename T>
class MutantStack : std::stack<T>
{
	public:
		MutantStack();
		MutantStack(class MutantStack<T>& Copy);
		MutantStack&	operator=(class MutantStack<T>& Copy);
		~MutantStack();
		typedef typename std::stack< T >::container_type::iterator	iterator;
		iterator	begin();
		iterator	end();
};

#endif

template <typename T>
MutantStack<T>::MutantStack() : std::stack<T>()
{
}

template <typename T>
MutantStack<T>::MutantStack(class MutantStack<T>& Copy) : std::stack<T>(Copy)
{
	(void)Copy;
}

template <typename T>
MutantStack<T>&	MutantStack<T>::operator=(class MutantStack<T>& Copy)
{
	return (std::stack<T>::operator=(Copy));
}

template <typename T>
MutantStack<T>::~MutantStack()
{
}

template <typename T>
iterator	MutantStack<T>::begin()
{
	return (std::stack<T>::begin());
}

template <typename T>
iterator	MutantStack<T>::end()
{
	return (std::stack<T>::end());
}
