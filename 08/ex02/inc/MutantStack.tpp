#include<MutantStack.hpp>

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
typename MutantStack< T >::iterator	MutantStack<T>::begin()
{
	return (this->c.begin());
}

template <typename T>
typename MutantStack< T >::iterator	MutantStack<T>::end()
{
	return (this->c.end());
}
